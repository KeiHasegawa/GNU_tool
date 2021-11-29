	.text
start:
	movw	$stack,sp
	bal (ra), _main@c
	nop
	.word	0x80f0

	.global	_printf
_printf:
	.word	0x80f1
	jump	 (ra)

	.global	_puts
_puts:
	.word	0x80f2
	jump	 (ra)

	.global	_putchar
_putchar:
	.word	0x80f3
	jump	 (ra)
	
	.globl	_memcpy
_memcpy:
.LFB13:
	push	$2, r13
.LCFI24:
	addd	$-16, (sp)
.LCFI25:
	movd	(sp), (r13)
.LCFI26:
	stord	(r3,r2), 4(r13)
	stord	(r5,r4), 8(r13)
	storw	r6, 12(r13)
	loadd	4(r13), (r1,r0)
	stord	(r1,r0), 0(r13)
	br	.L13
.L14:
	loadd	8(r13), (r3,r2)
	movd	$1, (r1,r0)
	addd	(r3,r2), (r1,r0)
	stord	(r1,r0), 8(r13)
	loadd	4(r13), (r1,r0)
	movd	$1, (r5,r4)
	addd	(r1,r0), (r5,r4)
	stord	(r5,r4), 4(r13)
	loadb	0(r3,r2), r2
	storb	r2, 0(r1,r0)
.L13:
	loadw	12(r13), r0
	movw	$-1, r1
	addw	r0, r1
	storw	r1, 12(r13)
	cmpw	$0, r0
	bne	.L14
	loadd	0(r13), (r1,r0)
	movd	(r13), (sp)
	addd	$16, (sp)
	pop	$2, r13
	jump	 (ra)


