	.text
start:
	orhi	r1, r0, hi(_bss_start)
	ori	r1, r1, lo(_bss_start)
	orhi	r2, r0, hi(_bss_end)
	ori	r2, r2, lo(_bss_end)
.L1:
	be	r1, r2, .L2
	nop
	sb	(r1+0), r0
	addi	r1, r1, 1
	bi	.L1
	nop
.L2:	
	orhi     sp, r0, hi(_stack)
	ori      sp, sp, lo(_stack)
	calli    main
	nop
	
