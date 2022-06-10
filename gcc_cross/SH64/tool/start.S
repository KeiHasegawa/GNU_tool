	.text
start:
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
	
