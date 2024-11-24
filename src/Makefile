CC=gcc
FLAGS=-Wall -Werror -Wextra -std=c11

s21_string.a: s21_string.o
	ar rcs s21_string.a s21_string.o
	ranlib s21_string.a

s21_string.o: s21_string.c s21_string.h
	$(CC) $(FLAGS) -c s21_string.c -o s21_string.o

clean:
	rm -rf *.a *.o tests/*.out *.out

test: s21_string.a tests/suite_test_runner.c tests/suite_test_runner.h
	$(CC) $(FLAGS) -lcheck s21_string.a tests/suite_test_runner.c -o testing.out
	./testing.out

