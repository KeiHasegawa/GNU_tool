	.text
start:
	movw	$_bss_start, r0
	movw	$_bss_end, r1
.L1:
	cmpw	r0, r1
	beq	.L2
	storb	$0, 0(r0)
	addw	$1, r0
	br	.L1
.L2:
	movw	$_stack,sp
	bal (ra), _main@c
	nop
end:
	nop
