all:dummy-gdb2.exe TAGS

dummy-gdb2.exe:dummy-gdb2.cpp
	g++ -g3 $< -o $@

TAGS:dummy-gdb2.exe
	mktags.exe -e $<
