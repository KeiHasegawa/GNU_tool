all:test015.objdump test015.lof

include ../Makefile.common

test015.elf:test015.o test015.x
	mcore-elf-ld -o $@ $< -T $(basename $<).x

test015.log:test015.elf
	echo quit | wdog.exe -v mcore-elf-gdb -q -x gdbcom $< > $@ 2>&1 &
	sleep 1
	kill -INT `ps -ef | grep mcore-elf-gdb | awk '{print $$2}'`

test015.lof:test015.log
	grep -q 'Program received signal SIGINT, Interrupt.' $< || grep -q 'Program received signal SIGINT, Interrupt.' $<
	touch $@

