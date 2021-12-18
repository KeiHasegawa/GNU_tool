all:test038.objdump test038.lof

include ../Makefile.common

test038.elf:test038.o test038.x
	cr16-elf-ld -o $@ $< -T $(basename $<).x

test038.log:test038.elf
	echo quit | wdog.exe -v cr16-elf-gdb -q -x gdbcom $< > $@ 2>&1 &
	sleep 1
	kill -INT `ps -ef | grep cr16-elf-gdb | awk '{print $$2}'`

test038.lof:test038.log
	grep -q 'Program received signal SIGINT, Interrupt.' $< || grep -q 'Program received signal SIGINT, Interrupt.' $<
	touch $@

