; *********************************************************************************
; This set of LCD functions are written for Dragon12 demo board. Dragon12 grounds
; the R/W pin, which prevent the user from reading from the LCD kit.
; Author: Dr. Han-Way Huang
; Date: 08/02/2008
; *********************************************************************************
lcd_dat equ	PTK   	        ; LCD data pins (PK5~PK2)
lcd_dir	equ   	DDRK            ; LCD data direction port
lcd_E   equ   	$02             ; E signal pin
lcd_RS  equ   	$01             ; RS signal pin
;------------------------------------------------------------------------------
; The next subroutine send a command to the LCD controller. The command to be
; send the LCD is passed in A.
; -----------------------------------------------------------------------------
cmd2LCD	psha           	        ; save the command in stack
	bclr  	lcd_dat,lcd_RS  ; select the instruction register
	bset  	lcd_dat,lcd_E   ; pull the E signal high
	anda  	#$F0    	; clear the lower four bits
	lsra            	; match the upper four bits with the LCD
	lsra            	; data pins
	oraa  	#lcd_E  	; maintain the E signal value
	staa  	lcd_dat 	; send the command, along with the RS, and E signals
	nop		        ; extend the duration of the E pulse
	nop		        ; 	"
	nop		        ;	"
	bclr  	lcd_dat,lcd_E   ; pull the E signal low
	pula		        ; retrieve the LCD command
	anda  	#$0F    	; clear the upper four bits
	lsla            	; match the lower four bits with the LCD
	lsla            	; data pins
	bset  	lcd_dat,lcd_E   ; pull the E signal high
	oraa  	#lcd_E  	; maintain the E signal value
	staa  	lcd_dat 	; send the lower four bits of command with E and RS
	nop		        ; extend the duration of the E pulse
	nop		        ;	"
	nop		        ;	"
	bclr  	lcd_dat,lcd_E   ; clear the E signal to complete the write operation
	ldy	#1	        ; adding this delay will complete the internal
	jsr	delayby50us	; operation for most instructions
	rts
; --------------------------------------------------------------------------------
; The next subroutine initializes the LCD to operate with 4-bit data width, 5 x 8
; font size, enable display, cursor, and cursor blinking. Finally, the screen is
; cleared and the cursor is moved to the upper-left corner.
; --------------------------------------------------------------------------------
openLCD movb  	#$FF,lcd_dir    ; configure Port K for output
	ldy   	#2	        ; wait for LCD to be ready
	jsr   	delayby100ms	;	"
	ldaa  	#$28            ; set 4-bit data, 2-line display, 5   8 font
	jsr   	cmd2LCD         ;       "
	ldaa  	#$0F            ; turn on display, cursor, and blinking
	jsr   	cmd2LCD         ;       "
	ldaa  	#$06            ; move cursor right (entry mode set instruction)
	jsr   	cmd2LCD         ;       "
	ldaa  	#$01            ; clear display screen and return to home position
	jsr   	cmd2LCD         ;       "
	ldy   	#2              ; wait until clear display command is complete
	jsr   	delayby1ms      ;       "
	rts
; --------------------------------------------------------------------------------
; The next subroutine outputs the character contained in A to the LCD.
; --------------------------------------------------------------------------------	
putcLCD	psha                    ; save a copy of the data
	bset  	lcd_dat,lcd_RS 	; select lcd Data register
	bset  	lcd_dat,lcd_E  	; pull E to high
	anda  	#$F0            ; mask out the lower four bits
	lsra           	        ; match the upper four bits with the LCD
	lsra            	; data pins
	oraa  	#$03            ; keep signal E and RS unchanged
	staa  	lcd_dat        	; send the upper four bits and E, RS signals
	nop                     ; provide enough duration to the E signal
	nop                     ;       "
	nop                     ;       "
	bclr  	lcd_dat,lcd_E   ; pull the E signal low
	pula		        ; retrieve the character from the stack
	anda  	#$0F    	; clear the upper four bits
	lsla            	; match the lower four bits with the LCD
	lsla            	; data pins
	bset  	lcd_dat,lcd_E   ; pull the E signal high
	oraa  	#$03            ; keep E and RS unchanged
	staa  	lcd_dat
	nop
	nop
	nop
	bclr  	lcd_dat,lcd_E   ; pull E low to complete the write cycle
	ldy	#1	        ; wait until the write operation is 
	jsr	delayby50us	; complete
	rts
; --------------------------------------------------------------------------------
; The next subroutine outputs the string pointed to by X to the LCD.
; --------------------------------------------------------------------------------	
putsLCD	ldaa  	1,x+   	; get one character from the string
	beq   	donePS	; reach NULL character?
	jsr   	putcLCD
	bra   	putsLCD
donePS	rts
