	.text
start:
	ld	hl, _bss_start
	ld	bc, _bss_start
	ld	de, _bss_end
	ld	a, 0
.L1:
	sbc	hl, de
	jp	z,.L2
	ld	hl, 0
	add	hl, bc
	ld	(hl), a
	inc	hl
	inc	bc
	jp	.L1
.L2:	
	ld	sp, stack
	call	_main
	nop
	jp	.

	.global _printf
_printf:	
	ret

	.global _puts
_puts:	
	ret

	.global _putchar
_putchar:	
	ret
