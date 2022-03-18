	.text
start:
	srll	rr4, #5
	slll	rr4, #5
	
	srlb	rh0, #7
	sllb	rh0, #7
	
	srl	r3, #3
	sll	r3, #3
	
	sral	rr2, #5
	slal	rr2, #5
	
	srab	rl0, #4
	slab	rl0, #4
	
	sra	r1, #3
	sla	r1, #3
	
	soutib	@r1, @r2, r3
	sotirb	@r1, @r2, r3
	
	souti	@r1, @r2, r3
	sotir	@r1, @r2, r3
	
	soutdb	@r1, @r2, r3
	sotdrb	@r1, @r2, r3
	
	soutd	@r1, @r2, r3
	sotdr	@r1, @r2, r3
	
	sinirb	@r1, @r2, r3
	sinib	@r1, @r2, r3
	
	sinir	@r1, @r2, r3
	sini	@r1, @r2, r3	

	sindrb	@r1, @r2, r3
	sindb	@r1, @r2, r3
	
	sindr	@r1, @r2, r3
	sind	@r1, @r2, r3
	
	outib	@r1, @r2, r3
	otirb	@r1, @r2, r3
	
	outi	@r1, @r2, r3
	otir	@r1, @r2, r3

	outdb	@r1, @r2, r3
	otdrb	@r1, @r2, r3
	
	outd	@r1, @r2, r3
	otdr	@r1, @r2, r3
	
	ldirb	@r1, @r2, r3
	ldib	@r1, @r2, r3
	
	ldir	@r1, @r2, r3
	ldi	@r1, @r2, r3
	
	lddrb	@r1, @r2, r3
	lddb	@r1, @r2, r3
	
	lddr	@r1, @r2, r3
	ldd	@r1, @r2, r3
	
	inirb	@r1, @r2, r3
	inib	@r1, @r2, r3
	
	inir	@r1, @r2, r3
	indb	@r1, @r2, r3
	
	indrb	@r1, @r2, r3
	indb	@r1, @r2, r3

	indr	@r1, @r2, r3
	ind	@r1, @r2, r3

end:
	nop
	
