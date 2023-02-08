; ****************************************************************************
; The following function sends out the byte in accumulator A from the SPI pin.
; ****************************************************************************
putcSPI	brclr	SPI0SR,SPTEF,*	; wait until write operation is permissible
	staa	SPI0DR
	brclr	SPI0SR,SPIF,*	; wait until the byte is shifted out
	rts
; ****************************************************************************
; The following function sends the NULL-terminated string pointed to by X 
; from the SPI port.
; ****************************************************************************
putsSPI	ldaa	1,x+		; get one byte to be output to SPI port
	beq	doneps		; reach the end of the string?
	jsr	putc2spi	; call subroutine to output the byte
	bra	puts2spi	; continue to output
doneps	rts
; ****************************************************************************
; The following function sends a string pointed to by X to the SPI port.
; The number of bytes to be output is specified in B
; ****************************************************************************
puts2bSPI	tstb		; is byte count zero?
	beq	dones2
	ldaa	1,x+		; get one byte to be output to SPI
	jsr	putc2spi
	decb			; decrement byte count
	bra	puts2bspi
dones2	rts
; ****************************************************************************
; The following function reads a byte from the SPI port and returns it in A.
; ****************************************************************************
getcSPI	brclr	SPI0SR,SPTEF,*	; wait until write operation is permissible
	staa	SPI0DR		; trigger eight clock pulses for SPI transfer
	brclr	SPI0SR,SPIF,*	; wait until a byte is shifted in
	ldaa	SPI0DR		; place the byte in A
	rts
; ****************************************************************************
; The following function reads the number of bytes specified in B from the 
; SPI port and saves the string in a buffer pointed to by X.
; ****************************************************************************
getsSPI	tstb			; check the byte count
	beq	donegs		; return when byte count is zero
	jsr	getcspi		; call subroutine to read a byte
	staa	1,x+		; save the returned byte in the buffer
	decb			; decrement the byte count
	bra	getsspi
donegs	clr	0,x		; terminate the string with a NULL character
	rts