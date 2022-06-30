	.text
start:
	li	r0, 0	
	li	r1, _bss_start
	li	r2, _bss_end
.L1:
	cr	r1, r2
	bez	.L2
	st	r0, 0, r1
	aim	r1, 2
	br	.L1
.L2:	
	li	r15, stack
	js	r13, main
	.word	0xcccb

	.global	printf
printf:
	.word	0xccca
	ji	r13

	.global	puts
puts:
	.word	0xccc9
	ji	r13

	.global	putchar
putchar:
	.word	0xccc8
	ji	r13
