	.text
start:
	mov	#stack,sp
	jsr	func
	nop


func:
	rts
	
