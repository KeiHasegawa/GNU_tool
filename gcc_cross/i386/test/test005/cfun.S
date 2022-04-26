	.file	"cfun.c"
	.code16gcc
	.text
.Ltext0:
	.cfi_sections	.debug_frame
	.globl	int17_function
	.type	int17_function, @function
int17_function:
.LFB0:
	.file 1 "cfun.c"
	.loc 1 47 1
	.cfi_startproc
	push	%bp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	%sp, %bp
	.cfi_def_cfa_register 5
	.loc 1 48 3
/APP
/  48 "cfun.c" 1
	int3
/  0 "" 2
	.loc 1 49 1
/NO_APP
	nop
	pop	%bp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	int17_function, .-int17_function
	.globl	int19_function
	.type	int19_function, @function
int19_function:
.LFB1:
	.loc 1 55 1
	.cfi_startproc
	push	%bp
	.cfi_def_cfa_offset 4
	.cfi_offset 5, -4
	mov	%sp, %bp
	.cfi_def_cfa_register 5
	sub	$2, %sp
	movw	2(%bp), %ax
	movw	%ax, -2(%bp)
	.loc 1 56 1
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	int19_function, .-int19_function
.Letext0:
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.long	0x6d
	.value	0x4
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
	.byte	0x34
	.byte	0x1c
	.long	0x31
	.uleb128 0x3
	.byte	0x2
	.byte	0x7
	.long	.LASF4
	.uleb128 0x4
	.long	.LASF5
	.byte	0x1
	.byte	0x36
	.byte	0x6
	.long	.LFB1
	.long	.LFE1-.LFB1
	.uleb128 0x1
	.byte	0x9c
	.long	0x5e
	.uleb128 0x5
	.long	.LASF6
	.byte	0x1
	.byte	0x36
	.byte	0x1e
	.long	0x25
	.uleb128 0x2
	.byte	0x91
	.sleb128 -10
	.byte	0
	.uleb128 0x6
	.long	.LASF7
	.byte	0x1
	.byte	0x2e
	.byte	0x6
	.long	.LFB0
	.long	.LFE0-.LFB0
	.uleb128 0x1
	.byte	0x9c
	.byte	0
	.section	.debug_abbrev,"",@progbits
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
	.uleb128 0x16
	.byte	0
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
	.uleb128 0xe
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0x2e
	.byte	0x1
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
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0x5
	.byte	0
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
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x6
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
	.byte	0
	.section	.debug_aranges,"",@progbits
	.long	0x1c
	.value	0x2
	.long	.Ldebug_info0
	.byte	0x4
	.byte	0
	.value	0
	.value	0
	.long	.Ltext0
	.long	.Letext0-.Ltext0
	.long	0
	.long	0
	.section	.debug_line,"",@progbits
.Ldebug_line0:
	.section	.debug_str,"MS",@progbits,1
.LASF4:
	.string	"short unsigned int"
.LASF0:
	.string	"GNU C17 10.2.0 -m16 -mtune=i386 -march=i386 -g"
.LASF5:
	.string	"int19_function"
.LASF2:
	.string	"/home/khasegawa/lang/53_GNU_tool/gcc_cross/i386/test/test005"
.LASF6:
	.string	"seq_nr"
.LASF1:
	.string	"cfun.c"
.LASF3:
	.string	"uint16_t"
.LASF7:
	.string	"int17_function"
	.ident	"GCC: (GNU) 10.2.0"
