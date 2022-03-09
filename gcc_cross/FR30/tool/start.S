	.text
start:
	ldi:32	_bss_start, r1
	ldi:32	_bss_end, r2
	ldi:8	#0, r3
.L0:
	cmp	r1, r2
	beq	.L1
	stb  	r3, @r1
	addn	1, r1
	bra	.L0
.L1:	
	ldi:32	_stack, sp
	ldi:32	main, r1
	call	@r1
	.short	0xbeef

	.global	printf
printf:
	ret

	.global	puts
puts:
	ret

	.global	putchar
putchar:
	ret
	
	
