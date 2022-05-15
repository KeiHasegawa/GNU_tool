	.text
start:
	mov	r1, #5
	add	r1, #5
	jmp	label
	
	br	next
	halt

label:
	mov	r1, #1
	halt

next:
	mov	r1, #2
	halt
	
