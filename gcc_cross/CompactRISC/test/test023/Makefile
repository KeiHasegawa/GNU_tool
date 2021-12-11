all:test023.objdump test023.lof

include ../Makefile.common

test023.elf:test023.o test023.x Makefile
	cr16-elf-ld -o $@ test023.o -T test023.x -Map test023.map \
	--defsym label=0x1000 --defsym label2=0x10

test023.o.objdump:test023.o
	cr16-elf-objdump -d --dwarf=rawline,decodedline $< > $@

test023.objdump:test023.elf
	cr16-elf-objdump -d --dwarf=rawline,decodedline $< > $@
