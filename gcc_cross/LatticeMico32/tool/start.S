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
	orhi     sp, r0, hi(stack)
	ori      sp, sp, lo(stack)
	calli    main
	nop
	.long	0xbadbeef0

	.global printf
printf:	
	b        ra

	.global puts
puts:	
	b        ra

	.global putchar
putchar:	
	b        ra

	.global	memcpy
memcpy:
	addi     sp, sp, -24
	sw       (sp+8), fp
	sw       (sp+4), ra
	or       fp, sp, r0
	addi     fp, fp, 24
	sw       (fp+-4), r1
	sw       (fp+-8), r2
	sw       (fp+-12), r3
	lw       r1, (fp+-4)
	sw       (fp+0), r1
	bi       .L13
.L14:
	lw       r2, (fp+-8)
	addi     r1, r2, 1
	sw       (fp+-8), r1
	lw       r1, (fp+-4)
	addi     r3, r1, 1
	sw       (fp+-4), r3
	lbu      r2, (r2+0)
	sb       (r1+0), r2
.L13:
	lw       r1, (fp+-12)
	addi     r2, r1, -1
	sw       (fp+-12), r2
	addi     r2, r0, 0
	bne    r1,r2,.L14
	lw       r1, (fp+0)
	lw       fp, (sp+8)
	lw       ra, (sp+4)
	addi     sp, sp, 24
	b        ra
	
_fstack:	
	nop
