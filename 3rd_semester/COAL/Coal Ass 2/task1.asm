.model small
.stack 100h
.data
msg byte 'Yesterday I bought a new game of $'
msg1 byte '250 $'

.code
main proc

mov ax,@data
mov ds,ax

lea dx,msg
mov ah,9
int 21h

mov dl,24h ;to display dollar sign whose askii is 24H 
mov ah,2
int 21h

lea dx,msg1
mov ah,9
int 21h

mov ah,4ch
int 21h

main endp
end main

