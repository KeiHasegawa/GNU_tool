	.stabs	"/home/khasegawa/lang/53_GNU_tool/gcc_cross/i960/test/test002/",100,0,0,Ltext0
	.stabs	"test.c",100,0,0,Ltext0
	.text
Ltext0:
	.stabs	"gcc2_compiled.",60,0,0,0
	.stabs	"int:t1=r1;-2147483648;2147483647;",128,0,0,0
	.stabs	"char:t2=@s8;r2;0;255;",128,0,0,0
	.stabs	"long int:t3=r3;-2147483648;2147483647;",128,0,0,0
	.stabs	"unsigned int:t4=r4;0000000000000;0037777777777;",128,0,0,0
	.stabs	"long unsigned int:t5=r5;0000000000000;0037777777777;",128,0,0,0
	.stabs	"long long int:t6=@s64;r6;01000000000000000000000;0777777777777777777777;",128,0,0,0
	.stabs	"long long unsigned int:t7=@s64;r7;0000000000000;01777777777777777777777;",128,0,0,0
	.stabs	"short int:t8=@s16;r8;-32768;32767;",128,0,0,0
	.stabs	"short unsigned int:t9=@s16;r9;0;65535;",128,0,0,0
	.stabs	"signed char:t10=@s8;r10;-128;127;",128,0,0,0
	.stabs	"unsigned char:t11=@s8;r11;0;255;",128,0,0,0
	.stabs	"float:t12=r1;4;0;",128,0,0,0
	.stabs	"double:t13=r1;8;0;",128,0,0,0
	.stabs	"long double:t14=r1;16;0;",128,0,0,0
	.stabs	"complex int:t15=s8real:1,0,32;imag:1,32,32;;",128,0,0,0
	.stabs	"complex float:t16=R3;8;0;",128,0,0,0
	.stabs	"complex double:t17=R3;16;0;",128,0,0,0
	.stabs	"complex long double:t18=R3;32;0;",128,0,0,0
	.stabs	"void:t19=19",128,0,0,0
	.stabs	"__builtin_va_list:t20=ar21=r21;0000000000000;0037777777777;;0;1;4",128,0,0,0
	.stabs	"_Bool:t22=@s8;-16;",128,0,0,0
	.align 4
	.globl _f
	#  Function 'f'
	#  Registers used: g0 g1 g4 g5 fp 
_f:
	.stabd	68,0,2
	addo	16,sp,sp
	#Prologue stats:
	#  Total Frame Size: 16 bytes
	#  Local Variable Size: 16 bytes
	#End Prologue#
	st	g0,64(fp)
	st	g1,68(fp)
	.stabd	68,0,3
	ld	64(fp),g5
	ld	68(fp),g4
	addo	g5,g4,g4
	.stabd	68,0,4
	mov	g4,g0
Li960R1:	ret
Lscope0:	
	.align 4
	.globl _main
	#  Function 'main'
	#  Registers used: g0 g1 g4 fp sp 
	#		   r3* 
_main:
	.stabd	68,0,7
	callx	___main
	.stabd	68,0,8
	mov	5,g0
	mov	6,g1
	callx	_f
	mov	g0,g4
	.stabd	68,0,9
	mov	g4,g0
Li960R2:	ret
Lscope1:
	.stabs	"f:F1",36,0,2,_f
	.stabs	"a:p1",160,0,1,64
	.stabs	"b:p1",160,0,1,68
	.stabs	"",36,0,0,Lscope0-_f
	.stabs	"main:F1",36,0,7,_main		
	.stabs	"",36,0,0,Lscope1-_main	
