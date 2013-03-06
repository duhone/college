title	Add numbers
comment ~********************************
	Name:Eric Duhon
	SSN: 453-97-8531
	Date:Sep 8,1999
	Purpose:This program adds the sum of the series of numbers
		1,4,7,10,...,301 and stores the result in Ax
~	 ********************************

	.model	  small

	.stack	 100h
     ; this is a "main program" so needs a stack
     ;subroutines/functions/"callees" do not need stack
        .dosseg
     ;this line and the ".Startup/.Exit lines
     ;should be removed for subs,funcs, and "callees"

     .code
main proc
        .Startup             ;needed for "main"
	mov ax,1	     ;first number to add is one
	mov dx,1	     ;initialize dx
	mov cx,100	     ;100 numbers to count
begin:
	add dx,3	     ;find next number in series
	add ax,dx	     ;add that number to the sum
	loop begin	     ;loop back for next number in series

        .Exit                ;return back to the OS
Main   endp
       end
