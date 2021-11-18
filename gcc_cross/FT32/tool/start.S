	.text
start:
	ldk.l	$r0, data_start
	ldk.l	$r1, data_end

.L1:
	/* if r0 == r1 goto .L2 */	
	cmp.l	$r0, $r1
	jmpc	z,.L2
	lpmi.l	$r2, $r0, 0
	sti.l	$r0,0,$r2
	add.l	$r0,$r0,4
	jmp	.L1
.L2:	
	ldk.l	$sp,stack
	call	main
	nop
	.long	0x0badbeef

	.global	printf
printf:
	.long	0x1badbeef
	return

	.global	puts
puts:
	.long	0x2badbeef
	return

	.global	putchar
putchar:
	.long	0x3badbeef
	return
