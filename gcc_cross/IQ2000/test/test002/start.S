	.text
start:
	lui	%29,%hi(stack)
	addiu	%29,%29,%lo(stack)
	lui	%3,%hi(main)
	addiu	%3,%3,%lo(main)
	jalr	%31,%3
	nop
end:
	nop
	
