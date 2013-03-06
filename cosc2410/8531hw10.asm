title	addbcd
comment ~********************************
	Name:Eric Duhon
	SSN: 453-97-8531
	Date:NOV 15,1999
	Purpose:This c callable function adds the numbers upup upd dnup
		and dndn 9 times each respectibely. the results are printed
		out using printf from c. clrscrn is also incuded.
~	 ********************************
	.model	  small,c
       .586
printf proto near c, arg1:ptr byte,:vararg

     .data
       ;numbers to add
       upup tbyte 123456789123456789h
       updn tbyte 123456789987654321h
       dnup tbyte 987654321123456789h
       dndn tbyte 987654321987654321h

       ;ansers
       ans1 real8 ?
       filler1 word ?	    ;filler included to make all variables
       ans2 real8 ?	     ;10 bytes appart from each other
       filler2 word ?
       ans3 real8 ?
       filler3 word ?
       ans4 real8 ?
       filler4 word ?
       msg byte 0ah,"%.0f",0h


     .code
FPU_BAdd proc near c
     pusha
     mov si,offset upup        ;first variable in list

outer:
     fbld tbyte ptr [si]       ;load in number to be added
     mov cx,9		       ;add nine of them
inner:
     fbld tbyte ptr [si]       ;load in number
     fadd		       ;add them
     loop inner 	       ;add another one

     fstp real8 ptr [si+028h]  ;store answer
     invoke printf, offset msg,real8 ptr [si+028h] ;print answer
     add si,10		       ;go to next one to be added
     cmp si,offset ans1        ;if si points to ans1 then were finished
	jnz outer	       ;in not do another
     popa
     mov ax,Last-FPU_BAdd      ;how many bytes total?
     ret
FPU_BAdd	endp

Last:

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
