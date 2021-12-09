all:start.elf start.elf.objdump start.lof

start.o:start.S
	arm-elf-as -g start.S -o start.o

start.elf:start.o start.x
	arm-elf-ld -o start.elf start.o -T start.x -Map start.map

start.elf.objdump:start.elf
	arm-elf-objdump -x -d -g start.elf > start.elf.objdump

start.log:start.elf gdbcom
	wdog.exe -v arm-elf-gdb -q -x gdbcom $< > $@

start.lof:start.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f start.o start.elf start.elf.objdump start.map *~
