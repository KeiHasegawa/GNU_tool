	.text
start:
	MOV.W	#stack, R1
	CALL	#main
	nop	
end:
	nop
	

main:
	RET
