	.text
	.global	_f
_f:
	enter	#6-2
	
	mov.w	r1,-2[fb]
	mov.w	r2,-4[fb]
	mov.w	-2[fb],r0
	add.w	-4[fb],r0
	
	exitd
