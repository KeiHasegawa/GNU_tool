	.text
start:
	adrp	x0, stack
	add	sp, x0, :lo12:stack
	bl	func1
end:
	nop

	/*

           +------------------+ <- sp_{new}, x29_{new} 
           |     x29_{old}    |
           +------------------+
           |     x30_{old}    |
           +------------------+ <- sp_{old}

	*/
	
func1:
	stp     x29, x30, [sp, #-16]!
	mov     w0, #0x1
	mov     x29, sp
	mov     w2, #0x5
	bl      func2
	ldp	x29, x30, [sp], 16
        ret

func2:
	ret
	
