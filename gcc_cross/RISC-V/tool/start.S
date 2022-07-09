	.text
start:
	lui	sp, %hi(stack)
	addi	sp, sp, %lo(stack)
	call	main
	.word	0xbadbeef0

	.global	printf
printf:
	.word	0xbadbeef1
	jr	ra

	.global	puts
puts:
	.word	0xbadbeef2
	jr	ra
	
	.global	putchar
putchar:
	.word	0xbadbeef4
	jr	ra
