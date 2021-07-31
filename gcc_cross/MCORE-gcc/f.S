	.text
f:
.LFB0:
	subi	sp,16
.LCFI0:	
	stw	r8,(sp,8)
.LCFI1:	
	mov	r8,sp
.LCFI2:
	stw	r2,(r8)
	stw	r3,(r8,4)
	ldw	r6,(r8)
	ldw	r7,(r8,4)
	addu	r7,r6
	mov	r2,r7
	mov	sp,r8
	ldw	r8,(sp,8)
	addi	sp,16
	jmp	r15
.LFE0:

	.section .debug_frame
.Lframe0:
	.long	.LECIE0-.LSCIE0
.LSCIE0:
	.long	0xffffffff
	.byte	0x3
	.string	""
	.uleb128 0x1
	.sleb128 -4
	.uleb128 0x14
	.byte	0xc
	.uleb128 0
	.uleb128 0
	.byte	0x9
	.uleb128 0x14
	.uleb128 0xf
	.align	2
.LECIE0:
.LSFDE0:
	.long	.LEFDE0-.LASFDE0
.LASFDE0:
	.long	.Lframe0
	.long	.LFB0
	.long	.LFE0-.LFB0
	.byte	0x4
	.long	.LCFI0-.LFB0
	.byte	0xe
	.uleb128 0x10
	.byte	0x4
	.long	.LCFI1-.LCFI0
	.byte	0x11
	.uleb128 0x8
	.sleb128 2
	.byte	0x4
	.long	.LCFI2-.LCFI1
	.byte	0xd
	.uleb128 0x8
	.align	2
.LEFDE0:
