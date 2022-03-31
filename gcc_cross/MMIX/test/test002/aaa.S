! mmixal:= 8H LOC Data_Section
	.text ! mmixal:= 9H LOC 8B
	.p2align 2
	LOC @+(4-@)&3
	.global f
f	IS @
	SUBU $254,$254,16
	STOU $253,$254,8
	ADDU $253,$254,16
	SET $2,$0
	SUBU $0,$253,12
	STTU $2,$0,0
	SUBU $0,$253,16
	STTU $1,$0,0
	SUBU $0,$253,12
	SUBU $1,$253,16
	LDT $2,$0,0
	LDT $0,$1,0
	ADDU $0,$2,$0
	LDO $253,$254,8
	ADDU $254,$254,16
	POP 1,0

	.p2align 2
	LOC @+(4-@)&3
	.global main
main	IS @
	SUBU $254,$254,8
	STOU $253,$254,0
	ADDU $253,$254,8
	GET $0,rJ
	SETL $2,#5
	SETL $3,#6
	PUSHJ $1,f
	PUT rJ,$0
	SET $0,$1
	LDO $253,$254,0
	ADDU $254,$254,8
	POP 1,0

	.data ! mmixal:= 8H LOC 9B
