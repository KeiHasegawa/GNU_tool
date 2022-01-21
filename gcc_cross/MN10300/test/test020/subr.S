	.section .text
	.global _f
	.type	_f, @function
_f:
	movm [a3],(sp)
	mov sp,a3
	mov d0,(8,a3)
	mov d1,(12,a3)
	
	mov (8,a3),d1
	mov (12,a3),d0
	add d1,d0
	
	mov a3,sp
	ret [a3],4
