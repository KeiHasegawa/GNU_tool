	.text
start:
	lui	%29,%hi(stack)
	addiu	%29,%29,%lo(stack)
	lui	%3,%hi(main)
	addiu	%3,%3,%lo(main)
	jalr	%31,%3
	nop
	.long	0xbadbeef0
	
	.global	printf
printf:
	j	%31
	nop

	.global	puts
puts:
	j	%31
	nop

	.global	putchar
putchar:
	j	%31
	nop
