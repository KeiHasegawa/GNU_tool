	.section P,"ax"
	.global	_f
_f:
	push.l	r10
	push.l	r6
	add	#-8, r0, r6
	mov.L	r6, r0
	mov.L	r1, [r6]
	mov.L	r2, 4[r6]
	
	mov.L	[r6], r10
	add	4[r6].L, r10
	mov.L	r10, r1
	add	#8, r0
	pop	r6
	pop	r10
	rts
