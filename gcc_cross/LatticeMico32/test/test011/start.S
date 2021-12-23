	.text
start:
	orhi     sp, r0, hi(stack)
	ori      sp, sp, lo(stack)
	calli    main
	nop
	break
_fstack:	
	nop
