	.text
	.global _start
_start:
	nop
    	addi	r6, r0, __sbss_start
	addi	r7, r0, __sbss_end	
label1:	
	rsub	r18, r6, r7
	blei	r18, label2
	swi	r0, r6, 0
	addi	r6, r6, 4
	bri	label1
label2:	
	nop

	addi	r6, r0, __bss_start
	addi	r7, r0, __bss_end
label3:	
    	rsub	r18, r6, r7
	blei	r18, label4
	swi	r0, r6, 0
	addi	r6, r6, 4
	bri	label3
label4:	
	nop

	la	r13, r0, _SDA_BASE_
	la	r2, r0, _SDA2_BASE_
	la	r1, r0, _stack-16

      	brlid	r15, main
	nop
end:	
	nop
