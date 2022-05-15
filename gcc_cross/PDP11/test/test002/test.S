	.text
start:
	mov	$5, r1
	add	$5, r1
	jmp	label
	
	br	next
	halt

label:
	mov	$1, r1
	halt

next:
	mov	$2, r1
	halt
	
