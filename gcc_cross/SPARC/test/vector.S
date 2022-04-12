	.text
	.global	TRAP_BASE
TRAP_BASE:	
	.org	0x50
WOFL:	
	ba	window_overflow
	nop
	nop
	nop

WUFL:
	ba	window_underflow
	nop
	nop
	nop
