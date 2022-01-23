	.text
start:
	nop
	mov.l	label1,r15
	mov.l	label2,r1
	jsr	@r1
	nop
	nop

label1:
	.long	stack
label2:
	.long	func
	
func:
	rts
	
