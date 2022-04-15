	.file	"sample.c"
	.section	".text"
	.section	".rodata"
	.align 8
.LLC0:
	.asciz	"%d + %d = %d\n"
	.section	".text"
	.align 4
	.global f
	.type	f, #function
	.proc	020
f:
	save	%sp, -96, %sp
	st	%i0, [%fp+68]
	st	%i1, [%fp+72]
	ld	[%fp+68], %g2
	ld	[%fp+72], %g1
	add	%g2, %g1, %g1
	mov	%g1, %o3
	ld	[%fp+72], %o2
	ld	[%fp+68], %o1
	sethi	%hi(.LLC0), %g1
	or	%g1, %lo(.LLC0), %o0
	call	printf, 0
	 nop
	nop
	restore
	jmp	%o7+8
	 nop
	.size	f, .-f
	.section	".rodata"
	.align 8
.LLC1:
	.asciz	"hello world"
	.section	".text"
	.align 4
	.global g
	.type	g, #function
	.proc	020
g:
	save	%sp, -96, %sp
	sethi	%hi(.LLC1), %g1
	or	%g1, %lo(.LLC1), %o0
	call	puts, 0
	 nop
	nop
	restore
	jmp	%o7+8
	 nop
	.size	g, .-g
	.section	".rodata"
	.align 8
.LLC2:
	.asciz	"%f\n"
	.section	".text"
	.align 4
	.global h
	.type	h, #function
	.proc	020
h:
	save	%sp, -104, %sp
	std	%i0, [%fp-8]
	mov	10, %o0
	call	putchar, 0
	 nop
	ld	[%fp-8], %o1
	ld	[%fp-4], %o2
	sethi	%hi(.LLC2), %g1
	or	%g1, %lo(.LLC2), %o0
	call	printf, 0
	 nop
	nop
	restore
	jmp	%o7+8
	 nop
	.size	h, .-h
	.section	".rodata"
	.align 8
.LLC3:
	.asciz	"%lld\n"
	.section	".text"
	.align 4
	.global ff
	.type	ff, #function
	.proc	020
ff:
	save	%sp, -104, %sp
	std	%i0, [%fp-8]
	ld	[%fp-8], %o1
	ld	[%fp-4], %o2
	sethi	%hi(.LLC3), %g1
	or	%g1, %lo(.LLC3), %o0
	call	printf, 0
	 nop
	nop
	restore
	jmp	%o7+8
	 nop
	.size	ff, .-ff
	.section	".rodata"
	.align 8
.LLC4:
	.asciz	"%s %d %f\n"
	.section	".text"
	.align 4
	.global gg
	.type	gg, #function
	.proc	020
gg:
	save	%sp, -104, %sp
	st	%i0, [%fp+68]
	st	%i1, [%fp+72]
	std	%i2, [%fp-8]
	ld	[%fp-8], %o3
	ld	[%fp-4], %o4
	ld	[%fp+72], %o2
	ld	[%fp+68], %o1
	sethi	%hi(.LLC4), %g1
	or	%g1, %lo(.LLC4), %o0
	call	printf, 0
	 nop
	nop
	restore
	jmp	%o7+8
	 nop
	.size	gg, .-gg
	.section	".rodata"
	.align 8
.LLC5:
	.asciz	"%Lf\n"
	.section	".text"
	.align 4
	.global hh
	.type	hh, #function
	.proc	020
hh:
	save	%sp, -104, %sp
	std	%i0, [%fp-8]
	ld	[%fp-8], %o1
	ld	[%fp-4], %o2
	sethi	%hi(.LLC5), %g1
	or	%g1, %lo(.LLC5), %o0
	call	printf, 0
	 nop
	nop
	restore
	jmp	%o7+8
	 nop
	.size	hh, .-hh
	.section	".rodata"
	.align 8
.LLC6:
	.asciz	"%f %f %f\n"
	.section	".text"
	.align 4
	.global f2
	.type	f2, #function
	.proc	020
f2:
	save	%sp, -128, %sp
	std	%i0, [%fp-8]
	std	%i2, [%fp-16]
	std	%i4, [%fp-24]
	ld	[%fp-20], %g1
	st	%g1, [%sp+92]
	ld	[%fp-24], %o5
	ld	[%fp-16], %o3
	ld	[%fp-12], %o4
	ld	[%fp-8], %o1
	ld	[%fp-4], %o2
	sethi	%hi(.LLC6), %g1
	or	%g1, %lo(.LLC6), %o0
	call	printf, 0
	 nop
	nop
	restore
	jmp	%o7+8
	 nop
	.size	f2, .-f2
	.section	".rodata"
	.align 8
.LLC7:
	.asciz	"%lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld\n"
	.section	".text"
	.align 4
	.global g2
	.type	g2, #function
	.proc	020
g2:
	save	%sp, -400, %sp
	std	%i0, [%fp-8]
	std	%i2, [%fp-16]
	std	%i4, [%fp-24]
	ld	[%fp+92], %g1
	st	%g1, [%fp-32]
	ld	[%fp+96], %g1
	st	%g1, [%fp-28]
	ld	[%fp+100], %g1
	st	%g1, [%fp-40]
	ld	[%fp+104], %g1
	st	%g1, [%fp-36]
	ld	[%fp+108], %g1
	st	%g1, [%fp-48]
	ld	[%fp+112], %g1
	st	%g1, [%fp-44]
	ld	[%fp+116], %g1
	st	%g1, [%fp-56]
	ld	[%fp+120], %g1
	st	%g1, [%fp-52]
	ld	[%fp+124], %g1
	st	%g1, [%fp-64]
	ld	[%fp+128], %g1
	st	%g1, [%fp-60]
	ld	[%fp+132], %g1
	st	%g1, [%fp-72]
	ld	[%fp+136], %g1
	st	%g1, [%fp-68]
	ld	[%fp+140], %g1
	st	%g1, [%fp-80]
	ld	[%fp+144], %g1
	st	%g1, [%fp-76]
	ld	[%fp+148], %g1
	st	%g1, [%fp-88]
	ld	[%fp+152], %g1
	st	%g1, [%fp-84]
	ld	[%fp+156], %g1
	st	%g1, [%fp-96]
	ld	[%fp+160], %g1
	st	%g1, [%fp-92]
	ld	[%fp+164], %g1
	st	%g1, [%fp-104]
	ld	[%fp+168], %g1
	st	%g1, [%fp-100]
	ld	[%fp+172], %g1
	st	%g1, [%fp-112]
	ld	[%fp+176], %g1
	st	%g1, [%fp-108]
	ld	[%fp+180], %g1
	st	%g1, [%fp-120]
	ld	[%fp+184], %g1
	st	%g1, [%fp-116]
	ld	[%fp+188], %g1
	st	%g1, [%fp-128]
	ld	[%fp+192], %g1
	st	%g1, [%fp-124]
	ld	[%fp+196], %g1
	st	%g1, [%fp-136]
	ld	[%fp+200], %g1
	st	%g1, [%fp-132]
	ld	[%fp+204], %g1
	st	%g1, [%fp-144]
	ld	[%fp+208], %g1
	st	%g1, [%fp-140]
	ld	[%fp+212], %g1
	st	%g1, [%fp-152]
	ld	[%fp+216], %g1
	st	%g1, [%fp-148]
	ld	[%fp+220], %g1
	st	%g1, [%fp-160]
	ld	[%fp+224], %g1
	st	%g1, [%fp-156]
	ld	[%fp-160], %g1
	st	%g1, [%sp+224]
	ld	[%fp-156], %g1
	st	%g1, [%sp+228]
	ld	[%fp-152], %g1
	st	%g1, [%sp+216]
	ld	[%fp-148], %g1
	st	%g1, [%sp+220]
	ld	[%fp-144], %g1
	st	%g1, [%sp+208]
	ld	[%fp-140], %g1
	st	%g1, [%sp+212]
	ld	[%fp-136], %g1
	st	%g1, [%sp+200]
	ld	[%fp-132], %g1
	st	%g1, [%sp+204]
	ld	[%fp-128], %g1
	st	%g1, [%sp+192]
	ld	[%fp-124], %g1
	st	%g1, [%sp+196]
	ld	[%fp-120], %g1
	st	%g1, [%sp+184]
	ld	[%fp-116], %g1
	st	%g1, [%sp+188]
	ld	[%fp-112], %g1
	st	%g1, [%sp+176]
	ld	[%fp-108], %g1
	st	%g1, [%sp+180]
	ld	[%fp-104], %g1
	st	%g1, [%sp+168]
	ld	[%fp-100], %g1
	st	%g1, [%sp+172]
	ld	[%fp-96], %g1
	st	%g1, [%sp+160]
	ld	[%fp-92], %g1
	st	%g1, [%sp+164]
	ld	[%fp-88], %g1
	st	%g1, [%sp+152]
	ld	[%fp-84], %g1
	st	%g1, [%sp+156]
	ld	[%fp-80], %g1
	st	%g1, [%sp+144]
	ld	[%fp-76], %g1
	st	%g1, [%sp+148]
	ld	[%fp-72], %g1
	st	%g1, [%sp+136]
	ld	[%fp-68], %g1
	st	%g1, [%sp+140]
	ld	[%fp-64], %g1
	st	%g1, [%sp+128]
	ld	[%fp-60], %g1
	st	%g1, [%sp+132]
	ld	[%fp-56], %g1
	st	%g1, [%sp+120]
	ld	[%fp-52], %g1
	st	%g1, [%sp+124]
	ld	[%fp-48], %g1
	st	%g1, [%sp+112]
	ld	[%fp-44], %g1
	st	%g1, [%sp+116]
	ld	[%fp-40], %g1
	st	%g1, [%sp+104]
	ld	[%fp-36], %g1
	st	%g1, [%sp+108]
	ld	[%fp-32], %g1
	st	%g1, [%sp+96]
	ld	[%fp-28], %g1
	st	%g1, [%sp+100]
	ld	[%fp-20], %g1
	st	%g1, [%sp+92]
	ld	[%fp-24], %o5
	ld	[%fp-16], %o3
	ld	[%fp-12], %o4
	ld	[%fp-8], %o1
	ld	[%fp-4], %o2
	sethi	%hi(.LLC7), %g1
	or	%g1, %lo(.LLC7), %o0
	call	printf, 0
	 nop
	nop
	restore
	jmp	%o7+8
	 nop
	.size	g2, .-g2
	.section	".rodata"
	.align 8
.LLC8:
	.asciz	"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n"
	.section	".text"
	.align 4
	.global h2
	.type	h2, #function
	.proc	020
h2:
	save	%sp, -176, %sp
	st	%i0, [%fp+68]
	st	%i1, [%fp+72]
	st	%i2, [%fp+76]
	st	%i3, [%fp+80]
	st	%i4, [%fp+84]
	st	%i5, [%fp+88]
	ld	[%fp+160], %g1
	st	%g1, [%sp+164]
	ld	[%fp+156], %g1
	st	%g1, [%sp+160]
	ld	[%fp+152], %g1
	st	%g1, [%sp+156]
	ld	[%fp+148], %g1
	st	%g1, [%sp+152]
	ld	[%fp+144], %g1
	st	%g1, [%sp+148]
	ld	[%fp+140], %g1
	st	%g1, [%sp+144]
	ld	[%fp+136], %g1
	st	%g1, [%sp+140]
	ld	[%fp+132], %g1
	st	%g1, [%sp+136]
	ld	[%fp+128], %g1
	st	%g1, [%sp+132]
	ld	[%fp+124], %g1
	st	%g1, [%sp+128]
	ld	[%fp+120], %g1
	st	%g1, [%sp+124]
	ld	[%fp+116], %g1
	st	%g1, [%sp+120]
	ld	[%fp+112], %g1
	st	%g1, [%sp+116]
	ld	[%fp+108], %g1
	st	%g1, [%sp+112]
	ld	[%fp+104], %g1
	st	%g1, [%sp+108]
	ld	[%fp+100], %g1
	st	%g1, [%sp+104]
	ld	[%fp+96], %g1
	st	%g1, [%sp+100]
	ld	[%fp+92], %g1
	st	%g1, [%sp+96]
	ld	[%fp+88], %g1
	st	%g1, [%sp+92]
	ld	[%fp+84], %o5
	ld	[%fp+80], %o4
	ld	[%fp+76], %o3
	ld	[%fp+72], %o2
	ld	[%fp+68], %o1
	sethi	%hi(.LLC8), %g1
	or	%g1, %lo(.LLC8), %o0
	call	printf, 0
	 nop
	nop
	restore
	jmp	%o7+8
	 nop
	.size	h2, .-h2
	.global test_f3
	.section	".bss"
	.align 4
	.type	test_f3, #object
	.size	test_f3, 4
test_f3:
	.skip	4
	.section	".rodata"
	.align 8
.LLC9:
	.asciz	"test_f3 = %d\n"
	.section	".text"
	.align 4
	.global f3
	.type	f3, #function
	.proc	020
f3:
	save	%sp, -96, %sp
	st	%i0, [%fp+68]
	sethi	%hi(test_f3), %g1
	or	%g1, %lo(test_f3), %g1
	ld	[%fp+68], %g2
	st	%g2, [%g1]
	sethi	%hi(test_f3), %g1
	or	%g1, %lo(test_f3), %g1
	ld	[%g1], %g1
	mov	%g1, %o1
	sethi	%hi(.LLC9), %g1
	or	%g1, %lo(.LLC9), %o0
	call	printf, 0
	 nop
	nop
	restore
	jmp	%o7+8
	 nop
	.size	f3, .-f3
	.global test_g3
	.section	".bss"
	.align 4
	.type	test_g3, #object
	.size	test_g3, 4
test_g3:
	.skip	4
	.section	".rodata"
	.align 8
.LLC10:
	.asciz	"test_g3 = %x\n"
	.section	".text"
	.align 4
	.global g3
	.type	g3, #function
	.proc	020
g3:
	save	%sp, -96, %sp
	sethi	%hi(test_g3), %g1
	or	%g1, %lo(test_g3), %g1
	ld	[%g1], %g1
	mov	%g1, %o1
	sethi	%hi(.LLC10), %g1
	or	%g1, %lo(.LLC10), %o0
	call	printf, 0
	 nop
	nop
	restore
	jmp	%o7+8
	 nop
	.size	g3, .-g3
	.global test_h3
	.section	".data"
	.align 4
	.type	test_h3, #object
	.size	test_h3, 4
test_h3:
	.long	456
	.section	".rodata"
	.align 8
.LLC11:
	.asciz	"test_h3 = %d\n"
	.section	".text"
	.align 4
	.global h3
	.type	h3, #function
	.proc	020
h3:
	save	%sp, -96, %sp
	sethi	%hi(test_h3), %g1
	or	%g1, %lo(test_h3), %g1
	ld	[%g1], %g1
	mov	%g1, %o1
	sethi	%hi(.LLC11), %g1
	or	%g1, %lo(.LLC11), %o0
	call	printf, 0
	 nop
	nop
	restore
	jmp	%o7+8
	 nop
	.size	h3, .-h3
	.section	".rodata"
	.align 8
.LLC12:
	.long	1072693248
	.long	0
	.align 8
.LLC13:
	.long	1075314688
	.long	0
	.align 8
.LLC14:
	.long	1074266112
	.long	0
	.align 8
.LLC15:
	.long	1073741824
	.long	0
	.section	".text"
	.align 4
	.global main
	.type	main, #function
	.proc	04
main:
	save	%sp, -264, %sp
	mov	6, %o1
	mov	5, %o0
	call	f, 0
	 nop
	call	g, 0
	 nop
	mov	10, %o0
	call	putchar, 0
	 nop
	sethi	%hi(.LLC12), %g1
	or	%g1, %lo(.LLC12), %g1
	ldd	[%g1], %f8
	std	%f8, [%fp-32]
	ldd	[%fp-32], %o0
	call	h, 0
	 nop
	mov	0, %o0
	mov	9, %o1
	call	ff, 0
	 nop
	sethi	%hi(1751216128), %g2
	or	%g2, 869, %g2
	sethi	%hi(1734439936), %g3
	or	%g3, 865, %g3
	std	%g2, [%fp-16]
	sethi	%hi(543908864), %g1
	or	%g1, 361, %g1
	st	%g1, [%fp-8]
	stb	%g0, [%fp-4]
	sethi	%hi(.LLC13), %g1
	or	%g1, %lo(.LLC13), %g1
	ldd	[%g1], %f8
	add	%fp, -16, %g1
	std	%f8, [%fp-32]
	ldd	[%fp-32], %o2
	mov	5, %o1
	mov	%g1, %o0
	call	gg, 0
	 nop
	sethi	%hi(.LLC14), %g1
	or	%g1, %lo(.LLC14), %g1
	ldd	[%g1], %f8
	std	%f8, [%fp-32]
	ldd	[%fp-32], %o0
	call	hh, 0
	 nop
	sethi	%hi(.LLC14), %g1
	or	%g1, %lo(.LLC14), %g1
	ldd	[%g1], %f12
	sethi	%hi(.LLC15), %g1
	or	%g1, %lo(.LLC15), %g1
	ldd	[%g1], %f10
	sethi	%hi(.LLC12), %g1
	or	%g1, %lo(.LLC12), %g1
	ldd	[%g1], %f8
	std	%f12, [%fp-32]
	ldd	[%fp-32], %o4
	std	%f10, [%fp-32]
	ldd	[%fp-32], %o2
	std	%f8, [%fp-32]
	ldd	[%fp-32], %o0
	call	f2, 0
	 nop
	mov	0, %g2
	mov	20, %g3
	std	%g2, [%fp-24]
	ld	[%fp-24], %g1
	st	%g1, [%sp+220]
	ld	[%fp-20], %g1
	st	%g1, [%sp+224]
	mov	0, %g2
	mov	19, %g3
	std	%g2, [%fp-24]
	ld	[%fp-24], %g1
	st	%g1, [%sp+212]
	ld	[%fp-20], %g1
	st	%g1, [%sp+216]
	mov	0, %g2
	mov	18, %g3
	std	%g2, [%fp-24]
	ld	[%fp-24], %g1
	st	%g1, [%sp+204]
	ld	[%fp-20], %g1
	st	%g1, [%sp+208]
	mov	0, %g2
	mov	17, %g3
	std	%g2, [%fp-24]
	ld	[%fp-24], %g1
	st	%g1, [%sp+196]
	ld	[%fp-20], %g1
	st	%g1, [%sp+200]
	mov	0, %g2
	mov	16, %g3
	std	%g2, [%fp-24]
	ld	[%fp-24], %g1
	st	%g1, [%sp+188]
	ld	[%fp-20], %g1
	st	%g1, [%sp+192]
	mov	0, %g2
	mov	15, %g3
	std	%g2, [%fp-24]
	ld	[%fp-24], %g1
	st	%g1, [%sp+180]
	ld	[%fp-20], %g1
	st	%g1, [%sp+184]
	mov	0, %g2
	mov	14, %g3
	std	%g2, [%fp-24]
	ld	[%fp-24], %g1
	st	%g1, [%sp+172]
	ld	[%fp-20], %g1
	st	%g1, [%sp+176]
	mov	0, %g2
	mov	13, %g3
	std	%g2, [%fp-24]
	ld	[%fp-24], %g1
	st	%g1, [%sp+164]
	ld	[%fp-20], %g1
	st	%g1, [%sp+168]
	mov	0, %g2
	mov	12, %g3
	std	%g2, [%fp-24]
	ld	[%fp-24], %g1
	st	%g1, [%sp+156]
	ld	[%fp-20], %g1
	st	%g1, [%sp+160]
	mov	0, %g2
	mov	11, %g3
	std	%g2, [%fp-24]
	ld	[%fp-24], %g1
	st	%g1, [%sp+148]
	ld	[%fp-20], %g1
	st	%g1, [%sp+152]
	mov	0, %g2
	mov	10, %g3
	std	%g2, [%fp-24]
	ld	[%fp-24], %g1
	st	%g1, [%sp+140]
	ld	[%fp-20], %g1
	st	%g1, [%sp+144]
	mov	0, %g2
	mov	9, %g3
	std	%g2, [%fp-24]
	ld	[%fp-24], %g1
	st	%g1, [%sp+132]
	ld	[%fp-20], %g1
	st	%g1, [%sp+136]
	mov	0, %g2
	mov	8, %g3
	std	%g2, [%fp-24]
	ld	[%fp-24], %g1
	st	%g1, [%sp+124]
	ld	[%fp-20], %g1
	st	%g1, [%sp+128]
	mov	0, %g2
	mov	7, %g3
	std	%g2, [%fp-24]
	ld	[%fp-24], %g1
	st	%g1, [%sp+116]
	ld	[%fp-20], %g1
	st	%g1, [%sp+120]
	mov	0, %g2
	mov	6, %g3
	std	%g2, [%fp-24]
	ld	[%fp-24], %g1
	st	%g1, [%sp+108]
	ld	[%fp-20], %g1
	st	%g1, [%sp+112]
	mov	0, %g2
	mov	5, %g3
	std	%g2, [%fp-24]
	ld	[%fp-24], %g1
	st	%g1, [%sp+100]
	ld	[%fp-20], %g1
	st	%g1, [%sp+104]
	mov	0, %g2
	mov	4, %g3
	std	%g2, [%fp-24]
	ld	[%fp-24], %g1
	st	%g1, [%sp+92]
	ld	[%fp-20], %g1
	st	%g1, [%sp+96]
	mov	0, %o4
	mov	3, %o5
	mov	0, %o2
	mov	2, %o3
	mov	0, %o0
	mov	1, %o1
	call	g2, 0
	 nop
	mov	24, %g1
	st	%g1, [%sp+160]
	mov	23, %g1
	st	%g1, [%sp+156]
	mov	22, %g1
	st	%g1, [%sp+152]
	mov	21, %g1
	st	%g1, [%sp+148]
	mov	20, %g1
	st	%g1, [%sp+144]
	mov	19, %g1
	st	%g1, [%sp+140]
	mov	18, %g1
	st	%g1, [%sp+136]
	mov	17, %g1
	st	%g1, [%sp+132]
	mov	16, %g1
	st	%g1, [%sp+128]
	mov	15, %g1
	st	%g1, [%sp+124]
	mov	14, %g1
	st	%g1, [%sp+120]
	mov	13, %g1
	st	%g1, [%sp+116]
	mov	12, %g1
	st	%g1, [%sp+112]
	mov	11, %g1
	st	%g1, [%sp+108]
	mov	10, %g1
	st	%g1, [%sp+104]
	mov	9, %g1
	st	%g1, [%sp+100]
	mov	8, %g1
	st	%g1, [%sp+96]
	mov	7, %g1
	st	%g1, [%sp+92]
	mov	6, %o5
	mov	5, %o4
	mov	4, %o3
	mov	3, %o2
	mov	2, %o1
	mov	1, %o0
	call	h2, 0
	 nop
	mov	123, %o0
	call	f3, 0
	 nop
	call	g3, 0
	 nop
	call	h3, 0
	 nop
	mov	0, %g1
	mov	%g1, %i0
	restore
	jmp	%o7+8
	 nop
	.size	main, .-main
	.align 4
	.global clear_bss
	.type	clear_bss, #function
	.proc	020
clear_bss:
	save	%sp, -96, %sp
	st	%i0, [%fp+68]
	st	%i1, [%fp+72]
	b	.LL16
	 nop
.LL17:
	ld	[%fp+68], %g1
	add	%g1, 1, %g2
	st	%g2, [%fp+68]
	stb	%g0, [%g1]
.LL16:
	ld	[%fp+68], %g2
	ld	[%fp+72], %g1
	cmp	%g2, %g1
	bne	.LL17
	 nop
	nop
	nop
	restore
	jmp	%o7+8
	 nop
	.size	clear_bss, .-clear_bss
	.ident	"GCC: (GNU) 10.2.0"
