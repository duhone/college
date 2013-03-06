title	Add array
comment ~********************************
	Name:Eric Duhon
	SSN: 453-97-8531
	Date:Sep 20,1999
	Purpose:This program adds the values in a single row or
		collum in an array.
		result is stored in ax.
~	 ********************************

	.model	  small

	.stack	 100h
     ; this is a "main program" so needs a stack
     ;subroutines/functions/"callees" do not need stack
        .dosseg
     ;this line and the ".Startup/.Exit lines
     ;should be removed for subs,funcs, and "callees"
     true	  equ	     -1
     false	  equ	     0
     nrows	  equ	     21
     ncols	  equ	     42
     step	  equ	     13
     dobyrow	  equ	     false
     dobycol	  equ	     1+dobyrow
     col2do	  equ	     37
     row2do	  equ	     17

     .data
     count = step
     array BYTE 0			 ;initial element of array
	   REPEAT nrows*ncols		 ;create other elements
	     BYTE count mod 256
	     count = count + step
	   ENDM
     .code
main proc
        .Startup             ;needed for "main"
IF dobyrow
	  mov bx,offset array + ((row2do-1) * ncols)
	  mov cx,ncols
	  mov ax,0
	  clc
begin:
	  add al,[bx]		       ;add next element
	  inc bx		       ;move to next column

	  jnc nocarry
	  add ah,1		       ;keep carry if it exists
	  clc
nocarry:
	  loop begin
ELSE

	  mov bx,offset array + (col2do-1)
	  mov cx,nrows
	  mov ax,0
	  clc
begin:
	  add al,[bx]		       ;add next element
	  jnc nocarry
	  add ah,1		       ;keep carry
	  clc
nocarry:
	  add bx,ncols		       ;move to next row

	  loop begin


ENDIF

        .Exit                ;return back to the OS
Main   endp



end
