	.text
start:
	ldi	sp, stack
	call	main
	nop
	.word	0xbadbeef0

	.global	printf
printf:
	.word	0xbadbeef1
	ret

	.global	puts
puts:
	.word	0xbadbeef2
	ret

	.global	putchar
putchar:
	.word	0xbadbeef3
	ret
