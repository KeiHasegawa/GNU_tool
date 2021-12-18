all:test012.objdump test012.lof

include ../Makefile.common

test012.elf:test012.o test012.x
	msp430-elf-ld -o $@ $< -T $(basename $<).x

test012.log:test012.elf
	echo quit | wdog.exe -v msp430-elf-gdb -q -x gdbcom $< > $@ 2>&1 &
	sleep 1
	kill -INT `ps -ef | grep msp430-elf-gdb | awk '{print $$2}'`

test012.lof:test012.log
	grep -q 'Program received signal SIGINT, Interrupt.' $< || grep -q 'Program received signal SIGINT, Interrupt.' $<
	touch $@

