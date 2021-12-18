all:test018.objdump test018.lof

include ../Makefile.common

test018.elf:test018.o test018.x
	m68hc11-elf-ld -o $@ $< -T $(basename $<).x

test018.log:test018.elf
	echo quit | wdog.exe -v m68hc11-elf-gdb -q -x gdbcom $< > $@ 2>&1 &
	sleep 1
	kill -INT `ps -ef | grep m68hc11-elf-gdb | awk '{print $$2}'`

test018.lof:test018.log
	grep -q 'Program received signal SIGINT, Interrupt.' $< || grep -q 'Program received signal SIGINT, Interrupt.' $<
	touch $@

