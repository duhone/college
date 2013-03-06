title	color bars
comment ~********************************
	Name:Eric Duhon
	SSN: 453-97-8531
	Date:Oct 18,1999
	Purpose:This program displays a series of color bars
		in text mode.
~	 ********************************

	.model	  small
	.486
	.stack	 100h
	.dosseg
      .data
	attrmask BYTE 0
      .code
main proc
        .Startup             ;needed for "main"
	mov ax,3	     ;set video mode
	int 10h

	mov ax,600	      ;clear the screen
	mov cx,0
	mov dx,184fh
	mov bh,7
	int 10h

	mov ax,902h		;set up write character with attribute
	mov bx,0		;set up video page video page
	mov dx,512h		;set up row(dh) and col(dl)
	mov cl,00001111b	;set up mask
	mov attrmask,cl 	;save mask
	mov cx,1		;output one character at once
outerloop:


innerloop:
	mov ah,2	      ;resets the cursor position to
	int 10h 	       ;row dh and col dl
	mov ah,9	      ;prepare to writes character in al
	inc dh		      ;inc row now to prevent pipeline stall
	int 10h 	      ;write character in al
	cmp dh,20	      ;have we written 20 rows yet?
	jne innerloop	      ;if not write another

	mov dh,5	      ;start back at row 5
	inc dl		      ;move to next column
	.if(dl < 40)	      ;if doing left side inc foreground
	 inc bl 	       ;color
	.else		      ;otherwise inc background color
	 add bl,10h
	.endif
	.if(dl == 34)	      ;if finished with left side
	 mov cl,01110000b      ;change mask
	 mov dl,44	       ;jump to first col on right side
	 mov attrmask,cl       ;save new mask
	 mov al,1	       ;change character to write
	 mov bl,0	       ;reset color to black
	 mov cx,1	       ;reset cx to write one character
	.endif
	and bl,attrmask        ;mask bl to keep only appropriate bits
	cmp dl,60	       ;done with all cols?
	jne outerloop	       ;if not do another

	.Exit		     ;return back to the OS
Main   endp



end
