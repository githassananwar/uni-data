//     Header Files

#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<stdlib.h>
#include<cstring>

using namespace std;

//   Some Global Variables

int wins=0, loses=0, draws=0, total=0;
char doublePlayer[10000][200]={NULL};
int dblPlayr[10000]={NULL};
int dblPlyr=0;

//    Declaration of Functions

void menu();
void forMenu(bool a, bool b, bool c, bool d);

void about();

void instructions();

void status();
void forStatus(bool a, bool b);

void playgame();
void forPlayGame(bool a, bool b);

void singleplayer();
void forSinglePlayer(bool a, bool b, bool c);


void easy();

void medium();

void hard();

char apnaCheck(char game[3][3]);

char dusryKaCheck(char game[3][3]);

void singlePlayerStatus();

void multiplayer();

void doublePlayerStatus();
void detailsStatus();


void showGame(char game[3][3], bool a, bool b, bool c, bool d, bool e, bool f, bool g, bool h, bool i);

int win(char game[3][3]);

void goToAfterWinLoseOrDraw(int aa);
void forGoTo(bool a, bool b);

void pressEscape(int a);
void forPressEscape(bool a, bool b, bool c);

void playagain(int a);

void indexUsed();

void youWon();

void youLose();

void draw();

void exit();


//Main Funtion

int main()
{
    cout<<"\n\n\n\n\n\n\n\n";
    cout<<"                   #########################################\n";
    cout<<"                   #########################################\n";
    cout<<"                   ##                                     ##\n";
    cout<<"                   ##               WELCOME!              ##\n";
    cout<<"                   ##                                     ##\n";
    cout<<"                   #########################################\n";
    cout<<"                   #########################################\n";
    getch();
    menu();

    return 0;
}

//      Main Menu

void menu()
{
    char choice='o';
    bool a=true, b=false, c=false, d=false;
    while (choice!=13 || choice!=77)
    {
        system("CLS");
        cout<<"\n";
        cout<<"                   #########################################\n";
        cout<<"                   #########################################\n";
        cout<<"                   ##                                     ##\n";
        cout<<"                   ##              MAIN MENU              ##\n";
        cout<<"                   ##                                     ##\n";
        cout<<"                   #########################################\n";
        cout<<"                   #########################################\n";
        forMenu(a, b, c, d);
        choice=getch();

        //   Up & Left arrow instructions.

        if (choice==72 || choice==75)
        {
            if (a==true)
            {
                a=false;
                d=true;
            }
            else if (b==true)
            {
                b=false;
                a=true;
            }
            else if (c==true)
            {
                c=false;
                b=true;
            }
            else if (d==true)
            {
                d=false;
                c=true;
            }
        }

        //      Down & Right arrow Instructions.

        else if (choice==80 || choice==77)
        {
            if (a==true)
            {
                a=false;
                b=true;
            }
            else if (b==true)
            {
                b=false;
                c=true;
            }
            else if (c==true)
            {
                c=false;
                d=true;
            }
            else if (d==true)
            {
                d=false;
                a=true;
            }
        }

        //       Enter Key

        else if (choice==13)
        {
            if (a==true)
            {
                playgame();
                break;
            }
            else if (b==true)
            {
                about();
                break;
            }
            else if (c==true)
            {
                status();
                break;
            }
            else if (d==true)
            {
                instructions();
                break;
            }
        }

        //       Escape Key

        else if (choice==27)
        {
            exit();
            break;
        }
    }
}
void forMenu(bool a, bool b, bool c, bool d)
{
    if (a==true)
    {
        cout<<"                   #            ----------------           #\n";
        cout<<"                   #           | Start New Game |          #\n";
        cout<<"                   #            ----------------           #\n";
    }
    else
    {
        cout<<"                   #                                       #\n";
        cout<<"                   #             Start New Game            #\n";
        cout<<"                   #                                       #\n";
    }
    cout<<"                   #########################################\n";
    if (b==true)
    {
        cout<<"                   #                -------                #\n";
        cout<<"                   #               | About |               #\n";
        cout<<"                   #                -------                #\n";
    }
    else
    {
        cout<<"                   #                                       #\n";
        cout<<"                   #                 About                 #\n";
        cout<<"                   #                                       #\n";
    }
    cout<<"                   #########################################\n";
    if (c==true)
    {
        cout<<"                   #                --------               #\n";
        cout<<"                   #               | Status |              #\n";
        cout<<"                   #                --------               #\n";
    }
    else
    {
        cout<<"                   #                                       #\n";
        cout<<"                   #                 Status                #\n";
        cout<<"                   #                                       #\n";
    }
    cout<<"                   #########################################\n";
    if (d==true)
    {
        cout<<"                   #              --------------           #\n";
        cout<<"                   #             | Instructions |          #\n";
        cout<<"                   #              --------------           #\n";
    }
    else
    {
        cout<<"                   #                                       #\n";
        cout<<"                   #               Instructions            #\n";
        cout<<"                   #                                       #\n";
    }
    cout<<"                   #########################################\n";
}

//     About

void about()
{
    system("CLS");
    cout<<"\n\n";
    cout<<"                   #########################################\n";
    cout<<"                   #########################################\n";
    cout<<"                   ##                                     ##\n";
    cout<<"                   ##             TIC TAC TOE             ##\n";
    cout<<"                   ##                                     ##\n";
    cout<<"                   #########################################\n";
    cout<<"                   #########################################\n";
   
    char choice='o';
    while (choice!=8)
    {
        choice=getch();
        if (choice==8)
        {
            menu();
            break;
        }
    }
}

//     Instructions

void instructions()
{
    system("CLS");
    cout<<"\n";
    cout<<"                   #########################################\n";
    cout<<"                   #########################################\n";
    cout<<"                   ##                                     ##\n";
    cout<<"                   ##             TIC TAC TOE             ##\n";
    cout<<"                   ##                                     ##\n";
    cout<<"                   #########################################\n";
    cout<<"                   #########################################\n";
   
    char choice='k';
    while (choice!=8)
    {
        choice=getch();
        if (choice==8)
        {
            menu();
            break;
        }
    }
}

//     Status

void status()
{
    bool a=true, b=false;
    char choice='d';
    while (choice!=13)
    {
        system("CLS");
        cout<<"\n\n\n\n";
        cout<<"                   #########################################\n";
        cout<<"                   #########################################\n";
        cout<<"                   ##                                     ##\n";
        cout<<"                   ##                STATUS               ##\n";
        cout<<"                   ##                                     ##\n";
        cout<<"                   #########################################\n";
        cout<<"                   #########################################\n";
        forStatus(a, b);
        choice=getch();

        //      Left, Right, Up & Down Keys.

        if (choice==80 || choice==77 || choice==75 || choice==72)
        {
            if (a==true)
            {
                a=false;
                b=true;
            }
            else if (b==true)
            {
                b=false;
                a=true;
            }
        }

        //      BackSpace Key

        else if (choice==8)
        {
            menu();
            break;
        }

        //      Enter Key

        else if (choice==13)
        {
            if (a==true)
            {
                singlePlayerStatus();
                break;
            }
            else if (b==true)
            {
                doublePlayerStatus();
                break;
            }
        }
    }
}
void forStatus(bool a, bool b)
{
    if (a==false)
    {
        cout<<"                   #                                       #\n";
        cout<<"                   #              Single Player            #\n";
        cout<<"                   #                                       #\n";
    }
    else
    {
        cout<<"                   #             ---------------           #\n";
        cout<<"                   #            | Single Player |          #\n";
        cout<<"                   #             ---------------           #\n";
    }
    cout<<"                   #########################################\n";
    if (b==false)
    {
        cout<<"                   #                                       #\n";
        cout<<"                   #               Multiplayer             #\n";
        cout<<"                   #                                       #\n";
    }
    else
    {
        cout<<"                   #              -------------            #\n";
        cout<<"                   #             | Multiplayer |           #\n";
        cout<<"                   #              -------------            #\n";
    }
    cout<<"                   #########################################\n";
}

//     Play Game

void playgame()
{
    char choice='1';
    bool a=true, b=false;
    while (choice!=13)
    {
        system("CLS");
        cout<<"\n\n\n\n";
        cout<<"                   #########################################\n";
        cout<<"                   #########################################\n";
        cout<<"                   ##                                     ##\n";
        cout<<"                   ##              PLAY GAME              ##\n";
        cout<<"                   ##                                     ##\n";
        cout<<"                   #########################################\n";
        cout<<"                   #########################################\n";
        forPlayGame(a, b);
        choice=getch();

        //      Up, Down, Left & Right Keys Instructions.

        if (choice==72 || choice==80 || choice==77 || choice==75)
        {
            if (a==true)
            {
                a=false;
                b=true;
            }
            else if (b==true)
            {
                b=false;
                a=true;
            }
        }

        //     Enter Key

        else if (choice==13)
        {
            if (a==true)
            {
                singleplayer();
                break;
            }
            else if (b==true)
            {
                multiplayer();
                break;
            }
        }

        //     BackSpace Key

        else if (choice==8)
        {
            menu();
            break;
        }
    }
}
void forPlayGame(bool a, bool b)
{
    if (a==true)
    {
        cout<<"                   #            ---------------            #\n";
        cout<<"                   #           | Single Player |           #\n";
        cout<<"                   #            ---------------            #\n";
    }
    else
    {
        cout<<"                   #                                       #\n";
        cout<<"                   #             Single Player             #\n";
        cout<<"                   #                                       #\n";
    }
    cout<<"                   #########################################\n";
    if (b==true)
    {
        cout<<"                   #             --------------            #\n";
        cout<<"                   #            | Multi Player |           #\n";
        cout<<"                   #             --------------            #\n";
    }
    else
    {
        cout<<"                   #                                       #\n";
        cout<<"                   #              Multi Player             #\n";
        cout<<"                   #                                       #\n";
    }
    cout<<"                   #########################################\n";
}

//       Single Player.

void singleplayer()
{
    char choice='0';
    bool a=true, b=false, c=false;
    while (choice!=13)
    {
        system("CLS");
        cout<<"\n\n\n";
        cout<<"                   #########################################\n";
        cout<<"                   #########################################\n";
        cout<<"                   ##                                     ##\n";
        cout<<"                   ##            DIFFICULTIES             ##\n";
        cout<<"                   ##                                     ##\n";
        cout<<"                   #########################################\n";
        cout<<"                   #########################################\n";
        forSinglePlayer(a, b, c);
        choice=getch();

        //      Up & Left Key Instructions.

        if (choice==72 || choice==75)
        {
            if (a==true)
            {
                a=false;
                c=true;
            }
            else if (b==true)
            {
                b=false;
                a=true;
            }
            else if (c==true)
            {
                c=false;
                b=true;
            }
        }

        //      Down & Right Key Instructions

        else if (choice==80 || choice==77)
        {
            if (a==true)
            {
                a=false;
                b=true;
            }
            else if (b==true)
            {
                b=false;
                c=true;
            }
            else if (c==true)
            {
                c=false;
                a=true;
            }
        }

        //     Enter Key.

        else if (choice==13)
        {
            if (a==true)
            {
                easy();
                break;
            }
            else if (b==true)
            {
                medium();
                break;
            }
            else if (c==true)
            {
                hard();
                break;
            }
        }

        //     BackSpace Key.

        else if (choice==8)
        {
            playgame();
            break;
        }
    }
}
void forSinglePlayer(bool a, bool b, bool c)
{
    if (a==true)
    {
        cout<<"                   #                 ------                #\n";
        cout<<"                   #                | Easy |               #\n";
        cout<<"                   #                 ------                #\n";
    }
    else
    {
        cout<<"                   #                                       #\n";
        cout<<"                   #                  Easy                 #\n";
        cout<<"                   #                                       #\n";
    }
    cout<<"                   #########################################\n";
    if (b==true)
    {
        cout<<"                   #                --------               #\n";
        cout<<"                   #               | Medium |              #\n";
        cout<<"                   #                --------               #\n";
    }
    else
    {
        cout<<"                   #                                       #\n";
        cout<<"                   #                 Medium                #\n";
        cout<<"                   #                                       #\n";
    }
    cout<<"                   #########################################\n";
    if (c==true)
    {
        cout<<"                   #                 ------                #\n";
        cout<<"                   #                | Hard |               #\n";
        cout<<"                   #                 ------                #\n";
    }
    else
    {
        cout<<"                   #                                       #\n";
        cout<<"                   #                  Hard                 #\n";
        cout<<"                   #                                       #\n";
    }
    cout<<"                   #########################################\n";
}

//            Easy Difficulty

void easy()
{
    char game[3][3]={NULL};
    int count=1, player=0, flag=0, aa=3, flagOne=0;
    char index='\0';
    bool a=true, b=false, c=false, d=false, e=false, f=false, g=false, h=false, i=false;
    system("CLS");
    int j=0;
    cout<<"              ##################################################\n";
    cout<<"              ##################################################\n";
    cout<<"              ###                                            ###\n";
    cout<<"              ###                  YOUR TURN                 ###\n";
    cout<<"              ###                                            ###\n";
    showGame(game, a, b, c, d, e, f, g, h, i);
    while (count<=9)
    {
        index='\0';
        flag=0;
        flagOne=0;
        if (count==1 || count==3 || count==5 || count==7 || count==9)
        {
            player=1;
            while (index!=13)
            {
                index=getch();

                while (index!=13 && index!=8 && index!=27 && index!=77 && index!=75 && index!=72 && index!=80)
                {
                    index=getch();
                }

                //      BackSpace Key

                if (index==8 && count==1)
                {
                    singleplayer();
                    break;
                }

                //       Escape Key.

                else if (index==27)
                {
                    pressEscape(aa);
                }

                //       Right Key.

                else if (index==77)
                {
                    if (a==true)
                    {
                        a=false;
                        b=true;
                    }
                    else if (b==true)
                    {
                        b=false;
                        c=true;
                    }
                    else if (c==true)
                    {
                        c=false;
                        d=true;
                    }
                    else if (d==true)
                    {
                        d=false;
                        e=true;
                    }
                    else if (e==true)
                    {
                        e=false;
                        f=true;
                    }
                    else if (f==true)
                    {
                        f=false;
                        g=true;
                    }
                    else if (g==true)
                    {
                        g=false;
                        h=true;
                    }
                    else if (h==true)
                    {
                        h=false;
                        i=true;
                    }
                    else if (i==true)
                    {
                        i=false;
                        a=true;
                    }
                }

                //       Left Key.

                else if (index==75)
                {
                    if (a==true)
                    {
                        a=false;
                        i=true;
                    }
                    else if (b==true)
                    {
                        b=false;
                        a=true;
                    }
                    else if (c==true)
                    {
                        c=false;
                        b=true;
                    }
                    else if (d==true)
                    {
                        d=false;
                        c=true;
                    }
                    else if (e==true)
                    {
                        e=false;
                        d=true;
                    }
                    else if (f==true)
                    {
                        f=false;
                        e=true;
                    }
                    else if (g==true)
                    {
                        g=false;
                        f=true;
                    }
                    else if (h==true)
                    {
                        h=false;
                        g=true;
                    }
                    else if (i==true)
                    {
                        i=false;
                        h=true;
                    }
                }

                //       Down Key.

                else if (index==80)
                {
                    if (a==true)
                    {
                        a=false;
                        d=true;
                    }
                    else if (b==true)
                    {
                        b=false;
                        e=true;
                    }
                    else if (c==true)
                    {
                        c=false;
                        f=true;
                    }
                    else if (d==true)
                    {
                        d=false;
                        g=true;
                    }
                    else if (e==true)
                    {
                        e=false;
                        h=true;
                    }
                    else if (f==true)
                    {
                        f=false;
                        i=true;
                    }
                    else if (g==true)
                    {
                        g=false;
                        a=true;
                    }
                    else if (h==true)
                    {
                        h=false;
                        b=true;
                    }
                    else if (i==true)
                    {
                        i=false;
                        c=true;
                    }
                }

                //     Up Key.

                else if (index==72)
                {
                    if (a==true)
                    {
                        a=false;
                        g=true;
                    }
                    else if (b==true)
                    {
                        b=false;
                        h=true;
                    }
                    else if (c==true)
                    {
                        c=false;
                        i=true;
                    }
                    else if (d==true)
                    {
                        d=false;
                        a=true;
                    }
                    else if (e==true)
                    {
                        e=false;
                        b=true;
                    }
                    else if (f==true)
                    {
                        f=false;
                        c=true;
                    }
                    else if (g==true)
                    {
                        g=false;
                        d=true;
                    }
                    else if (h==true)
                    {
                        h=false;
                        e=true;
                    }
                    else if (i==true)
                    {
                        i=false;
                        f=true;
                    }
                }

                //      Enter Key.

                else if (index==13)
                {
                    if (a==true && game[0][0]=='\0')
                    {
                        game[0][0]='X';
                    }
                    else if (a==true && game[0][0]!='\0')
                    {
                        indexUsed();
                        flagOne=1;
                    }
                    else if (b==true && game[0][1]=='\0')
                    {
                        game[0][1]='X';
                    }
                    else if (b==true && game[0][1]!='\0')
                    {
                        indexUsed();
                        flagOne=1;
                    }
                    else if (c==true && game[0][2]=='\0')
                    {
                        game[0][2]='X';
                    }
                    else if (c==true && game[0][2]!='\0')
                    {
                        indexUsed();
                        flagOne=1;
                    }
                    else if (d==true && game[1][0]=='\0')
                    {
                        game[1][0]='X';
                    }
                    else if (d==true && game[1][0]!='\0')
                    {
                        indexUsed();
                        flagOne=1;
                    }
                    else if (e==true && game[1][1]=='\0')
                    {
                        game[1][1]='X';
                    }
                    else if (e==true && game[1][1]!='\0')
                    {
                        indexUsed();
                        flagOne=1;
                    }
                    else if (f==true && game[1][2]=='\0')
                    {
                        game[1][2]='X';
                    }
                    else if (f==true && game[1][2]!='\0')
                    {
                        indexUsed();
                        flagOne=1;
                    }
                    else if (g==true && game[2][0]=='\0')
                    {
                        game[2][0]='X';
                    }
                    else if (g==true && game[2][0]!='\0')
                    {
                        indexUsed();
                        flagOne=1;
                    }
                    else if (h==true && game[2][1]=='\0')
                    {
                        game[2][1]='X';
                    }
                    else if (h==true && game[2][1]!='\0')
                    {
                        indexUsed();
                        flagOne=1;
                    }
                    else if (i==true && game[2][2]=='\0')
                    {
                        game[2][2]='X';
                    }
                    else if (i==true && game[2][2]!='\0')
                    {
                        indexUsed();
                        flagOne=1;
                    }
                }
                system("CLS");
                cout<<"              ##################################################\n";
                cout<<"              ##################################################\n";
                cout<<"              ###                                            ###\n";
                cout<<"              ###                  YOUR TURN                 ###\n";
                cout<<"              ###                                            ###\n";
                showGame(game, a, b, c, d, e, f, g, h, i);
            }
        }
        else if (count==2 || count==4 || count==6 || count==8)
        {
            player=2;
            flagOne=2;
            while (flagOne==2)
            {
                index=49+(rand()%9);
                flagOne=0;
                switch (index)
                {
                    case '1':
                    if (game[0][0]!='X' && game[0][0]!='O' && player==2)
                    game[0][0]='O';
                    else
                    {
                        flagOne=2;
                    }
                    break;
                    case '2':
                    if (game[0][1]!='X' && game[0][1]!='O' && player==2)
                    game[0][1]='O';
                    else
                    {
                        flagOne=2;
                    }
                    break;
                    case '3':
                    if (game[0][2]!='X' && game[0][2]!='O' && player==2)
                    game[0][2]='O';
                    else
                    {
                        flagOne=2;
                    }
                    break;
                    case '4':
                    if (game[1][0]!='X' && game[1][0]!='O' && player==2)
                    game[1][0]='O';
                    else
                    {
                        flagOne=2;
                    }
                    break;
                    case '5':
                    if (game[1][1]!='X' && game[1][1]!='O' && player==2)
                    game[1][1]='O';
                    else
                    {
                        flagOne=2;
                    }
                    break;
                    case '6':
                    if (game[1][2]!='X' && game[1][2]!='O' && player==2)
                    game[1][2]='O';
                    else
                    {
                        flagOne=2;
                    }
                    break;
                    case '7':
                    if (game[2][0]!='X' && game[2][0]!='O' && player==2)
                    game[2][0]='O';
                    else
                    {
                        flagOne=2;
                    }
                    break;
                    case '8':
                    if (game[2][1]!='X' && game[2][1]!='O' && player==2)
                    game[2][1]='O';
                    else
                    {
                        flagOne=2;
                    }
                    break;
                    case '9':
                    if (game[2][2]!='X' && game[2][2]!='O' && player==2)
                    game[2][2]='O';
                    else
                    {
                        flagOne=2;
                    }
                    break;
                    default:
                    flagOne=2;
                }
            }
        }
        system("CLS");
        cout<<"              ##################################################\n";
        cout<<"              ##################################################\n";
        cout<<"              ###                                            ###\n";
        cout<<"              ###                  YOUR TURN                 ###\n";
        cout<<"              ###                                            ###\n";
        showGame(game, a, b, c, d, e, f, g, h, i);
        if (index=='1' || index=='2' || index=='3' || index=='4' || index=='5' || index=='6' || index=='7' || index=='8' || index=='9' || index==13)
        count++;
        if (flagOne==1 || flagOne==2)
        count--;
        flag=win(game);
        if (flag==1)
        {
            wins++;
            system("CLS");
            cout<<"              ##################################################\n";
            cout<<"              ##################################################\n";
            cout<<"              ###                                            ###\n";
            cout<<"              ###          PRESS ANY KEY TO CONTINUE         ###\n";
            cout<<"              ###                                            ###\n";
            showGame(game, a, b, c, d, e, f, g, h, i);
            getch();
            youWon();
            goToAfterWinLoseOrDraw(aa);
            break;
        }
        else if (flag==2)
        {
            loses++;
            system("CLS");
            cout<<"              ##################################################\n";
            cout<<"              ##################################################\n";
            cout<<"              ###                                            ###\n";
            cout<<"              ###          PRESS ANY KEY TO CONTINUE         ###\n";
            cout<<"              ###                                            ###\n";
            showGame(game, a, b, c, d, e, f, g, h, i);
            getch();
            youLose();
            goToAfterWinLoseOrDraw(aa);
            break;
        }
    }
    if (flag==0)
    {
        system("CLS");
        cout<<"              ##################################################\n";
        cout<<"              ##################################################\n";
        cout<<"              ###                                            ###\n";
        cout<<"              ###          PRESS ANY KEY TO CONTINUE         ###\n";
        cout<<"              ###                                            ###\n";
        showGame(game, a, b, c, d, e, f, g, h, i);
        getch();
        draws++;
        draw();
        goToAfterWinLoseOrDraw(aa);
    }
}

//         Medium Difficulty.

void medium()
{
    char game[3][3]={NULL};
    bool a=true, b=false, c=false, d=false, e=false, f=false, g=false, h=false, i=false;
    int player=0, count=1, flag=0, aa=2;
    char index='\0';
    system("CLS");
    int j=0;
    cout<<"              ##################################################\n";
    cout<<"              ##################################################\n";
    cout<<"              ###                                            ###\n";
    cout<<"              ###                  YOUR TURN                 ###\n";
    cout<<"              ###                                            ###\n";
    showGame(game, a, b, c, d, e, f, g, h, i);
    while (count<=9)
    {
        flag=0;
        index='\0';
        int flagOne=0;
        if (count==1 || count==3 || count==5 || count==7 || count==9)
        {
            while (index!=13)
            {
                index=getch();

                while (index!=13 && index!=8 && index!=27 && index!=77 && index!=75 && index!=72 && index!=80)
                {
                    index=getch();
                }

                //      BackSpace Key

                if (index==8 && count==1)
                {
                    singleplayer();
                    break;
                }

                //      Escape Key

                else if (index==27)
                {
                    pressEscape(aa);
                }

                //      Right Key

                else if (index==77)
                {
                    if (a==true)
                    {
                        a=false;
                        b=true;
                    }
                    else if (b==true)
                    {
                        b=false;
                        c=true;
                    }
                    else if (c==true)
                    {
                        c=false;
                        d=true;
                    }
                    else if (d==true)
                    {
                        d=false;
                        e=true;
                    }
                    else if (e==true)
                    {
                        e=false;
                        f=true;
                    }
                    else if (f==true)
                    {
                        f=false;
                        g=true;
                    }
                    else if (g==true)
                    {
                        g=false;
                        h=true;
                    }
                    else if (h==true)
                    {
                        h=false;
                        i=true;
                    }
                    else if (i==true)
                    {
                        i=false;
                        a=true;
                    }
                }

                //       Left Key.

                else if (index==75)
                {
                    if (a==true)
                    {
                        a=false;
                        i=true;
                    }
                    else if (b==true)
                    {
                        b=false;
                        a=true;
                    }
                    else if (c==true)
                    {
                        c=false;
                        b=true;
                    }
                    else if (d==true)
                    {
                        d=false;
                        c=true;
                    }
                    else if (e==true)
                    {
                        e=false;
                        d=true;
                    }
                    else if (f==true)
                    {
                        f=false;
                        e=true;
                    }
                    else if (g==true)
                    {
                        g=false;
                        f=true;
                    }
                    else if (h==true)
                    {
                        h=false;
                        g=true;
                    }
                    else if (i==true)
                    {
                        i=false;
                        h=true;
                    }
                }

                //       Down Key.

                else if (index==80)
                {
                    if (a==true)
                    {
                        a=false;
                        d=true;
                    }
                    else if (b==true)
                    {
                        b=false;
                        e=true;
                    }
                    else if (c==true)
                    {
                        c=false;
                        f=true;
                    }
                    else if (d==true)
                    {
                        d=false;
                        g=true;
                    }
                    else if (e==true)
                    {
                        e=false;
                        h=true;
                    }
                    else if (f==true)
                    {
                        f=false;
                        i=true;
                    }
                    else if (g==true)
                    {
                        g=false;
                        a=true;
                    }
                    else if (h==true)
                    {
                        h=false;
                        b=true;
                    }
                    else if (i==true)
                    {
                        i=false;
                        c=true;
                    }
                }

                //      Up Key.

                else if (index==72)
                {
                    if (a==true)
                    {
                        a=false;
                        g=true;
                    }
                    else if (b==true)
                    {
                        b=false;
                        h=true;
                    }
                    else if (c==true)
                    {
                        c=false;
                        i=true;
                    }
                    else if (d==true)
                    {
                        d=false;
                        a=true;
                    }
                    else if (e==true)
                    {
                        e=false;
                        b=true;
                    }
                    else if (f==true)
                    {
                        f=false;
                        c=true;
                    }
                    else if (g==true)
                    {
                        g=false;
                        d=true;
                    }
                    else if (h==true)
                    {
                        h=false;
                        e=true;
                    }
                    else if (i==true)
                    {
                        i=false;
                        f=true;
                    }
                }

                //     Enter Key

                else if (index==13)
                {
                    if (a==true && game[0][0]=='\0')
                    {
                        game[0][0]='X';
                    }
                    else if (a==true && game[0][0]!='\0')
                    {
                        indexUsed();
                        flagOne=1;
                    }
                    else if (b==true && game[0][1]=='\0')
                    {
                        game[0][1]='X';
                    }
                    else if (b==true && game[0][1]!='\0')
                    {
                        indexUsed();
                        flagOne=1;
                    }
                    else if (c==true && game[0][2]=='\0')
                    {
                        game[0][2]='X';
                    }
                    else if (c==true && game[0][2]!='\0')
                    {
                        indexUsed();
                        flagOne=1;
                    }
                    else if (d==true && game[1][0]=='\0')
                    {
                        game[1][0]='X';
                    }
                    else if (d==true && game[1][0]!='\0')
                    {
                        indexUsed();
                        flagOne=1;
                    }
                    else if (e==true && game[1][1]=='\0')
                    {
                        game[1][1]='X';
                    }
                    else if (e==true && game[1][1]!='\0')
                    {
                        indexUsed();
                        flagOne=1;
                    }
                    else if (f==true && game[1][2]=='\0')
                    {
                        game[1][2]='X';
                    }
                    else if (f==true && game[1][2]!='\0')
                    {
                        indexUsed();
                        flagOne=1;
                    }
                    else if (g==true && game[2][0]=='\0')
                    {
                        game[2][0]='X';
                    }
                    else if (g==true && game[2][0]!='\0')
                    {
                        indexUsed();
                        flagOne=1;
                    }
                    else if (h==true && game[2][1]=='\0')
                    {
                        game[2][1]='X';
                    }
                    else if (h==true && game[2][1]!='\0')
                    {
                        indexUsed();
                        flagOne=1;
                    }
                    else if (i==true && game[2][2]=='\0')
                    {
                        game[2][2]='X';
                    }
                    else if (i==true && game[2][2]!='\0')
                    {
                        indexUsed();
                        flagOne=1;
                    }
                }
                system("CLS");
                cout<<"              ##################################################\n";
                cout<<"              ##################################################\n";
                cout<<"              ###                                            ###\n";
                cout<<"              ###                  YOUR TURN                 ###\n";
                cout<<"              ###                                            ###\n";
                showGame(game, a, b, c, d, e, f, g, h, i);
            }
        }
        else if (count==2 || count==4 || count==6 || count==8)
        {
            player=2;
            index='0';
            index=apnaCheck(game);
            if (index=='0')
            {
                index=dusryKaCheck(game);
            }
                if (index=='0')
                {
                    flagOne=2;
                    while (flagOne==2)
                    {
                        index=49+(rand()%9);
                        flagOne=0;
                        switch (index)
                        {
                            case '1':
                            if (game[0][0]!='X' && game[0][0]!='O' && player==2)
                            game[0][0]='O';
                            else
                            {
                                flagOne=2;
                            }
                            break;
                            case '2':
                            if (game[0][1]!='X' && game[0][1]!='O' && player==2)
                            game[0][1]='O';
                            else
                            {
                                flagOne=2;
                            }
                            break;
                            case '3':
                            if (game[0][2]!='X' && game[0][2]!='O' && player==2)
                            game[0][2]='O';
                            else
                            {
                                flagOne=2;
                            }
                            break;
                            case '4':
                            if (game[1][0]!='X' && game[1][0]!='O' && player==2)
                            game[1][0]='O';
                            else
                            {
                                flagOne=2;
                            }
                            break;
                            case '5':
                            if (game[1][1]!='X' && game[1][1]!='O' && player==2)
                            game[1][1]='O';
                            else
                            {
                                flagOne=2;
                            }
                            break;
                            case '6':
                            if (game[1][2]!='X' && game[1][2]!='O' && player==2)
                            game[1][2]='O';
                            else
                            {
                                flagOne=2;
                            }
                            break;
                            case '7':
                            if (game[2][0]!='X' && game[2][0]!='O' && player==2)
                            game[2][0]='O';
                            else
                            {
                                flagOne=2;
                            }
                            break;
                            case '8':
                            if (game[2][1]!='X' && game[2][1]!='O' && player==2)
                            game[2][1]='O';
                            else
                            {
                                flagOne=2;
                            }
                            break;
                            case '9':
                            if (game[2][2]!='X' && game[2][2]!='O' && player==2)
                            game[2][2]='O';
                            else
                            {
                                flagOne=2;
                            }
                            break;
                            default:
                            flagOne=2;
                        }
                    }
                }
                else
                {
                    switch (index)
                    {
                        case '1':
                        game[0][0]='O';
                        break;
                        case '2':
                        game[0][1]='O';
                        break;
                        case '3':
                        game[0][2]='O';
                        break;
                        case '4':
                        game[1][0]='O';
                        break;
                        case '5':
                        game[1][1]='O';
                        break;
                        case '6':
                        game[1][2]='O';
                        break;
                        case '7':
                        game[2][0]='O';
                        break;
                        case '8':
                        game[2][1]='O';
                        break;
                        case '9':
                        game[2][2]='O';
                        break;
                    }
                }
                system("CLS");
                cout<<"              ##################################################\n";
                cout<<"              ##################################################\n";
                cout<<"              ###                                            ###\n";
                cout<<"              ###                  YOUR TURN                 ###\n";
                cout<<"              ###                                            ###\n";
                showGame(game, a, b, c, d, e, f, g, h, i);
        }
        if (index=='1' || index=='2' || index=='3' || index=='4' || index=='5' || index=='6' || index=='7' || index=='8' || index=='9' || index==13)
        count++;
        if (flagOne==1)
        count--;
        flag=win(game);
        if (flag==1)
        {
            wins++;
            system("CLS");
            cout<<"              ##################################################\n";
            cout<<"              ##################################################\n";
            cout<<"              ###                                            ###\n";
            cout<<"              ###          PRESS ANY KEY TO CONTINUE         ###\n";
            cout<<"              ###                                            ###\n";
            showGame(game, a, b, c, d, e, f, g, h, i);
            getch();
            youWon();
            goToAfterWinLoseOrDraw(aa);
            break;
        }
        else if (flag==2)
        {
            loses++;
            system("CLS");
            cout<<"              ##################################################\n";
            cout<<"              ##################################################\n";
            cout<<"              ###                                            ###\n";
            cout<<"              ###          PRESS ANY KEY TO CONTINUE         ###\n";
            cout<<"              ###                                            ###\n";
            showGame(game, a, b, c, d, e, f, g, h, i);
            getch();
            youLose();
            goToAfterWinLoseOrDraw(aa);
            break;
        }
    }
    if (flag==0)
    {
        draws++;
        system("CLS");
        cout<<"              ##################################################\n";
        cout<<"              ##################################################\n";
        cout<<"              ###                                            ###\n";
        cout<<"              ###          PRESS ANY KEY TO CONTINUE         ###\n";
        cout<<"              ###                                            ###\n";
        showGame(game, a, b, c, d, e, f, g, h, i);
        getch();
        draw();
        goToAfterWinLoseOrDraw(aa);
    }
}

//      Hard Difficulty

void hard()
{
    char game[3][3]={NULL};
    bool a=true, b=false, c=false, d=false, e=false, f=false, g=false, h=false, i=false;
    int player=0, count=1, flag=0, aa=1;
    char index='\0';
    system("CLS");
    cout<<"              ##################################################\n";
    cout<<"              ##################################################\n";
    cout<<"              ###                                            ###\n";
    cout<<"              ###                  YOUR TURN                 ###\n";
    cout<<"              ###                                            ###\n";
    showGame(game, a, b, c, d, e, f, g, h, i);
    while (count<=9)
    {
        index='\0';
        flag=0;
        int flagOne=0;
        if (count==1 || count==3 || count==5 || count==7 || count==9)
        {
            player=1;
            while (index!=13)
            {
                index=getch();

                while (index!=13 && index!=8 && index!=27 && index!=77 && index!=75 && index!=72 && index!=80)
                {
                    index=getch();
                }

                //      BackSpace Key.

                if (index==8 && count==1)
                {
                    singleplayer();
                    break;
                }

                //      Escape Key.

                else if (index==27)
                {
                    pressEscape(aa);
                }

                //      Right Key.

                else if (index==77)
                {
                    if (a==true)
                    {
                        a=false;
                        b=true;
                    }
                    else if (b==true)
                    {
                        b=false;
                        c=true;
                    }
                    else if (c==true)
                    {
                        c=false;
                        d=true;
                    }
                    else if (d==true)
                    {
                        d=false;
                        e=true;
                    }
                    else if (e==true)
                    {
                        e=false;
                        f=true;
                    }
                    else if (f==true)
                    {
                        f=false;
                        g=true;
                    }
                    else if (g==true)
                    {
                        g=false;
                        h=true;
                    }
                    else if (h==true)
                    {
                        h=false;
                        i=true;
                    }
                    else if (i==true)
                    {
                        i=false;
                        a=true;
                    }
                }

                //      Left Key.

                else if (index==75)
                {
                    if (a==true)
                    {
                        a=false;
                        i=true;
                    }
                    else if (b==true)
                    {
                        b=false;
                        a=true;
                    }
                    else if (c==true)
                    {
                        c=false;
                        b=true;
                    }
                    else if (d==true)
                    {
                        d=false;
                        c=true;
                    }
                    else if (e==true)
                    {
                        e=false;
                        d=true;
                    }
                    else if (f==true)
                    {
                        f=false;
                        e=true;
                    }
                    else if (g==true)
                    {
                        g=false;
                        f=true;
                    }
                    else if (h==true)
                    {
                        h=false;
                        g=true;
                    }
                    else if (i==true)
                    {
                        i=false;
                        h=true;
                    }
                }

                //     Down Key.

                else if (index==80)
                {
                    if (a==true)
                    {
                        a=false;
                        d=true;
                    }
                    else if (b==true)
                    {
                        b=false;
                        e=true;
                    }
                    else if (c==true)
                    {
                        c=false;
                        f=true;
                    }
                    else if (d==true)
                    {
                        d=false;
                        g=true;
                    }
                    else if (e==true)
                    {
                        e=false;
                        h=true;
                    }
                    else if (f==true)
                    {
                        f=false;
                        i=true;
                    }
                    else if (g==true)
                    {
                        g=false;
                        a=true;
                    }
                    else if (h==true)
                    {
                        h=false;
                        b=true;
                    }
                    else if (i==true)
                    {
                        i=false;
                        c=true;
                    }
                }

                //      Up Key.

                else if (index==72)
                {
                    if (a==true)
                    {
                        a=false;
                        g=true;
                    }
                    else if (b==true)
                    {
                        b=false;
                        h=true;
                    }
                    else if (c==true)
                    {
                        c=false;
                        i=true;
                    }
                    else if (d==true)
                    {
                        d=false;
                        a=true;
                    }
                    else if (e==true)
                    {
                        e=false;
                        b=true;
                    }
                    else if (f==true)
                    {
                        f=false;
                        c=true;
                    }
                    else if (g==true)
                    {
                        g=false;
                        d=true;
                    }
                    else if (h==true)
                    {
                        h=false;
                        e=true;
                    }
                    else if (i==true)
                    {
                        i=false;
                        f=true;
                    }
                }

                //      Enter Key.

                else if (index==13)
                {
                    if (a==true && game[0][0]=='\0')
                    {
                        game[0][0]='X';
                        break;
                    }
                    else if (a==true && game[0][0]!='\0')
                    {
                        indexUsed();
                        flagOne=1;
                    }
                    else if (b==true && game[0][1]=='\0')
                    {
                        game[0][1]='X';
                        break;
                    }
                    else if (b==true && game[0][1]!='\0')
                    {
                        indexUsed();
                        flagOne=1;
                    }
                    else if (c==true && game[0][2]=='\0')
                    {
                        game[0][2]='X';
                        break;
                    }
                    else if (c==true && game[0][2]!='\0')
                    {
                        indexUsed();
                        flagOne=1;
                    }
                    else if (d==true && game[1][0]=='\0')
                    {
                        game[1][0]='X';
                        break;
                    }
                    else if (d==true && game[1][0]!='\0')
                    {
                        indexUsed();
                        flagOne=1;
                    }
                    else if (e==true && game[1][1]=='\0')
                    {
                        game[1][1]='X';
                        break;
                    }
                    else if (e==true && game[1][1]!='\0')
                    {
                        indexUsed();
                        flagOne=1;
                    }
                    else if (f==true && game[1][2]=='\0')
                    {
                        game[1][2]='X';
                        break;
                    }
                    else if (f==true && game[1][2]!='\0')
                    {
                        indexUsed();
                        flagOne=1;
                    }
                    else if (g==true && game[2][0]=='\0')
                    {
                        game[2][0]='X';
                        break;
                    }
                    else if (g==true && game[2][0]!='\0')
                    {
                        indexUsed();
                        flagOne=1;
                    }
                    else if (h==true && game[2][1]=='\0')
                    {
                        game[2][1]='X';
                        break;
                    }
                    else if (h==true && game[2][1]!='\0')
                    {
                        indexUsed();
                        flagOne=1;
                    }
                    else if (i==true && game[2][2]=='\0')
                    {
                        game[2][2]='X';
                        break;
                    }
                    else if (i==true && game[2][2]!='\0')
                    {
                        indexUsed();
                        flagOne=1;
                    }
                }
                system("CLS");
                cout<<"              ##################################################\n";
                cout<<"              ##################################################\n";
                cout<<"              ###                                            ###\n";
                cout<<"              ###                  YOUR TURN                 ###\n";
                cout<<"              ###                                            ###\n";
                showGame(game, a, b, c, d, e, f, g, h, i);
            }
        }
        else if (count==2 || count==4 || count==6 || count==8)
        {
            player=2;
            flagOne=2;
            index='0';
            index=apnaCheck(game);
            if (index=='0')
            index=dusryKaCheck(game);
            if (index=='0')
            {
                if (count==2)
                {
                    if (game[0][0]=='X' || game[0][2]=='X' || game[2][0]=='X' || game[2][2]=='X' || game[0][1]=='X' || game[1][0]=='X' || game[1][2]=='X' || game[2][1]=='X')
                    index='5';
                    else if (game[1][1]=='X')
                    index='1';
                }
                else if (count==4)
                {
                    if (game[2][2]=='X' && game[0][0]=='X')
                    index='8';
                    else if (game[0][2]=='X' && game[2][0]=='X')
                    index='4';
                    else if (game[1][1]=='X' && game[2][2]=='X')
                    index='3';
                    else if (game[0][1]=='X' && game[1][0]=='X')
                    index='1';
                    else if (game[0][1]=='X' && game[1][2]=='X')
                    index='3';
                    else if (game[1][0]=='X' && game[2][1]=='X')
                    index='7';
                    else if (game[2][1]=='X' && game[1][2]=='X')
                    index='9';
                    else if (game[2][1]=='X' && game[0][2]=='X')
                    index='9';
                    else if (game[2][1]=='X' && game[0][0]=='X')
                    index='7';
                    else if (game[0][1]=='X' && game[2][0]=='X')
                    index='1';
                    else if (game[0][1]=='X' && game[2][2]=='X')
                    index='3';
                    else if (game[1][2]=='X' && game[0][0]=='X')
                    index='3';
                    else if (game[1][2]=='X' && game[2][0]=='X')
                    index='9';
                    else if (game[1][0]=='X' && game[0][2]=='X')
                    index='1';
                    else if (game[1][0]=='X' && game[2][2]=='X')
                    index='7';
                    else if ((game[1][0]=='X' && game[1][2]=='X') || (game[0][1]=='X' && game[2][1]=='X'))
                    index='1';

                }
            }
            if (index=='0')
            {
                flagOne=2;
                while (flagOne==2)
                {
                    index=49+(rand()%9);
                    flagOne=0;
                    switch (index)
                    {
                        case '1':
                        if (game[0][0]!='X' && game[0][0]!='O' && player==2)
                        game[0][0]='O';
                        else
                        {
                            flagOne=2;
                        }
                        break;
                        case '2':
                        if (game[0][1]!='X' && game[0][1]!='O' && player==2)
                        game[0][1]='O';
                        else
                        {
                            flagOne=2;
                        }
                        break;
                        case '3':
                        if (game[0][2]!='X' && game[0][2]!='O' && player==2)
                        game[0][2]='O';
                        else
                        {
                            flagOne=2;
                        }
                        break;
                        case '4':
                        if (game[1][0]!='X' && game[1][0]!='O' && player==2)
                        game[1][0]='O';
                        else
                        {
                            flagOne=2;
                        }
                        break;
                        case '5':
                        if (game[1][1]!='X' && game[1][1]!='O' && player==2)
                        game[1][1]='O';
                        else
                        {
                            flagOne=2;
                        }
                        break;
                        case '6':
                        if (game[1][2]!='X' && game[1][2]!='O' && player==2)
                        game[1][2]='O';
                        else
                        {
                            flagOne=2;
                        }
                        break;
                        case '7':
                        if (game[2][0]!='X' && game[2][0]!='O' && player==2)
                        game[2][0]='O';
                        else
                        {
                            flagOne=2;
                        }
                        break;
                        case '8':
                        if (game[2][1]!='X' && game[2][1]!='O' && player==2)
                        game[2][1]='O';
                        else
                        {
                            flagOne=2;
                        }
                        break;
                        case '9':
                        if (game[2][2]!='X' && game[2][2]!='O' && player==2)
                        game[2][2]='O';
                        else
                        {
                            flagOne=2;
                        }
                        break;
                        default:
                        flagOne=2;
                    }
                }
            }
            else
            {
                switch (index)
                {
                    case '1':
                    game[0][0]='O';
                    break;
                    case '2':
                    game[0][1]='O';
                    break;
                    case '3':
                    game[0][2]='O';
                    break;
                    case '4':
                    game[1][0]='O';
                    break;
                    case '5':
                    game[1][1]='O';
                    break;
                    case '6':
                    game[1][2]='O';
                    break;
                    case '7':
                    game[2][0]='O';
                    break;
                    case '8':
                    game[2][1]='O';
                    break;
                    case '9':
                    game[2][2]='O';
                    break;
                }
            }
            system("CLS");
            cout<<"              ##################################################\n";
            cout<<"              ##################################################\n";
            cout<<"              ###                                            ###\n";
            cout<<"              ###                  YOUR TURN                 ###\n";
            cout<<"              ###                                            ###\n";
            showGame(game, a, b, c, d, e, f, g, h, i);
        }
        if (index=='1' || index=='2' || index=='3' || index=='4' || index=='5' || index=='6' || index=='7' || index=='8' || index=='9' || index==13)
        {
            count++;
        }
        if (flagOne==1)
        {
            count--;
        }
        flag=win(game);
        if (flag==1)
        {
            wins++;
            system("CLS");
            cout<<"              ##################################################\n";
            cout<<"              ##################################################\n";
            cout<<"              ###                                            ###\n";
            cout<<"              ###          PRESS ANY KEY TO CONTINUE         ###\n";
            cout<<"              ###                                            ###\n";
            showGame(game, a, b, c, d, e, f, g, h, i);
            getch();
            youWon();
            goToAfterWinLoseOrDraw(aa);
            break;
        }
        else if (flag==2)
        {
            loses++;
            system("CLS");
            cout<<"              ##################################################\n";
            cout<<"              ##################################################\n";
            cout<<"              ###                                            ###\n";
            cout<<"              ###          PRESS ANY KEY TO CONTINUE         ###\n";
            cout<<"              ###                                            ###\n";
            showGame(game, a, b, c, d, e, f, g, h, i);
            getch();
            youLose();
            goToAfterWinLoseOrDraw(aa);
            break;
        }
    }
    if (flag==0)
    {
        draws++;
        system("CLS");
        cout<<"              ##################################################\n";
        cout<<"              ##################################################\n";
        cout<<"              ###                                            ###\n";
        cout<<"              ###          PRESS ANY KEY TO CONTINUE         ###\n";
        cout<<"              ###                                            ###\n";
        showGame(game, a, b, c, d, e, f, g, h, i);
        getch();
        draw();
        goToAfterWinLoseOrDraw(aa);
    }
}

//       Apna Check

char apnaCheck(char game[3][3])
{
    char index='0';
    if ((game[0][0]=='O' && game[0][1]=='O' && game[0][2]=='\0') || (game[1][2]=='O' && game[2][2]=='O' && game[0][2]=='\0') || (game[1][1]=='O' && game[2][0]=='O' && game[0][2]=='\0'))
    index='3';
    else if ((game[0][1]=='O' && game[0][2]=='O' && game[0][0]=='\0') || (game[1][0]=='O' && game[2][0]=='O' && game[0][0]=='\0') || (game[1][1]=='O' && game[2][2]=='O' && game[0][0]=='\0'))
    index='1';
    else if ((game[0][0]=='O' && game[0][2]=='O' && game[0][1]=='\0') || (game[1][1]=='O' && game[2][1]=='O' && game[0][1]=='\0'))
    index='2';
    else if ((game[1][0]=='O' && game[1][1]=='O' && game[1][2]=='\0') || (game[0][2]=='O' && game[2][2]=='O' && game[1][2]=='\0'))
    index='6';
    else if ((game[1][1]=='O' && game[1][2]=='O' && game[1][0]=='\0') || (game[0][0]=='O' && game[2][0]=='O' && game[1][0]=='\0'))
    index='4';
    else if ((game[1][0]=='O' && game[1][2]=='O' && game[1][1]=='\0') || (game[0][1]=='O' && game[2][1]=='O' && game[1][1]=='\0') || (game[0][0]=='O' && game[2][2]=='O' && game[1][1]=='\0') || (game[0][2]=='O' && game[2][0]=='O' && game[1][1]=='\0'))
    index='5';
    else if ((game[2][0]=='O' && game[2][1]=='O' && game[2][2]=='\0') || (game[0][2]=='O' && game[1][2]=='O' && game[2][2]=='\0') || (game[0][0]=='O' && game[1][1]=='O' && game[2][2]=='\0'))
    index='9';
    else if ((game[2][1]=='O' && game[2][2]=='O' && game[2][0]=='\0') || (game[0][2]=='O' && game[1][1]=='O' && game[2][0]=='\0') || (game[0][0]=='O' && game[1][0]=='O' && game[2][0]=='\0'))
    index='7';
    else if ((game[2][0]=='O' && game[2][2]=='O' && game[2][1]=='\0') || (game[0][1]=='O' && game[1][1]=='O' && game[2][1]=='\0'))
    index='8';
    return index;
}

//      Dusray Ka Check

char dusryKaCheck(char game[3][3])
{
    char index='0';
    if ((game[0][0]=='X' && game[0][1]=='X' && game[0][2]=='\0') || (game[1][1]=='X' && game[2][0]=='X' && game[0][2]=='\0') || (game[1][2]=='X' && game[2][2]=='X' && game[0][2]=='\0'))
    index='3';
    else if ((game[0][1]=='X' && game[0][2]=='X' && game[0][0]=='\0') || (game[1][0]=='X' && game[2][0]=='X' && game[0][0]=='\0') || (game[1][1]=='X' && game[2][2]=='X' && game[0][0]=='\0'))
    index='1';
    else if ((game[0][0]=='X' && game[0][2]=='X' && game[0][1]=='\0') || (game[1][1]=='X' && game[2][1]=='X' && game[0][1]=='\0'))
    index='2';
    else if ((game[1][0]=='X' && game[1][1]=='X' && game[1][2]=='\0') || (game[0][2]=='X' && game[2][2]=='X' && game[1][2]=='\0'))
    index='6';
    else if ((game[1][1]=='X' && game[1][2]=='X' && game[1][0]=='\0') || (game[0][0]=='X' && game[2][0]=='X' && game[1][0]=='\0'))
    index='4';
    else if ((game[1][0]=='X' && game[1][2]=='X' && game[1][1]=='\0') || (game[0][1]=='X' && game[2][1]=='X' && game[1][1]=='\0') || (game[0][0]=='X' && game[2][2]=='X' && game[1][1]=='\0') || (game[0][2]=='X' && game[2][0]=='X' && game[1][1]=='\0'))
    index='5';
    else if ((game[2][0]=='X' && game[2][1]=='X' && game[2][2]=='\0') || (game[0][2]=='X' && game[1][2]=='X' && game[2][2]=='\0') || (game[0][0]=='X' && game[1][1]=='X' && game[2][2]=='\0'))
    index='9';
    else if ((game[2][1]=='X' && game[2][2]=='X' && game[2][0]=='\0') || (game[0][0]=='X' && game[1][0]=='X' && game[2][0]=='\0') || (game[0][2]=='X' && game[1][1]=='X' && game[2][0]=='\0'))
    index='7';
    else if ((game[2][0]=='X' && game[2][2]=='X' && game[2][1]=='\0') || (game[0][1]=='X' && game[1][1]=='X' && game[2][1]=='\0'))
    index='8';
    return index;
}

//      Single Player Status

void singlePlayerStatus()
{
    int a=wins, b=loses, c=draws, ii=0, iii=0, iiii=0, iiiii=0, total=wins+loses+draws;
    if (a==0)
    ii=1;
    if (b==0)
    iii=1;
    if (c==0)
    iiii=1;
    if (total==0)
    iiiii=1;
    while (a>0)
    {
        ii++;
        a/=10;
    }
    while (b>0)
    {
        iii++;
        b/=10;
    }
    while (c>0)
    {
        iiii++;
        c/=10;
    }
    while (total>0)
    {
        iiiii++;
        total/=10;
    }
    system("CLS");
    cout<<"\n\n\n";
    cout<<"                   #########################################\n";
    cout<<"                   #########################################\n";
    cout<<"                   ##                                     ##\n";
    cout<<"                   ##                STATUS               ##\n";
    cout<<"                   ##                                     ##\n";
    cout<<"                   #########################################\n";
    cout<<"                   #########################################\n";
    cout<<"                   #                                       #\n";
    cout<<"                   #           Your Current Status:        #\n";
    cout<<"                   #                                       #\n";
    cout<<"                   #             Total Played: "<<wins+loses+draws;
    for (int i=0; i<(12-iiiii); i++)
    cout<<" ";
    cout<<"#\n";
    cout<<"                   #                                       #\n";
    cout<<"                   #             Wins: "<<wins;
    for (int i=0; i<(20-ii); i++)
    cout<<" ";
    cout<<"#\n";
    cout<<"                   #                                       #\n";
    cout<<"                   #             Loses: "<<loses;
    for (int i=0; i<(19-iii); i++)
    cout<<" ";
    cout<<"#\n";
    cout<<"                   #                                       #\n";
    cout<<"                   #             Draws: "<<draws;
    for (int i=0; i<(19-iiii); i++)
    cout<<" ";
    cout<<"#\n";
    cout<<"                   #                                       #\n";
    cout<<"                   #########################################\n";
    char choice='a';
    while (choice!=8)
    {
        choice=getch();
        if (choice==8)
        {
            status();
            break;
        }
    }
}

//      Multi Player Game

void multiplayer()
{
        char game[3][3]={NULL}, vs[]=" vs ", won[]=" WON";
        int playerOne_Size=0, playerTwo_Size=0;
        char playerOne[150]={NULL}, playerTwo[150]={NULL};
        int player=1, count=1, flag=0, aa=4;
        bool a=true, b=false, c=false, d=false, e=false, f=false, g=false, h=false, i=false;
        char index='\0';
        bool name_error=true;
        while (name_error==true)
        {
            name_error=false;
            system("CLS");
            cout<<"\n\n\n";
            cout<<"                            #####################\n";
            cout<<"                            ##  Player 1 Name  ##\n";
            cout<<"                            #####################\n";
            cout<<"\n";
            cout<<"                              ";
            cin>>playerOne;
            playerOne_Size=0;
            for (int i=0; playerOne[i]!='\0'; i++)
            {
                playerOne_Size++;
            }
            for (int i=0; i<playerOne_Size; i++)
            {
                if (!(playerOne[i]>=97 && playerOne[i]<=122) && !(playerOne[i]>=65 && playerOne[i]<=90))
                {
                    name_error=true;
                    system("CLS");
                    cout<<"\n\n\n\n\n\n\n\n";
                    cout<<"              ##################################################\n";
                    cout<<"              ##################################################\n";
                    cout<<"              ###                                            ###\n";
                    cout<<"              ###      Only Lower & Upper Case Letters       ###\n";
                    cout<<"              ###                Are Allowed                 ###\n";
                    cout<<"              ###                                            ###\n";
                    cout<<"              ##################################################\n";
                    cout<<"              ##################################################\n";
                    getch();
                }
            }
            if (name_error==false)
            {
                cout<<"\n\n";
                cout<<"                            #####################\n";
                cout<<"                            ##  Player 2 Name  ##\n";
                cout<<"                            #####################\n";
                cout<<"\n";
                cout<<"                              ";
                cin>>playerTwo;
                playerTwo_Size=0;
                for (int i=0; playerTwo[i]!='\0'; i++)
                {
                    playerTwo_Size++;
                }
                for (int i=0; i<playerTwo_Size; i++)
                {
                    if (!(playerTwo[i]>=97 && playerTwo[i]<=122) && !(playerTwo[i]>=65 && playerTwo[i]<=90))
                    {
                        name_error=true;
                        system("CLS");
                        cout<<"\n\n\n\n\n\n\n\n";
                        cout<<"              ##################################################\n";
                        cout<<"              ##################################################\n";
                        cout<<"              ###                                            ###\n";
                        cout<<"              ###      Only Lower & Upper Case Letters       ###\n";
                        cout<<"              ###                Are Allowed                 ###\n";
                        cout<<"              ###                                            ###\n";
                        cout<<"              ##################################################\n";
                        cout<<"              ##################################################\n";
                        getch();
                    }
                }
            }
        }
        for (int i=0; i<playerOne_Size; i++)
        {
            if (playerOne[i]>=97 && playerOne[i]<=122)
            {
                playerOne[i]-=32;
            }
        }
        for (int i=0; i<playerTwo_Size; i++)
        {
            if (playerTwo[i]>=97 && playerTwo[i]<=122)
            {
                playerTwo[i]-=32;
            }
        }
        system("CLS");
        int j=0;
        cout<<"              ##################################################\n";
        cout<<"              ##################################################\n";
        cout<<"              ###                                            ###\n";
        cout<<"              ###";
        if (player==1)
        {
            for (int z=0; z<(22-(playerOne_Size+7)/2); z++)
            {
                cout<<" ";
                j++;
            }
            cout<<playerOne<<"'S TURN";
            for (int z=0; z<(44-j-playerOne_Size-7); z++)
            {
                cout<<" ";
            }
            cout<<"###\n";
            cout<<"              ###                                            ###\n";
        }
        showGame(game, a, b, c, d, e, f, g, h, i);
        while (count<=9)
        {
            flag=0;
            int j=0;
            index='\0';
            int flagOne=0;
            if (count==1 || count==3 || count==5 || count==7 || count==9)
            {
                player=1;
            }
            else if (count==2 || count==4 || count==6 || count==8)
            {
                player=2;
            }
            system("CLS");
            j=0;
            cout<<"              ##################################################\n";
            cout<<"              ##################################################\n";
            cout<<"              ###                                            ###\n";
            cout<<"              ###";
            if (player==1)
            {
                for (int z=0; z<(22-(playerOne_Size+7)/2); z++)
                {
                    cout<<" ";
                    j++;
                }
                cout<<playerOne<<"'S TURN";
                for (int z=0; z<(44-j-playerOne_Size-7); z++)
                {
                    cout<<" ";
                }
                cout<<"###\n";
                cout<<"              ###                                            ###\n";
            }
            else if (player==2)
            {
                for (int z=0; z<(22-(playerTwo_Size+7)/2); z++)
                {
                    cout<<" ";
                    j++;
                }
                cout<<playerTwo<<"'S TURN";
                for (int z=0; z<(44-j-playerTwo_Size-7); z++)
                {
                    cout<<" ";
                }
                cout<<"###\n";
                cout<<"              ###                                            ###\n";
            }

            showGame(game, a, b, c, d, e, f, g, h, i);

            while (index!=13)
            {
                index=getch();

                while (index!=13 && index!=8 && index!=27 && index!=77 && index!=75 && index!=72 && index!=80)
                {
                    index=getch();
                }

                //     BackSpace Key

                if (index==8 && count==1)
                {
                    playgame();
                    break;
                }

                //     Escape Key

                else if (index==27)
                {
                    pressEscape(aa);
                }

                //     Right Key

                else if (index==77)
                {
                    if (a==true)
                    {
                        a=false;
                        b=true;
                    }
                    else if (b==true)
                    {
                        b=false;
                        c=true;
                    }
                    else if (c==true)
                    {
                        c=false;
                        d=true;
                    }
                    else if (d==true)
                    {
                        d=false;
                        e=true;
                    }
                    else if (e==true)
                    {
                        e=false;
                        f=true;
                    }
                    else if (f==true)
                    {
                        f=false;
                        g=true;
                    }
                    else if (g==true)
                    {
                        g=false;
                        h=true;
                    }
                    else if (h==true)
                    {
                        h=false;
                        i=true;
                    }
                    else if (i==true)
                    {
                        i=false;
                        a=true;
                    }
                }

                //       Left Key

                else if (index==75)
                {
                    if (a==true)
                    {
                        a=false;
                        i=true;
                    }
                    else if (b==true)
                    {
                        b=false;
                        a=true;
                    }
                    else if (c==true)
                    {
                        c=false;
                        b=true;
                    }
                    else if (d==true)
                    {
                        d=false;
                        c=true;
                    }
                    else if (e==true)
                    {
                        e=false;
                        d=true;
                    }
                    else if (f==true)
                    {
                        f=false;
                        e=true;
                    }
                    else if (g==true)
                    {
                        g=false;
                        f=true;
                    }
                    else if (h==true)
                    {
                        h=false;
                        g=true;
                    }
                    else if (i==true)
                    {
                        i=false;
                        h=true;
                    }
                }

                //       Down Key

                else if (index==80)
                {
                    if (a==true)
                    {
                        a=false;
                        d=true;
                    }
                    else if (b==true)
                    {
                        b=false;
                        e=true;
                    }
                    else if (c==true)
                    {
                        c=false;
                        f=true;
                    }
                    else if (d==true)
                    {
                        d=false;
                        g=true;
                    }
                    else if (e==true)
                    {
                        e=false;
                        h=true;
                    }
                    else if (f==true)
                    {
                        f=false;
                        i=true;
                    }
                    else if (g==true)
                    {
                        g=false;
                        a=true;
                    }
                    else if (h==true)
                    {
                        h=false;
                        b=true;
                    }
                    else if (i==true)
                    {
                        i=false;
                        c=true;
                    }
                }

                //      Up Key

                else if (index==72)
                {
                    if (a==true)
                    {
                        a=false;
                        g=true;
                    }
                    else if (b==true)
                    {
                        b=false;
                        h=true;
                    }
                    else if (c==true)
                    {
                        c=false;
                        i=true;
                    }
                    else if (d==true)
                    {
                        d=false;
                        a=true;
                    }
                    else if (e==true)
                    {
                        e=false;
                        b=true;
                    }
                    else if (f==true)
                    {
                        f=false;
                        c=true;
                    }
                    else if (g==true)
                    {
                        g=false;
                        d=true;
                    }
                    else if (h==true)
                    {
                        h=false;
                        e=true;
                    }
                    else if (i==true)
                    {
                        i=false;
                        f=true;
                    }
                }

                //       Enter Key

                else if (index==13)
                {
                    if (a==true && game[0][0]=='\0')
                    {
                        if (player==1)
                        {
                            game[0][0]='X';
                        }
                        else if (player==2)
                        {
                            game[0][0]='O';
                        }
                    }
                    else if (a==true && game[0][0]!='\0')
                    {
                        indexUsed();
                        flagOne=1;
                    }
                    else if (b==true && game[0][1]=='\0')
                    {
                        if (player==1)
                        {
                            game[0][1]='X';
                        }
                        else if (player==2)
                        {
                            game[0][1]='O';
                        }
                    }
                    else if (b==true && game[0][1]!='\0')
                    {
                        indexUsed();
                        flagOne=1;
                    }
                    else if (c==true && game[0][2]=='\0')
                    {
                        if (player==1)
                        {
                            game[0][2]='X';
                        }
                        else if (player==2)
                        {
                            game[0][2]='O';
                        }
                    }
                    else if (c==true && game[0][2]!='\0')
                    {
                        indexUsed();
                        flagOne=1;
                    }
                    else if (d==true && game[1][0]=='\0')
                    {
                        if (player==1)
                        {
                            game[1][0]='X';
                        }
                        else if (player==2)
                        {
                            game[1][0]='O';
                        }
                    }
                    else if (d==true && game[1][0]!='\0')
                    {
                        indexUsed();
                        flagOne=1;
                    }
                    else if (e==true && game[1][1]=='\0')
                    {
                        if (player==1)
                        {
                            game[1][1]='X';
                        }
                        else if (player==2)
                        {
                            game[1][1]='O';
                        }
                    }
                    else if (e==true && game[1][1]!='\0')
                    {
                        indexUsed();
                        flagOne=1;
                    }
                    else if (f==true && game[1][2]=='\0')
                    {
                        if (player==1)
                        {
                            game[1][2]='X';
                        }
                        else if (player==2)
                        {
                            game[1][2]='O';
                        }
                    }
                    else if (f==true && game[1][2]!='\0')
                    {
                        indexUsed();
                        flagOne=1;
                    }
                    else if (g==true && game[2][0]=='\0')
                    {
                        if (player==1)
                        {
                            game[2][0]='X';
                        }
                        else if (player==2)
                        {
                            game[2][0]='O';
                        }
                    }
                    else if (g==true && game[2][0]!='\0')
                    {
                        indexUsed();
                        flagOne=1;
                    }
                    else if (h==true && game[2][1]=='\0')
                    {
                        if (player==1)
                        {
                            game[2][1]='X';
                        }
                        else if (player==2)
                        {
                            game[2][1]='O';
                        }
                    }
                    else if (h==true && game[2][1]!='\0')
                    {
                        indexUsed();
                        flagOne=1;
                    }
                    else if (i==true && game[2][2]=='\0')
                    {
                        if (player==1)
                        {
                            game[2][2]='X';
                        }
                        else if (player==2)
                        {
                            game[2][2]='O';
                        }
                    }
                    else if (i==true && game[2][2]!='\0')
                    {
                        indexUsed();
                        flagOne=1;
                    }
                }
                system("CLS");
                int j=0;
                cout<<"              ##################################################\n";
                cout<<"              ##################################################\n";
                cout<<"              ###                                            ###\n";
                cout<<"              ###";
                if (player==1)
                {
                    for (int z=0; z<(22-(playerOne_Size+7)/2); z++)
                    {
                        cout<<" ";
                        j++;
                    }
                    cout<<playerOne<<"'S TURN";
                    for (int z=0; z<(44-j-playerOne_Size-7); z++)
                    {
                        cout<<" ";
                    }
                    cout<<"###\n";
                    cout<<"              ###                                            ###\n";
                }
                else if (player==2)
                {
                    for (int z=0; z<(22-(playerTwo_Size+7)/2); z++)
                    {
                        cout<<" ";
                        j++;
                    }
                    cout<<playerTwo<<"'S TURN";
                    for (int z=0; z<(44-j-playerTwo_Size-7); z++)
                    {
                        cout<<" ";
                    }
                    cout<<"###\n";
                    cout<<"              ###                                            ###\n";
                }
                showGame(game, a, b, c, d, e, f, g, h, i);
            }
            if (index=='1' || index=='2' || index=='3' || index=='4' || index=='5' || index=='6' || index=='7' || index=='8' || index=='9' || index==13)
            count++;
            if (flagOne==1)
            count--;
            flag=win(game);
            if (flag==1)
            {
                total++;
                system("CLS");
                cout<<"              ##################################################\n";
                cout<<"              ##################################################\n";
                cout<<"              ###                                            ###\n";
                cout<<"              ###          PRESS ANY KEY TO CONTINUE         ###\n";
                cout<<"              ###                                            ###\n";
                showGame(game, a, b, c, d, e, f, g, h, i);
                if (dblPlyr<9999)
                {
                    strcat(doublePlayer[dblPlyr], playerOne);
                    strcat(doublePlayer[dblPlyr], vs);
                    strcat(doublePlayer[dblPlyr], playerTwo);
                    dblPlayr[dblPlyr]=playerOne_Size;
                    dblPlyr++;
                    strcat(doublePlayer[dblPlyr], playerOne);
                    strcat(doublePlayer[dblPlyr], won);
                    dblPlayr[dblPlyr]=playerTwo_Size;
                    dblPlyr++;
                }
                getch();
                system("CLS");
                cout<<"\n\n\n\n\n\n\n";
                cout<<"                   #########################################\n";
                cout<<"                   #########################################\n";
                cout<<"                   ##                                     ##\n";
                cout<<"                   ##";
                j=0;
                for (int z=0; z<(19-(playerOne_Size+5)/2); z++)
                {
                    cout<<" ";
                    j++;
                }
                cout<<playerOne;
                cout<<" WON!";
                for (int x=0; x<(37-playerOne_Size-5-j); x++)
                {
                    cout<<" ";
                }
                cout<<"##\n";
                cout<<"                   ##                                     ##\n";
                cout<<"                   #########################################\n";
                cout<<"                   #########################################\n";
                getch();
                goToAfterWinLoseOrDraw(aa);
                break;
            }
                else if (flag==2)
                {
                    total++;
                    system("CLS");
                    cout<<"              ##################################################\n";
                    cout<<"              ##################################################\n";
                    cout<<"              ###                                            ###\n";
                    cout<<"              ###          PRESS ANY KEY TO CONTINUE         ###\n";
                    cout<<"              ###                                            ###\n";
                    showGame(game, a, b, c, d, e, f, g, h, i);
                    if (dblPlyr<9999)
                    {
                        strcat(doublePlayer[dblPlyr], playerOne);
                        strcat(doublePlayer[dblPlyr], vs);
                        strcat(doublePlayer[dblPlyr], playerTwo);
                        dblPlayr[dblPlyr]=playerTwo_Size;
                        dblPlyr++;
                        strcat(doublePlayer[dblPlyr], playerTwo);
                        strcat(doublePlayer[dblPlyr], won);
                        dblPlayr[dblPlyr]=playerOne_Size;
                        dblPlyr++;
                    }
                    getch();
                    system("CLS");
                    cout<<"\n\n\n\n\n\n\n";
                    cout<<"                   #########################################\n";
                    cout<<"                   #########################################\n";
                    cout<<"                   ##                                     ##\n";
                    cout<<"                   ##";
                    j=0;
                    for (int i=0; i<(19-(playerTwo_Size+5)/2); i++)
                    {
                        cout<<" ";
                        j++;
                    }
                    cout<<playerTwo;
                    cout<<" WON!";
                    for (int i=0; i<(37-playerTwo_Size-5-j); i++)
                    {
                        cout<<" ";
                    }
                    cout<<"##\n";
                    cout<<"                   ##                                     ##\n";
                    cout<<"                   #########################################\n";
                    cout<<"                   #########################################\n";
                    getch();
                    goToAfterWinLoseOrDraw(aa);
                    break;
                }
        }
        if (flag==0)
        {
            total++;
            system("CLS");
            cout<<"              ##################################################\n";
            cout<<"              ##################################################\n";
            cout<<"              ###                                            ###\n";
            cout<<"              ###          PRESS ANY KEY TO CONTINUE         ###\n";
            cout<<"              ###                                            ###\n";
            showGame(game, a, b, c, d, e, f, g, h, i);
            if (dblPlyr<9999)
            {
                strcat(doublePlayer[dblPlyr], playerOne);
                strcat(doublePlayer[dblPlyr], vs);
                strcat(doublePlayer[dblPlyr], playerTwo);
                dblPlayr[dblPlyr]=playerOne_Size;
                dblPlyr++;
                doublePlayer[dblPlyr][0]='1';
                dblPlayr[dblPlyr]=playerTwo_Size;
                dblPlyr++;
            }
            getch();
            draw();
            goToAfterWinLoseOrDraw(aa);
        }
}

//        Double Player Status

void doublePlayerStatus()
{
    int dup_dblPlyr=dblPlyr;
    char choice='f';
    while (choice!=8)
    {
        system("CLS");
        cout<<"\n\n\n\n";
        cout<<"                   #########################################\n";
        cout<<"                   #########################################\n";
        cout<<"                   ##                                     ##\n";
        cout<<"                   ##                STATUS               ##\n";
        cout<<"                   ##                                     ##\n";
        cout<<"                   #########################################\n";
        cout<<"                   #                                       #\n";
        cout<<"                   #         Total Games Played: ";
        cout<<total;
        int total_size=0;
        if (total==0)
        {
            total_size=1;
        }
        else
        {
            int atotal=total;
            while (atotal>0)
            {
                atotal/=10;
                total_size++;
            }
        }
        for (int i=0; i<10-total_size; i++)
        cout<<" ";
        cout<<"#\n";
        for (int i=0; i<3; i++)
        cout<<"                   #                                       #\n";
        cout<<"                   #      Press Enter to View Details      #\n";
        for (int i=0; i<3; i++)
        cout<<"                   #                                       #\n";
        cout<<"                   #########################################\n";
        choice=getch();
        while (choice!=8 && choice!=13)
        choice=getch();
        if (choice==8)
        {
            status();
            break;
        }
        else if (choice==13)
        {
            detailsStatus();
            break;
        }
    }
}

void detailsStatus()
{
    int a=0, count=0;
    char choice='f';
    while (choice!=8)
    {
        while (count<3)
        {
            if (count==0)
            {
                system("CLS");
                cout<<"\n\n";
                cout<<"                   #########################################\n";
                cout<<"                   #########################################\n";
                cout<<"                   ##                                     ##\n";
                cout<<"                   ##                STATUS               ##\n";
                cout<<"                   ##                                     ##\n";
            }
            cout<<"                   #########################################\n";
            cout<<"                   #                                       #\n";
            if (doublePlayer[a][0]=='\0')
            {
                cout<<"                   #                                       #\n";
                cout<<"                   #                                       #\n";
                cout<<"                   #                                       #\n";
                a++;
            }
            else
            {
                cout<<"                   #";
                int size;
                size=(39-(dblPlayr[a]+dblPlayr[a+1]+4))/2;
                for (int i=0; i<size; i++)
                cout<<" ";
                cout<<doublePlayer[a];
                size=39-size-(dblPlayr[a]+dblPlayr[a+1]+4);
                for (int i=0; i<size; i++)
                cout<<" ";
                cout<<"#\n";
                a++;
                if (doublePlayer[a][0]=='1')
                {
                    cout<<"                   #             It Was a Draw             #\n";
                }
                else
                {
                    cout<<"                   #";
                    size=(39-(dblPlayr[a]+4))/2;
                    int j=0;
                    for (int i=0; i<size; i++)
                    cout<<" ";
                    cout<<doublePlayer[a];
                    size=39-size-(dblPlayr[a-1]+4);
                    for (int i=0; i<size; i++)
                    cout<<" ";
                    cout<<"#\n";
                }
                cout<<"                   #                                       #\n";
            }
            a++;
            count++;
            if (count==3)
            {
                cout<<"                   #########################################\n";
            }
        }
        choice=getch();
        if (choice==8)
        {
            doublePlayerStatus();
            break;
        }
        else if (choice==80 || choice==77)
        {
            if (!(a<dblPlyr))
            {
                a-=6;
                count=0;
            }
            else
            count=0;
        }
        else if ((choice==75 || choice==72) && a>6)
        {
            a-=12;
            count=0;
        }
    }
}

//      Game Grid

void showGame(char game[3][3], bool a, bool b, bool c, bool d, bool e, bool f, bool g, bool h, bool i)
{
    cout<<"              ##################################################\n              ###                                            ###\n              ###                                            ###\n              ###                                            ###\n";
    if (a==true)
    {
        cout<<"              ###         -----  #          #                ###\n";
        cout<<"              ###        |  "<<game[0][0]<<"  | #     "<<game[0][1]<<"    #    "<<game[0][2]<<"           ###\n";
        cout<<"              ###         -----  #          #                ###\n";
    }
    else if (b==true)
    {
        cout<<"              ###                #  ------  #                ###\n";
        cout<<"              ###           "<<game[0][0]<<"    # |   "<<game[0][1]<<"  | #    "<<game[0][2]<<"           ###\n";
        cout<<"              ###                #  ------  #                ###\n";
    }
    else if (c==true)
    {
        cout<<"              ###                #          #  -----         ###\n";
        cout<<"              ###           "<<game[0][0]<<"    #     "<<game[0][1]<<"    # |  "<<game[0][2]<<"  |        ###\n";
        cout<<"              ###                #          #  -----         ###\n";
    }
    else
    {
        cout<<"              ###                #          #                ###\n";
        cout<<"              ###           "<<game[0][0]<<"    #     "<<game[0][1]<<"    #    "<<game[0][2]<<"           ###\n";
        cout<<"              ###                #          #                ###\n";
    }
    cout<<"              ###       ##############################       ###\n";
    if (d==true)
    {
        cout<<"              ###         -----  #          #                ###\n";
        cout<<"              ###        |  "<<game[1][0]<<"  | #     "<<game[1][1]<<"    #    "<<game[1][2]<<"           ###\n";
        cout<<"              ###         -----  #          #                ###\n";
    }
    else if (e==true)
    {
        cout<<"              ###                #  ------  #                ###\n";
        cout<<"              ###           "<<game[1][0]<<"    # |   "<<game[1][1]<<"  | #    "<<game[1][2]<<"           ###\n";
        cout<<"              ###                #  ------  #                ###\n";
    }
    else if (f==true)
    {
        cout<<"              ###                #          #  -----         ###\n";
        cout<<"              ###           "<<game[1][0]<<"    #     "<<game[1][1]<<"    # |  "<<game[1][2]<<"  |        ###\n";
        cout<<"              ###                #          #  -----         ###\n";
    }
    else
    {
        cout<<"              ###                #          #                ###\n";
        cout<<"              ###           "<<game[1][0]<<"    #     "<<game[1][1]<<"    #    "<<game[1][2]<<"           ###\n";
        cout<<"              ###                #          #                ###\n";
    }
    cout<<"              ###       ##############################       ###\n";
    if (g==true)
    {
        cout<<"              ###         -----  #          #                ###\n";
        cout<<"              ###        |  "<<game[2][0]<<"  | #     "<<game[2][1]<<"    #    "<<game[2][2]<<"           ###\n";
        cout<<"              ###         -----  #          #                ###\n";
    }
    else if (h==true)
    {
        cout<<"              ###                #  ------  #                ###\n";
        cout<<"              ###           "<<game[2][0]<<"    # |   "<<game[2][1]<<"  | #    "<<game[2][2]<<"           ###\n";
        cout<<"              ###                #  ------  #                ###\n";
    }
    else if (i==true)
    {
        cout<<"              ###                #          #  -----         ###\n";
        cout<<"              ###           "<<game[2][0]<<"    #     "<<game[2][1]<<"    # |  "<<game[2][2]<<"  |        ###\n";
        cout<<"              ###                #          #  -----         ###\n";
    }
    else
    {
        cout<<"              ###                #          #                ###\n";
        cout<<"              ###           "<<game[2][0]<<"    #     "<<game[2][1]<<"    #    "<<game[2][2]<<"           ###\n";
        cout<<"              ###                #          #                ###\n";
    }
    cout<<"              ###                                            ###\n";
    cout<<"              ###                                            ###\n";
    cout<<"              ##################################################\n";
    cout<<"              ##################################################\n";
}

//       Win Check

int win(char game[3][3])
{
    int flag=0;
    if ((game[0][2]=='X' && game[1][1]=='X' && game[2][0]=='X') || (game[0][0]=='X' && game[1][1]=='X' && game[2][2]=='X') || (game[0][2]=='X' && game[1][2]=='X' && game[2][2]=='X') || (game[0][1]=='X' && game[1][1]=='X' && game[2][1]=='X') || (game[0][0]=='X' && game[1][0]=='X' && game[2][0]=='X') || (game[0][0]=='X' && game[0][1]=='X' && game[0][2]=='X') || (game[1][0]=='X' && game[1][1]=='X' && game[1][2]=='X') || (game[2][0]=='X' && game[2][1]=='X' && game[2][2]=='X'))
    flag=1;
    else if ((game[0][2]=='O' && game[1][1]=='O' && game[2][0]=='O') || (game[0][0]=='O' && game[1][1]=='O' && game[2][2]=='O') || (game[0][2]=='O' && game[1][2]=='O' && game[2][2]=='O') || (game[0][1]=='O' && game[1][1]=='O' && game[2][1]=='O') || (game[0][0]=='O' && game[1][0]=='O' && game[2][0]=='O') || (game[2][0]=='O' && game[2][1]=='O' && game[2][2]=='O') || (game[1][0]=='O' && game[1][1]=='O' && game[1][2]=='O') || (game[0][0]=='O' && game[0][1]=='O' && game[0][2]=='O'))
    flag=2;
    return flag;
}


//           Go To After Game End

void goToAfterWinLoseOrDraw(int aa)
{
    char choice='w';
    bool a=true, b=false;
    while (choice!=13)
    {
        system("CLS");
        cout<<"\n\n\n";
        cout<<"                   #########################################\n";
        cout<<"                   #########################################\n";
        cout<<"                   ##                                     ##\n";
        cout<<"                   ##                GO TO                ##\n";
        cout<<"                   ##                                     ##\n";
        cout<<"                   #########################################\n";
        cout<<"                   #########################################\n";
        forGoTo(a, b);
        choice=getch();

        //       Up, Down, Left & Right Key

        if (choice==72 || choice==75 || choice==77 || choice==80)
        {
            if (a==true)
            {
                a=false;
                b=true;
            }
            else if (b==true)
            {
                b=false;
                a=true;
            }
        }

        //       Enter Key

        else if (choice==13)
        {
            if (a==true)
            {
                playagain(aa);
                break;
            }
            else if (b==true)
            {
                menu();
                break;
            }
        }

        //       Escape Key

        else if (choice==27)
        {
            exit();
            break;
        }
    }
}
void forGoTo(bool a, bool b)
{
    if (a==true)
    {
        cout<<"                   #              ------------             #\n";
        cout<<"                   #             | Play Again |            #\n";
        cout<<"                   #              ------------             #\n";
    }
    else
    {
        cout<<"                   #                                       #\n";
        cout<<"                   #               Play Again              #\n";
        cout<<"                   #                                       #\n";
    }
    cout<<"                   #########################################\n";
    if (b==true)
    {
        cout<<"                   #                 ------                #\n";
        cout<<"                   #                | Menu |               #\n";
        cout<<"                   #                 ------                #\n";
    }
    else
    {
        cout<<"                   #                                       #\n";
        cout<<"                   #                  Menu                 #\n";
        cout<<"                   #                                       #\n";
    }
    cout<<"                   #########################################\n";
}

//      Press Escape During Game

void pressEscape(int aa)
{
    char choice='h';
    bool a=true, b=false, c=false;
    while (choice!=13)
    {
        system("CLS");
        cout<<"\n\n\n";
        cout<<"                   #########################################\n";
        cout<<"                   #########################################\n";
        cout<<"                   ##                                     ##\n";
        cout<<"                   ##                GO TO                ##\n";
        cout<<"                   ##                                     ##\n";
        cout<<"                   #########################################\n";
        cout<<"                   #########################################\n";
        forPressEscape(a, b, c);
        choice=getch();

        //      Up & Left Key

        if (choice==72 || choice==75)
        {
            if (a==true)
            {
                a=false;
                c=true;
            }
            else if (b==true)
            {
                b=false;
                a=true;
            }
            else if (c==true)
            {
                c=false;
                b=true;
            }
        }

        //       Down & Right Key

        else if (choice==77 || choice==80)
        {
            if (a==true)
            {
                a=false;
                b=true;
            }
            else if (b==true)
            {
                b=false;
                c=true;
            }
            else if (c==true)
            {
                c=false;
                a=true;
            }
        }

        //       Enter Key

        else if (choice==13)
        {
            if (a==true)
            {
                break;
            }
            else if (b==true)
            {
                playagain(aa);
                break;
            }
            else if (c==true)
            {
                menu();
                break;
            }
        }

        //      BackSpace Key

        else if (choice==8)
        {
            break;
        }

        //      Escape Key

        else if (choice==27)
        {
            exit();
            break;
        }
    }
}
void forPressEscape(bool a, bool b, bool c)
{
    if (a==true)
    {
        cout<<"                   #             -------------             #\n";
        cout<<"                   #            | Resume Game |            #\n";
        cout<<"                   #             -------------             #\n";
    }
    else
    {
        cout<<"                   #                                       #\n";
        cout<<"                   #              Resume Game              #\n";
        cout<<"                   #                                       #\n";
    }
    cout<<"                   #########################################\n";
    if (b==true)
    {
        cout<<"                   #             --------------            #\n";
        cout<<"                   #            | Restart Game |           #\n";
        cout<<"                   #             --------------            #\n";
    }
    else
    {
        cout<<"                   #                                       #\n";
        cout<<"                   #              Restart Game             #\n";
        cout<<"                   #                                       #\n";
    }
    cout<<"                   #########################################\n";
    if (c==true)
    {
        cout<<"                   #                 ------                #\n";
        cout<<"                   #                | Menu |               #\n";
        cout<<"                   #                 ------                #\n";
    }
    else
    {
        cout<<"                   #                                       #\n";
        cout<<"                   #                  Menu                 #\n";
        cout<<"                   #                                       #\n";
    }
    cout<<"                   #########################################\n";
}

//      Play Again

void playagain(int a)
{
    switch (a)
    {
        case 1:
        hard();
        break;
        case 2:
        medium();
        break;
        case 3:
        easy();
        break;
        case 4:
        multiplayer();
        break;
    }
}


//      Used Index Message

void indexUsed()
{
    system("CLS");
    cout<<"\n\n\n\n\n";
    cout<<"                   #########################################\n";
    cout<<"                   #########################################\n";
    cout<<"                   ##                                     ##\n";
    cout<<"                   ##      This Index is already used     ##\n";
    cout<<"                   ##      Press any key to continue.     ##\n";
    cout<<"                   ##                                     ##\n";
    cout<<"                   #########################################\n";
    cout<<"                   #########################################\n";
    getch();
}

//      You Lose Message

void youLose()
{
    system("CLS");
    cout<<"\n\n\n\n\n\n\n\n";
    cout<<"                   #########################################\n";
    cout<<"                   #########################################\n";
    cout<<"                   ##                                     ##\n";
    cout<<"                   ##              YOU LOSE!              ##\n";
    cout<<"                   ##                                     ##\n";
    cout<<"                   #########################################\n";
    cout<<"                   #########################################\n";
    getch();
}


//      You Won Message

void youWon()
{
    system("CLS");
    cout<<"\n\n\n\n\n\n\n\n";
    cout<<"                   #########################################\n";
    cout<<"                   #########################################\n";
    cout<<"                   ##                                     ##\n";
    cout<<"                   ##               YOU WON!              ##\n";
    cout<<"                   ##                                     ##\n";
    cout<<"                   #########################################\n";
    cout<<"                   #########################################\n";
    getch();
}


//      Draw Message

void draw()
{
    system("CLS");
    cout<<"\n\n\n\n\n\n\n\n";
    cout<<"                   #########################################\n";
    cout<<"                   #########################################\n";
    cout<<"                   ##                                     ##\n";
    cout<<"                   ##                 DRAW!               ##\n";
    cout<<"                   ##                                     ##\n";
    cout<<"                   #########################################\n";
    cout<<"                   #########################################\n";
    getch();
}


//       Thanks For Playing

void exit()
{
    system("CLS");
    cout<<"\n\n\n\n\n\n\n\n";
    cout<<"                   #########################################\n";
    cout<<"                   #########################################\n";
    cout<<"                   ##                                     ##\n";
    cout<<"                   ##          THANKS FOR PLAYING!        ##\n";
    cout<<"                   ##                                     ##\n";
    cout<<"                   #########################################\n";
    cout<<"                   #########################################\n";
    getch();
    exit(0);
}
