	.text
start:
	adrp	x0, stack
	add	sp, x0, :lo12:stack
	mov	w0, 123
	mov	x1, 456
	fmov	d0, 5.0e-1

	mov	x19, 0xdef0
	movk	x19, 0x9abc, lsl 16
	movk	x19, 0x5678, lsl 32
	movk	x19, 0x1234, lsl 48     // x19 = 0x123456789abcdef0LL
	
	bl	func1
	nop
	nop
	nop
end:
	nop

	/* func1(int w0, long long x1, double d0)*/
	/*

           +------------------+ <- sp_{new}
           |    0x9abcdef0    |
           |    0x12345678    |
           +------------------+ +8
           |                  |
           |                  |
           +------------------+ +16
           |                  |
           |                  |
           +------------------+ +24
           |       0.5        |
           |                  |
           +------------------+ +32
           |       456        |
           |                  |
           +------------------+ +40
           |                  |
           |       123        |
           +------------------+ <- sp_{old}

	 */
func1:
	str	x19, [sp, #-48]!
	str	w0, [sp, #44]
	str	x1, [sp, #32]
	str	d0, [sp, #24]
	mov	x19, x2
	ldr	x0, [sp, #32]
        ret
