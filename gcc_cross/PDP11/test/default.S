	.text
start:
	mov	$stack, sp
	jsr	pc, _main
end:	
	halt

	.global	___main
___main:
	rts	pc
