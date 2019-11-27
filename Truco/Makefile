CC := g++
SRCDIR := src
TSTDIR := tests
OBJDIR := build
BINDIR := bin

MAIN := program/Truco.cpp
TESTER := program/Tester.cpp

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name '*.$(SRCEXT)')
OBJECTS := $(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
TSTSOURCES := $(shell find $(TSTDIR) -type f -name '*.$(SRCEXT)')

CFLAGS := -g --coverage -ftest-coverage -Wall -O3 -std=c++11

H_SOURCE=$(wildcard ./include/*.h) $(wildcard ./include/*.hpp) $(wildcard ./include/*/*.hpp)
INC=$(addprefix -I,$(shell find include -type d -print))

$(OBJDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

main: $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $(INC) $(MAIN) $^ -o $(BINDIR)/main

tests: $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $(INC) $(TESTER) $(TSTSOURCES) $^ -o $(BINDIR)/tester
	$(BINDIR)/tester

all: main

run: main
	$(BINDIR)/main

coverage:
	@mkdir -p coverage/
	@gcov -s $(SRCDIR) $(SOURCES) -rlpo build/
	@$(RM) *.gcda *.gcno

clean:
	$(RM) -r $(OBJDIR)/* $(BINDIR)/* coverage/* *.gcda *.gcno

.PHONY: clean coverage