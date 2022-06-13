	.text
start:
	movi	0, r0
	movi	_bss_start, r1
	movi	_bss_end, r2
	pta	.L1, tr1
	pta	.L2, tr2
.L1:
	beq	r1, r2, tr2
	st.b	r1, 0, r0
	addi	r1, 1, r1
	blink	tr1, r13
.L2:	
	movi	stack, r15
	pta	main, tr0
	blink	tr0, r13
	.long	0xbadbeef1

	.global	printf
printf:
	ptabs	r13, tr0
	blink	tr0, r13
	
	.global	puts
puts:
	ptabs	r13, tr0
	blink	tr0, r13

	.global	putchar
putchar:
	ptabs	r13, tr0
	blink	tr0, r13
	
