	.text
start:
	nop
	ldi.l	$sp, stack
	jsra	func
	nop
	nop
	nop
end:
	nop
	

func:
	ret
