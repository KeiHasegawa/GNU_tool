	.text
start:
	l.nop
	l.nop

	l.movhi	r17, ha(_bss_start)
	l.addi	r17, r17, lo(_bss_start)
	l.movhi	r19, ha(_bss_end)
	l.addi	r19, r19, lo(_bss_end)
.L1:
	l.sfeq	r17, r19
	l.bf	.L2
	l.nop
	l.sb	0(r17), r0
	l.addi	r17, r17, 1
	l.j	.L1
	l.nop
.L2:
	
	l.movhi	r1, ha(_stack)
	l.addi	r1, r1, lo(_stack)
	l.jal	main
	l.nop
	.word	0xbadbeef0

	.global	printf
printf:
	l.jr	r9
	l.nop

	.global	puts
puts:
	l.jr	r9
	l.nop

	.global	putchar
putchar:
	l.jr	r9
	l.nop

	.global	memcpy
memcpy:
	l.addi	r1, r1, -24
	l.sw	16(r1), r2
	l.addi	r2, r1, 24
	l.sw	20(r1), r9
	l.sw	-16(r2), r3
	l.sw	-20(r2), r4
	l.sw	-24(r2), r5
	l.lwz	r17, -16(r2)
	l.sw	-12(r2), r17
	l.j	.L13
	 l.nop

.L14:
	l.lwz	r17, -20(r2)
	l.addi	r19, r17, 1
	l.sw	-20(r2), r19
	l.lwz	r19, -16(r2)
	l.addi	r21, r19, 1
	l.sw	-16(r2), r21
	l.lbz	r17, 0(r17)
	l.ori	r21, r0, 24
	l.sll	r17, r17, r21
	l.sra	r17, r17, r21
	l.sb	0(r19), r17
.L13:
	l.lwz	r17, -24(r2)
	l.addi	r19, r17, -1
	l.sw	-24(r2), r19
	l.movhi	r19, hi(0)
	l.sfne	r17, r19
	l.bf	.L14
	 l.nop

	l.lwz	r17, -12(r2)
	l.or	r11, r17, r17
	l.lwz	r2, 16(r1)
	l.lwz	r9, 20(r1)
	l.addi	r1, r1, 24
	l.jr	r9
	 l.nop
