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
	ld	bc, 64
	sbc	hl, bc
	ld	sp, hl
	ld	ix, 0
	add	ix, sp


	ld	hl, 0
	add	hl, sp
	ld	bc, 64
	add	hl, bc
	ld	sp, hl
	pop	ix
	ret
