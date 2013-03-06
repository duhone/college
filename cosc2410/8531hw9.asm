title	findEuler
comment ~********************************
	Name:Eric Duhon
	SSN: 453-97-8531
	Date:Nov 8,1999
	Purpose:This fuction finds x^x - sin(2.5x) and returns a pointer
		to the result in ax. The function clrscrn is also included
~	 ********************************
	.286
	.387
	.model	  small,c

     .data
       result real8 0.0
       data   real8 2.15

     .code
Euler proc near c, input:real8
;
;    find sin(2.5x)
;
     fld input
     fld data
     fmul
     fsin
;
;    find x^x
;
     fld input
     fld input
     fyl2x
     f2xm1
     fld1
     fadd
;
;    subtract x^x - sin(2.5x)
;
     fsubr
     fstp result
;
;    return a pointer to result
;
     mov ax,offset result
     ret
Euler	endp

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
