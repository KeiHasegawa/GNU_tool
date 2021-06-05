all:dummy-gdb.exe TAGS

dummy-gdb.exe:dummy-gdb.cpp
	g++ -g3 $< -o $@

TAGS:dummy-gdb.exe
	mktags.exe -e $<
