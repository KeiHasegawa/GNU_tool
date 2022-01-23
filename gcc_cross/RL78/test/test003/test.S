	.text
start:
	nop
	movw	sp, #stack
	call	!!func
	nop
end:
	nop
	


func:
	ret
	
