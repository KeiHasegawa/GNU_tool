	.text
	.global start
start:
	ldi ZL, lo8(_etext)
	ldi ZH, hi8(_etext)
	ldi YL, lo8(__data_load_end)
	ldi YH, hi8(__data_load_end)
	ldi XL, lo8(__data_start)
	ldi XH, hi8(__data_start)
label1:
	; if Z == Y goto label2
	cp ZL, YL
	cpc ZH, YH
	breq label2

	lpm r0, Z
	st X, r0
	adiw ZL, 1
	adiw XL, 1
	rjmp label1
label2:	
	ldi r16, 0xff
	out 0x3d, r16
	ldi r16, 0xfe
	out 0x3e, r16
	rcall	main
end:	
	nop
	
