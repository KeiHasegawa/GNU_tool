	.text
start:
	la	$2, _bss_start
	la	$3, _bss_end
$L1:
	beq	$2, $3, $L2
	sb	$0, 0($2)
	addiu	$2, $2, 1
	b	$L1
$L2:	
	nop
	la	$gp, _gp
	la	$sp, _stack
	jal	main
	nop
	.word	0x7fffbee0
	
	.global	printf
printf:
	.word	0x7fffbee1
	j	$31

	.global	puts
puts:
	.word	0x7fffbee2
	j	$31

	.global	putchar
putchar:
	.word	0x7fffbee3
	j	$31
	
	.globl	memcpy
	.set	nomips16
	.set	nomicromips
	.ent	memcpy
memcpy:
	.frame	$fp,16,$31		# vars= 8, regs= 1/0, args= 0, gp= 0
	.mask	0x40000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-16
	sw	$fp,12($sp)
	move	$fp,$sp
	sw	$4,16($fp)
	sw	$5,20($fp)
	sw	$6,24($fp)
	lw	$2,16($fp)
	nop
	sw	$2,0($fp)
	b	$L13
	nop

$L14:
	lw	$3,20($fp)
	nop
	addiu	$2,$3,1
	sw	$2,20($fp)
	lw	$2,16($fp)
	nop
	addiu	$4,$2,1
	sw	$4,16($fp)
	lb	$3,0($3)
	nop
	sb	$3,0($2)
$L13:
	lw	$2,24($fp)
	nop
	addiu	$3,$2,-1
	sw	$3,24($fp)
	bne	$2,$0,$L14
	nop

	lw	$2,0($fp)
	move	$sp,$fp
	lw	$fp,12($sp)
	addiu	$sp,$sp,16
	jr	$31
	nop
	.end	memcpy

	.globl	memset
	.set	nomips16
	.set	nomicromips
	.ent	memset
memset:
	.frame	$fp,16,$31		# vars= 8, regs= 1/0, args= 0, gp= 0
	.mask	0x40000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-16
	sw	$fp,12($sp)
	move	$fp,$sp
	sw	$4,16($fp)
	sw	$5,20($fp)
	sw	$6,24($fp)
	lw	$2,16($fp)
	nop
	sw	$2,0($fp)
	b	$L17
	nop

$L18:
	lw	$2,16($fp)
	nop
	addiu	$3,$2,1
	sw	$3,16($fp)
	lw	$3,20($fp)
	nop
	sll	$3,$3,24
	sra	$3,$3,24
	sb	$3,0($2)
$L17:
	lw	$2,24($fp)
	nop
	addiu	$3,$2,-1
	sw	$3,24($fp)
	bne	$2,$0,$L18
	nop

	lw	$2,0($fp)
	move	$sp,$fp
	lw	$fp,12($sp)
	addiu	$sp,$sp,16
	jr	$31
	nop
	.end	memset
