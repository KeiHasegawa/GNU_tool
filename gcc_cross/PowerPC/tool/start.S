	.text
start:
	lis 1,stack@ha
	la 1,stack@l(1)
	bl main
	nop	
	.long	0x7fffbad0
	
	.global	printf
printf:
	.long	0x7fffbad1
	blr

	.global	puts
puts:
	.long	0x7fffbad2
	blr
	
	.global	putchar
putchar:
	.long	0x7fffbad3
	blr
	
