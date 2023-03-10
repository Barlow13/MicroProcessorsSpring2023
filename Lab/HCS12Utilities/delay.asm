; ***************************************************************************
; Author: Dr. Han-Way Huang
; Date: 07/18/2004
; Organization: Minnesota State University, Mankato
; *******************************************************************************************
; The following subroutine uses modulus counter to create a delay that is a multiple of
; 50 us. The multiple is passed in Y.
; *******************************************************************************************
delayby50us
	bset	TSCR1,TFFCA	; enable timer fast flag clear
	movb	#04,MCCTL	; enable modulus down counter with 1:1 as prescaler
	movw	#1200,MCCNT	; load the value to be down counted
	brclr	MCFLG,MCZF,*
	bclr	MCCTL,$04	; disable modulus down counter
	dbne	y,delayby50us
	rts
; ***************************************************************************
; The following function creates a time delay which is equal to the multiple
; of 1 ms. The value passed in Y specifies the number of milliseconds to be
; delayed.
; ***************************************************************************
delayby1ms 	movb	#$90,TSCR1	; enable TCNT & fast flags clear
		movb	#$06,TSCR2 	; configure prescale factor to 64
		movb	#$01,TIOS	; enable OC0
		ldd 	TCNT
again0		addd	#375		; start an output compare operation
		std	TC0		; with 50 ms time delay
wait_lp0	brclr	TFLG1,$01,wait_lp0
		ldd	TC0
		dbne	y,again0
		rts
; ***************************************************************************
; The following function creates a time delay which is equal to the multiple
; of 10 ms. The value passed in Y specifies the number of 10 milliseconds
; to be delayed.
; ***************************************************************************
delayby10ms 	movb	#$90,TSCR1	; enable TCNT & fast flags clear
		movb	#$06,TSCR2 	; configure prescale factor to 64
		movb	#$01,TIOS	; enable OC0
		ldd 	TCNT
again1		addd	#3750		; start an output compare operation
		std	TC0		; with 50 ms time delay
wait_lp1	brclr	TFLG1,$01,wait_lp1
		ldd	TC0
		dbne	y,again1
		rts
; ***************************************************************************
; The following function creates a time delay which is equal to the multiple
; of 100 ms. The value passed in Y specifies the number of 100 milliseconds
; to be delayed.
; ***************************************************************************
delayby100ms 	movb	#$90,TSCR1	; enable TCNT & fast flags clear
		movb	#$06,TSCR2 	; configure prescale factor to 64
		movb	#$01,TIOS	; enable OC0
		ldd 	TCNT
again2		addd	#37500		; start an output compare operation
		std	TC0		; with 50 ms time delay
wait_lp2	brclr	TFLG1,$01,wait_lp2
		ldd	TC0
		dbne	y,again2
		rts
		end

