	.text
start:
	ldk.l	$r0, __data_load_start
	ldk.l	$r1, __data_load_end
	ldk.l	$r2, _data_start
.L1:
	/* if r0 == r1 goto .L2 */	
	cmp.l	$r0, $r1
	jmpc	z,.L2
	lpmi.b	$r3, $r0, 0
	sti.b	$r2,0,$r3
	add.l	$r0,$r0,1
	add.l	$r2,$r2,1
	jmp	.L1
.L2:
	ldk.l	$r0, _bss_start
	ldk.l	$r1, _bss_end
	ldk.b	$r2, 0
.L5:
	/* if r0 == r1 goto .L6 */
	cmp.l	$r0, $r1
	jmpc	z,.L6
	sti.b	$r0,0,$r2
	add.l	$r0,$r0,1
	jmp	.L5
.L6:	
	ldk.l	$sp,stack
	call	main
	nop
	.long	0x0badbeef

	.global	printf
printf:
	.long	0x0badbeee
	return

	.global	puts
puts:
	.long	0x0badbeed
	return

	.global	putchar
putchar:
	.long	0x0badbeec
	return
