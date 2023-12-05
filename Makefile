PROG=programmet.exe
TEST=check.exe
SOURCES=isValidPassword.cpp
DEPS=
CC=gcc
CFLAGS=-Wall -Werror
DEBUG?=1
GTEST = gtest
LIBGTEST = C:\msys64\mingw64\lib\libgtest_main.a C:\msys64\mingw64\lib\libgtest.a

ifeq ($(DEBUG), 1)
    CFLAGS += -g
    OUTPUTDIR=bin/debug
    PROG=programmet-debug.exe
else
    CFLAGS += -g0 -O3
    OUTPUTDIR=bin/release
endif

OBJS =  $(addprefix $(OUTPUTDIR)/,$(SOURCES:.cpp=.o))

$(PROG): $(OUTPUTDIR) $(OBJS)
	$(CC)	$(CFLAGS)	-o	$@	$(OBJS)	-lstdc++

$(OUTPUTDIR)/%.o:	%.cpp	$(DEPS)
	$(CC)	$(CFLAGS) -o	$@	-c	$<

clean:
	@del	/q	"$(OUTPUTDIR)"
	@del	/q	$(PROG)

$(OUTPUTDIR):
	@mkdir	-p	"$(OUTPUTDIR)"

# Add the following rules for the test target
TEST=check.exe

$(TEST):	password.o PasswordTests.cpp
	g++	-o	$@	$^	$(CFLAGS)	-I	$(GTEST)	$(LIBGTEST)	-lstdc++

test: $(TEST)
	./$(TEST)

.PHONY: clean test
