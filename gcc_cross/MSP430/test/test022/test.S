start:
	mov.w	#stack, r1
	call	#func1
	nop
	br	#start		; change to jmp -4
