	.text
start:
	orhi     sp, r0, hi(stack)
	ori      sp, sp, lo(stack)
	calli    main
	nop
	nop
end:
_fstack:	
	nop
	
func:	
	b        ra
