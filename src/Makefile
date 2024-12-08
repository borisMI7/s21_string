CC=gcc
FLAGS=-Wall -Werror -Wextra -std=c11
LFLAGS=
OS=$(shell uname)
ifeq ($(OS), Linux)
	LFLAGS=-lcheck -lm -lsubunit
else ifeq ($(OS), Darwin)
	LFLAGS=-lcheck
endif

s21_string.a: s21_string.o s21_sprintf.o
	ar rcs s21_string.a s21_string.o s21_sprintf.o
	ranlib s21_string.a

s21_string.o: s21_string.c s21_string.h
	$(CC) $(FLAGS) -c s21_string.c -o s21_string.o

s21_sprintf.o: s21_sprintf.c s21_string.h
	$(CC) $(FLAGS) -c s21_sprintf.c -o s21_sprintf.o

clean:
	rm -rf *.a *.o tests/*.out *.out tests/*.temp report/

suite_test_runner.o: tests/suite_test_runner.c tests/suite_test_runner.h
	$(CC) $(FLAGS) -c tests/suite_test_runner.c

test: clean s21_string.a
	$(CC) $(FLAGS) tests/suite_test_runner.c s21_string.a $(LFLAGS) -o testing.out
	./testing.out

gcov_report: s21_string.a
gcov_report: FLAGS += -coverage
gcov_report: test
	gcov s21_sprintf.c s21_string.c
	lcov -t "gcov_report" -o report.info -c -d .
	genhtml -o ./report report.info
	rm -f *.gcno *.gcda *.info report.out *.gcov
	open ./report/index-sort-f.html
