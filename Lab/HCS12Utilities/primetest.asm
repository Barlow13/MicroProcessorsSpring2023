; ------------------------------------------------------------------------------------------------------------------------
; The following subroutine tests whether an integer is a prime. The number to be tested
; is 32-bit and is pushed into the stack with lower half first. The result is returned in A
; and will be 1 if the number is a prime.
; ------------------------------------------------------------------------------------------------------------------------
ii	equ	0	; stack offset from SP of loop index
tlimit	equ	2	; stack offset from SP of test limit
pNumHi	equ	10	; stack offset from SP of upper half of test number
pNumLo	equ	12	; stack offset from SP of lower half of test number
pLocal	equ	4	; number of bytes used by local variables
; ------------------------------------------------------------------------------------------------------------------------
PrimeTest	pshx
	pshy
	leas	-pLocal,SP	; allocate space for local variables
	ldaa	pNumLo+1,SP	; check if the number is even (if bit 0 is 0)
	anda	#$01	;	"
	beq	nonPRI	;	"
	ldd	pNumHi,SP
	cpd	#0
	bne	testPR	; upper half nonzero, then enter normal test
	ldd	pNumLo,SP	; if upper half is 0, then test lower half
	cpd	#0	; is lower half equal to 0?
	beq	nonPri	; 0 is not a prime
	cpd	#1	; is lower half equal to 1
	beq	nonPri	; 1 is not a prime
testPR	ldd	pNumLo,SP	; find the square root of Num
	ldx	pNumHi,SP	;	“
	pshd		;	“
	pshx		;	“
	jsr	findsqr	;	“
	leas	4,SP	; de-allocate space for passing parameters
	std	tlimit,SP	; save returned value as the prime test limit
	movw	#2,ii,SP	; initialize test divide number to 3
divLoop	ldd	ii,SP
	cpd	tlimit,SP	; has test divided all numbers up to tlimit?
	bhi	isPRI	; the number is prime
	ldd	pNumLo,SP	; divide Num by ii
	ldx	pNumHi,SP	;	“
	ldy	ii,SP	;	“
	leas	-8,SP	; 	“
	pshd		; 	“ (push pNumLo)
	pshx		; 	“ (push pNumHi)
	pshy		; 	“ (push ii)
	movw	#0,2,-SP	; 	“ (push 0 to the stack)
	jsr	div32	; 	“ (call the divide subroutine)
	leas	14,SP	; de-allocate the space used by outgoing parameters
	puld		; get the lower two bytes of the remainder
	cpd	#0	; is remainder equal to 0?
	beq	nonPRI	; If remainder equals 0, then Num is not a prime
	ldd	ii,SP	; test divide the next higher integer
	addd	#1	;	“
	std	ii,SP	;	“
	bra	divLoop
isPRI	ldaa	#1
	bra	exitPT
nonPRI	ldaa	#0
exitPT	leas	pLocal,SP
	puly
	pulx
	rts