	.section	.text
	.align 4
	.global	f
f:
	addi     sp, sp, -16
	sw       (sp+8), fp
	sw       (sp+4), ra
	or       fp, sp, r0
	addi     fp, fp, 16
	
	sw       (fp+0), r1
	sw       (fp+-4), r2
	lw       r2, (fp+0)
	lw       r1, (fp+-4)
	add      r1, r2, r1
	
	lw       fp, (sp+8)
	lw       ra, (sp+4)
	addi     sp, sp, 16
	b        ra
