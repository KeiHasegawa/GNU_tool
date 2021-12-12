	.text
start:
	nop
	ldc	#stack, sp
	jsr.a	_main
	nop
end:
	nop
