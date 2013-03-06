title	Add numbers
comment ~********************************
	Name:Eric Duhon
	SSN: 453-97-8531
	Date:Sep 20,1999
	Purpose:This program calculates the largest fibanacci number
		that will fit in an unsigned 16 bit number. The
		result is stored in dx.
~	 ********************************

	.model	  small

  ;	.stack	 100h
     ; this is a "main program" so needs a stack
     ;subroutines/functions/"callees" do not need stack
  ;	 .dosseg
     ;this line and the ".Startup/.Exit lines
     ;should be removed for subs,funcs, and "callees"
     include dos.inc

     .data
	;temp dw 0
     .code
Bin2ASCII proc c
	;.Startup	      ;needed for "main"
	push bx
	mov ax,0
	mov bx,sp
	add bx,-6
	mov [bx],ax
	add bx,
	mov [sp-6]+4,ax


	pop bx
	;.Exit		      ;return back to the OS
Bin2ASCII	endp



end
