all:test014.objdump test014.lof

include ../Makefile.common

test014.a:test014a.o test014b.o test014c.o
	ar r $@ test014a.o test014b.o test014c.o

test014.elf:start.o test014.o test014.a test014.x
	cr16-elf-ld -o $@ start.o test014.o test014.a \
	-T test014.x --defsym _heap=0x1000

test014.lof:test014.log
