.PHONY: all test gcov_report clean valgrind_check leaks style cppcheck

CC = gcc
STDFLAGS = -Wall -Werror -Wextra -std=c11
GCOV_FLAGS=-fprofile-arcs -ftest-coverage 
LINUX_FLAGS=-lsubunit -lrt -lpthread -lm
TESTFLAGS = -lcheck -lm -lpthread -o 

SRC=$(wildcard *.c)
OBJ=$(patsubst %.c,%.o, ${SRC})

OS := $(shell uname -s)

ifeq ($(OS),Linux)
  OPEN_CMD = xdg-open
endif
ifeq ($(OS),Darwin)
	OPEN_CMD = open
endif

TEST_SRC=$(wildcard ./TEST//*.c)
LIBS=-lcheck

all : clean matrix.a test

debug : clean matrix.a
	gcc debug.c d3_matrix.a -o debug
	rm -rf *.o
	./debug > matrix.log

test : matrix.a
ifeq ($(OS), Darwin)
	${CC} $(STDFLAGS) TEST/common_test.c  $< -o unit_test $(LIBS) -lm
else
	${CC} $(STDFLAGS) TEST/common_test.c  $< -o unit_test $(LIBS) $(LINUX_FLAGS)
endif
	./unit_test
	
gcov_report:
ifeq ($(OS), Darwin)
	$(CC) $(STDFLAGS) $(GCOV_FLAGS) TEST/common_test.c ${SRC}  -o unit_test $(LIBS) -lm
else
	$(CC) $(STDFLAGS) $(GCOV_FLAGS) TEST/common_test.c ${SRC} -o unit_test $(LIBS) $(LINUX_FLAGS)
endif
	./unit_test
	lcov -t "stest" -o test.info --no-external --filter range -c -d .
	genhtml -o report test.info
	$(OPEN_CMD) ./report/index.html

matrix.a : ${SRC} 
	$(CC) -c $(STDFLAGS) $(SRC)
	ar rc $@ $(OBJ)
	ranlib $@
	cp $@ lib$@
	make clean_obj

clean_obj :
	rm -f *.o

 clean:
	rm -rf *.a *.o *.info *.gcno *.gcda *.gcov
	rm -rf *.o *_exe *.dSYM *.out ./.clang-format *.DS_Store
	rm -rf report
	rm -rf unit_test

valgrind_check: test
	CK_FORK=no valgrind --tool=memcheck ./unit_test

leaks: clean test
	CK_FORK=no leaks -atExit -- ./unit_test

style:
	cp ../materials/linters/.clang-format ./
	clang-format -n *.c *.h
	clang-format -n TEST/common_test.c *.c *.h

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem . *.c *.h