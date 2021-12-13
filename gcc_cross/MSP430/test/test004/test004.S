	.text
start:
	MOV.W	#stack, R1
	call #func
end:
	nop
	nop

func:
	ret


	
	
