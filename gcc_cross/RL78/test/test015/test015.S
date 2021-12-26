	.text
start:
	movw	sp, #stack
	call	!!%code(__rl78_init)
	brk1
	nop
	
	.section	.init,"ax"
	.global __rl78_init
__rl78_init:
	ret
