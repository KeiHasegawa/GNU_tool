	.text
start:
	lrw	r6, _bss_start
	lrw	r7, _bss_end
	movi	r8,0
	movi	r9,1
.L1:	
	cmpne	r6, r7
	jbf	.L2
	nop
	st.b	r8,(r6)
	addu	r6, r9
	jbr	.L1
	nop
.L2:	
	lrw	r8, stack
	mov	sp, r8
	jsri	main
	nop
_exit:	
	jbr	.
