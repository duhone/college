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

	.stack	 100h
     ; this is a "main program" so needs a stack
     ;subroutines/functions/"callees" do not need stack
        .dosseg
     ;this line and the ".Startup/.Exit lines
     ;should be removed for subs,funcs, and "callees"
     .data
	temp dw 0
     .code
main proc
        .Startup             ;needed for "main"
	mov ax,0	     ;initialize ax,dx to 2 first fib numbers
	mov dx,1
	call fib
	mov dx,temp	     ;restore largest valid fib number

        .Exit                ;return back to the OS
Main   endp


fib proc
       mov cx,dx	     ;dont destroy dx
       add ax,dx	     ;calculate next fib number
       mov temp,dx	     ;store previos fib number
       mov dx,ax	     ;rearange dx and ax
       mov ax,cx
       jc finished	     ;dont call again if last fib
       call fib
       finished:
       ret


fib	endp

end
