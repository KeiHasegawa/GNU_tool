	.text
start:
	mvkl	.s2	stack, b15
	mvkh	.s2	stack, b15
 	callp	.s2	(main), b3
	.long	0xbadbeef0

	.global	printf
printf:
	.long	0xbadbeef2
	ret	.s2	b3
	nop	5

	.global	puts
puts:
	.long	0xbadbeef4
	ret	.s2	b3
	nop	5

	.global	putchar
putchar:
	.long	0xbadbeef6
	ret	.s2	b3
	nop	5
	
