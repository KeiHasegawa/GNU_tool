	.text
start:
	aaa
	aad
	.byte	0xd5
	.byte	0xcc
	aam
	aas

	adc	$5, %al
	adc	$256, %ax
	adc	$65536, %eax
	adc	$7, %dh
	adcb	$8, 0x10
	adc	$256, %dx
	adcw	$257, 0x10
	adc	$65536, %edx
	adcl	$65537, 0x10
	adc	%al, %bl
	adcb	%cl, 0x10
	adc	%ax, %bx
	adcw	%cx, 0x10
	adc	0x10, %cl
	adc	0x10, %cx
	adc	0x10, %ecx

	mov	$0x18, %ax
	mov	%ax, %ss
