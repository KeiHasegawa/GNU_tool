	.text
start:
	ldi32	sp, stack
	call	%label(func1)
	call	%label(func2)
	nop
	
func1:
	sub	r2, r2, 134
	sbbo	r3.b2, r2, 128, 6
	add	r4, r2, 134
	sub	r2, r4, 6
	lbbo	r3.b2, r2, 0, 6
	add	r2, r2, 6
	ret


func2:
	sub	r2, r2, 4
	sbbo	r4.b0, r2, 0, 4
	add	r4, r2, 4
	ldi	r1, 256
	sub	r2, r2, r1
	nop
	sub	r2, r4, 4
	lbbo	r4.b0, r2, 0, 4
	add	r2, r2, 4
	ret
	
