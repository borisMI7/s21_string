#include <limits.h>
#include <stdio.h>

#include "suite_test_runner.h"

START_TEST(returning_value_tests) {
  char str1[1000], str2[1000];
  int n1 = s21_sprintf(str1, "aboba is equal to %d", 20),
      n2 = sprintf(str2, "aboba is equal to %d", 20);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_c_1) {
  char str1[50], str2[50];
  sprintf(str1, "here is letter: %c", 'a');
  s21_sprintf(str2, "here is letter: %c", 'a');
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_c_2) {
  char str1[1000], str2[1000];
  sprintf(str1, "here is letter: %c", 'a');
  s21_sprintf(str2, "here is letter: %c", 'a');
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_c_3) {
  char str1[1000], str2[1000];
  sprintf(str1, "here is letter: %5c", 'a');
  s21_sprintf(str2, "here is letter: %5c", 'a');
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_c_4) {
  char str1[1000], str2[1000];
  sprintf(str1, "here is letter: %-5c", 'a');
  s21_sprintf(str2, "here is letter: %-5c", 'a');
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_c_5) {
  char str1[1000], str2[1000];
  sprintf(str1, "here is letter: %*c", 'a', 3);
  s21_sprintf(str2, "here is letter: %*c", 'a', 3);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_c_6) {
  char str1[1000], str2[1000];
  sprintf(str1, "here is letter: %*lc", 'a', 3);
  s21_sprintf(str2, "here is letter: %*lc", 'a', 3);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_c_7) {
  char str1[1000], str2[1000];
  sprintf(str1, "here is letter: %-*c", 'a', 3);
  s21_sprintf(str2, "here is letter: %-*c", 'a', 3);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_d_1) {
  char str1[1000], str2[1000];
  sprintf(str1, "here is the number: %d", 1234);
  s21_sprintf(str2, "here is the number: %d", 1234);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_d_2) {
  char str1[1000], str2[1000];
  sprintf(str1, "here is the number: %+d", 1234);
  s21_sprintf(str2, "here is the number: %+d", 1234);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_d_3) {
  char str1[1000], str2[1000];
  sprintf(str1, "here is the number: %-d", 1234);
  s21_sprintf(str2, "here is the number: %-d", 1234);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_d_4) {
  char str1[1000], str2[1000];
  sprintf(str1, "here is the number: %-10d", 1234);
  s21_sprintf(str2, "here is the number: %-10d", 1234);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_d_5) {
  char str1[1000], str2[1000];
  sprintf(str1, "here is the number: %-2d", 1234);
  s21_sprintf(str2, "here is the number: %-2d", 1234);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_d_6) {
  char str1[1000], str2[1000];
  sprintf(str1, "here is the number: %-2.0d", 1234);
  s21_sprintf(str2, "here is the number: %-2.0d", 1234);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_d_7) {
  char str1[1000], str2[1000];
  sprintf(str1, "here is the number: %-2.5d", 1234);
  s21_sprintf(str2, "here is the number: %-2.5d", 1234);
  ck_assert_str_eq(str1, str2);
}
END_TEST

// START_TEST(spec_d_8) {
//   char str1[1000], str2[1000];
//   sprintf(str1, "here is the number: %010.0d", 1234);
//   s21_sprintf(str2, "here is the number: %010.0d", 1234);
//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

START_TEST(spec_d_9) {
  char str1[1000], str2[1000];
  sprintf(str1, "here is the number: %-+10.0d", 1234);
  s21_sprintf(str2, "here is the number: %-+10.0d", 1234);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_d_10) {
  char str1[1000], str2[1000];
  sprintf(str1, "here is the number: %+10.0d", 1234);
  s21_sprintf(str2, "here is the number: %+10.0d", 1234);
  ck_assert_str_eq(str1, str2);
}
END_TEST

// START_TEST(spec_d_11) {
//   char str1[1000], str2[1000];
//   sprintf(str1, "here is the number: %+010.0d", 1234);
//   s21_sprintf(str2, "here is the number: %+010.0d", 1234);
//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(spec_d_12) {
//   char str1[1000], str2[1000];
//   sprintf(str1, "here is the number: %0+10.0d", 1234);
//   s21_sprintf(str2, "here is the number: %0+10.0d", 1234);
//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

START_TEST(spec_d_13) {
  char str1[1000], str2[1000];
  sprintf(str1, "here is the number: %+15.0d", -1234);
  s21_sprintf(str2, "here is the number: %+15.0d", -1234);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_d_14) {
  char str1[1000], str2[1000];
  sprintf(str1, "here is the number: %ld", LONG_MAX);
  s21_sprintf(str2, "here is the number: %ld", LONG_MAX);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_d_15) {
  char str1[1000], str2[1000];
  sprintf(str1, "here is the number: %ld", LONG_MIN);
  s21_sprintf(str2, "here is the number: %ld", LONG_MIN);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_d_16) {
  char str1[1000], str2[1000];
  sprintf(str1, "here is the number: %lld", LLONG_MAX);
  s21_sprintf(str2, "here is the number: %ld", LLONG_MAX);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_d_17) {
  char str1[1000], str2[1000];
  sprintf(str1, "here is the number: %lld", LLONG_MIN);
  s21_sprintf(str2, "here is the number: %lld", LLONG_MIN);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_d_18) {
  char str1[1000], str2[1000];
  sprintf(str1, "here is the number: %hd", (short)-32767);
  s21_sprintf(str2, "here is the number: %hd", (short)-32767);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_d_19) {
  char str1[1000], str2[1000];
  sprintf(str1, "here is the number: %hd", (short)32766);
  s21_sprintf(str2, "here is the number: %hd", (short)32766);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_d_20) {
  char str1[1000], str2[1000];
  sprintf(str1, "here is the number: % d", 1234);
  s21_sprintf(str2, "here is the number: % d", 1234);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_d_21) {
  char str1[1000], str2[1000];
  sprintf(str1, "here is the number: %-+20.10d lol", 123);
  s21_sprintf(str2, "here is the number: %+20.10d lol", 123);
  ck_assert_str_eq(str1, str2);
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
  tcase_add_test(temp_case, spec_d_1);
  tcase_add_test(temp_case, spec_d_2);
  tcase_add_test(temp_case, spec_d_3);
  tcase_add_test(temp_case, spec_d_4);
  tcase_add_test(temp_case, spec_d_5);
  tcase_add_test(temp_case, spec_d_6);
  tcase_add_test(temp_case, spec_d_7);
  // tcase_add_test(temp_case, spec_d_8);
  tcase_add_test(temp_case, spec_d_9);
  tcase_add_test(temp_case, spec_d_10);
  // tcase_add_test(temp_case, spec_d_11);
  // tcase_add_test(temp_case, spec_d_12);
  tcase_add_test(temp_case, spec_d_13);
  tcase_add_test(temp_case, spec_d_14);
  tcase_add_test(temp_case, spec_d_15);
  tcase_add_test(temp_case, spec_d_16);
  tcase_add_test(temp_case, spec_d_17);
  tcase_add_test(temp_case, spec_d_18);
  tcase_add_test(temp_case, spec_d_19);
  tcase_add_test(temp_case, spec_d_20);
  tcase_add_test(temp_case, spec_d_21);
  return temp_case;
}