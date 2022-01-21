	.text
	.align	2
	.globl	f
	.ent	f
	.type	f, @function
f:
	addik	r1,r1,-8
	swi	r15,r1,0
	swi	r19,r1,4
	addk	r19,r1,r0
	swi	r5,r19,12
	swi	r6,r19,16
	
	lwi	r4,r19,12
	lwi	r3,r19,16
	addk	r3,r4,r3
	addk	r1,r19,r0
	
	lwi	r19,r1,4
	lwi	r15,r1,0
	addik	r1,r1,8
	rtsd	r15,8 
	nop
