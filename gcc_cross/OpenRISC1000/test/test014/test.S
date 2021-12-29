	.text
start:
	l.movhi	r3, hi(0)
	l.jal	func
	l.ori	r3, r0, 123
	l.nop
	
func:
	l.movhi	r4, hi(0)
	l.jr	r9
	l.ori	r4, r0, 456

	
