	.text
	.global start
start:
	nop
	mov.L	#_stack, r0
	bsr	_main
	nop
	.byte	0x00
	nop


