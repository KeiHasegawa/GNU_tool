	.text
start:
	move.d _stack,$sp
	Jsr _main
	nop
	break 8
	nop
