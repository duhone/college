title	semester project
comment ~********************************
	Name:Eric Duhon
	SSN: 453-97-8531
	Date:NOV 30,1999
	Email:duhone@airmail.net
	Purpose:This program simulates heat distibution on a uniform metal
	 plate with constant external temperature and constant pipe
	 temperature
~	 ********************************

    .model small
    .586

     include fall1999.inc

    .data
;variable to keep track if first execution or not
      first byte 0
;variables to keep track of various temperatures
      temphigh real8 0.0
      templow real8 0.0
      toptemp real8 tempTOP
      bottemp real8 tempBOT
      lefttemp real8 tempLEFT
      righttemp real8 tempRIGHT
      outertemp real8 tempOUTERSPACE
;variables to deal with temperature color
      attrtable byte 7,8,5,3,1,9,4,6,2,13,12,14,10,11
      dividefactor real8 13.0
      floatconst2 real8 2.0
      floatconst8 real8 8.0
      tempint word 0
      faverage real8 0.0
;various other variables
      frog word 0
      localtemp word 0
      xaxis word ellipseSEMIMAJOR
      yaxis word ellipseSEMIMINOR
     .code

outpipe proc near
;output 1 in ax if outside pipe, else outputs 0 in ax
;input must be row in dh and column in dl
    mov ax,0
    .if(dh > y_PIPE_LR || dh < y_PIPE_UL || dl > x_PIPE_LR || dl < x_PIPE_UL)
     mov ax,1
    .endif
    ret
outpipe endp

inellipse proc near
;output, 1 in ax if in ellipse else output 0 in ax
;input must be row in dh and column in dl
     push bx
     mov ax,0
;load dl into localtemp so it can be loaded into the fpu
     movzx bx,dl
     sub bx,40
     mov localtemp,bx
;calculate ellipse formula
     fild localtemp
     fild localtemp
     fmul
;load dh into localtemp for free while the fpu is calculating
     movzx bx,dh
     sub bx,12
     mov localtemp,bx
;finish calculating ellipse formula
     fild xaxis
     fild xaxis
     fmul
     fdiv
     fild localtemp
     fild localtemp
     fmul
     fild yaxis
     fild yaxis
     fmul
     fdiv
     fadd
     fld1
     fucompp
     fstsw ax
     fwait
     sahf
     jb endellipse
     mov ax,1
endellipse:
     pop bx
 ret

inellipse endp



initialize proc near c calc:word , look:word
;insanly long procedure to initialize everything, but only executed once
     mov ah,0
     mov al,3
     int 10h
;round down
     fstcw frog
     and frog, 0F3FFh
     or	frog, 00C00h
     fldcw frog
;insane way to find low and high temp, but oh-well its only done once
     fld toptemp
     fld bottemp
     fucomp
     fstsw ax
     sahf
     jc nottop
     fld lefttemp
     fucomp
     fstsw ax
     sahf
     jc nottop
     fld righttemp
     fucomp
     fstsw ax
     sahf
     jc nottop
     fld outertemp
     fucomp
     fstsw ax
     sahf
     jc nottop
     fst temphigh
nottop:
     ffree st

     fld bottemp
     fld toptemp
     fucomp
     fstsw ax
     sahf
     jc notbot
     fld lefttemp
     fucomp
     fstsw ax
     sahf
     jc notbot
     fld righttemp
     fucomp
     fstsw ax
     sahf
     jc notbot
     fld outertemp
     fucomp
     fstsw ax
     sahf
     jc notbot
     fst temphigh
notbot:
     ffree st

     fld lefttemp
     fld bottemp
     fucomp
     fstsw ax
     sahf
     jc notleft
     fld toptemp
     fucomp
     fstsw ax
     sahf
     jc notleft
     fld righttemp
     fucomp
     fstsw ax
     sahf
     jc notleft
     fld outertemp
     fucomp
     fstsw ax
     sahf
     jc notleft
     fst temphigh
notleft:
     ffree st

     fld righttemp
     fld bottemp
     fucomp
     fstsw ax
     sahf
     jc notright
     fld lefttemp
     fucomp
     fstsw ax
     sahf
     jc notright
     fld toptemp
     fucomp
     fstsw ax
     sahf
     jc notright
     fld outertemp
     fucomp
     fstsw ax
     sahf
     jc notright
     fst temphigh
notright:
     ffree st

     fld outertemp
     fld bottemp
     fucomp
     fstsw ax
     sahf
     jc notouter
     fld lefttemp
     fucomp
     fstsw ax
     sahf
     jc notouter
     fld righttemp
     fucomp
     fstsw ax
     sahf
     jc notouter
     fld toptemp
     fucomp
     fstsw ax
     sahf
     jc notouter
     fst temphigh
notouter:
     ffree st

     ;find lower
     fld toptemp
     fld bottemp
     fucomp
     fstsw ax
     sahf
     jnc nottop2
     fld lefttemp
     fucomp
     fstsw ax
     sahf
     jnc nottop2
     fld righttemp
     fucomp
     fstsw ax
     sahf
     jnc nottop2
     fld outertemp
     fucomp
     fstsw ax
     sahf
     jnc nottop2
     fst templow
nottop2:
     ffree st

     fld bottemp
     fld toptemp
     fucomp
     fstsw ax
     sahf
     jnc notbot2
     fld lefttemp
     fucomp
     fstsw ax
     sahf
     jnc notbot2
     fld righttemp
     fucomp
     fstsw ax
     sahf
     jnc notbot2
     fld outertemp
     fucomp
     fstsw ax
     sahf
     jnc notbot2
     fst templow
notbot2:
     ffree st

     fld lefttemp
     fld bottemp
     fucomp
     fstsw ax
     sahf
     jnc notleft2
     fld toptemp
     fucomp
     fstsw ax
     sahf
     jnc notleft2
     fld righttemp
     fucomp
     fstsw ax
     sahf
     jnc notleft2
     fld outertemp
     fucomp
     fstsw ax
     sahf
     jnc notleft2
     fst templow
notleft2:
     ffree st

     fld righttemp
     fld bottemp
     fucomp
     fstsw ax
     sahf
     jnc notright2
     fld lefttemp
     fucomp
     fstsw ax
     sahf
     jnc notright2
     fld toptemp
     fucomp
     fstsw ax
     sahf
     jnc notright2
     fld outertemp
     fucomp
     fstsw ax
     sahf
     jnc notright2
     fst templow
notright2:
     ffree st

     fld outertemp
     fld bottemp
     fucomp
     fstsw ax
     sahf
     jnc notouter2
     fld lefttemp
     fucomp
     fstsw ax
     sahf
     jnc notouter2
     fld righttemp
     fucomp
     fstsw ax
     sahf
     jnc notouter2
     fld toptemp
     fucomp
     fstsw ax
     sahf
     jnc notouter2
     fst templow
notouter2:
     ffree st
;screwed up someware and put temphigh and templow backwards
;this is a quik fix
     fld temphigh
     fld templow
     fstp temphigh
     fstp templow
;calculate the dividefactor
     fld temphigh
     fld templow
     fsub
     fld dividefactor
     fdiv
     fstp dividefactor
;get ready for rep movd instructions
     mov ax,ds
     mov es,ax
;get average tempurature so ellipse converges faster
     fld temphigh
     fld templow
     fadd
     fld floatconst2
     fdiv
     fstp faverage
;initialize whole array to the outside temp
     mov si,calc
     mov cx,80*24
     mov dh,0
     mov dl,0
     fld outertemp
begininitialize1:
     fst real8 ptr[si]
     add si,8
     loop begininitialize1
     ffree st
;now initialize just inside of ellipse to average temperature
     mov dh,0
     mov dl,0
     mov si,calc
     mov cx,80*24
     fld faverage
begininitialize2:
     call inellipse
     .if(ax == 1)
      fst real8 ptr[si]
     .endif
     add si,8
     inc dl
     .if(dl == 80)
      mov dl,0
      inc dh
     .endif
     loop begininitialize2
     ffree st
;finaly initialize the pipe temperatures
     mov dh,0
     mov dl,0
     mov si,calc
     mov cx,80*24
begininitialize3:
     call outpipe
     .if(ax != 1)
      .if(dh == y_PIPE_UL)
       fld toptemp
       fstp real8 ptr[si]
      .endif
      .if(dh == y_PIPE_LR)
       fld bottemp
       fstp real8 ptr[si]
      .endif
      .if(dl == x_PIPE_UL)
       fld lefttemp
       fstp real8 ptr[si]
      .endif
      .if(dl == x_PIPE_LR)
       fld righttemp
       fstp real8 ptr[si]
      .endif
     .endif
     add si,8
     inc dl
     .if(dl == 80)
      mov dl,0
      inc dh
     .endif
     loop begininitialize3
;move all initialized values to the look array as well
     mov ax,ds
     mov es,ax
     mov si,calc
     mov di,look
     cld
     mov cx,80*25*2
     rep movsd

     ret
initialize endp


Ellipse proc near c calc:word , look:word
     pusha
;exit with error if null pointers passed
     .if(calc == 0)
      popa
      mov ax,-1
      stc
      ret
     .endif
     .if(look == 0)
      popa
      mov ax,-1
      stc
      ret
     .endif
;if first loop initialize arrays
     .if(first == 0)
      inc first
      invoke initialize, calc, look
     .endif
;compute new values in array
     mov si,calc
     mov di,look
     mov cx,80*24
     mov dx,0
begincomputing:
;only calculate values in the ellipse and out of the pipe
     call inellipse
     .if(ax == 1)
       call outpipe
       .if(ax == 1)
;add 8 neighbers  to get new value
	fld real8 ptr[di-(81*8)]
        fld real8 ptr[di-(80*8)]
        fld real8 ptr[di-(79*8)]
        fld real8 ptr[di-(1*8)]
        fld real8 ptr[di+(1*8)]
        fld real8 ptr[di+(79*8)]
        fld real8 ptr[di+(80*8)]
        fld real8 ptr[di+(81*8)]
        faddp st(7),st
        faddp st(6),st
        faddp st(5),st
        faddp st(4),st
        faddp st(3),st
        faddp st(2),st
        faddp st(1),st
;divide by 8 to get average
	fld floatconst8
        fdiv
        fstp real8 ptr[si]
       .endif
     .endif
;go to next location
     inc dl
     .if(dl == 80)
      mov dl,0
      inc dh
     .endif
     add si,8
     add di,8
     loop begincomputing
;store new values into the look array
     mov si,calc
     mov di,look
     mov ax,ds
     mov es,ax
     cld
     mov cx,80*24*2
     rep movsd

     popa
     mov ax,0
     clc
     ret
Ellipse endp

Show proc near c look:word
;output array to the screen using direct video memory access
     pusha
;check for null pointers
     .if(look == 0)
      popa
      mov ax,-1
      stc
      ret
     .endif
;put address of video memory ito fs
     mov ax,0b800h
     mov fs,ax
     mov cx,(80*24)
     mov dx,0
     mov si,look
begin:
;only draw if in the ellipse and out of the pipe
     call inellipse
      .if(ax == 1)
      call outpipe
      .if(ax == 1)
;caclulate the color
       fld real8 ptr[si]
       fld templow
       fsub
       fld dividefactor
       fdiv
;store the offset of the color from attr table in di
       mov bx,offset tempint
       fistp word ptr[bx]
       fwait
       mov di,[bx]

       push cx
;set up bx with character and attribute to be written into video memory
       mov bh,attrtable[di]
       mov bl,219
;set up di with offset into video memory to be written to
       movzx ax,dh
       mov cl,160
       mul cl
       movzx cx,dl
       add ax,cx
       add ax,cx
       mov di,ax
;write bx into video memory
       mov fs:[di],bx
       pop cx

      .endif
     .endif
;move on to next location
     add si,8
     inc dl
     .if(dl == 80)
      mov dl,0
      inc dh
     .endif
     loop begin
     popa
     mov ax,0
     clc
     ret
show endp

PlzWait proc near c mills:sword
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

ClrScrn proc near c col:byte , row:byte

    mov ax,0600h
    xor cx,cx
    mov dx,0184fh
    mov bx,7
	int 10h

	mov ah,2	      ;resets the cursor position to
	mov dh,row	       ; row and column specified
	mov dl,col
    int 10h
	ret
ClrScrn endp

end
