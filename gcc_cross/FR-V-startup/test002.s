	.file	"test002.c"
	.text
	.globl __main
	.section	.rodata
	.p2align 2
.LC0:
	.string	"hello world"
	.text
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
	sethi #hi(.LC0), gr8
	setlo #lo(.LC0), gr8
	call puts
	setlos #0, gr4
	mov gr4, gr8
	ldi @(fp,8), gr5
	ld @(fp,gr0), fp
	addi sp,#16,sp
	jmpl @(gr5,gr0)
	.size	main, .-main
	.ident	"GCC: (GNU) 10.2.0"
