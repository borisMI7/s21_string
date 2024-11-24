CC=gcc
FLAGS=-Wall -Werror -Wextra -std=c11
LFLAGS=
OS=$(shell uname)
ifeq ($(OS), Linux)
	LFLAGS=-lcheck -lm -lsubunit
else ifeq ($(OS), Darwin)
	LFLAGS=-lcheck -lm
endif

s21_string.a: s21_string.o
	ar rcs s21_string.a s21_string.o
	ranlib s21_string.a

s21_string.o: s21_string.c s21_string.h
	$(CC) $(FLAGS) -c s21_string.c -o s21_string.o

clean:
	rm -rf *.a *.o tests/*.out *.out

suite_test_runner.o: tests/suite_test_runner.c tests/suite_test_runner.h
	$(CC) $(FLAGS) -c tests/suite_test_runner.c

test: s21_string.a suite_test_runner.o
	$(CC) $(FLAGS) suite_test_runner.o s21_string.a $(LFLAGS) -o testing.out
	./testing.out
	make clean

