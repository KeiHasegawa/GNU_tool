	.text
start:
	mvkl	.s1	_bss_start, a1
	mvkh	.s1	_bss_start, a1
	mvkl	.s1	_bss_end, a2
	mvkh	.s1	_bss_end, a2
	mvkl	.s1	0, a3
.L1:
	cmpeq	.l1	a1, a2, a0
	[a0] b	.s2	.L2
	nop	5
	stb	.d1t1	a3, *a1
	add	.d1	a1, 1, a1
	b	.s2	.L1
	nop	5
.L2:	
	mvkl	.s2	__c6xabi_DSBT_BASE, b14
	mvkh	.s2	__c6xabi_DSBT_BASE, b14
	mvkl	.s2	stack, b15
	mvkh	.s2	stack, b15
 	callp	.s2	(main), b3
	nop
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
	
