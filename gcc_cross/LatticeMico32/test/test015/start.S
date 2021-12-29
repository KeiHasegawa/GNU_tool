	.text
start:
	orhi     sp, r0, hi(stack)
	ori      sp, sp, lo(stack)
	calli    main
	nop
_fstack:	
	nop
