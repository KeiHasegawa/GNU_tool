	.text
start:
	movhi hi(func),r0,r10
	movea lo(func),r10,r10
	jarl .+4, r31 ; add 4, r31 ; jmp r10
	nop

func:
	jmp [r31]



	
	
