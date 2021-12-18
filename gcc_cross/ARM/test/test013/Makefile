all:test013.objdump test013.lof

include ../Makefile.common

test013.elf:test013.o test013.x
	arm-elf-ld -o $@ $< -T $(basename $<).x

test013.log:test013.elf
	echo quit | wdog.exe -v arm-elf-gdb -q -x gdbcom $< > $@ 2>&1 &
	sleep 1
	kill -INT `ps -ef | grep arm-elf-gdb | awk '{print $$2}'`

test013.lof:test013.log
	grep -q 'Program received signal SIGINT, Interrupt.' $< || grep -q 'Program received signal SIGINT, Interrupt.' $<
	touch $@

