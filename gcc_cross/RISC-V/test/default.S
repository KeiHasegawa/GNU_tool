	.text
start:
	lui	sp, %hi(stack)
	addi	sp, sp, %lo(stack)
	call	main
end:
	nop
