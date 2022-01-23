	.section .text
	.align 1
	.global _f
_f:
.LFB0:
	add -8,sp
.LCFI0:
	st.w r31,4[sp]
	st.w r29,0[sp]
	add -8,sp
.LCFI1:
	mov sp,r29
.LCFI2:
	st.w r6,4[r29]
	st.w r7,0[r29]
	
	ld.w 4[r29],r11
	ld.w 0[r29],r10
	add r11,r10
	
	mov r29,sp
	ld.w 12[sp],r31
	ld.w 8[sp],r29
	addi 16,sp,sp
	jmp [r31]
.LFE0:
	.size	_f, .-_f
	.section	.debug_frame,"",@progbits
.Lframe0:
	.4byte	.LECIE0-.LSCIE0
.LSCIE0:
	.4byte	0xffffffff
	.byte	0x3
	.string	""
	.uleb128 0x1
	.sleb128 -4
	.uleb128 0x1f
	.byte	0xc
	.uleb128 0x3
	.uleb128 0
	.align 2
.LECIE0:
.LSFDE0:
	.4byte	.LEFDE0-.LASFDE0
.LASFDE0:
	.4byte	.Lframe0
	.4byte	.LFB0
	.4byte	.LFE0-.LFB0
	.byte	0x4
	.4byte	.LCFI0-.LFB0
	.byte	0xe
	.uleb128 0x4
	.byte	0x4
	.4byte	.LCFI1-.LCFI0
	.byte	0xe
	.uleb128 0xc
	.byte	0x9d
	.uleb128 0x1
	.byte	0x4
	.4byte	.LCFI2-.LCFI1
	.byte	0xd
	.uleb128 0x1d
	.align 2
.LEFDE0:
	.ident	"GCC: (GNU) 10.2.0"
