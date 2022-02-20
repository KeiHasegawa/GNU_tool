	.text
start:
	abs	r0
	abs	a0
	add	r0, r1
	add	a0, r0
	add	a0, a1
	add2w	r0, r2
	add3	r0, r1, 5
	addac3	r0, r2, a0
	addac3	r0, a0, a1
	addac3s	r0, r2, a0
	addac3s r0, a0, a1
	addi	r0, 6
	and	r0, r1
	and3	r0, r1, 7
	bclri	r0, 8
	bl	func
	bl.s	func
	bl.l	func
	bnoti	r1, 9
	bra.s	start
	bra.l	start
	brf0f.s	start
	brf0f.l	start
	brf0t.s	start
	brf0t.l	start
	bseti	r2, 10
	btsti	r3, 11
	clrac	a0
	cmp	r0, r1
	cmp	a0, a1
	cmpeq	r0, r1
	cmpeq	a0, a1
	cmpeqi.s	r0, 5
	cmpeqi.l	r1, 13
	cmpi.s	r0, 6
	cmpi.l	r1, 14
	cmpu	r0, r1
	cmpui	r0, 15
	;;  cpfg ?? ?? OP_4E09
	.long	0x5e004e0f
	.long	0x5e004e09
	cpfg	f1, c || nop
	cpfg	f0, f1 || nop
	dbt || nop
	divs	r0, r1
	exef1f || nop
	exef1t || nop
	exefaf || nop
	exefat || nop
	exetaf || nop
	exetat || nop
	exp	r0, r2
	jl	r2
	jmp	r4
	.long	0x30000000
	ld	r1, @(4,r2)
	.long	0x30125e00
	ld	r1, @r2+
	ld	r1, @start
	ld2w	r0, @(4,r2)
	ld2w	r0, @r2+
	ld2w	r0, @r2-
	ld2w	r0, @start
	ldb	r0, @(6, r2)
	ldb	r0, @r2
	ldi.s	r0, 5
	ldi.l	r0, 17
	ldub	r0, @(4, r2)
	mac	a1, r0, r1
	macsu	a0, r1, r0
	macsu	a1, r1, r2
	max	r0, r1
	max	a0, a1
	min	r0, r1
	min	a0, a1
	msb	a0, r1, r2
	msbu	a0, r1, r2
	mul	r0, r1
	mulx	a0, r0, r1
	mulxsu	a0, r0, r1
	mulxu	a0, r0, r1
	mv	r0, r1
	mv2w	r0, r2
	mv2wfac	r0, a0
	mv2wtac	r0, a1
	mvac	a0, a1
	mvb	r0, r1
	mvf0f	r0, r1
	mvf0t	r1, r2
	mvfacg	r1, a1
	mvfachi	r0, a1
	mvfaclo	r1, a0
	mvfc	r0, cr0
	mvtacg	r0, a0
	mvtachi	r0, a1
	mvtaclo	r1, a0
	mvtaclo	r0, a1
	mvtc	r0, cr0
	mvub	r0, r1
	neg	r1
	neg	a0
	not	r1
	or	r0, r1
	or3	r0, r1, 3
	rac	r0, a0, 1
	rachi	r0, a0, 2
	rep	r0, 1
	repi	1, 2
	rtd
	rte
	sac	r2, a0
	sachi	r0, a1
	sadd	a0, a1
	setf0f	r0
	setf0t	r1
	slae	a0, r1
	sleep
	sll	r0, r1
	sll	a0, r1
	slli	r0, 3
	slli	r1, 3
	slx	r1
	sra	r1, r0
	sra	a0, r0
	srai	r1, 3
	srai	r0, 3
	srai	a0, 3
	srl	r0, r1
	srl	a0, r1
	srli	r1, 1
	srli	a1, 1
	srx	r1
	st	r0, @(4,r2)
	st	r0, @r2
	st	r0, @-sp
	st	r0, @r2+
	st	r0, @r0-
	st	r0, @start
	st2w	r0, @(4,r2)
	st2w	r0, @r2
	st2w	r0, @-sp
	st2w	r0, @r0+
	st2w	r0, @r0-
	st2w	r0, @start
	stb	r0, @(3,r2)
	stb	r0, @r1
	stop
	sub	r0, r1
	sub	a0, r1
	sub	a0, a1
	sub2w	r0, r2
	subac3	r0, r2, a0
	subac3	r0, a0, a1
	subac3s	r0, r2, a0
	subac3s	r0, a1, a0
	subi	r0, 5
	trap	1
	tst0i	r0, 1
	tst1i	r1, 1
	wait
	xor	r0, r1
	xor3	r0, r1, 3
	nop || nop
end:


func:
	nop || nop
	
