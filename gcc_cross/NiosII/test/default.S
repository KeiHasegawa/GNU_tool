	.text
start:
	movhi	sp, %hiadj(stack)
	addi	sp, sp, %lo(stack)
	call	main
end:
	nop
