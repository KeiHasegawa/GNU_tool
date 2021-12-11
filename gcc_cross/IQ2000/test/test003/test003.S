	.text
start:
	lui	%3,%hi(func)
	addiu	%3,%3,%lo(func)
	jalr	%31,%3
	nop
	nop

func:
	j	%31
	nop

	
	
