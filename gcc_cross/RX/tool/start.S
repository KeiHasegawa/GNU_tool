	.text
	.global start
start:
	mov.L	#_bss_start, r6
	mov.L	#_bss_end, r7
.L1:	
	cmp	r6, r7
	beq	.L2	
	mov.B	#0, [r6]
	add	#1, r6, r6
	bra	.L1
.L2:
	nop
	mov.L	#_stack, r0
	bsr	_main
	nop
	.byte	0x30

	.global	_printf
_printf:
	.byte	0x31
	rts

	.global	_puts
_puts:
	.byte	0x32
	rts

	.global	_putchar
_putchar:
	.byte	0x33
	rts
	


