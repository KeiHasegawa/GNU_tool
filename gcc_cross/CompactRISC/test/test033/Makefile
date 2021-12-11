all:test033.objdump test033.lof

include ../Makefile.common

test033.elf:start.o test033.o test033.x Makefile
	cr16-elf-ld -o $@ start.o test033.o -T test033.x \
	-Map test033.map --defsym _var=0xc

test033.o.objdump:test033.o
	cr16-elf-objdump -x -d --dwarf=rawline,decodedline $< > $@

test033.objdump:test033.elf
	cr16-elf-objdump -x -d --dwarf=rawline,decodedline $< > $@

test033.objdump.2:test033.elf
	cr16-elf-objdump -x -d -g $< > $@

test033.lof:test033.log

