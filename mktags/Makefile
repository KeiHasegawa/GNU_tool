PROG = mktags.exe

all:$(PROG)

OBJS = mktags.o my_dwarf.o my_objdump.o

UNAME := $(shell uname)

ifneq (,$(findstring CYGWIN,$(UNAME)))
	BINUTILS_DIR = d:/home/khasegawa/binutils-2.36.1-2.src/binutils-2.36.1
else
	BINUTILS_DIR = /home/khasegawa/binutils-2.36.1-2.src/binutils-2.36.1
endif

LIB_BFD =  $(BINUTILS_DIR)/bfd/libbfd.a
LIB_LIBIBERTY = $(BINUTILS_DIR)/libiberty/libiberty.a

ifneq (,$(findstring CYGWIN,$(UNAME)))
	LIB_INTL_FLAG = -lintl
endif

EXTRA_LIBS = $(BINUTILS_DIR)/binutils/bucomm.o \
	     $(BINUTILS_DIR)/binutils/debug.o \
	     $(BINUTILS_DIR)/binutils/elfcomm.o \
	     $(BINUTILS_DIR)/binutils/filemode.o \
	     $(BINUTILS_DIR)/binutils/prdbg.o \
	     $(BINUTILS_DIR)/binutils/rdcoff.o \
	     $(BINUTILS_DIR)/binutils/rddbg.o \
	     $(BINUTILS_DIR)/binutils/stabs.o \
	     $(BINUTILS_DIR)/binutils/version.o \
	     $(BINUTILS_DIR)/opcodes/libopcodes.a \
	     $(BINUTILS_DIR)/libctf/.libs/libctf.a \
	     $(LIB_BFD) $(LIB_LIBIBERTY) -ldl -lz $(LIB_INTL_FLAG)

$(PROG):$(OBJS)
	g++ -o $(PROG) $(OBJS) $(EXTRA_LIBS)

EXTRA_DEFINES = -DPACKAGE

EXTRA_INCLUDES = -I$(BINUTILS_DIR)/binutils -I$(BINUTILS_DIR)/include \
		 -I$(BINUTILS_DIR)/bfd

%.o : %.cpp
	g++ -g3 -O0 -c $(EXTRA_DEFINES) $(EXTRA_INCLUDES) $< -o $@

%.o : %.c
	gcc -g3 -O0 -c $(EXTRA_INCLUDES) $< -o $@

clean:
	rm -f $(PROG) $(OBJS)
