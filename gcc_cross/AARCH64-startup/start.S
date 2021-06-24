	.text
	.global _start
_start:
	adrp	x0, _stack
	add	sp, x0, :lo12:_stack
	bl	main
end:
	nop
