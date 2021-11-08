## Makefile for ubuntu

CFLAGS=-std=c99
CFLAGS += -g
CFLAGS += -Wall
CFLAGS += -Wfatal-errors
CFLAGS += -Wextra
CFLAGS += -Wpointer-arith
CFLAGS += -Wcast-align
CFLAGS += -Wwrite-strings
#CFLAGS += -Wswitch-default
CFLAGS += -Wunreachable-code
CFLAGS += -Winit-self
CFLAGS += -Wmissing-field-initializers
CFLAGS += -Wno-unknown-pragmas
CFLAGS += -Wstrict-prototypes
CFLAGS += -Wundef
CFLAGS += -Wold-style-definition

GCOVFLAGS  = -fprofile-arcs
GCOVFLAGS += -ftest-coverage

CPPCHECKFLAGS  = --enable=all
CPPCHECKFLAGS += --suppress=missingIncludeSystem
CPPCHECKFLAGS += --suppress=unusedFunction
CPPCHECKFLAGS += --suppress=variableScope
CPPCHECKFLAGS += --suppress=arrayIndexThenCheck
CPPCHECKFLAGS += --suppress=unmatchedSuppression


VALGRINDFLAGS  = --leak-check=full
VALGRINDFLAGS += --show-leak-kinds=all
VALGRINDFLAGS += -q

SANITIZERFLAGS  = -g
SANITIZERFLAGS += -Wall
SANITIZERFLAGS += -Wfatal-errors
SANITIZERFLAGS += -fsanitize=address 

###################################
# Unity vars
TARGET = all_tests.out
SRC_FILES=\
  Unity/src/unity.c \
  Unity/fixture/unity_fixture.c \
  sort.c \
  test/TestSort.c \
  test/test_runners/TestSort_Runner.c \
  test/test_runners/all_tests.c
INC_DIRS=-Isrc -I Unity/src -I Unity/fixture

all: clean cppcheck valgrind sanitizer unity


cppcheck:
	@echo -------------------------- cppcheck
	@cppcheck $(CPPCHECKFLAGS) main.c array.c get_opt.c sort.c
	@echo

valgrind:
	@echo -------------------------- valgrind
	@gcc -g -Wall -Wfatal-errors -o app main.c array.c sort.c get_opt.c
	valgrind $(VALGRINDFLAGS) ./app -a selection -n 10 -s random
	valgrind $(VALGRINDFLAGS) ./app -a insertion -n 10 -s random
	valgrind $(VALGRINDFLAGS) ./app -a shell     -n 10 -s random
	valgrind $(VALGRINDFLAGS) ./app -a quick     -n 10 -s random
	valgrind $(VALGRINDFLAGS) ./app -a heap      -n 10 -s random
	valgrind $(VALGRINDFLAGS) ./app -a merge     -n 10 -s random
	@echo

sanitizer:
	@echo -------------------------- sanitizer
	@gcc $(SANITIZERFLAGS) -o app main.c array.c sort.c get_opt.c
	./app -a selection -n 10 -s random
	./app -a insertion -n 10 -s random
	./app -a shell     -n 10 -s random
	./app -a quick     -n 10 -s random
	./app -a heap      -n 10 -s random
	./app -a merge     -n 10 -s random
	@echo

unity:
	$(info -------------------------- unity)
	@gcc $(CFLAGS) $(INC_DIRS) $(SRC_FILES) $(GCOVFLAGS) -o $(TARGET) && ./$(TARGET) -v && gcov -b sort.gcda

comp_app: clean
	@gcc -o app main.c array.c sort.c get_opt.c

run_selection: 
	./app -a selection -n 20 -s random -P

run_insertion: 
	./app -a insertion -n 20 -s random -P

run_shell: 
	./app -a shell     -n 20 -s random -P

run_quick: 
	./app -a quick     -n 20 -s random -P

run_heap: 
	./app -a heap      -n 20 -s random -P

run_merge: 
	./app -a merge     -n 20 -s random -P

clean:
	@rm -fr $(sort) *.o cov* *.dSYM *.gcda *.gcno *.gcov *.out
	@rm -f app
