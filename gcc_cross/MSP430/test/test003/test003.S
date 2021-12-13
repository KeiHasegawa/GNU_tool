	.text
start:
	MOV.W	#stack, R1
	call #func
	nop

func:
	ret


	
	
