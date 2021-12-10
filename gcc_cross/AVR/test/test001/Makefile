all:start.elf start.objdump start.lof

start.o:start.S
	avr-elf-as -g -o start.o start.S

start.elf:start.o start.x
	avr-elf-ld -o start.elf start.o -T start.x -Map start.map

start.objdump:start.elf
	avr-elf-objdump -x -d start.elf > start.objdump

start.log:start.elf gdbcom
	wdog.exe -v avr-elf-gdb -q -x gdbcom $< > $@

start.lof:start.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f start.o start.elf start.map start.objdump *.log *~
