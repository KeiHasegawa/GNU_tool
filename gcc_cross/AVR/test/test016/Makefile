all:test016.objdump test016.lof

include ../Makefile.common

test016.elf:test016.o test016.x
	avr-elf-ld -o $@ $< -T $(basename $<).x

test016.log:test016.elf
	echo quit | wdog.exe -v avr-elf-gdb -q -x gdbcom $< > $@ 2>&1 &
	sleep 1
	kill -INT `ps -ef | grep avr-elf-gdb | awk '{print $$2}'`

test016.lof:test016.log
	grep -q 'Program received signal SIGINT, Interrupt.' $< || grep -q 'Program received signal SIGINT, Interrupt.' $<
	echo PASS
	touch $@

