	.text
start:
	movw	sp, #stack
	call	!!func
	nop
	nop
	


func:
	ret
	
