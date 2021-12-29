	.text
start:
	l.jal	func
	l.nop
end:
	l.nop
	
func:
	l.jr	r9
	l.nop
	
