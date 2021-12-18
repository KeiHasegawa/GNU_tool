	.text
	.global start
start:
	nop
	mov.L	#_stack, r0
	bsr	func
	nop
	nop
end:
	nop


func:
	rts
	


