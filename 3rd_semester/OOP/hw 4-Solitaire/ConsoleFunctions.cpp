#include "ConsoleFunctions.h"
#include <string.h>

ConsoleFunctions::ConsoleFunctions()
{	
	hIn = GetStdHandle(STD_INPUT_HANDLE);   
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleMode(hIn,ENABLE_MOUSE_INPUT);
}

void ConsoleFunctions::setConsoleTitle(char* title)
{
	int len = strlen(title);
	wchar_t* str = new wchar_t[len+1];

	for(int i = 0; i<len; i++)
		str[i] = title[i];
	str[len] = '\0';

	SetConsoleTitle(LPCWSTR(str));
}

void ConsoleFunctions::SetCursorAt(int x,int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(hOut, coord);
}

char ConsoleFunctions::ReadFrom(int x, int y)
{
	char* str = new char;  //Buffer of 1 char size
	DWORD nLength = 1;     //The number of chars to read, we need to read one character only!
	COORD readFromCoord;   //Co-ordinates from where to read
	readFromCoord.X = x; 
	readFromCoord.Y = y;
	DWORD num_read=0;      //Will be set to no. of charaters actually read
	ReadConsoleOutputCharacter(hOut,(LPTSTR)str, nLength, readFromCoord,(LPDWORD)&num_read);
	return *str;																		 
}

void ConsoleFunctions::DetectEvent()
{
	DWORD nLength = 1;     //The number of records to read, we need to read one record only!
	DWORD num_read=0;      //Will be set to no. of input records actually read
	ReadConsoleInput(hIn, &InRec, nLength, &num_read);
}

void ConsoleFunctions::getMousePosition(point &p)
{
	p.x = InRec.Event.MouseEvent.dwMousePosition.X;
	p.y = InRec.Event.MouseEvent.dwMousePosition.Y;

}

bool ConsoleFunctions::IsMouseLeftClickEvent(point &p)
{
	if(InRec.EventType==MOUSE_EVENT && InRec.Event.MouseEvent.dwEventFlags==0 && InRec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
	{
		p.x = InRec.Event.MouseEvent.dwMousePosition.X;
		p.y = InRec.Event.MouseEvent.dwMousePosition.Y;
		return true;
	}
	return false;
}


bool ConsoleFunctions::IsMouseRightClickEvent(point &p)
{
	if(InRec.EventType==MOUSE_EVENT && InRec.Event.MouseEvent.dwEventFlags==0 && InRec.Event.MouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED)
	{
		p.x = InRec.Event.MouseEvent.dwMousePosition.X;
		p.y = InRec.Event.MouseEvent.dwMousePosition.Y;
		return true;
	}
	return false;
}

bool ConsoleFunctions::IsKeyPressEvent(char& key)
{
	if(InRec.EventType == KEY_EVENT && InRec.Event.KeyEvent.bKeyDown)
	{
		key = InRec.Event.KeyEvent.uChar.AsciiChar;
		return true;
	}
	return false;
}



bool ConsoleFunctions::IsKeyReleaseEvent(char& key)
{
	if(InRec.EventType == KEY_EVENT && !InRec.Event.KeyEvent.bKeyDown)
	{
		key = InRec.Event.KeyEvent.uChar.AsciiChar;
		return true;
	}
	return false;
}

int ConsoleFunctions::getTextColor()
{
	GetConsoleScreenBufferInfo(hOut,&csbi);
	int a=csbi.wAttributes;
	return a%16;
}

int ConsoleFunctions::getBackColor()
{
	GetConsoleScreenBufferInfo(hOut,&csbi);
	int a=csbi.wAttributes;
	return (a/16)%16;
}

void ConsoleFunctions::SetColor(ConsoleColor textcol,ConsoleColor backcol)
{
	SetColor(int(textcol),int(backcol));
}

void ConsoleFunctions::SetColor(int textcol,int backcol)
{
	bool textcolorprotect=true; //for future use
	/*doesn't let textcolor be the same as backgroung color if true*/
	if(textcolorprotect)
	{
		if((textcol%16)==(backcol%16))textcol++;
	}
	textcol%=16;
	backcol%=16;
	unsigned short wAttributes= (unsigned)textcol|((unsigned)backcol<<4);
	SetConsoleTextAttribute(hOut, wAttributes);
}

void ConsoleFunctions::clearConsole()
{

	COORD coordScreen = { 0, 0 };    // home for the cursor 
	DWORD cCharsWritten;
	//CONSOLE_SCREEN_BUFFER_INFO csbi; 
	DWORD dwConSize;
	SetColor(black,black);
	// Get the number of character cells in the current buffer. 

	if( !GetConsoleScreenBufferInfo( hOut, &csbi ))
	{
		return;
	}

	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

	// Fill the entire screen with blanks.

	if( !FillConsoleOutputCharacter( hOut,        // Handle to console screen buffer 
		(TCHAR) ' ',     // Character to write to the buffer
		dwConSize,       // Number of cells to write 
		coordScreen,     // Coordinates of first cell 
		&cCharsWritten ))// Receive number of characters written
	{
		return;
	}

	// Get the current text attribute.

	if( !GetConsoleScreenBufferInfo( hOut ,&csbi ))
	{
		return;
	}

	// Set the buffer's attributes accordingly.

	if( !FillConsoleOutputAttribute( hOut,         // Handle to console screen buffer 
		csbi.wAttributes, // Character attributes to use
		dwConSize,        // Number of cells to set attribute 
		coordScreen,      // Coordinates of first cell 
		&cCharsWritten )) // Receive number of characters written
	{
		return;
	}

	// Put the cursor at its home coordinates.

	SetConsoleCursorPosition( hOut, coordScreen );


}

ConsoleFunctions::~ConsoleFunctions()
{
}
