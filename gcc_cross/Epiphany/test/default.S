	.text
start:
	mov	sp, %low(_stack)
	movt	sp, %high(_stack)
	mov	r2, %low(_main)
	movt	r2, %high(_main)
	jalr	r2
end:
	nop
