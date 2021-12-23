	.text
start:
	ld24 sp,#stack
	bl main
	nop	
	trap #0x1
