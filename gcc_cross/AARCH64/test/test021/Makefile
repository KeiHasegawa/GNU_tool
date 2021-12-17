all:test021.objdump test021.lof

include ../Makefile.common

test021.elf:test021.o test021.x
	aarch64-elf-ld -o $@ $< -T $(basename $<).x

test021.log:test021.elf
	echo quit | wdog.exe -v aarch64-elf-gdb -q -x gdbcom $< > $@ 2>&1 &
	sleep 1
	kill -INT `ps -ef | grep aarch64-elf-gdb | awk '{print $$2}'`

test021.lof:test021.log
	grep -q 'Program received signal SIGINT, Interrupt.' $<
	touch $@

