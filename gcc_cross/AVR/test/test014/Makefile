all:test014.objdump test014.lof

include ../Makefile.common

test014.elf:test014.o test014.x
	avr-elf-ld -o $@ $< -T test014.x

test014.log:test014.elf gdbcom
	echo quit | wdog.exe -v avr-elf-gdb -q -x gdbcom $< > $@ 2>&1

test014.lof:test014.log
