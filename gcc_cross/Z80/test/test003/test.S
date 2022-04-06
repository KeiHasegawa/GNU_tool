	.text
start:
	ld	sp, stack
	call	_f
	nop
end:
	nop
	

_f:
	push	ix
	ld	hl, 0
	add	hl, sp
	ld	a, l
	sub	64
	ld	l, a
	ld	sp, hl
	ld	ix, 0
	add	ix, sp


	ld	hl, 0
	add	hl, sp
	ld	a, l
	add	a, 64
	ld	l, a
	ld	sp, hl
	pop	ix
	ret
	
	
