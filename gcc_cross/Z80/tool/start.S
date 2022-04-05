	.text
start:
	ld	sp, stack
	call	_main
	nop
end:
	nop

	.global _printf
_printf:	
	ret

	.global _puts
_puts:	
	ret

	.global _putchar
_putchar:	
	ret
