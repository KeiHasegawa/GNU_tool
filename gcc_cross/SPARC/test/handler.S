/*
	http://icps.u-strasbg.fr/people/loechner/public_html/enseignement/SPARC/sparcstack.html
 */
	.text
	.global window_overflow
        /* a SAVE instruction caused a trap */
window_overflow:
        /* rotate WIM on bit right, we have 8 windows */
        mov	%wim, %l3
        sll	%l3, 7, %l4
        srl	%l3, 1, %l3
        or	%l3, %l4, %l3
        and	%l3, 0xff, %l3

        /* disable WIM traps */
        mov	%g0, %wim
        nop
	nop
	nop

        /* point to correct window */
        save

        /* dump registers to stack */
        std	%l0, [%sp +  0]
        std	%l2, [%sp +  8]
        std	%l4, [%sp + 16]
        std	%l6, [%sp + 24]
        std	%i0, [%sp + 32]
        std	%i2, [%sp + 40]
        std	%i4, [%sp + 48]
        std	%i6, [%sp + 56]

        /* back to where we should be */
        restore

        /* set new value of window */
        mov	%l3, %wim
        nop
	nop
	nop

        /* go home */
        jmp	%l1
        rett	%l2

	.global window_underflow
        /* a RESTORE instruction caused a trap */
window_underflow:
        
        /* rotate WIM on bit LEFT, we have 8 windows */ 
        mov %wim, %l3
        srl %l3, 7, %l4
        sll %l3, 1, %l3
        or  %l3, %l4, %l3
        and %l3, 0xff, %l3

        /* disable WIM traps */
        mov %g0, %wim
        nop
	nop
	nop

        /* point to correct window */
        restore
        restore

        /* dump registers to stack */
        ldd	[%sp +  0], %l0
        ldd	[%sp +  8], %l2
        ldd	[%sp + 16], %l4
        ldd	[%sp + 24], %l6
        ldd	[%sp + 32], %i0
        ldd	[%sp + 40], %i2
        ldd	[%sp + 48], %i4
        ldd	[%sp + 56], %i6

        /* back to where we should be */
        save
        save

        /* set new value of window */
        mov	%l3, %wim
        nop
	nop
	nop

        /* go home */
        jmp	%l1
        rett	%l2
