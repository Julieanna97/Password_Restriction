PROG = programmet.exe
TEST = check.exe
SOURCES = main.cpp password.cpp
DEPS =
CC = g++
CFLAGS = -Wall -Werror
DEBUG ?= 1
GTEST = gtest
LIBGTEST = C:\msys64\mingw64\lib\libgtest_main.a C:\msys64\mingw64\lib\libgtest.a

ifeq ($(DEBUG), 1)
    CFLAGS += -g
    OUTPUTDIR = bin/debug
    PROG = programmet-debug.exe
else
    CFLAGS += -g0 -O3
    OUTPUTDIR = bin/release
endif

OBJS = $(addprefix $(OUTPUTDIR)/,$(SOURCES:.cpp=.o))

$(PROG): $(OUTPUTDIR) $(OBJS)
	$(CC)	$(CFLAGS)	-o	$(PROG)	$(OBJS)

$(OUTPUTDIR)/%.o: %.cpp $(DEPS)
	$(CC)	$(CFLAGS)	-o	$@	-c	$<

clean:
	@rm	-rf	"$(OUTPUTDIR)"
	@rm	-f	$(PROG)
	@rm	-f	$(TEST)

$(OUTPUTDIR):
	@mkdir	-p	"$(OUTPUTDIR)"

$(TEST): password.o PasswordTests.o
	g++	-o	$@	$^	$(CFLAGS)	-I	$(GTEST)	$(LIBGTEST)

test: $(TEST)
	./$(TEST)

.PHONY: clean test
