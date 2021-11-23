	.text
start:
	lrw	r8, stack
	mov	sp, r8
	jbsr	main
	nop
	.short 0x09f0

	.global	printf
printf:	
	.short 0x09f1
	jmp r15

	.global	puts
puts:	
	.short 0x09f2
	jmp r15

	.global	putchar
putchar:	
	.short 0x09f3
	jmp r15

