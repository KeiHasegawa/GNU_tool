	.text
start:
	ldi.l	$r0, _bss_start
	ldi.l	$r1, _bss_end
	xor	$r2, $r2
.L1:	
	cmp	$r0, $r1
	beq	.L2
	st.b	($r0), $r2
	inc	$r0, 1
	jmpa	.L1
.L2:	
	nop
	ldi.l	$sp, _stack
	jsra	main
	nop
	.short	0xfff0
	
	.global	printf
printf:
	.short	0xfff1
	ret

	.global	puts
puts:
	.short	0xfff2
	ret

	.global	putchar
putchar:
	.short	0xfff3
	ret
	
	.global	memcpy
memcpy:
	dec	$sp, 4
	sto.l	12($fp), $r0
	sto.l	16($fp), $r1
	sto.l	20($fp), $r2
	ldo.l	$r0, 12($fp)
	sto.l	-4($fp), $r0
	jmpa	.L13
.L14:
	ldo.l	$r1, 16($fp)
	mov	$r0, $r1
	inc	$r0, 1
	sto.l	16($fp), $r0
	ldo.l	$r0, 12($fp)
	mov	$r2, $r0
	inc	$r2, 1
	sto.l	12($fp), $r2
	ld.b	$r1, ($r1)
	st.b	($r0), $r1
.L13:
	ldo.l	$r0, 20($fp)
	mov	$r1, $r0
	dec	$r1, --1
	sto.l	20($fp), $r1
	xor	$r1, $r1
	cmp	$r0, $r1
	bne	.L14
	ldo.l	$r0, -4($fp)
	ret
	
