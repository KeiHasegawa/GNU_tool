	.text
start:
	ld	sp, stack
	call	_f
	nop
end:
	nop
	

_f:
	ld	hl, 0
	add	hl, sp
	push	hl
	push	ix
	ld	a, l
	sub	0x44
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
	pop	hl
	ld	sp, hl
	ret
	
	
