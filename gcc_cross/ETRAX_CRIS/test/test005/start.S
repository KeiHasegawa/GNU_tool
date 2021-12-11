	.text
start:
	move.d _stack,$sp
	Jsr _main
	nop
	nop
end:
	nop
	
	
func:
	ret
	
	
