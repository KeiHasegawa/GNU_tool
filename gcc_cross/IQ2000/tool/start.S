	.text
start:
	lui	%2,%hi(_bss_start)
	addiu	%2,%2,%lo(_bss_start)
	lui	%3,%hi(_bss_end)
	addiu	%3,%3,%lo(_bss_end)
$L1:	
	beq	%2,%3,$L2
	nop
	sb	%0,0(%2)
	addiu	%2,%2,1
	j	$L1
$L2:	
	lui	%29,%hi(_stack)
	addiu	%29,%29,%lo(_stack)
	lui	%3,%hi(main)
	addiu	%3,%3,%lo(main)
	jalr	%31,%3
	nop
	.long	0xbadbeef0
	
	.global	printf
printf:
	j	%31
	nop

	.global	puts
puts:
	j	%31
	nop

	.global	putchar
putchar:
	j	%31
	nop

	.globl	memcpy
memcpy:
	addiu	%29,%29,-32
	sw	%27,24(%29)
	or	%27,%0,%29
	sw	%4,8(%27)
	sw	%5,12(%27)
	sw	%6,16(%27)
	lw	%2,8(%27)
	nop
	sw	%2,0(%27)
	j	$L13
	nop
$L14:
	lw	%4,12(%27)
	nop
	addiu	%2,%4,1
	sw	%2,12(%27)
	lw	%3,8(%27)
	nop
	addiu	%2,%3,1
	sw	%2,8(%27)
	lb	%2,0(%4)
	nop
	sb	%2,0(%3)
$L13:
	lw	%3,16(%27)
	nop
	addiu	%2,%3,-1
	sw	%2,16(%27)
	bne	%3,%0,$L14
	nop
	lw	%2,0(%27)
	nop
	or	%29,%0,%27
	lw	%27,24(%29)
	nop
	addiu	%29,%29,32
	j	%31
	nop
	
