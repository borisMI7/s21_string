#include "suite_test_runner.h"

// void *s21_memset(void *str, int c, s21_size_t n) {
//   if (str == S21_NULL || n < 1) return str;
//   char *p = (char *)str;
//   while (n-- > 0) *(p++) = c;
//   return str;
// }

START_TEST(s21_memset_test_number_1) {
    char str1[] = "Aboba", str2[] = "Aboba";
    ck_assert_str_eq(memset(str1, 'a', 5), s21_memset(str2, 'a', 5));
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_memset_test_number_2) {
    char str1[10] = "Aboba", str2[10] = "Aboba";
    ck_assert_str_eq((char* )memset(str1, 'a', 6), (char* )s21_memset(str2, 'a', 6));
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_memset_test_number_3) {
    char str1[] = "Aboba", str2[] = "Aboba";
    ck_assert_str_eq(str1, s21_memset(str2, 'a', 0));
    ck_assert_str_eq(str1, str2);
}
END_TEST


START_TEST(s21_memset_test_number_5) {
    char str1[10] = "Aboba", str2[10] = "Aboba";
    ck_assert_str_eq(memset(str1, 'a', 9), s21_memset(str2, 'a', 9));
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_memset_test_number_6) {
    char str1[10] = "", str2[10] = "";
    ck_assert_str_eq(memset(str1, 'a', 9), s21_memset(str2, 'a', 9));
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_memset_test_number_7) {
    char str1[10] = "", str2[10] = "";
    ck_assert_str_eq(str1, s21_memset(str2, 'a', 0));
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_memset_test_number_8) {
    char str2[13] = "";
    ck_assert_str_eq("aaaaaaaaaaaa", s21_memset(str2, 'a', 12));
    ck_assert_str_eq("aaaaaaaaaaaa", str2);
}
END_TEST

TCase *s21_memset_create_tcase(void) {
    TCase *temp_case = tcase_create("S21_MEMSET_TESTING:\n");
    tcase_add_test(temp_case, s21_memset_test_number_1);
    tcase_add_test(temp_case, s21_memset_test_number_2);
    tcase_add_test(temp_case, s21_memset_test_number_3);
    tcase_add_test(temp_case, s21_memset_test_number_5);
    tcase_add_test(temp_case, s21_memset_test_number_6);
    tcase_add_test(temp_case, s21_memset_test_number_7);
    tcase_add_test(temp_case, s21_memset_test_number_8);
    return temp_case;
}