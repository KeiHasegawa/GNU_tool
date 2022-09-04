	.text
start:
	movhi	sp, %hiadj(stack)
	addi	sp, sp, %lo(stack)
	call	main
end:
	nop

	.global	printf
printf:
	ret

	.global	puts
puts:
	ret

	.global	putchar
putchar:
	ret
