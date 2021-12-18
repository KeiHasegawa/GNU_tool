	.text
	.global _start
_start:
	adrp	x0, __bss_start__
	add	x0, x0, :lo12:__bss_start__
	adrp	x1, __bss_end__
	add	x1, x1, :lo12:__bss_end__
.L1:	
	cmp	x0, x1
	beq	.L2
	strb	wzr, [x0]
	add	x0, x0, 1
	b	.L1
.L2:
	adrp	x0, _stack
	add	sp, x0, :lo12:_stack
	bl	main
	nop
	nop
	nop

	.global _exit
_exit:
	b	.
