title	addbcd
comment ~********************************
	Name:Eric Duhon
	SSN: 453-97-8531
	Date:Oct 25,1999
	Purpose:This c callable function inputs 2 numeric strings and
		adds them together. the result is a string returned in ans
~	 ********************************
	.286
	.model	  small,c



     .code
UnpackedAdd proc near c uses  si di ans:word,input1:word,input2:word,numbchar:word
;************************************************
; initilzation and error checking
;************************************************
     mov bx,ans 		;move offsets of ans,input1, and input2
     mov di,input1		 ;strings into bx,di, and si respectivly
     mov si,input2
     mov ax,[di]		;check for null pointer in input1
     .if(ax == 0)		 ;if so return with error
      stc
      mov ax,-1
      ret
     .endif
     mov ax,[si]		;check for null pointer in input2
     .if(ax == 0)		 ;if so return with error
      stc
      mov ax,-1
      ret
     .endif
     .if(numbchar == 0) 	;check if any charcters to do
      stc			 ;if none return now
      mov ax,-1
      ret
     .endif
;******************************************
; prepare for loop
;******************************************
     add bx,numbchar		;point to null charcters of
     add di,numbchar		 ;3 strings
     add si,numbchar
     mov ax,0			;make this character null in ans
     mov [bx],al
     mov cx,numbchar		;add numbchars
     clc
;******************************************
; addition loop
;******************************************
begin:
     dec bx			;point to next characters
     dec di			 ;in ans,input1, and input2
     dec si
     mov al,[di]		;add character in input1 and input2
     adc al,[si]		 ;and carry from previous add
     aaa			;adjust
     pushf			;dont let or al,30h destroy carry
     or al,30h			;turn into ascii
     popf			;restor carry
     mov [bx],al		;save character in ans
     loop begin 		;do another character
;******************************************
; finished
;******************************************
     mov ax,0			;done so return with no error
     clc
     ret
UnpackedAdd	endp


end
