	.text
start:
	move.d	_bss_start, $r10
	move.d	_bss_end, $r11
.L1:	
	cmp.d	$r10, $r11
	beq	.L2
	nop
	clear.b	[$r10]	
	add.d	1,$r10
	ba	.L1
	nop
.L2:
	move.d	_stack,sp
	jsr	_main
	nop
_exit:	
	ba	.
