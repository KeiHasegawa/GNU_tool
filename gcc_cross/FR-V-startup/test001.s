	.file	"test001.c"
	.text
	.globl x
	.section	.sbss,"aw",@nobits
	.p2align 2
	.type	x, @object
	.size	x, 4
x:
	.zero	4
	.text
	.p2align 4
	.globl f
	.type	f, @function
f:
	addi sp,#-24,sp
	sti fp, @(sp,8)
	addi sp,#8,fp
	movsg lr, gr5
	sti gr5, @(fp,8)
	sti gr8, @(fp,-4)
	sti gr9, @(fp,-8)
	ldi @(fp,-4), gr5
	ldi @(fp,-8), gr4
	add gr5,gr4,gr5
	addi gr16,#gprel12(x),gr4
	st gr5, @(gr4,gr0)
	addi gr16,#gprel12(x),gr4
	ld @(gr4,gr0), gr4
	mov gr4, gr8
	ldi @(fp,8), gr5
	ld @(fp,gr0), fp
	addi sp,#24,sp
	jmpl @(gr5,gr0)
	.size	f, .-f
	.globl __main
	.p2align 4
	.globl main
	.type	main, @function
main:
	addi sp,#-16,sp
	sti fp, @(sp,0)
	mov sp, fp
	movsg lr, gr5
	sti gr5, @(fp,8)
	call __main
	setlos #6, gr9
	setlos #5, gr8
	call f
	setlos #0, gr4
	mov gr4, gr8
	ldi @(fp,8), gr5
	ld @(fp,gr0), fp
	addi sp,#16,sp
	jmpl @(gr5,gr0)
	.size	main, .-main
	.ident	"GCC: (GNU) 10.2.0"
