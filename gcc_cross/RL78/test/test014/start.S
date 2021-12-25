	.text
start:
	movw	sp, #stack
	call	!!%code(_main)
	nop
	brk1
	nop
	
