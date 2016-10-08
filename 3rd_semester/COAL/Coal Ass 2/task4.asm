.model small
.stack 100h
.data

msg byte 'Enter two numbers  $'
msg1 byte 0ah,0dh,'Sum is  $'
msg2 byte 0ah,0dh,'Difference is  $'
msg3 byte 0ah,0dh,'Multiplication is  $'
var1 byte 0
var2 byte 0

.code
main proc

mov ax,@data
mov ds,ax

lea dx,msg
mov ah,9
int 21h

mov ah,1 ;input 1st number
int 21h
mov bl,al  
mov var1,al ;1st number in var1 and bl


mov ah,1 ;input 2nd number
int 21h
mov var2,al ;2nd number in var2

add bl,var2 ;add both numbers and store in bl  

lea dx,msg1
mov ah,9
int 21h

mov dl,bl ;to display sum
sub dl,30h ;Minus 30h to make a character number
mov ah,2
int 21h

lea dx,msg2
mov ah,9
int 21h

mov bl,var1
sub bl,var2 ;subtract var2 from var1
mov dl,bl
add dl,30h ;adds 30h to make it a character number
mov ah,2
int 21h

lea dx,msg3
mov ah,9
int 21h

mov al,var1
sub al,30h
mov bl,var2
sub bl,30h

mul bl ;mutiply value stored in bl with value in al
add al,30h
mov dl,al
mov ah,2
int 21h

mov ah,4ch
int 21h

main endp
end main
