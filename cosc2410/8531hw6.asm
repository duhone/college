title	library
comment ~********************************
	Name:Eric Duhon
	SSN: 453-97-8531
	Date:Oct 10,1999
	Purpose:This library contains 3 functions which can be called
		from a c program.these functions are Bin2ASCII,PlzWait,
		and ClsScrn.
~	 ********************************
	.286
	.model	  small,c

     include dos.inc
     include bios.inc

     .data
	xtable byte '0123456789ABCDEF'

     .code
Bin2ASCII proc near c uses bp si di ds ss ans:ptr byte,radix:sword,arg:sword
	.if(ans == 0)	      ;check for null pinter
	  stc
	  mov ax,-1
	  ret
	.endif
	mov bx,radix
	mov di,ans
	.if(bx == -10)	      ;if radix is -10 negate it
	  neg bx
	.elseif(bx != 10 && bx != 16)
	  mov ax,6142h
	  mov [di],ax	      ;if radix is not correct
	  mov ax,5264h	       ;send back BadRdx in ans
	  mov [di+2],ax	;also send  back error
	  mov ax,7864h
	  mov [di+4],ax
	  stc
	  mov ax,-1
	  ret
	.endif
	mov ax,2020h	       ;put blanks in answer
	mov [di],ax
	mov [di+2],ax
	mov [di+4],ax
	.if(bx == 16)	       ;if converting to hex
	  mov ax,3030h		;put 0's in answer
	  mov [di],ax		;and an h in the last
	  mov [di+2],ax 	;position and point di
	  mov ax,6830h		;to the next to last element
	  mov [di+4],ax
	  add di,5
	.else		       ;point di to the last element
	  add di,6
	.endif
	mov cx,0
	mov ax,arg
	.repeat 	       ;convert to ascii until arg is 0
	  mov dx,0
	  idiv bx
	  xchg ax,dx
	  push bx
	  mov bx,offset xtable
	  xlat
	  pop bx
	  dec di
	  mov [di],al
	  mov ax,dx
	  inc cx
	.until (ax == 0)
	.if(radix == -10)      ;add a plus or minus sign
	  dec di		;if converting a signed number
	  .if(arg >=0)
	    mov dl,2bh
	    mov [di],dl
	  .else
	    mov dl,2dh
	    mov [di],dl
	  .endif
	.endif
	mov ax,cx	       ;return number of characters generated
	clc			;and clear the carry flag
	ret
Bin2ASCII	endp

PlzWait proc c mills:sword
	mov ax,mills	      ;put argument in ax
	.if(ax > 2000)	      ;insure ax  is not
	 mov ax,2000	       ;larger than 2000
	.endif
	mov bx,1000	      ;turn milliseconds into
	mul bx		       ;microseconds
	mov cx,dx
	mov dx,ax
	mov ah,86h	      ;wait cx:dx microseconds
	int 15h
	ret
PlzWait endp

ClrScrn proc c col:byte , row:byte

	mov ah,6	      ;clear the screen
	mov al,0	       ;using scrolling up
	mov ch,0
	mov cl,0
	mov dh,24
	mov dl,79
	mov bh,7
	int 10h

	mov ah,2	      ;resets the cursor position to
	mov dh,row	       ; row and column specified
	mov dl,col
	mov bh,0
	int 10h
	ret
ClrScrn endp

end
