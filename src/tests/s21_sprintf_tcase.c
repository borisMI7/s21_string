#include "suite_test_runner.h"
#include <stdio.h>
#include <limits.h>

START_TEST(returning_value_tests) {
  char str1[500], str2[500];
  int n1 = s21_sprintf(str1, "aboba is equal to %d", 20), n2 = sprintf(str2, "aboba is equal to %d", 20);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_c_1) {
  char str1[500], str2[500];
  sprintf(str1, "here is letter: %c", 'a');
  s21_sprintf(str2, "here is letter: %c", 'a');
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_c_2) {
  char str1[500], str2[500];
  sprintf(str1, "here is letter: %c", 'a');
  s21_sprintf(str2, "here is letter: %c", 'a');
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_c_3) {
  char str1[500], str2[500];
  sprintf(str1, "here is letter: %5c", 'a');
  s21_sprintf(str2, "here is letter: %5c", 'a');
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_c_4) {
  char str1[500], str2[500];
  sprintf(str1, "here is letter: %-5c", 'a');
  s21_sprintf(str2, "here is letter: %-5c", 'a');
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_c_5) {
  char str1[500], str2[500];
  sprintf(str1, "here is letter: %*c", 'a', 3);
  s21_sprintf(str2, "here is letter: %*c", 'a', 3);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_c_6) {
  char str1[500], str2[500];
  sprintf(str1, "here is letter: %*lc", 'a', 3);
  s21_sprintf(str2, "here is letter: %*lc", 'a', 3);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_c_7) {
  char str1[500], str2[500];
  sprintf(str1, "here is letter: %-*c", 'a', 3);
  s21_sprintf(str2, "here is letter: %-*c", 'a', 3);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_d_tests) {
  char str1[500], str2[500];
  sprintf(str1, "here is the number: %d", 1234);
  s21_sprintf(str2, "here is the number: %d", 1234);
  ck_assert_str_eq(str1, str2);
  char str3[500];
  sprintf(str1, "here is the number: %+d", 1234);
  s21_sprintf(str3, "here is the number: %+d", 1234);
  ck_assert_str_eq(str1, str3);
  sprintf(str1, "here is the number: %+d", 1234);
  s21_sprintf(str2, "here is the number: %+d", 1234);
  ck_assert_str_eq(str1, str2);
  // sprintf(str1, "here is the number: %+d", -1234);
  // s21_sprintf(str2, "here is the number: %+d", -1234);
  // ck_assert_str_eq(str1, str2);
  // sprintf(str1, "here is the number: % d", 1234);
  // s21_sprintf(str2, "here is the number: % d", 1234);
  // ck_assert_str_eq(str1, str2);
  // sprintf(str1, "here is the number: %-d", 1234);
  // s21_sprintf(str2, "here is the number: %-d", 1234);
  // ck_assert_str_eq(str1, str2);
  // sprintf(str1, "here is the number: %-3d", 1234);
  // s21_sprintf(str2, "here is the number: %-3d", 1234);
  // ck_assert_str_eq(str1, str2);
  // sprintf(str1, "here is the number: %-10d", 1234);
  // s21_sprintf(str2, "here is the number: %-10d", 1234);
  // ck_assert_str_eq(str1, str2);
  // sprintf(str1, "here is the number: %-5.0d", 1234);
  // s21_sprintf(str2, "here is the number: %-5.0d", 1234);
  // ck_assert_str_eq(str1, str2);
  // sprintf(str1, "here is the number: %-5.2d", 1234);
  // s21_sprintf(str2, "here is the number: %-5.2d", 1234);
  // ck_assert_str_eq(str1, str2);
  // sprintf(str1, "here is the number: %010.2d", 1234);
  // s21_sprintf(str2, "here is the number: %010.2d", 1234);
  // ck_assert_str_eq(str1, str2);
}
END_TEST

TCase *s21_sprintf_create_tcase(void) {
  TCase *temp_case = tcase_create("S21_SPRINTF_TESTING:\n");
  tcase_add_test(temp_case, spec_c_1);
  tcase_add_test(temp_case, spec_c_2);
  tcase_add_test(temp_case, spec_c_3);
  tcase_add_test(temp_case, spec_c_4);
  tcase_add_test(temp_case, spec_c_5);
  tcase_add_test(temp_case, spec_c_6);
  tcase_add_test(temp_case, spec_c_7);
  tcase_add_test(temp_case, returning_value_tests);
  tcase_add_test(temp_case, spec_d_tests);
  return temp_case;
}