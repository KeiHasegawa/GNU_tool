	.text
start:
	ldi32	sp, stack
	call	%label(main)
end:
	nop
