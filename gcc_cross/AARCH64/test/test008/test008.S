	.text
start:
	adrp	x0, stack
	add	sp, x0, :lo12:stack

	mov	w1, 0xff00
	movk	w1, 0xddee, lsl 16    // w1 = 0xddeeff00

	mov	x2, 0xdef0
	movk	x2, 0x9abc, lsl 16
	movk	x2, 0x5678, lsl 32
	movk	x2, 0x1234, lsl 48     // x2 = 0x123456789abcdef0LL

	mov	x3, 0x7788
	movk	x3, 0x5566, lsl 16
	movk	x3, 0x3344, lsl 32
	movk	x3, 0x1122, lsl 48     // x3 = 0x1122334455667788LL
	
	bl	func1
end:
	nop

	/*
           +------------------+ <- sp_{new}, x29_{new} 
           |     x29_{old}    |
           +------------------+ +8
           |     x30_{old}    |
           +--------+---------+ +16
           |   1    |w1_{old} |
           +--------+---------+ +24
           |     x2_{old}     |
           +------------------+ +32
           |     x3_{old}     |
           +------------------+ +40
           |                  |
           +------------------+ +48
           |                  |
           +------------------+ +56
           |                  |
           +------------------+ <- sp_{old}

	*/
	
func1:
	stp     x29, x30, [sp, #-64]!
	mov     w0, #0x1
	stp     w0, w1, [sp, #16]
	stp     x2, x3, [sp, #24]
	mov     w2, #0x5
	bl      func2
	ldp	x29, x30, [sp], 64
        ret

func2:
	ret
	
