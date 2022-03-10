	.text
start:
	ldi:32	stack, sp
	ldi:32	main, r1
	call	@r1
	int	9
	nop
