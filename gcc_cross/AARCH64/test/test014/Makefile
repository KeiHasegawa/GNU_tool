all:test014.objdump test014.lof

start.o:start.S
	aarch64-elf-as -o start.o -g start.S

test014.s:test014.c
	aarch64-elf-gcc -o test014.s -g -S test014.c

test014.o:test014.s
	aarch64-elf-as -o test014.o test014.s

test014.elf:start.o test014.o test014.x
	aarch64-elf-ld -o test014.elf start.o test014.o \
	-T test014.x -Map test014.map

test014.objdump:test014.elf
	aarch64-elf-objdump -x -t -d -g test014.elf > test014.objdump

test014.log:test014.elf gdbcom
	wdog.exe -v aarch64-elf-gdb -q -x gdbcom $< > $@

test014.lof:test014.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *.s *.o *.elf *.map *.objdump *.log *~


