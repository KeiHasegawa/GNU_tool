	.text
start:
	nop
	SP.H = 0
	SP.L = stack	
	call	_main
end:
	nop
	nop
	nop
	nop
	nop
	
