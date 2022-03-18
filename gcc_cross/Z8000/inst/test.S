	.text
start:	
	adc	r0, r1
	adcb	rh0, rh0
	add	r1, @r15
	add	r2, start
	add	r3, start(r2)
	add	r4, 5
	addb	rh0,@r14
	addb	rh1, start
	addb	rh2, start(r3)
	addb	rh3, 6
	addb	rh4, rh5
	addl	rr2, @r14
	addl	rr4, start
	addl	rr6, 255
	addl	rr4, rr2
	and	r0, @r14
	and	r1, start
	and	r2, start(r1)
	and	r3, 65535
	and	r1, r2
	andb	rl0, @r13
	andb	rl1, start
	andb	rh1, start(r12)
	andb	rl2, 255
	andb	rh1, rl1
	bit	@r1, #15
	bit	start(r2), #14
	bit	start, #13
	bit	r3, #12
	bitb	@r1, #11
	bitb	start(r1), #10
	bitb	start, #9
	bitb	rh1, #8
	bitb	rh1, r2
	bpt
	brk
	call	@r1
	call	start
	call	start(r1)
	calr	start
	clr	@r1
	clr	start
	clr	start(r1)
	clr	r0
	clrb	@r1
	clrb	start
	clrb	start(r2)
	clrb	rl0
	com	@r1
	com	start
	com	start(r1)
	com	r0
	comb	@r14
	comb	start
	comb	start(r2)
	comb	rl0
	comflg	p
	cp	@r1, #65535
	cp	start(r1), #65534
	cp	start, #65533
	cp	r1, @r2
	cp	r1, start
	cp	r1, start(r2)
	cp	r2, #65532
	cp	r3, r4
	cpb	@r1, #255
	cpb	start(r1), #255
	cpb	start, #255
	cpb	rl0, @r14
	cpb	rl0, start
	cpb	rh0, start(r2)
	cpb	rl1, #255
	cpb	rh1, rh0
	cpd	r2, @r1, r1, ule
	cpdb	rh2, @r14, r2, ule
	cpdr	r3, @r14, r3, t
	cpi	r4, @r3, r4, f
	cpib	rh4, @r5, r5, ule
	cpir	r1, @r6, r6, ule
	cpirb	rh1, @r7, r8, ule
	cpl	rr2, @r3
	cpl	rr2, start
	cpl	rr4, start(r3)
	cpl	rr6, 65535
	cpl	rr8, rr10
	cpsd	@r14, @r15, r3, ule
	cpsdb	@r1, @r2, r3, ule
	cpsdr	@r2, @r3, r4, ule
	cpsdrb	@r3, @r4, r5, ule
	cpsi	@r4, @r5, r6, ule
	cpsib	@r5, @r6, r7, ule
	cpsir	@r6, @r7, r8, ule
	cpsirb	@r7, @r8, r9, ule
	dab	rl0
.L0:
	dbjnz	rh0, .L0
	dec	@r1, #15
	dec	start(r1), #14
	dec	start, #13
	dec	r2, #12
	decb	start(r2), #15
	decb	start, #14
	decb	rl0, #13
	di	vi,nvi
	div	rr2, @r14
	lddr	@r1, @r2, r3
	nop
	
	
