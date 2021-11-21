	.text
start:
	nop
	la	$gp, _gp
	la	$sp, stack
	jal	main
	nop
	.word	0x7fffbee0
	
	.global	printf
printf:
	.word	0x7fffbee1
	j	$31

	.global	puts
puts:
	.word	0x7fffbee2
	j	$31

	.global	putchar
putchar:
	.word	0x7fffbee3
	j	$31
	
