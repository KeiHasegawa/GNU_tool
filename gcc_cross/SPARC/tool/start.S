	.text
start:
	sethi	%hi(_bss_start), %o0
	or	%o0, %lo(_bss_start), %o0
	sethi	%hi(_bss_end), %o1
	or	%o1, %lo(_bss_end), %o1
.L0:	
	cmp	%o0, %o1
	be	.L1
	nop
	stb	%g0, [%o0]
	add	%o0, 1, %o0
	b	.L0
	nop
.L1:	
	sethi	%hi(stack), %sp
	or	%sp, %lo(stack), %sp
	call	main
	nop
	unimp	0

	.global	printf
printf:
	unimp	1
	jmp	%o7+8
	nop

	.global	puts
puts:
	unimp	2
	jmp	%o7+8
	nop

	.global	putchar
putchar:
	unimp	3
	jmp	%o7+8
	nop

	
