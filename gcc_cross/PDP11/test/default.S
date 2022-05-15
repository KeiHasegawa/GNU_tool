	.text
start:
	mov	$stack, sp
	jsr	pc, _main
	halt

	.global	___main
___main:
	rts	pc
