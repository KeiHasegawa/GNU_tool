	.text
	mov	stack, a0
	mov	a0, sp
start:
	nop
	nop
	call _main,[],0
	.short	0xf8f0
	
	.global	_printf
_printf:
	.short	0xf8f1
	movm [a3],(sp)
	ret [a3],4

	.global	_puts
_puts:
	.short	0xf8f8
	movm [a3],(sp)
	ret [a3],4

	.global	_putchar
_putchar:
	.short	0xf8f9
	movm [a3],(sp)
	ret [a3],4
	
	.global _memcpy
_memcpy:
	movm [a3],(sp)
	mov sp,a3
	add -4,sp
	mov d0,(8,a3)
	mov d1,(12,a3)
	mov (8,a3),d0
	mov d0,(-4,a3)
	jmp .L13
.L14:
	mov (12,a3),a1
	mov 1,d0
	add a1,d0
	mov d0,(12,a3)
	mov (8,a3),a0
	mov 1,d0
	add a0,d0
	mov d0,(8,a3)
	movbu (a1),d0
	movbu d0,(a0)
.L13:
	mov (16,a3),d0
	mov -1,d1
	add d0,d1
	mov d1,(16,a3)
	cmp 0,d0
	bne .L14
	mov (-4,a3),d0
	mov d0,d1
	mov d1,a0
	mov a3,sp
	ret [a3],4
