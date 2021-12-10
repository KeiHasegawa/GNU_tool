all:start.elf start.objdump start.lof

start.o:start.S
	avr-elf-as -g -o $@ $<

#func.o:func.s
#	avr-elf-as -g -o $@ $<

#func.s:func.c
#	avr-elf-gcc -S -o func.s func.c

func.o:func.c
	avr-elf-gcc -g -c -o func.o func.c

func.o:Makefile

start.elf:start.o func.o test003.x
	avr-elf-ld -o start.elf start.o func.o -Map start.map -T test003.x

start.objdump:start.elf
	avr-elf-objdump -x -d start.elf > start.objdump

start.log:start.elf gdbcom
	wdog.exe -v avr-elf-gdb -q -x gdbcom $< > $@

start.lof:start.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f start.o func.o func.s start.elf start.map start.objdump *.log *~
