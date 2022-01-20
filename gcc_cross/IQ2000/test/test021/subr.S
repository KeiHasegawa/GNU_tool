	.text
	.balign 4
	.globl	f
f:
	addiu	%29,%29,-16
	sw	%27,8(%29)
	sw	%31,12(%29)
	or	%27,%0,%29
	sw	%4,0(%27)
	sw	%5,4(%27)
	
	lw	%3,0(%27)
	lw	%2,4(%27)
	nop
	addu	%2,%3,%2
	
	or	%29,%0,%27
	lw	%31,12(%29)
	lw	%27,8(%29)
	nop
	addiu	%29,%29,16
	j	%31
	nop
