	.text
start:
	l.nop
	l.nop
	l.movhi	r1, ha(stack)
	l.addi	r1, r1, lo(stack)
	l.jal	main
	l.nop
	.word	0xbadbeef0

	.global	printf
printf:
	l.jr	r9
	l.nop

	.global	puts
puts:
	l.jr	r9
	l.nop

	.global	putchar
putchar:
	l.jr	r9
	l.nop

