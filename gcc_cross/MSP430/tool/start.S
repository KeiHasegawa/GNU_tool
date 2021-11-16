	.text
start:
	MOV.W	#stack, R1
	CALL	#main
	nop	
	.word	0x11c0      	; simulator or gdb will exit(0);
	
	.global printf
printf:
	.word	0x11c1
	RET

	.global puts
puts:
	.word	0x11c2
	RET

	.global putchar
putchar:
	.word	0x11c3
	RET

	.global memcpy
memcpy:
	SUB.W	#8, R1
	; end of prologue
	MOV.W	R12, 4(R1)
	MOV.W	R13, 2(R1)
	MOV.W	R14, @R1
	MOV.W	4(R1), 6(R1)
	BR	#.L5
.L6:
	MOV.W	2(R1), R13
	MOV.W	R13, R12
	ADD.W	#1, R12
	MOV.W	R12, 2(R1)
	MOV.W	4(R1), R12
	MOV.W	R12, R14
	ADD.W	#1, R14
	MOV.W	R14, 4(R1)
	MOV.B	@R13, R13
	MOV.B	R13, @R12
.L5:
	MOV.W	@R1, R12
	MOV.W	R12, R13
	ADD.W	#-1, R13
	MOV.W	R13, @R1
	CMP.W	#0, R12 { JNE	.L6
	MOV.W	6(R1), R12
	; start of epilogue
	ADD.W	#8, R1
	RET
