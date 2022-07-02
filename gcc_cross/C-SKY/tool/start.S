	.text
start:
	lrw	r0, _bss_start
	lrw	r1, _bss_end
	movi	r2, 0
.L1:
	cmpne	r0, r1
	jbf	.L2
	st.b	r2, (r0, 0)
	addi	r0, r0, 1
	br	.L1
.L2:	
	lrw	sp, stack
	jbsr	main
	.short	1

	
	.global	printf
printf:
	.short	2
	rts

	.global	puts
puts:
	.short	3
	rts

	.global	putchar
putchar:
	.short	4
	rts
