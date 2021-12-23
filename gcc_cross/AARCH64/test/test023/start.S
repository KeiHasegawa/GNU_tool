	.text
	.global _start
_start:
	adrp	x0, _stack
	add	sp, x0, :lo12:_stack
	bl	main
	nop
	.word 0xd4200000

