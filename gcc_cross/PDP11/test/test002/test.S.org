	.text
start:
	mov	$stack, sp
	jsr	pc, _main
	halt

	.global	___main
___main:
	rts	pc


	.even
	.globl _f
_f:

	;	/* function prologue f*/
	mov r5, -(sp)
	mov sp, r5
	;/* end of prologue */

	mov 04(r5), r0
	add 06(r5), r0

	;	/*function epilogue */
	mov r5, sp
	mov (sp)+, r5
	rts pc
	;/* end of epilogue*/


	.even
	.globl _main
_main:

	;	/* function prologue main*/
	;/* switch cpu to double float, single integer */
	setd
	seti

	mov r5, -(sp)
	mov sp, r5
	;/* end of prologue */

	jsr pc, ___main
	mov $06, -(sp)
	mov $05, -(sp)
	jsr pc, _f
	add $04, sp

	;	/*function epilogue */
	mov r5, sp
	mov (sp)+, r5
	rts pc
	;/* end of epilogue*/


	
