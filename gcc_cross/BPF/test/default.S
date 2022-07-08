	.text
start:
	mov	%r9, stack
	mov	%fp, stack
	call	main
end:
	mov	%r0, %r0
	
