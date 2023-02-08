; *********************************************************************************************
; The following subroutine divides an unsigned 32-bit integer by another unsigned 
; 32-bit integer
; *********************************************************************************************
buf	equ	0	; distance of buf from the top of the stack
i	equ	4	; distance of i from the top of the stack
R	equ	5	; distance of R from the top of the stack
Q	equ	9	; distance of Q from the top of the stack
divisor	equ	21	; distance of divisor from the top of the stack
dividend	equ	25	; distance of dividend from the top of the stack
quo	equ	29	; distance of quo from the top of the stack
rem	equ	33	; distance of rem from the top of the stack
locVar	equ	13	; number of bytes for local variables

div32	pshd
	pshx
	pshy
	leas	-locVar,sp	; allocate space for local variables
	ldd	#0
	std	R,sp	; initialize register R to 0
	std	R+2,sp	;	“
	ldd	dividend,sp	; place dividend in register Q
	std	Q,sp	; 	“
	ldd	dividend+2,sp	; 	“
	std	Q+2,sp	;	“
	ldaa	#32	; initialize loop count
	staa	i,sp	; 	“
loop	lsl	Q+3,sp	; shift register pair Q and R to the left
	rol	Q+2,sp	; by 1 bit
	rol	Q+1,sp	; 	"
	rol	Q,sp	; 	"
	rol	R+3,sp	; 	"
	rol	R+2,sp	; 	"
	rol	R+1,sp	; 	"
	rol	R,sp	;	"
; the following eight instructions subtract the divisor from register R
	ldd	R+2,sp	
	subd	divisor+2,sp
	std	buf+2,sp
	ldaa	R+1,sp
	sbca	divisor+1,sp
	staa	buf+1,sp
	ldaa	R,sp
	sbca	divisor,sp
	bcs	smaller
; the following six instructions store the difference back to R register
	staa	R,sp
	ldaa	buf+1,sp
	staa	R+1,sp
	ldd	buf+2,sp
	std	R+2,sp
	bset	Q+3,sp,$01	; set the least significant bit of Q register to 1
	bra	looptest	
smaller	bclr	Q+3,sp,$01	; set the least significant bit of Q register to 0
looptest	dec	i,sp
	lbne	loop
; the following four instructions copy the remainder into the hole in the stack
	ldd	R,sp
	std	rem,sp
	ldd	R+2,sp
	std	rem+2,sp
; the following four instructions copy the quotient into the hole in the stack
	ldd	Q,sp
	std	quo,sp
	ldd	Q+2,sp
	std	quo+2,sp
	leas	locVar,sp	; deallocate local variables
	puly
	pulx
	puld
	rts