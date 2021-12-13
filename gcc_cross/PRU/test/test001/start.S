	.text
start:
	ldi32	r14, _bss_start
	ldi32	r15, _bss_end
	ldi	r0, 0
.L1:	
	qbeq	.L2, r14, r15
	sbbo	r0.b0, r14, 0, 1
	add	r14, r14, 1
	jmp	%label(.L1)
.L2:	
	ldi32	sp, _stack
	call	main
	nop
	.word	0xbadbeef0
