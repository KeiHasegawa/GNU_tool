	.text
	.align 4
	.global _f
_f:
	LINK 0;
	[FP+8] = R0;
	[FP+12] = R1;
	R1 = [FP+8];
	R0 = [FP+12];
	R0 = R1 + R0;
	P2 = R0;
	R0 = P2;
	UNLINK;
	rts;
	
