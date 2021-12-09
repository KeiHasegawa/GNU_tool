	.text
start:
	adrp	x0, stack
	add	sp, x0, :lo12:stack
	bl	func1
end:
	nop
	
func1:
	stp     x29, x30, [sp, #-64]!
	mov     w0, #0x1
	str     w4, [sp, #40]
	str     x5, [sp, #48]
	mov     w2, #0x5
	bl      func2
	ldp	x29, x30, [sp], 64
        ret

func2:
	ret
	
