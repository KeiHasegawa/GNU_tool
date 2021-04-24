PROG = bbprof.exe

all:$(PROG)

SRCS = bbprof3.cpp

OBJS = $(SRCS:.cpp=.o)

BINUTILS = /home/khasegawa/binutils-2.36.1-2.src/binutils-2.36.1

UNAME := $(shell uname)
ifneq (,$(findstring CYGWIN,$(UNAME)))
	LIB_INTL_FLAGS = -lintl
endif

LIB_FLAG = -lbfd -liberty -L$(BINUTILS)/libiberty -ldl -lz $(LIB_INTL_FLAGS)

$(PROG):$(OBJS)
	$(CXX) -o $(PROG) $(OBJS) $(LIB_FLAG)

DEBUG_FLAG = -g

CXX_FLAG = $(DEBUG_FLAG) -DPACKAGE

%.o : %.cpp
	$(CXX) $(CXX_FLAG) $< -c -o $@

clean:
	rm -f $(PROG) $(OBJS)
