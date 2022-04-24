	.text
start:
	mov	%cr0, %eax
	or	$0x01, %al
	mov	%eax, %cr0
	ljmp	$8, $0x10000
end:
	nop
