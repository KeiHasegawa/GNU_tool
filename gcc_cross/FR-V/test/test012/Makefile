all:test014.objdump test014.lof

include ../Makefile.common

test014.elf:test014.o test014.x
	frv-elf-ld -o $@ $< -T $(basename $<).x

test014.log:test014.elf
	echo quit | wdog.exe -v frv-elf-gdb -q -x gdbcom $< > $@ 2>&1 &
	sleep 1
	kill -INT `ps -ef | grep frv-elf-gdb | awk '{print $$2}'`

test014.lof:test014.log
	grep -q 'Program received signal SIGINT, Interrupt.' $< || grep -q 'Program received signal SIGINT, Interrupt.' $<
	echo PASS
	touch $@

