	.text
start:
	ldconst	stack, g4
	mov	g4, sp
	mov	g4, fp
	callx	_main
	mov	g0, g0
	mov	g0, g0
end:
	mov	g0, g0


	.global	___main
___main:
	ret
	
