	.text
	.global start
start:
	nop
	mov.L	#_stack, r0
	bsr	_main
	nop
	nop
end:
	nop


func:
	rts
	


