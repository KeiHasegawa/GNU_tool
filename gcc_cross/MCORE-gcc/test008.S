	.file	"test008.c"
	.text
.Ltext0:
	.align	1
	.export	f
	.type	f, @function
f:
.LFB0:
.LM1:
	subi	sp,16
.LCFI0:	
	stw	r8,(sp,8)
.LCFI1:	
	mov	r8,sp
.LCFI2:
	stw	r2,(r8)
	stw	r3,(r8,4)
.LM2:
	ldw	r6,(r8)
	ldw	r7,(r8,4)
	addu	r7,r6
.LM3:
	mov	r2,r7
	mov	sp,r8
	ldw	r8,(sp,8)
	addi	sp,16
	jmp	r15
.LFE0:
	.size	f, .-f
	.align	1
	.export	main
	.type	main, @function
main:
.LFB1:
.LM4:
	subi	sp,8
.LCFI3:	
	stw	r15,(sp)
	stw	r8,(sp,4)
.LCFI4:	
	mov	r8,sp
.LCFI5:
.LM5:
	movi	r3,6
	movi	r2,5
	jbsr	f
	mov	r7,r2
.LM6:
	mov	r2,r7
	mov	sp,r8
	ldw	r15,(sp)
	ldw	r8,(sp,4)
	addi	sp,8
	jmp	r15
.LFE1:
	.size	main, .-main
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
.LSFDE2:
	.long	.LEFDE2-.LASFDE2
.LASFDE2:
	.long	.Lframe0
	.long	.LFB1
	.long	.LFE1-.LFB1
	.byte	0x4
	.long	.LCFI3-.LFB1
	.byte	0xe
	.uleb128 0x8
	.byte	0x4
	.long	.LCFI4-.LCFI3
	.byte	0x11
	.uleb128 0xf
	.sleb128 1
	.byte	0x11
	.uleb128 0x8
	.sleb128 2
	.byte	0x4
	.long	.LCFI5-.LCFI4
	.byte	0xd
	.uleb128 0x8
	.align	2
.LEFDE2:
	.text
.Letext0:
	.section .debug_info
.Ldebug_info0:
	.long	0x6e
	.short	0x4
	.long	.Ldebug_abbrev0
	.byte	0x4
	.uleb128 0x1
	.long	.LASF0
	.byte	0xc
	.long	.LASF1
	.long	.LASF2
	.long	.Ltext0
	.long	.Letext0-.Ltext0
	.long	.Ldebug_line0
	.uleb128 0x2
	.long	.LASF3
	.byte	0x1
	.byte	0x6
	.byte	0x5
	.long	0x3b
	.long	.LFB1
	.long	.LFE1-.LFB1
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0x3
	.byte	0x4
	.byte	0x5
	.string	"int"
	.uleb128 0x4
	.string	"f"
	.byte	0x1
	.byte	0x1
	.byte	0x5
	.long	0x3b
	.long	.LFB0
	.long	.LFE0-.LFB0
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0x5
	.string	"a"
	.byte	0x1
	.byte	0x1
	.byte	0xb
	.long	0x3b
	.uleb128 0x2
	.byte	0x78
	.sleb128 0
	.uleb128 0x5
	.string	"b"
	.byte	0x1
	.byte	0x1
	.byte	0x12
	.long	0x3b
	.uleb128 0x2
	.byte	0x78
	.sleb128 4
	.byte	0
	.byte	0
	.section .debug_abbrev
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1b
	.uleb128 0xe
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x10
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x2e
	.byte	0
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.byte	0
	.section .debug_aranges
	.long	0x1c
	.short	0x2
	.long	.Ldebug_info0
	.byte	0x4
	.byte	0
	.short	0
	.short	0
	.long	.Ltext0
	.long	.Letext0-.Ltext0
	.long	0
	.long	0
	.section .debug_line
.Ldebug_line0:
	.long	.LELT0-.LSLT0
.LSLT0:
	.short	0x4
	.long	.LELTP0-.LASLTP0
.LASLTP0:
	.byte	0x1
	.byte	0x1
	.byte	0x1
	.byte	0xf6
	.byte	0xf2
	.byte	0xd
	.byte	0
	.byte	0x1
	.byte	0x1
	.byte	0x1
	.byte	0x1
	.byte	0
	.byte	0
	.byte	0
	.byte	0x1
	.byte	0
	.byte	0
	.byte	0x1
	.byte	0
	.string	"test008.c"
	.uleb128 0
	.uleb128 0
	.uleb128 0
	.byte	0
.LELTP0:
	.byte	0
	.uleb128 0x5
	.byte	0x2
	.long	.LM1
	.byte	0x18
	.byte	0x5
	.uleb128 0x1
	.byte	0
	.uleb128 0x5
	.byte	0x2
	.long	.LM2
	.byte	0x18
	.byte	0x5
	.uleb128 0xc
	.byte	0
	.uleb128 0x5
	.byte	0x2
	.long	.LM3
	.byte	0x18
	.byte	0x5
	.uleb128 0x1
	.byte	0
	.uleb128 0x5
	.byte	0x2
	.long	.LM4
	.byte	0x1a
	.byte	0x5
	.uleb128 0x1
	.byte	0
	.uleb128 0x5
	.byte	0x2
	.long	.LM5
	.byte	0x18
	.byte	0x5
	.uleb128 0xa
	.byte	0
	.uleb128 0x5
	.byte	0x2
	.long	.LM6
	.byte	0x18
	.byte	0x5
	.uleb128 0x1
	.byte	0
	.uleb128 0x5
	.byte	0x2
	.long	.Letext0
	.byte	0
	.uleb128 0x1
	.byte	0x1
.LELT0:
	.section .debug_str
.LASF0:
	.string	"GNU C17 10.2.0 -funsigned-bitfields -g"
.LASF2:
	.string	"/media/ca850f52-0605-42a7-9fd4-899de9edf461/work/test_mcore.008"
.LASF1:
	.string	"test008.c"
.LASF3:
	.string	"main"
	.ident	"GCC: (GNU) 10.2.0"
