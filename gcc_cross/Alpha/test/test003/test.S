	.text
start:
	lda	$29, 0x8000($31)
	lda	$29, 0x100($29)
	lda	$30, stack
	jsr	$26, func
end:
	halt

func:
	ret
	
