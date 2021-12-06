all:test014.elf test014.objdump TAGS test014.lof

test014.elf:test014.c
	h8300-elf-gcc -g3 -o test014.elf test014.c -Wl,-Map -Wl,test014.map

test014.elf:Makefile

test014.objdump:test014.elf
	h8300-elf-objdump -x -d test014.elf > test014.objdump

TAGS:test014.elf
	mktags.exe -o TAGS -e test014.elf

test014.log:test014.elf
	wdog.exe -v h8300-elf-gdb -q -x gdbcom $< > $@

test014.lof:test014.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *.elf *.map *.objdump TAGS *.log *~
