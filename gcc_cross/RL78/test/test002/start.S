	.text
start:
	movw	sp, #stack
	call	!!%code(_main)
	nop
end:
	nop
	
