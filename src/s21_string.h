#ifndef S21_STRING_H
#define S21_STRING_H

#include <stdlib.h>

#define S21_NULL ((void *)0)

typedef long unsigned s21_size_t;
typedef struct spec {
    int width; // ширина вывода
    int left_allig; // варываниваение слева или справа?
    int accuracy; // количество знаков после запятый;
    int print_plus; // печатать ли плюсы
    int is_up; // нужно ли переводить в заглавные буквы?
    int is_zero; // нужно ли заполнять слева нулями в рамках ширины?
    char spec; // Какой спецификатор?
    char spec_size; // l, h, L - длина спецификатора
} spec;

void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
s21_size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

//additional funcs
int is_trim_symbol(const char *trim_chars, char symbol);




#endif