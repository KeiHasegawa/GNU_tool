	.text
start:	
	mov	sp, @stack
	bl	@main
end:
	nop
