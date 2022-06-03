	.text
_start:
	addr	_bss_start(pc), r0
	addr	_bss_end(pc), r1
.L1:
	cmpd	r0, r1
	beq	.L2
	movqb	0, 0(r0)
	addqd	1, r0
	br	.L1
.L2:	
	addr	_stack(pc), r0
	lprd	sp, r0
	bsr	_main
	.byte	0x06

	.global	___main
___main:
	ret	0
	
	.global	_printf
_printf:
	.byte	0x16
	ret	0

	.global	_puts
_puts:
	.byte	0x36
	ret	0

	.global	_putchar
_putchar:
	.byte	0x46
	ret	0
