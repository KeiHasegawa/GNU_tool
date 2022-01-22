	.text
	.balign 2
	.global	f
f:
	SUB.W	#4, R1
	MOV.W	R12, 2(R1)
	MOV.W	R13, @R1
	
	MOV.W	2(R1), R12
	ADD.W	@R1, R12

	ADD.W	#4, R1
	RET
