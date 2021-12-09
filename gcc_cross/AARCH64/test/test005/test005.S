	.text
start:
	adrp	x0, stack
	add	sp, x0, :lo12:stack
	bl func1
end:
	nop

func1:
	stp     x29, x30, [sp,#-272]!
	mov     x29, sp
	bl	func2
	ldp	x29, x30, [sp], 272
        ret

func2:
	ret
