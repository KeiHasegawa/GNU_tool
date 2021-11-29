	.text
start:
	move.d _stack,$sp
	jsr _main
	nop
	.word	0xfdb0
	
	.global	_printf
_printf:
	ret
	nop

	.global	_puts
_puts:
	ret
	nop

	.global	_putchar
_putchar:
	ret
	nop
	
	.global _memcpy
_memcpy:
	subq 4,$sp
	move.d $r8,[$sp]
	move.d $sp,$r8
	subq 16,$sp
	move.d $r10,[$r8-8]
	move.d $r11,[$r8-12]
	move.d $r12,[$r8-16]
	move.d [$r8-8],$r9
	move.d $r9,[$r8-4]
	ba .L13
	nop
.L14:
	move.d [$r8-12],$r13
	moveq 1,$r9
	add.d $r13,$r9
	move.d $r9,[$r8-12]
	move.d [$r8-8],$r9
	moveq 1,$r12
	add.d $r9,$r12
	move.d $r12,[$r8-8]
	move.b [$r13],$r13
	move.b $r13,[$r9]
.L13:
	move.d [$r8-16],$r13
	moveq -1,$r9
	add.d $r13,$r9
	move.d $r9,[$r8-16]
	test.d $r13
	bne .L14
	nop
	move.d [$r8-4],$r9
	move.d $r9,$r10
	move.d $r8,$sp
	move.d [$sp+],$r8
	ret
	nop
