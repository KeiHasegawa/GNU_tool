	.text
start:
	MOV.W	#stack, R1
	CALL	#main
	nop	
	clr.b	r3
	nop	
