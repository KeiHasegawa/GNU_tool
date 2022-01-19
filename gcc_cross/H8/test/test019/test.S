	.text
start:
	mov	#stack,sp
	jsr	_main
	nop

_main:
	rts
	
