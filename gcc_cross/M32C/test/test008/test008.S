	.text
start:
	ldc	#stack, sp
	jsr.a	_main
	nop
end:
	nop

_main:
	rts
	
