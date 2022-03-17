	.file	"sample.c"
	.text
	.section	.rodata
	.p2align 2
.LC0:
	.string	"%d + %d = %d\n"
	.text
	.p2align 2
	.globl f
	.type	f, @function
f:
	st	rp, @-r15
	enter	#12
	ldi:8 	#252, r1
	extsb	r1
	addn	fp, r1
	st    	r4, @r1
	ldi:8 	#248, r1
	extsb	r1
	addn	fp, r1
	st    	r5, @r1
	ldi:8 	#252, r2
	extsb	r2
	addn	fp, r2
	ldi:8 	#248, r1
	extsb	r1
	addn	fp, r1
	ld    	@r2, r2
	ld    	@r1, r1
	mov   	r2, r3
	addn	r1, r3
	ldi:8 	#248, r2
	extsb	r2
	addn	fp, r2
	ldi:8 	#252, r1
	extsb	r1
	addn	fp, r1
	mov   	r3, r7
	ld    	@r2, r6
	ld    	@r1, r5
	ldi:32	.LC0, r4
	ldi:32	printf, r1
	call	@r1
	nop
	leave
	ld	@r15+, rp
	ret
	.size	f, .-f
	.section	.rodata
	.p2align 2
.LC1:
	.string	"hello world"
	.text
	.p2align 2
	.globl g
	.type	g, @function
g:
	st	rp, @-r15
	enter	#4
	ldi:32	.LC1, r4
	ldi:32	puts, r1
	call	@r1
	nop
	ld	@r15+, fp
	ld	@r15+, rp
	ret
	.size	g, .-g
	.section	.rodata
	.p2align 2
.LC2:
	.string	"%f\n"
	.text
	.p2align 2
	.globl h
	.type	h, @function
h:
	st	rp, @-r15
	enter	#12
	ldi:8 	#248, r1
	extsb	r1
	addn	fp, r1
	st    	r4, @r1
	mov   	r1, r0
	addn	4, r0
	st    	r5, @r0
	ldi:8 	#10, r4
	ldi:32	putchar, r1
	call	@r1
	ldi:8 	#248, r1
	extsb	r1
	addn	fp, r1
	mov   	r1, r6
	ld    	@r1, r5
	addn	4, r6
	ld    	@r6, r6
	ldi:32	.LC2, r4
	ldi:32	printf, r1
	call	@r1
	nop
	leave
	ld	@r15+, rp
	ret
	.size	h, .-h
	.section	.rodata
	.p2align 2
.LC3:
	.string	"%lld\n"
	.text
	.p2align 2
	.globl ff
	.type	ff, @function
ff:
	st	rp, @-r15
	enter	#12
	ldi:8 	#248, r1
	extsb	r1
	addn	fp, r1
	st    	r4, @r1
	mov   	r1, r0
	addn	4, r0
	st    	r5, @r0
	ldi:8 	#248, r1
	extsb	r1
	addn	fp, r1
	mov   	r1, r6
	ld    	@r1, r5
	addn	4, r6
	ld    	@r6, r6
	ldi:32	.LC3, r4
	ldi:32	printf, r1
	call	@r1
	nop
	leave
	ld	@r15+, rp
	ret
	.size	ff, .-ff
	.section	.rodata
	.p2align 2
.LC4:
	.string	"%s %d %f\n"
	.text
	.p2align 2
	.globl gg
	.type	gg, @function
gg:
	st	rp, @-r15
	enter	#24
	ldi:8 	#252, r1
	extsb	r1
	addn	fp, r1
	st    	r4, @r1
	ldi:8 	#248, r1
	extsb	r1
	addn	fp, r1
	st    	r5, @r1
	ldi:8 	#240, r1
	extsb	r1
	addn	fp, r1
	st    	r6, @r1
	mov   	r1, r0
	addn	4, r0
	st    	r7, @r0
	ldi:8 	#240, r1
	extsb	r1
	addn	fp, r1
	ldi:8 	#248, r3
	extsb	r3
	addn	fp, r3
	ldi:8 	#252, r2
	extsb	r2
	addn	fp, r2
	mov   	r1, r4
	addn	4, r4
	ld    	@r4, r4
	st    	r4, @sp
	ld    	@r1, r7
	ld    	@r3, r6
	ld    	@r2, r5
	ldi:32	.LC4, r4
	ldi:32	printf, r1
	call	@r1
	nop
	leave
	ld	@r15+, rp
	ret
	.size	gg, .-gg
	.section	.rodata
	.p2align 2
.LC5:
	.string	"%Lf\n"
	.text
	.p2align 2
	.globl hh
	.type	hh, @function
hh:
	st	rp, @-r15
	enter	#12
	ldi:8 	#248, r1
	extsb	r1
	addn	fp, r1
	st    	r4, @r1
	mov   	r1, r0
	addn	4, r0
	st    	r5, @r0
	ldi:8 	#248, r1
	extsb	r1
	addn	fp, r1
	mov   	r1, r6
	ld    	@r1, r5
	addn	4, r6
	ld    	@r6, r6
	ldi:32	.LC5, r4
	ldi:32	printf, r1
	call	@r1
	nop
	leave
	ld	@r15+, rp
	ret
	.size	hh, .-hh
	.section	.rodata
	.p2align 2
.LC6:
	.string	"%f %f %f\n"
	.text
	.p2align 2
	.globl f2
	.type	f2, @function
f2:
	st	rp, @-r15
	enter	#32
	ldi:8 	#248, r1
	extsb	r1
	addn	fp, r1
	st    	r4, @r1
	mov   	r1, r0
	addn	4, r0
	st    	r5, @r0
	ldi:8 	#240, r1
	extsb	r1
	addn	fp, r1
	st    	r6, @r1
	mov   	r1, r0
	addn	4, r0
	st    	r7, @r0
	ldi:8 	#240, r1
	extsb	r1
	addn	fp, r1
	ldi:8 	#248, r2
	extsb	r2
	addn	fp, r2
	ldi:8 	#4, r3
	addn	sp, r3
	ldi:8	#8, r6  
	addn	fp, r6
	mov   	r6, r5
	ld    	@r6, r4
	addn	4, r5
	ld    	@r5, r5
	st    	r4, @r3
	mov   	r3, r0
	addn	4, r0
	st    	r5, @r0
	mov   	r1, r3
	addn	4, r3
	ld    	@r3, r3
	st    	r3, @sp
	ld    	@r1, r7
	mov   	r2, r6
	ld    	@r2, r5
	addn	4, r6
	ld    	@r6, r6
	ldi:32	.LC6, r4
	ldi:32	printf, r1
	call	@r1
	nop
	leave
	ld	@r15+, rp
	ret
	.size	f2, .-f2
	.section	.rodata
	.p2align 2
.LC7:
	.string	"%lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld\n"
	.text
	.p2align 2
	.globl g2
	.type	g2, @function
g2:
	st	rp, @-r15
	enter	#104
	ldi:8 	#248, r1
	extsb	r1
	addn	fp, r1
	st    	r4, @r1
	mov   	r1, r0
	addn	4, r0
	st    	r5, @r0
	ldi:8 	#240, r1
	extsb	r1
	addn	fp, r1
	st    	r6, @r1
	mov   	r1, r0
	addn	4, r0
	st    	r7, @r0
	ldi:8 	#240, r1
	extsb	r1
	addn	fp, r1
	ldi:8 	#248, r2
	extsb	r2
	addn	fp, r2
	ldi:8 	#72, r4
	ldi:8	#80, r4  
	addn	fp, r4
	ldi:8 	#76, r3
	addn	sp, r3
	mov   	r4, r5
	ld    	@r4, r4
	addn	4, r5
	ld    	@r5, r5
	st    	r4, @r3
	mov   	r3, r0
	addn	4, r0
	st    	r5, @r0
	ldi:8 	#64, r4
	ldi:8	#72, r4  
	addn	fp, r4
	ldi:8 	#68, r3
	addn	sp, r3
	mov   	r4, r5
	ld    	@r4, r4
	addn	4, r5
	ld    	@r5, r5
	st    	r4, @r3
	mov   	r3, r0
	addn	4, r0
	st    	r5, @r0
	ldi:8 	#56, r4
	ldi:8	#64, r4  
	addn	fp, r4
	ldi:8 	#60, r3
	addn	sp, r3
	mov   	r4, r5
	ld    	@r4, r4
	addn	4, r5
	ld    	@r5, r5
	st    	r4, @r3
	mov   	r3, r0
	addn	4, r0
	st    	r5, @r0
	ldi:8 	#48, r4
	ldi:8	#56, r4  
	addn	fp, r4
	ldi:8 	#52, r3
	addn	sp, r3
	mov   	r4, r5
	ld    	@r4, r4
	addn	4, r5
	ld    	@r5, r5
	st    	r4, @r3
	mov   	r3, r0
	addn	4, r0
	st    	r5, @r0
	ldi:8 	#40, r4
	ldi:8	#48, r4  
	addn	fp, r4
	ldi:8 	#44, r3
	addn	sp, r3
	mov   	r4, r5
	ld    	@r4, r4
	addn	4, r5
	ld    	@r5, r5
	st    	r4, @r3
	mov   	r3, r0
	addn	4, r0
	st    	r5, @r0
	ldi:8 	#32, r4
	ldi:8	#40, r4  
	addn	fp, r4
	ldi:8 	#36, r3
	addn	sp, r3
	mov   	r4, r5
	ld    	@r4, r4
	addn	4, r5
	ld    	@r5, r5
	st    	r4, @r3
	mov   	r3, r0
	addn	4, r0
	st    	r5, @r0
	ldi:8 	#24, r4
	ldi:8	#32, r4  
	addn	fp, r4
	ldi:8 	#28, r3
	addn	sp, r3
	mov   	r4, r5
	ld    	@r4, r4
	addn	4, r5
	ld    	@r5, r5
	st    	r4, @r3
	mov   	r3, r0
	addn	4, r0
	st    	r5, @r0
	ldi:8 	#16, r4
	ldi:8	#24, r4  
	addn	fp, r4
	ldi:8 	#20, r3
	addn	sp, r3
	mov   	r4, r5
	ld    	@r4, r4
	addn	4, r5
	ld    	@r5, r5
	st    	r4, @r3
	mov   	r3, r0
	addn	4, r0
	st    	r5, @r0
	ldi:8 	#8, r4
	ldi:8	#16, r4  
	addn	fp, r4
	ldi:8 	#12, r3
	addn	sp, r3
	mov   	r4, r5
	ld    	@r4, r4
	addn	4, r5
	ld    	@r5, r5
	st    	r4, @r3
	mov   	r3, r0
	addn	4, r0
	st    	r5, @r0
	ldi:8 	#4, r3
	addn	sp, r3
	ldi:8	#8, r6  
	addn	fp, r6
	mov   	r6, r5
	ld    	@r6, r4
	addn	4, r5
	ld    	@r5, r5
	st    	r4, @r3
	mov   	r3, r0
	addn	4, r0
	st    	r5, @r0
	mov   	r1, r3
	addn	4, r3
	ld    	@r3, r3
	st    	r3, @sp
	ld    	@r1, r7
	mov   	r2, r6
	ld    	@r2, r5
	addn	4, r6
	ld    	@r6, r6
	ldi:32	.LC7, r4
	ldi:32	printf, r1
	call	@r1
	nop
	leave
	ld	@r15+, rp
	ret
	.size	g2, .-g2
	.section	.rodata
	.p2align 2
.LC8:
	.string	"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n"
	.text
	.p2align 2
	.globl h2
	.type	h2, @function
h2:
	st	rp, @-r15
	enter	#104
	ldi:8 	#252, r1
	extsb	r1
	addn	fp, r1
	st    	r4, @r1
	ldi:8 	#248, r1
	extsb	r1
	addn	fp, r1
	st    	r5, @r1
	ldi:8 	#244, r1
	extsb	r1
	addn	fp, r1
	st    	r6, @r1
	ldi:8 	#240, r1
	extsb	r1
	addn	fp, r1
	st    	r7, @r1
	ldi:8 	#244, r3
	extsb	r3
	addn	fp, r3
	ldi:8 	#248, r2
	extsb	r2
	addn	fp, r2
	ldi:8 	#252, r1
	extsb	r1
	addn	fp, r1
	ldi:8 	#76, r5
	ldi:8	#84, r5  
	addn	fp, r5
	ldi:8 	#80, r4
	addn	sp, r4
	ld    	@r5, r5
	st    	r5, @r4
	ldi:8 	#72, r5
	ldi:8	#80, r5  
	addn	fp, r5
	ldi:8 	#76, r4
	addn	sp, r4
	ld    	@r5, r5
	st    	r5, @r4
	ldi:8 	#68, r5
	ldi:8	#76, r5  
	addn	fp, r5
	ldi:8 	#72, r4
	addn	sp, r4
	ld    	@r5, r5
	st    	r5, @r4
	ldi:8 	#64, r5
	ldi:8	#72, r5  
	addn	fp, r5
	ldi:8 	#68, r4
	addn	sp, r4
	ld    	@r5, r5
	st    	r5, @r4
	ldi:8 	#60, r5
	ldi:8	#68, r5  
	addn	fp, r5
	ldi:8 	#64, r4
	addn	sp, r4
	ld    	@r5, r5
	st    	r5, @r4
	ldi:8 	#56, r5
	ldi:8	#64, r5  
	addn	fp, r5
	ldi:8 	#60, r4
	addn	sp, r4
	ld    	@r5, r5
	st    	r5, @r4
	ldi:8 	#52, r5
	ldi:8	#60, r5  
	addn	fp, r5
	ldi:8 	#56, r4
	addn	sp, r4
	ld    	@r5, r5
	st    	r5, @r4
	ldi:8 	#48, r5
	ldi:8	#56, r5  
	addn	fp, r5
	ldi:8 	#52, r4
	addn	sp, r4
	ld    	@r5, r5
	st    	r5, @r4
	ldi:8 	#44, r5
	ldi:8	#52, r5  
	addn	fp, r5
	ldi:8 	#48, r4
	addn	sp, r4
	ld    	@r5, r5
	st    	r5, @r4
	ldi:8 	#40, r5
	ldi:8	#48, r5  
	addn	fp, r5
	ldi:8 	#44, r4
	addn	sp, r4
	ld    	@r5, r5
	st    	r5, @r4
	ldi:8 	#36, r5
	ldi:8	#44, r5  
	addn	fp, r5
	ldi:8 	#40, r4
	addn	sp, r4
	ld    	@r5, r5
	st    	r5, @r4
	ldi:8 	#32, r5
	ldi:8	#40, r5  
	addn	fp, r5
	ldi:8 	#36, r4
	addn	sp, r4
	ld    	@r5, r5
	st    	r5, @r4
	ldi:8 	#28, r5
	ldi:8	#36, r5  
	addn	fp, r5
	ldi:8 	#32, r4
	addn	sp, r4
	ld    	@r5, r5
	st    	r5, @r4
	ldi:8 	#24, r5
	ldi:8	#32, r5  
	addn	fp, r5
	ldi:8 	#28, r4
	addn	sp, r4
	ld    	@r5, r5
	st    	r5, @r4
	ldi:8 	#20, r5
	ldi:8	#28, r5  
	addn	fp, r5
	ldi:8 	#24, r4
	addn	sp, r4
	ld    	@r5, r5
	st    	r5, @r4
	ldi:8 	#16, r5
	ldi:8	#24, r5  
	addn	fp, r5
	ldi:8 	#20, r4
	addn	sp, r4
	ld    	@r5, r5
	st    	r5, @r4
	ldi:8 	#12, r5
	ldi:8	#20, r5  
	addn	fp, r5
	ldi:8 	#16, r4
	addn	sp, r4
	ld    	@r5, r5
	st    	r5, @r4
	ldi:8 	#8, r5
	ldi:8	#16, r5  
	addn	fp, r5
	ldi:8 	#12, r4
	addn	sp, r4
	ld    	@r5, r5
	st    	r5, @r4
	ldi:8 	#4, r5
	ldi:8	#12, r5  
	addn	fp, r5
	ldi:8 	#8, r4
	addn	sp, r4
	ld    	@r5, r5
	st    	r5, @r4
	ldi:8 	#4, r4
	addn	sp, r4
	ld    	@(r14, #8), r5
	st    	r5, @r4
	ldi:8 	#240, r4
	extsb	r4
	addn	fp, r4
	ld    	@r4, r4
	st    	r4, @sp
	ld    	@r3, r7
	ld    	@r2, r6
	ld    	@r1, r5
	ldi:32	.LC8, r4
	ldi:32	printf, r1
	call	@r1
	nop
	leave
	ld	@r15+, rp
	ret
	.size	h2, .-h2
	.globl test_f3
	.section .bss
	.p2align 2
	.type	test_f3, @object
	.size	test_f3, 4
test_f3:
	.zero	4
	.section	.rodata
	.p2align 2
.LC9:
	.string	"%d\n"
	.text
	.p2align 2
	.globl f3
	.type	f3, @function
f3:
	st	rp, @-r15
	enter	#8
	ldi:8 	#252, r1
	extsb	r1
	addn	fp, r1
	st    	r4, @r1
	ldi:32	test_f3, r2
	ldi:8 	#252, r1
	extsb	r1
	addn	fp, r1
	ld    	@r1, r1
	st    	r1, @r2
	ldi:32	test_f3, r1
	ld    	@r1, r1
	mov   	r1, r5
	ldi:32	.LC9, r4
	ldi:32	printf, r1
	call	@r1
	nop
	leave
	ld	@r15+, rp
	ret
	.size	f3, .-f3
	.globl test_g3
	.section .bss
	.p2align 2
	.type	test_g3, @object
	.size	test_g3, 4
test_g3:
	.zero	4
	.section	.rodata
	.p2align 2
.LC10:
	.string	"%x\n"
	.text
	.p2align 2
	.globl g3
	.type	g3, @function
g3:
	st	rp, @-r15
	enter	#4
	ldi:32	test_g3, r1
	ld    	@r1, r1
	mov   	r1, r5
	ldi:32	.LC10, r4
	ldi:32	printf, r1
	call	@r1
	nop
	ld	@r15+, fp
	ld	@r15+, rp
	ret
	.size	g3, .-g3
	.globl test_h3
	.data
	.p2align 2
	.type	test_h3, @object
	.size	test_h3, 4
test_h3:
	.word	456
	.text
	.p2align 2
	.globl h3
	.type	h3, @function
h3:
	st	rp, @-r15
	enter	#4
	ldi:32	test_h3, r1
	ld    	@r1, r1
	mov   	r1, r5
	ldi:32	.LC9, r4
	ldi:32	printf, r1
	call	@r1
	nop
	ld	@r15+, fp
	ld	@r15+, rp
	ret
	.size	h3, .-h3
	.p2align 2
	.globl f4
	.type	f4, @function
f4:
	enter	#20
	ldi:8 	#248, r1
	extsb	r1
	addn	fp, r1
	st    	r4, @r1
	mov   	r1, r0
	addn	4, r0
	st    	r5, @r0
	ldi:8 	#240, r1
	extsb	r1
	addn	fp, r1
	st    	r6, @r1
	mov   	r1, r0
	addn	4, r0
	st    	r7, @r0
	ldi:8 	#248, r2
	extsb	r2
	addn	fp, r2
	ldi:8 	#240, r1
	extsb	r1
	addn	fp, r1
	mov   	r2, r5
	ld    	@r2, r4
	addn	4, r5
	ld    	@r5, r5
	mov   	r1, r7
	ld    	@r1, r6
	addn	4, r7
	ld    	@r7, r7
	mov   	r5, r3
	addn	r7, r3
	ldi:8 	#1, r1
	cmp	r5, r3
	bc	.L14
	ldi:8 	#0, r1
.L14:
	mov   	r4, r2
	addn	r6, r2
	addn	r2, r1
	mov   	r1, r2
	mov   	r2, r4
	mov   	r3, r5
	ldi:8	#4, r1  
	addn	fp, r1
	mov   	r1, r7
	ld    	@r1, r6
	addn	4, r7
	ld    	@r7, r7
	mov   	r5, r3
	addn	r7, r3
	ldi:8 	#1, r1
	cmp	r5, r3
	bc	.L15
	ldi:8 	#0, r1
.L15:
	mov   	r4, r2
	addn	r6, r2
	addn	r2, r1
	mov   	r1, r2
	mov   	r2, r4
	mov   	r3, r5
	ldi:8 	#8, r1
	ldi:8	#12, r1  
	addn	fp, r1
	mov   	r1, r7
	ld    	@r1, r6
	addn	4, r7
	ld    	@r7, r7
	mov   	r5, r3
	addn	r7, r3
	ldi:8 	#1, r1
	cmp	r5, r3
	bc	.L16
	ldi:8 	#0, r1
.L16:
	mov   	r4, r2
	addn	r6, r2
	addn	r2, r1
	mov   	r1, r2
	mov   	r2, r4
	mov   	r3, r5
	ldi:8 	#16, r1
	ldi:8	#20, r1  
	addn	fp, r1
	mov   	r1, r7
	ld    	@r1, r6
	addn	4, r7
	ld    	@r7, r7
	mov   	r5, r3
	addn	r7, r3
	ldi:8 	#1, r1
	cmp	r5, r3
	bc	.L17
	ldi:8 	#0, r1
.L17:
	mov   	r4, r2
	addn	r6, r2
	addn	r2, r1
	mov   	r1, r2
	mov   	r2, r4
	mov   	r3, r5
	ldi:8 	#24, r1
	ldi:8	#28, r1  
	addn	fp, r1
	mov   	r1, r7
	ld    	@r1, r6
	addn	4, r7
	ld    	@r7, r7
	mov   	r5, r3
	addn	r7, r3
	ldi:8 	#1, r1
	cmp	r5, r3
	bc	.L18
	ldi:8 	#0, r1
.L18:
	mov   	r4, r2
	addn	r6, r2
	addn	r2, r1
	mov   	r1, r2
	mov   	r2, r4
	mov   	r3, r5
	ldi:8 	#32, r1
	ldi:8	#36, r1  
	addn	fp, r1
	mov   	r1, r7
	ld    	@r1, r6
	addn	4, r7
	ld    	@r7, r7
	mov   	r5, r3
	addn	r7, r3
	ldi:8 	#1, r1
	cmp	r5, r3
	bc	.L19
	ldi:8 	#0, r1
.L19:
	mov   	r4, r2
	addn	r6, r2
	addn	r2, r1
	mov   	r1, r2
	mov   	r2, r4
	mov   	r3, r5
	ldi:8 	#40, r1
	ldi:8	#44, r1  
	addn	fp, r1
	mov   	r1, r7
	ld    	@r1, r6
	addn	4, r7
	ld    	@r7, r7
	mov   	r5, r3
	addn	r7, r3
	ldi:8 	#1, r1
	cmp	r5, r3
	bc	.L20
	ldi:8 	#0, r1
.L20:
	mov   	r4, r2
	addn	r6, r2
	addn	r2, r1
	mov   	r1, r2
	mov   	r2, r4
	mov   	r3, r5
	ldi:8 	#48, r1
	ldi:8	#52, r1  
	addn	fp, r1
	mov   	r1, r7
	ld    	@r1, r6
	addn	4, r7
	ld    	@r7, r7
	mov   	r5, r3
	addn	r7, r3
	ldi:8 	#1, r1
	cmp	r5, r3
	bc	.L21
	ldi:8 	#0, r1
.L21:
	mov   	r4, r2
	addn	r6, r2
	addn	r2, r1
	mov   	r1, r2
	mov   	r2, r4
	mov   	r3, r5
	ldi:8 	#56, r1
	ldi:8	#60, r1  
	addn	fp, r1
	mov   	r1, r7
	ld    	@r1, r6
	addn	4, r7
	ld    	@r7, r7
	mov   	r5, r3
	addn	r7, r3
	ldi:8 	#1, r1
	cmp	r5, r3
	bc	.L22
	ldi:8 	#0, r1
.L22:
	mov   	r4, r2
	addn	r6, r2
	addn	r2, r1
	mov   	r1, r2
	mov   	r2, r4
	mov   	r3, r5
	ldi:8 	#64, r1
	ldi:8	#68, r1  
	addn	fp, r1
	mov   	r1, r7
	ld    	@r1, r6
	addn	4, r7
	ld    	@r7, r7
	mov   	r5, r3
	addn	r7, r3
	ldi:8 	#1, r1
	cmp	r5, r3
	bc	.L23
	ldi:8 	#0, r1
.L23:
	mov   	r4, r2
	addn	r6, r2
	addn	r2, r1
	mov   	r1, r2
	mov   	r2, r4
	mov   	r3, r5
	ldi:8 	#72, r1
	ldi:8	#76, r1  
	addn	fp, r1
	mov   	r1, r7
	ld    	@r1, r6
	addn	4, r7
	ld    	@r7, r7
	mov   	r5, r3
	addn	r7, r3
	ldi:8 	#1, r1
	cmp	r5, r3
	bc	.L24
	ldi:8 	#0, r1
.L24:
	mov   	r4, r2
	addn	r6, r2
	addn	r2, r1
	mov   	r1, r2
	mov   	r2, r4
	mov   	r3, r5
	ldi:8 	#80, r1
	ldi:8	#84, r1  
	addn	fp, r1
	mov   	r1, r7
	ld    	@r1, r6
	addn	4, r7
	ld    	@r7, r7
	mov   	r5, r3
	addn	r7, r3
	ldi:8 	#1, r1
	cmp	r5, r3
	bc	.L25
	ldi:8 	#0, r1
.L25:
	mov   	r4, r2
	addn	r6, r2
	addn	r2, r1
	mov   	r1, r2
	mov   	r2, r4
	mov   	r3, r5
	ldi:8 	#88, r1
	ldi:8	#92, r1  
	addn	fp, r1
	mov   	r1, r7
	ld    	@r1, r6
	addn	4, r7
	ld    	@r7, r7
	mov   	r5, r3
	addn	r7, r3
	ldi:8 	#1, r1
	cmp	r5, r3
	bc	.L26
	ldi:8 	#0, r1
.L26:
	mov   	r4, r2
	addn	r6, r2
	addn	r2, r1
	mov   	r1, r2
	mov   	r2, r4
	mov   	r3, r5
	ldi:8 	#96, r1
	ldi:8	#100, r1  
	addn	fp, r1
	mov   	r1, r7
	ld    	@r1, r6
	addn	4, r7
	ld    	@r7, r7
	mov   	r5, r3
	addn	r7, r3
	ldi:8 	#1, r1
	cmp	r5, r3
	bc	.L27
	ldi:8 	#0, r1
.L27:
	mov   	r4, r2
	addn	r6, r2
	addn	r2, r1
	mov   	r1, r2
	mov   	r2, r4
	mov   	r3, r5
	ldi:8 	#104, r1
	ldi:8	#108, r1  
	addn	fp, r1
	mov   	r1, r7
	ld    	@r1, r6
	addn	4, r7
	ld    	@r7, r7
	mov   	r5, r3
	addn	r7, r3
	ldi:8 	#1, r1
	cmp	r5, r3
	bc	.L28
	ldi:8 	#0, r1
.L28:
	mov   	r4, r2
	addn	r6, r2
	addn	r2, r1
	mov   	r1, r2
	mov   	r2, r4
	mov   	r3, r5
	ldi:8 	#112, r1
	ldi:8	#116, r1  
	addn	fp, r1
	mov   	r1, r7
	ld    	@r1, r6
	addn	4, r7
	ld    	@r7, r7
	mov   	r5, r3
	addn	r7, r3
	ldi:8 	#1, r1
	cmp	r5, r3
	bc	.L29
	ldi:8 	#0, r1
.L29:
	mov   	r4, r2
	addn	r6, r2
	addn	r2, r1
	mov   	r1, r2
	mov   	r2, r4
	mov   	r3, r5
	ldi:8 	#120, r1
	ldi:8	#124, r1  
	addn	fp, r1
	mov   	r1, r7
	ld    	@r1, r6
	addn	4, r7
	ld    	@r7, r7
	mov   	r5, r3
	addn	r7, r3
	ldi:8 	#1, r1
	cmp	r5, r3
	bc	.L30
	ldi:8 	#0, r1
.L30:
	mov   	r4, r2
	addn	r6, r2
	addn	r2, r1
	mov   	r1, r2
	mov   	r2, r4
	mov   	r3, r5
	ldi:8 	#128, r1
	ldi:8	#132, r1  
	addn	fp, r1
	mov   	r1, r7
	ld    	@r1, r6
	addn	4, r7
	ld    	@r7, r7
	mov   	r5, r3
	addn	r7, r3
	ldi:8 	#1, r1
	cmp	r5, r3
	bc	.L31
	ldi:8 	#0, r1
.L31:
	mov   	r4, r2
	addn	r6, r2
	addn	r2, r1
	mov   	r1, r2
	mov   	r2, r4
	mov   	r3, r5
	ldi:8 	#136, r1
	ldi:8	#140, r1  
	addn	fp, r1
	mov   	r1, r7
	ld    	@r1, r6
	addn	4, r7
	ld    	@r7, r7
	mov   	r5, r3
	addn	r7, r3
	ldi:8 	#1, r1
	cmp	r5, r3
	bc	.L32
	ldi:8 	#0, r1
.L32:
	mov   	r4, r2
	addn	r6, r2
	addn	r2, r1
	mov   	r1, r2
	mov   	r2, r4
	mov   	r3, r5
	leave
	ret
	.size	f4, .-f4
	.p2align 2
	.globl main
	.type	main, @function
main:
	st	rp, @-r15
	enter	#164
	ldi:8 	#6, r5
	ldi:8 	#5, r4
	ldi:32	f, r1
	call	@r1
	ldi:32	g, r1
	call	@r1
	ldi:8 	#10, r4
	ldi:32	putchar, r1
	call	@r1
	ldi:32	#1072693248, r4
	ldi:8 	#0, r5
	ldi:32	h, r1
	call	@r1
	ldi:8 	#0, r4
	ldi:8 	#9, r5
	ldi:32	ff, r1
	call	@r1
	ldi:8 	#243, r1
	extsb	r1
	addn	fp, r1
	ldi:8	#104, r2
	stb  	r2, @r1
	mov   	r1, r2
	addn	1, r2
	ldi:8	#97, r3
	stb  	r3, @r2
	mov   	r1, r2
	addn	2, r2
	ldi:8	#115, r3
	stb  	r3, @r2
	mov   	r1, r2
	addn	3, r2
	ldi:8	#101, r3
	stb  	r3, @r2
	mov   	r1, r2
	addn	4, r2
	ldi:8	#103, r3
	stb  	r3, @r2
	mov   	r1, r2
	addn	5, r2
	ldi:8	#97, r3
	stb  	r3, @r2
	mov   	r1, r2
	addn	6, r2
	ldi:8	#119, r3
	stb  	r3, @r2
	mov   	r1, r2
	addn	7, r2
	ldi:8	#97, r3
	stb  	r3, @r2
	mov   	r1, r2
	addn	8, r2
	ldi:8	#32, r3
	stb  	r3, @r2
	mov   	r1, r2
	addn	9, r2
	ldi:8	#107, r3
	stb  	r3, @r2
	mov   	r1, r2
	addn	10, r2
	ldi:8	#101, r3
	stb  	r3, @r2
	mov   	r1, r2
	addn	11, r2
	ldi:8	#105, r3
	stb  	r3, @r2
	addn	12, r1
	ldi:8	#0, r2
	stb  	r2, @r1
	ldi:8 	#243, r1
	extsb	r1
	addn	fp, r1
	ldi:32	#1075314688, r6
	ldi:8 	#0, r7
	ldi:8 	#5, r5
	mov   	r1, r4
	ldi:32	gg, r1
	call	@r1
	ldi:32	#1074266112, r4
	ldi:8 	#0, r5
	ldi:32	hh, r1
	call	@r1
	ldi:32	#1074266112, r2
	ldi:8 	#0, r3
	st    	r2, @sp
	st    	r3, @(r15, #4)
	ldi:8 	#1, r6
	lsl2	14, r6
	ldi:8 	#0, r7
	ldi:32	#1072693248, r4
	ldi:8 	#0, r5
	ldi:32	f2, r1
	call	@r1
	ldi:8 	#72, r1
	addn	sp, r1
	ldi:8 	#0, r2
	ldi:8 	#12, r3
	st    	r2, @r1
	mov   	r1, r0
	addn	4, r0
	st    	r3, @r0
	ldi:8 	#64, r1
	addn	sp, r1
	ldi:8 	#0, r2
	ldi:8 	#11, r3
	st    	r2, @r1
	mov   	r1, r0
	addn	4, r0
	st    	r3, @r0
	ldi:8 	#56, r1
	addn	sp, r1
	ldi:8 	#0, r2
	ldi:8 	#10, r3
	st    	r2, @r1
	mov   	r1, r0
	addn	4, r0
	st    	r3, @r0
	ldi:8 	#48, r1
	addn	sp, r1
	ldi:8 	#0, r2
	ldi:8 	#9, r3
	st    	r2, @r1
	mov   	r1, r0
	addn	4, r0
	st    	r3, @r0
	ldi:8 	#40, r1
	addn	sp, r1
	ldi:8 	#0, r2
	ldi:8 	#8, r3
	st    	r2, @r1
	mov   	r1, r0
	addn	4, r0
	st    	r3, @r0
	ldi:8 	#32, r1
	addn	sp, r1
	ldi:8 	#0, r2
	ldi:8 	#7, r3
	st    	r2, @r1
	mov   	r1, r0
	addn	4, r0
	st    	r3, @r0
	ldi:8 	#24, r1
	addn	sp, r1
	ldi:8 	#0, r2
	ldi:8 	#6, r3
	st    	r2, @r1
	mov   	r1, r0
	addn	4, r0
	st    	r3, @r0
	ldi:8 	#16, r1
	addn	sp, r1
	ldi:8 	#0, r2
	ldi:8 	#5, r3
	st    	r2, @r1
	mov   	r1, r0
	addn	4, r0
	st    	r3, @r0
	ldi:8 	#8, r1
	addn	sp, r1
	ldi:8 	#0, r2
	ldi:8 	#4, r3
	st    	r2, @r1
	mov   	r1, r0
	addn	4, r0
	st    	r3, @r0
	ldi:8 	#0, r2
	ldi:8 	#3, r3
	st    	r2, @sp
	st    	r3, @(r15, #4)
	ldi:8 	#0, r6
	ldi:8 	#2, r7
	ldi:8 	#0, r4
	ldi:8 	#1, r5
	ldi:32	g2, r1
	call	@r1
	ldi:8 	#76, r1
	addn	sp, r1
	ldi:8 	#24, r2
	st    	r2, @r1
	ldi:8 	#72, r1
	addn	sp, r1
	ldi:8 	#23, r2
	st    	r2, @r1
	ldi:8 	#68, r1
	addn	sp, r1
	ldi:8 	#22, r2
	st    	r2, @r1
	ldi:8 	#64, r1
	addn	sp, r1
	ldi:8 	#21, r2
	st    	r2, @r1
	ldi:8 	#60, r1
	addn	sp, r1
	ldi:8 	#20, r2
	st    	r2, @r1
	ldi:8 	#56, r1
	addn	sp, r1
	ldi:8 	#19, r2
	st    	r2, @r1
	ldi:8 	#52, r1
	addn	sp, r1
	ldi:8 	#18, r2
	st    	r2, @r1
	ldi:8 	#48, r1
	addn	sp, r1
	ldi:8 	#17, r2
	st    	r2, @r1
	ldi:8 	#44, r1
	addn	sp, r1
	ldi:8 	#16, r2
	st    	r2, @r1
	ldi:8 	#40, r1
	addn	sp, r1
	ldi:8 	#15, r2
	st    	r2, @r1
	ldi:8 	#36, r1
	addn	sp, r1
	ldi:8 	#14, r2
	st    	r2, @r1
	ldi:8 	#32, r1
	addn	sp, r1
	ldi:8 	#13, r2
	st    	r2, @r1
	ldi:8 	#28, r1
	addn	sp, r1
	ldi:8 	#12, r2
	st    	r2, @r1
	ldi:8 	#24, r1
	addn	sp, r1
	ldi:8 	#11, r2
	st    	r2, @r1
	ldi:8 	#20, r1
	addn	sp, r1
	ldi:8 	#10, r2
	st    	r2, @r1
	ldi:8 	#16, r1
	addn	sp, r1
	ldi:8 	#9, r2
	st    	r2, @r1
	ldi:8 	#12, r1
	addn	sp, r1
	ldi:8 	#8, r2
	st    	r2, @r1
	ldi:8 	#8, r1
	addn	sp, r1
	ldi:8 	#7, r2
	st    	r2, @r1
	ldi:8 	#4, r1
	addn	sp, r1
	ldi:8 	#6, r2
	st    	r2, @r1
	ldi:8 	#5, r1
	st    	r1, @sp
	ldi:8 	#4, r7
	ldi:8 	#3, r6
	ldi:8 	#2, r5
	ldi:8 	#1, r4
	ldi:32	h2, r1
	call	@r1
	ldi:8 	#123, r4
	ldi:32	f3, r1
	call	@r1
	ldi:32	g3, r1
	call	@r1
	ldi:32	h3, r1
	call	@r1
	ldi:8 	#136, r1
	addn	sp, r1
	ldi:8 	#0, r2
	ldi:8 	#21, r3
	st    	r2, @r1
	mov   	r1, r0
	addn	4, r0
	st    	r3, @r0
	ldi:8 	#128, r1
	addn	sp, r1
	ldi:8 	#0, r2
	ldi:8 	#20, r3
	st    	r2, @r1
	mov   	r1, r0
	addn	4, r0
	st    	r3, @r0
	ldi:8 	#120, r1
	addn	sp, r1
	ldi:8 	#0, r2
	ldi:8 	#19, r3
	st    	r2, @r1
	mov   	r1, r0
	addn	4, r0
	st    	r3, @r0
	ldi:8 	#112, r1
	addn	sp, r1
	ldi:8 	#0, r2
	ldi:8 	#18, r3
	st    	r2, @r1
	mov   	r1, r0
	addn	4, r0
	st    	r3, @r0
	ldi:8 	#104, r1
	addn	sp, r1
	ldi:8 	#0, r2
	ldi:8 	#17, r3
	st    	r2, @r1
	mov   	r1, r0
	addn	4, r0
	st    	r3, @r0
	ldi:8 	#96, r1
	addn	sp, r1
	ldi:8 	#0, r2
	ldi:8 	#16, r3
	st    	r2, @r1
	mov   	r1, r0
	addn	4, r0
	st    	r3, @r0
	ldi:8 	#88, r1
	addn	sp, r1
	ldi:8 	#0, r2
	ldi:8 	#15, r3
	st    	r2, @r1
	mov   	r1, r0
	addn	4, r0
	st    	r3, @r0
	ldi:8 	#80, r1
	addn	sp, r1
	ldi:8 	#0, r2
	ldi:8 	#14, r3
	st    	r2, @r1
	mov   	r1, r0
	addn	4, r0
	st    	r3, @r0
	ldi:8 	#72, r1
	addn	sp, r1
	ldi:8 	#0, r2
	ldi:8 	#13, r3
	st    	r2, @r1
	mov   	r1, r0
	addn	4, r0
	st    	r3, @r0
	ldi:8 	#64, r1
	addn	sp, r1
	ldi:8 	#0, r2
	ldi:8 	#12, r3
	st    	r2, @r1
	mov   	r1, r0
	addn	4, r0
	st    	r3, @r0
	ldi:8 	#56, r1
	addn	sp, r1
	ldi:8 	#0, r2
	ldi:8 	#11, r3
	st    	r2, @r1
	mov   	r1, r0
	addn	4, r0
	st    	r3, @r0
	ldi:8 	#48, r1
	addn	sp, r1
	ldi:8 	#0, r2
	ldi:8 	#10, r3
	st    	r2, @r1
	mov   	r1, r0
	addn	4, r0
	st    	r3, @r0
	ldi:8 	#40, r1
	addn	sp, r1
	ldi:8 	#0, r2
	ldi:8 	#9, r3
	st    	r2, @r1
	mov   	r1, r0
	addn	4, r0
	st    	r3, @r0
	ldi:8 	#32, r1
	addn	sp, r1
	ldi:8 	#0, r2
	ldi:8 	#8, r3
	st    	r2, @r1
	mov   	r1, r0
	addn	4, r0
	st    	r3, @r0
	ldi:8 	#24, r1
	addn	sp, r1
	ldi:8 	#0, r2
	ldi:8 	#7, r3
	st    	r2, @r1
	mov   	r1, r0
	addn	4, r0
	st    	r3, @r0
	ldi:8 	#16, r1
	addn	sp, r1
	ldi:8 	#0, r2
	ldi:8 	#6, r3
	st    	r2, @r1
	mov   	r1, r0
	addn	4, r0
	st    	r3, @r0
	ldi:8 	#8, r1
	addn	sp, r1
	ldi:8 	#0, r2
	ldi:8 	#5, r3
	st    	r2, @r1
	mov   	r1, r0
	addn	4, r0
	st    	r3, @r0
	ldi:8 	#0, r2
	ldi:8 	#4, r3
	st    	r2, @sp
	st    	r3, @(r15, #4)
	ldi:8 	#0, r6
	ldi:8 	#3, r7
	ldi:8 	#0, r4
	ldi:8 	#2, r5
	ldi:32	f4, r1
	call	@r1
	mov   	r4, r2
	mov   	r5, r3
	mov   	r2, r5
	mov   	r3, r6
	ldi:32	.LC3, r4
	ldi:32	printf, r1
	call	@r1
	ldi:8 	#0, r1
	mov   	r1, r4
	leave
	ld	@r15+, rp
	ret
	.size	main, .-main
	.p2align 2
	.globl clear_bss
	.type	clear_bss, @function
clear_bss:
	enter	#12
	ldi:8 	#252, r1
	extsb	r1
	addn	fp, r1
	st    	r4, @r1
	ldi:8 	#248, r1
	extsb	r1
	addn	fp, r1
	st    	r5, @r1
	bra	.L37
.L38:
	ldi:8 	#252, r1
	extsb	r1
	addn	fp, r1
	ld    	@r1, r2
	ldi:8 	#252, r1
	extsb	r1
	addn	fp, r1
	mov   	r2, r3
	addn	1, r3
	st    	r3, @r1
	ldi:8	#0, r1
	stb  	r1, @r2
.L37:
	ldi:8 	#252, r2
	extsb	r2
	addn	fp, r2
	ldi:8 	#248, r1
	extsb	r1
	addn	fp, r1
	ld    	@r2, r2
	ld    	@r1, r1
	cmp	r1, r2
	bne	.L38
	nop
	nop
	leave
	ret
	.size	clear_bss, .-clear_bss
	.ident	"GCC: (GNU) 10.2.0"
