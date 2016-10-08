.model small
.stack 100h
.data

msg byte 'Enter An Alphabet  $';
msg1 byte 0ah,0dh,'The previous alphabet is $' ;0ah,0dh is shortcut for newline
msg2 byte 0ah,0dh,'The next alphabet is  $'
var byte 0


.code

main proc
mov ax,@data
mov ds,ax

lea dx,msg ;Dislay Enter a message
mov ah,9
int 21h

mov ah,1 ;Input alphabet
int 21h

mov bl,al ;Input stored in bl
mov var,al ;move to var also

lea dx,msg1 ;Display previous prompt message
mov ah,9
int 21h


sub bl,1h ;subtract 1h so it can be askii code of previous character
mov dl,bl ;to output previous alphabet, moving it to dl 
mov ah,2
int 21h



lea dx,msg2 ;Display next prompt message
mov ah,9	
int 21h


add var,1h ;add 1h so it can be askii code of next character
mov dl,var ;to output next alphabet, moving it to dl 
mov ah,2
int 21h



mov ah,4ch
int 21h

main endp
end main
