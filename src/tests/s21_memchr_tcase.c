#include "suite_test_runner.h"

START_TEST(s21_memchr_test_number_1) {
  char str[] = "Aboba";
  ck_assert_ptr_eq(memchr(str, 'o', 3), s21_memchr(str, 'o', 3));
}
END_TEST

START_TEST(s21_memchr_test_number_2) {
  char str[] = "Aboba";
  ck_assert_ptr_eq(memchr(str, 'o', 0), s21_memchr(str, 'o', 0));
}
END_TEST
START_TEST(s21_memchr_test_number_3) {
  char str[20] = "Aboba";
  ck_assert_ptr_eq(memchr(str, 'o', 10), s21_memchr(str, 'o', 10));
}
END_TEST
START_TEST(s21_memchr_test_number_4) {
  char str[] = "Abobal";
  ck_assert_ptr_eq(memchr(str, 'l', 3), s21_memchr(str, 'l', 3));
}
END_TEST
START_TEST(s21_memchr_test_number_5) {
  char str[] = "Abobal";
  ck_assert_ptr_eq(memchr(str, 'l', 5), s21_memchr(str, 'l', 5));
}
END_TEST
START_TEST(s21_memchr_test_number_6) {
  char str[5] = "";
  ck_assert_ptr_eq(memchr(str, 'o', 3), s21_memchr(str, 'o', 3));
}
END_TEST
START_TEST(s21_memchr_test_number_7) {
  char str[] = "Aboba";
  ck_assert_ptr_eq(memchr(str, '\0', 3), s21_memchr(str, '\0', 3));
}
END_TEST
START_TEST(s21_memchr_test_number_8) {
  char str[12] = "Aboba";
  ck_assert_ptr_eq(memchr(str, '\0', 10), s21_memchr(str, '\0', 10));
}
END_TEST
START_TEST(s21_memchr_test_number_9) {
  char str[] = "asdfg";
  ck_assert_ptr_eq(memchr(str, 'g', 5), s21_memchr(str, 'g', 5));
}
END_TEST
START_TEST(s21_memchr_test_number_10) {
  char str[] = "asdfg";
  ck_assert_ptr_eq(memchr(str, 'g', 6), s21_memchr(str, 'g', 6));
}
END_TEST
START_TEST(s21_memchr_test_number_11) {
  ck_assert_ptr_eq(S21_NULL, s21_memchr(S21_NULL, 'g', 6));
}
END_TEST

TCase *s21_memchr_create_tcase(void) {
  TCase *temp_case = tcase_create("S21_MEMCHR_TESTING:\n");
  tcase_add_test(temp_case, s21_memchr_test_number_1);
  tcase_add_test(temp_case, s21_memchr_test_number_2);
  tcase_add_test(temp_case, s21_memchr_test_number_3);
  tcase_add_test(temp_case, s21_memchr_test_number_4);
  tcase_add_test(temp_case, s21_memchr_test_number_5);
  tcase_add_test(temp_case, s21_memchr_test_number_6);
  tcase_add_test(temp_case, s21_memchr_test_number_7);
  tcase_add_test(temp_case, s21_memchr_test_number_8);
  tcase_add_test(temp_case, s21_memchr_test_number_9);
  tcase_add_test(temp_case, s21_memchr_test_number_10);
  tcase_add_test(temp_case, s21_memchr_test_number_11);
  return temp_case;
}