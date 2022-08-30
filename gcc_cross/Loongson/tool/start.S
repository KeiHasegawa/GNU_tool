	.text
start:
	la.global	$r1, _bss_start
	la.global	$r2, _bss_end
.L1:
	beq	$r1, $r2, .L2
	st.b	$r0, $r1, 0
	addi.d	$r1, $r1, 1
	b	.L1
.L2:	
	la.global	$sp, stack
	bl	main
	.long	0xbadbeef0

	.global printf
printf:
	.long	0xbadbeef1
	jr	$r1

	.global puts
puts:
	.long	0xbadbeef2
	jr	$r1

	.global putchar
putchar:
	.long	0xbadbeef3
	jr	$r1
