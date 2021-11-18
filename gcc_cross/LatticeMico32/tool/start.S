	.text
start:
	orhi     sp, r0, hi(stack)
	ori      sp, sp, lo(stack)
	calli    main
	nop
	.long	0xbadbeef0

	.global printf
printf:	
	b        ra

	.global puts
puts:	
	b        ra

	.global putchar
putchar:	
	b        ra

_fstack:	
	nop
