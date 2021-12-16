	.text
start:
	movw	sp, #stack
	call	!!%code(_main)
	nop
	nop
	

_main:
	ret
	
