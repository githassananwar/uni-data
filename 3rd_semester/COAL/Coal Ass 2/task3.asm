.model small
.stack 100h
.data

msg byte 'Enter two lowercase characters   $' 
msg1 byte 0ah,0dh,'The characters in Upper case are  $' ;0ah,0dh shortcut for newline
var byte 0
var2 byte 0

.code
main proc

mov ax,@data
mov ds,ax

lea dx,msg ;Output msg
mov ah,9
int 21h

mov ah,1 ;input
int 21h

sub al,20h ;subtact 20h to make it capital
mov var,al ;store in var

mov ah,1 ;input
int 21h

sub al,20h ;subtact 20h to make it capital
mov var2,al ;store in var2

lea dx,msg1 ;output msg1 
mov ah,9 
int 21h


mov dl,var ;display var
mov ah,2 
int 21h

mov dl,var2;display var2
mov ah,2
int 21h

mov ah,4ch
int 21h

main endp
end main