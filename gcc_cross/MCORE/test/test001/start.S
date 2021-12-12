	.text
start:
	nop
	lrw	r8, stack
	mov	sp, r8
	jsri	main
	nop
end:
	nop
	
