	.text
start:
	movi	stack, r15
	pta	main, tr0
	blink	tr0, r13
	.long	0xbadbeef1

	.global	printf
printf:
	.long	0xbadbeef2
	ptabs	r13, tr0
	blink	tr0, r13
	
	.global	puts
puts:
	.long	0xbadbeef3
	ptabs	r13, tr0
	blink	tr0, r13

	.global	putchar
putchar:
	.long	0xbadbeef4
	ptabs	r13, tr0
	blink	tr0, r13
	
