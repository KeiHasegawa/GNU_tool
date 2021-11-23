	.text
start:
	nop
	ldi.l	$sp, stack
	jsra	main
	nop
	.short	0xfff0
	
	.global	printf
printf:
	.short	0xfff1
	ret

	.global	puts
puts:
	.short	0xfff2
	ret

	.global	putchar
putchar:
	.short	0xfff3
	ret
	
	
