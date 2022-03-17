	.text
start:
	bl	func
	nop		|| nop
	nop		|| nop

func:
	jmp	link	|| nop
