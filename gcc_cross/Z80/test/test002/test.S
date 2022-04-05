	.text
start:
	ld	sp, stack
	call	func
	nop
end:	
	nop

func:
	ret
	
