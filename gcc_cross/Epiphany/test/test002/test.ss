	.file	"test.c"
	.section .text
	.balign 4
	.global	_f
_f:
	str fp,[sp],#-4   ; [sp] := fp, sp := sp-16
	mov fp,sp         ; fp := sp
	str r0,[fp,#3]    ; [fp+12] := r0
	str r1,[fp,#2]    ; [fp+8] := r1
	ldr r1,[fp,#3]
	ldr r0,[fp,#2]
	add r0,r1,r0
	mov sp,fp
	ldr fp,[sp,#4]    ; fp := [sp+16]
	add sp,sp,#16     ; sp := sp + 16
	rts
	.size	_f, .-_f

	+---------------+ <- sp_{new}, fp_{new}
	|		|
	+---------------+
	|  r1(b)	|
	+---------------+
	|  r0(a)	|
	+---------------+
	|		|
	+---------------+ <- sp_{old}
	|  fp_{old}	|
	+---------------+

	.balign 4
	.global	_main
_main:
	str fp,[sp],#-2    ; [sp] := fp, sp := sp-8
	str lr,[sp,#3]     ; [sp+12] := lr
	mov fp,sp          ; fp := sp
	mov r1,#6
	mov r0,#5
	mov r2, %low(_f)
	movt r2, %high(_f)
	jalr r2
	mov sp,fp
	ldr lr,[sp,#3]     ; lr := [sp+12]
	ldr fp,[sp,#2]     ; fp := [sp+8]
	add sp,sp,#8       ; sp := sp + 8
	rts

	+---------------+ <- sp_{new}, fp_{new}
	|		|
	+---------------+
	|		|
	+---------------+ <- sp_{old}
	|  fp_{old}	|
	+---------------+
	|  lr_{old}	|
	+---------------+

	.size	_main, .-_main
	.ident	"GCC: (GNU) 12.1.0"
