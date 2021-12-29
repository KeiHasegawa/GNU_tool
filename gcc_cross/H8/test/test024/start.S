	.text
start:
	mov	#stack,sp
	jsr	_main
	nop
	sleep
	nop
