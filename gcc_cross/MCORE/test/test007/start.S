	.text
start:
	lrw	r8, stack
	mov	sp, r8
	jbsr	main
	nop
	nop
end:
	nop
	

func:
	jmp r15
	
