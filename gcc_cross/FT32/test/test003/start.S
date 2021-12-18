	.text
start:
	ldk.l	$r0, _data_start
	ldk.l	$r1, _data_end
.L1:
	/* if r0 == r1 goto .L2 */	
	cmp.l	$r0, $r1
	jmpc	z,.L2
	lpmi.b	$r2, $r0, 0
	sti.b	$r0,0,$r2
	add.l	$r0,$r0,1
	jmp	.L1
.L2:
	ldk.l	$r0, _rodata_start
	ldk.l	$r1, _rodata_end
.L3:
	/* if r0 == r1 goto .L4 */
	cmp.l	$r0, $r1
	jmpc	z,.L4
	lpmi.b	$r2, $r0, 0
	sti.b	$r0,0,$r2
	add.l	$r0,$r0,1
	jmp	.L3
.L4:	
	ldk.l	$r0, _bss_start
	ldk.l	$r1, _bss_end
	ldk.b	$r2,0
.L5:
	/* if r0 == r1 goto .L6 */
	cmp.l	$r0, $r1
	jmpc	z,.L6
	sti.b	$r0,0,$r2
	add.l	$r0,$r0,1
	jmp	.L5
.L6:	
	ldk.l	$sp,_stack
	call	main
_exit:
	jmp	.
