	.text
start:
	ldi.l	sp, stack
	bl	main
	nop || nop
end:
	nop || nop


f:
	st	r13, @-sp
	st	r14, @-sp
	subi	sp, 4
	mv	r14, sp
	st	r0, @r14
	st	r1, @(2, r14)
	ld	r8, @r14
	ld	r9, @(2, r14)
	add	r8, r9
	mv	r0, r8
	addi	sp, 4
	ld	r14, @sp+
	ld	r13, @sp+
	jmp	r13



main:
	st	r13, @-sp
	st	r14, @-sp
	ldi.s	r0, 5
	ldi.s	r1, 6
	bl	f
	ldi.s	r0, 0
	ld	r14, @sp+
	ld	r13, @sp+
	jmp	r13
