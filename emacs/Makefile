all:dummy-gdb.exe

dummy-gdb.exe:dummy-gdb.cpp
	g++ -g3 $< -o $@

TAGS:dummy-gdb.exe
	mktags.exe -e $<
