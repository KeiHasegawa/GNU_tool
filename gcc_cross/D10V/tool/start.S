	.text
start:
	ldi.l	r0, _bss_start
	ldi.l	r1, _bss_end
	ldi.s	r2, 0
.L0:	
	cmpeq	r0, r1
	brf0t.s	.L1
	stb	r2, @r0
	addi	r0, 1
	bra.s	.L0
.L1:	
	ldi.l	sp, _stack
	bl	main
	nop || nop
	.long	0xbadbeef0

	.global	printf
printf:
	.long	0xbadbeef1
	jmp	r13

	.global	puts
puts:
	.long	0xbadbeef2
	jmp	r13

	.global	putchar
putchar:
	.long	0xbadbeef3
	jmp	r13
	

	
