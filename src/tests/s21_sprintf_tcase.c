#include <limits.h>
#include <stdio.h>

#include "suite_test_runner.h"

START_TEST(returning_value_tests) {
  char str1[1000] = {0}, str2[1000] = {0};
  int n1 = s21_sprintf(str1, "aboba is equal to %d", 20),
      n2 = sprintf(str2, "aboba is equal to %d", 20);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_c_1) {
  char str1[50] = {'\0'}, str2[50] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is letter: %c", 'a');
  n2 = s21_sprintf(str2, "here is letter: %c", 'a');
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_c_2) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is letter: %c", 'a');
  n2 = s21_sprintf(str2, "here is letter: %c", 'a');
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_c_3) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is letter: %5c", 'a');
  n2 = s21_sprintf(str2, "here is letter: %5c", 'a');
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_c_4) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is letter: %-5c", 'a');
  n2 = s21_sprintf(str2, "here is letter: %-5c", 'a');
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_c_5) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is letter: %*c", 'a', 3);
  n2 = s21_sprintf(str2, "here is letter: %*c", 'a', 3);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_c_6) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is letter: %*lc", 'a', 3);
  n2 = s21_sprintf(str2, "here is letter: %*lc", 'a', 3);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_c_7) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is letter: %-*c", 'a', 3);
  n2 = s21_sprintf(str2, "here is letter: %-*c", 'a', 3);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_c_8) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is letter: %-*c", 'a', 3);
  n2 = s21_sprintf(str2, "here is letter: %-*c", 'a', 3);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_c_9) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is letter: %-*c", 'a', CHAR_MAX);
  n2 = s21_sprintf(str2, "here is letter: %-*c", 'a', CHAR_MAX);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_c_10) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is letter: %-*c", 'a', CHAR_MIN);
  n2 = s21_sprintf(str2, "here is letter: %-*c", 'a', CHAR_MIN);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_d_1) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %d", 1234);
  n2 = s21_sprintf(str2, "here is the number: %d", 1234);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_d_2) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %+d", 1234);
  n2 = s21_sprintf(str2, "here is the number: %+d", 1234);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_d_3) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %-d", 1234);
  n2 = s21_sprintf(str2, "here is the number: %-d", 1234);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_d_4) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %-10d", 1234);
  n2 = s21_sprintf(str2, "here is the number: %-10d", 1234);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_d_5) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %-2d", 1234);
  n2 = s21_sprintf(str2, "here is the number: %-2d", 1234);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_d_6) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %-2.0d", 1234);
  n2 = s21_sprintf(str2, "here is the number: %-2.0d", 1234);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_d_7) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %-2.5d", 1234);
  n2 = s21_sprintf(str2, "here is the number: %-2.5d", 1234);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_d_8) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: % 20.10d lol", 123);
  n2 = s21_sprintf(str2, "here is the number: % 20.10d lol", 123);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_d_9) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %-+10.0d", 1234);
  n2 = s21_sprintf(str2, "here is the number: %-+10.0d", 1234);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_d_10) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %+10.0d", 1234);
  n2 = s21_sprintf(str2, "here is the number: %+10.0d", 1234);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_d_11) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %+010d", 1234);
  n2 = s21_sprintf(str2, "here is the number: %+010d", 1234);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_d_13) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %+15.0d", -1234);
  n2 = s21_sprintf(str2, "here is the number: %+15.0d", -1234);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_d_14) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %ld", LONG_MAX);
  n2 = s21_sprintf(str2, "here is the number: %ld", LONG_MAX);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_d_15) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %ld", LONG_MIN);
  n2 = s21_sprintf(str2, "here is the number: %ld", LONG_MIN);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_d_18) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %hd", (short)SHRT_MIN);
  n2 = s21_sprintf(str2, "here is the number: %hd", (short)SHRT_MIN);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_d_19) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %hd", (short)SHRT_MAX);
  n2 = s21_sprintf(str2, "here is the number: %hd", (short)SHRT_MAX);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_d_20) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: % d", 1234);
  n2 = s21_sprintf(str2, "here is the number: % d", 1234);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_d_21) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %-+20.10d lol", 123);
  n2 = s21_sprintf(str2, "here is the number: %-+20.10d lol", 123);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_d_22) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %-1.10d lol", 123);
  n2 = s21_sprintf(str2, "here is the number: %-1.10d lol", 123);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_d_23) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %+.10d lol", 123);
  n2 = s21_sprintf(str2, "here is the number: %+.10d lol", 123);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_d_24) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %+.2d lol", 123);
  n2 = s21_sprintf(str2, "here is the number: %+.2d lol", 123);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_d_25) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %+.2d lol", -123);
  n2 = s21_sprintf(str2, "here is the number: %+.2d lol", -123);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_d_26) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %+.10d lol", -123);
  n2 = s21_sprintf(str2, "here is the number: %+.10d lol", -123);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_d_27) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %+-.10d lol", -123);
  n2 = s21_sprintf(str2, "here is the number: %+-.10d lol", -123);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_d_28) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %.*d lol", -123, 10);
  n2 = s21_sprintf(str2, "here is the number: %.*d lol", -123, 10);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_d_29) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %*.*d lol", -123, 10, 5);
  n2 = s21_sprintf(str2, "here is the number: %*.*d lol", -123, 10, 5);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_d_30) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %*.5d lol", -123, 10);
  n2 = s21_sprintf(str2, "here is the number: %*.5d lol", -123, 10);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_d_31) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %*d lol", -123, 10);
  n2 = s21_sprintf(str2, "here is the number: %*d lol", -123, 10);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_d_32) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %*.*d lol", 123, 10, 5);
  n2 = s21_sprintf(str2, "here is the number: %*.*d lol", 123, 10, 5);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_d_33) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %*.5d lol", 123, 10);
  n2 = s21_sprintf(str2, "here is the number: %*.5d lol", 123, 10);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_d_34) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %*d lol", 123, -10);
  n2 = s21_sprintf(str2, "here is the number: %*d lol", 123, -10);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_d_36) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %*d lol % -*.*d", 123, 10, -10, 20,
               -15);
  n2 = s21_sprintf(str2, "here is the number: %*d lol % -*.*d", 123, 10, -10,
                   20, -15);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_d_37) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: lol % -*.*d", -10, 20, 15);
  n2 = s21_sprintf(str2, "here is the number: lol % -*.*d", -10, 20, 15);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_d_38) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: lol % -*.*d", 10, 20, 15);
  n2 = s21_sprintf(str2, "here is the number: lol % -*.*d", 10, 20, 15);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_d_special_1) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %*d lol", 123, 10);
  n2 = s21_sprintf(str2, "here is the number: %*d lol", 123, 10);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
  n1 = sprintf(str1, "here is the number: %*d lol %-*.*d", 123, 10, 10, 20, 15);
  n2 = s21_sprintf(str2, "here is the number: %*d lol %-*.*d", 123, 10, 10, 20,
                   15);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
  n1 =
      sprintf(str1, "here is the number: %*d lol %-*.*d", 123, 10, -10, 20, 15);
  n2 = s21_sprintf(str2, "here is the number: %*d lol %-*.*d", 123, 10, -10, 20,
                   15);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
  n1 = sprintf(str1, "here is the number: %*d lol % -*.*d", 123, 10, -10, 20,
               15);
  n2 = s21_sprintf(str2, "here is the number: %*d lol % -*.*d", 123, 10, -10,
                   20, 15);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_f_1) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: lol %f", (float)10);
  n2 = s21_sprintf(str2, "here is the number: lol %f", (float)10);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_f_2) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: lol %f", 10.0);
  n2 = s21_sprintf(str2, "here is the number: lol %f", 10.0);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_f_3) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: lol %f", 10.1232);
  n2 = s21_sprintf(str2, "here is the number: lol %f", 10.1232);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_f_4) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: lol %lf", (double)10.1232);
  n2 = s21_sprintf(str2, "here is the number: lol %lf", (double)10.1232);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_f_5) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: lol %Lf", (long double)15.12345e-35);
  n2 = s21_sprintf(str2, "here is the number: lol %Lf",
                   (long double)15.12345e-35);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_f_7) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: lol %f", FLT_MIN);
  n2 = s21_sprintf(str2, "here is the number: lol %f", FLT_MIN);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_f_9) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: lol %lf", DBL_MIN);
  n2 = s21_sprintf(str2, "here is the number: lol %lf", DBL_MIN);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_f_11) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: lol %Lf", LDBL_MIN);
  n2 = s21_sprintf(str2, "here is the number: lol %Lf", LDBL_MIN);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_f_12) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: lol %5Lf", (long double)1337.1488);
  n2 =
      s21_sprintf(str2, "here is the number: lol %5Lf", (long double)1337.1488);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_f_13) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: lol %15Lf", (long double)1337.1488);
  n2 = s21_sprintf(str2, "here is the number: lol %15Lf",
                   (long double)1337.1488);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_f_14) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: lol %5.10Lf", (long double)1337.1488);
  n2 = s21_sprintf(str2, "here is the number: lol %5.10Lf",
                   (long double)1337.1488);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_f_15) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 =
      sprintf(str1, "here is the number: lol %25.10Lf", (long double)1337.1488);
  n2 = s21_sprintf(str2, "here is the number: lol %25.10Lf",
                   (long double)1337.1488);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_f_16) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: lol %15.0Lf", (long double)1337.1488);
  n2 = s21_sprintf(str2, "here is the number: lol %15.0Lf",
                   (long double)1337.1488);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_f_17) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 =
      sprintf(str1, "here is the number: lol %#15.0Lf", (long double)1337.1488);
  n2 = s21_sprintf(str2, "here is the number: lol %#15.0Lf",
                   (long double)1337.1488);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_f_18) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: lol %#15.Lf", (long double)1337.1488);
  n2 = s21_sprintf(str2, "here is the number: lol %#15.Lf",
                   (long double)1337.1488);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_f_19) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: lol %#15Lf", (long double)1337.1488);
  n2 = s21_sprintf(str2, "here is the number: lol %#15Lf",
                   (long double)1337.1488);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_f_20) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: lol %#015Lf", (long double)1337.1488);
  n2 = s21_sprintf(str2, "here is the number: lol %#015Lf",
                   (long double)1337.1488);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_f_21) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 =
      sprintf(str1, "here is the number: lol %#0+15Lf", (long double)1337.1488);
  n2 = s21_sprintf(str2, "here is the number: lol %#0+15Lf",
                   (long double)1337.1488);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_f_22) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: lol %#0+15.*Lf", 0,
               (long double)1337.1488);
  n2 = s21_sprintf(str2, "here is the number: lol %#0+15.*Lf", 0,
                   (long double)1337.1488);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_f_23) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: lol %#0+*.5Lf", 15,
               (long double)1337.1488);
  n2 = s21_sprintf(str2, "here is the number: lol %#0+*.5Lf", 15,
                   (long double)1337.1488);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_f_24) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: lol %#0+*.*Lf", 15, 5,
               (long double)1337.1488);
  n2 = s21_sprintf(str2, "here is the number: lol %#0+*.*Lf", 15, 5,
                   (long double)1337.1488);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_f_25) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: lol %#+*.*Lf", -15, 5,
               (long double)1337.1488);
  n2 = s21_sprintf(str2, "here is the number: lol %#+*.*Lf", -15, 5,
                   (long double)1337.1488);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_f_26) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: lol %+*.*Lf", -15, 0,
               (long double)1337.1488);
  n2 = s21_sprintf(str2, "here is the number: lol %+*.*Lf", -15, 0,
                   (long double)1337.1488);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_f_27) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: lol %# *.*Lf", -15, 5,
               (long double)1337.1488);
  n2 = s21_sprintf(str2, "here is the number: lol %# *.*Lf", -15, 5,
                   (long double)1337.1488);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_f_28) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: lol % *.*Lf", -15, 5,
               (long double)1337.1488);
  n2 = s21_sprintf(str2, "here is the number: lol % *.*Lf", -15, 5,
                   (long double)1337.1488);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_f_29) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: lol %# -*.*Lf", 15, 5,
               (long double)1337.1488);
  n2 = s21_sprintf(str2, "here is the number: lol %# -*.*Lf", 15, 5,
                   (long double)1337.1488);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_f_30) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: lol % *.*Lf", 15, 5,
               (long double)1337.1488);
  n2 = s21_sprintf(str2, "here is the number: lol % *.*Lf", 15, 5,
                   (long double)1337.1488);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_f_31) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: lol %Lf",
               5.141592653589793238462643383279502884L);
  n2 = s21_sprintf(str2, "here is the number: lol %Lf",
                   5.141592653589793238462643383279502884L);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_s_1) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: lol %s", "aboba");
  n2 = s21_sprintf(str2, "here is the number: lol %s", "aboba");
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_s_2) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: lol %s", "");
  n2 = s21_sprintf(str2, "here is the number: lol %s", "");
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_s_5) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: lol %.2s", "\0");
  n2 = s21_sprintf(str2, "here is the number: lol %.2s", "\0");
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_s_6) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: lol %50.2s", "ABOBABAABABABABAB");
  n2 = s21_sprintf(str2, "here is the number: lol %50.2s", "ABOBABAABABABABAB");
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_s_7) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: lol %*.2s", 5, "ABOBABAABABABABAB");
  n2 = s21_sprintf(str2, "here is the number: lol %*.2s", 5,
                   "ABOBABAABABABABAB");
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_s_8) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: lol %*.*s", 5, 50,
               "ABOBABAABABABABAB");
  n2 = s21_sprintf(str2, "here is the number: lol %*.*s", 5, 50,
                   "ABOBABAABABABABAB");
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_s_9) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: lol %*.*s", -5, 2,
               "ABOBABAABABABABAB");
  n2 = s21_sprintf(str2, "here is the number: lol %*.*s", -5, 2,
                   "ABOBABAABABABABAB");
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_s_10) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: lol %*.*s", -50, 20,
               "ABOBABAABABABABAB");
  n2 = s21_sprintf(str2, "here is the number: lol %*.*s", -50, 20,
                   "ABOBABAABABABABAB");
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_s_11) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: lol %.0s", "ABOBABAABABABABAB");
  n2 = s21_sprintf(str2, "here is the number: lol %.0s", "ABOBABAABABABABAB");
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_s_12) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: lol %-30.0s", "ABOBABAABABABABAB");
  n2 =
      s21_sprintf(str2, "here is the number: lol %-30.0s", "ABOBABAABABABABAB");
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_u_1) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %u", 1234);
  n2 = s21_sprintf(str2, "here is the number: %u", 1234);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_u_2) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %1u", 1234);
  n2 = s21_sprintf(str2, "here is the number: %1u", 1234);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_u_3) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %-u", 1234);
  n2 = s21_sprintf(str2, "here is the number: %-u", 1234);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_u_4) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %-10u", 1234);
  n2 = s21_sprintf(str2, "here is the number: %-10u", 1234);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_u_5) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %-2u", 1234);
  n2 = s21_sprintf(str2, "here is the number: %-2u", 1234);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_u_6) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %-2.0u", 1234);
  n2 = s21_sprintf(str2, "here is the number: %-2.0u", 1234);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_u_7) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %-2.5u", 1234);
  n2 = s21_sprintf(str2, "here is the number: %-2.5u", 1234);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_u_9) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %-10.0u", -1234);
  n2 = s21_sprintf(str2, "here is the number: %-10.0u", -1234);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_u_10) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %10.0u", 1234);
  n2 = s21_sprintf(str2, "here is the number: %10.0u", 1234);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_u_11) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %010u", 1234);
  n2 = s21_sprintf(str2, "here is the number: %010u", 1234);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_percnet_1) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %% %d", 1234);
  n2 = s21_sprintf(str2, "here is the number: %% %d", 1234);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_percnet_2) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %%%%%%%%%%%% %d", 1234);
  n2 = s21_sprintf(str2, "here is the number: %%%%%%%%%%%% %d", 1234);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_gG_1) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %g %G", 123423421431.431431412,
               -121232124554534334.345678908765);
  n2 = s21_sprintf(str2, "here is the number: %g %G", 123423421431.431431412,
                   -121232124554534334.345678908765);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_gG_2) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %5.g %5.G", 2.431431412,
               -4.345678908765);
  n2 = s21_sprintf(str2, "here is the number: %5.g %5.G", 2.431431412,
                   -4.345678908765);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_gG_3) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %5.3g %5.3G", 1.431431412,
               -121232124554534334.345678908765);
  n2 = s21_sprintf(str2, "here is the number: %5.3g %5.3G", 1.431431412,
                   -121232124554534334.345678908765);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_gG_4) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %5.0g %5.0G", 123423421431.431431412,
               -121232124554534334.345678908765);
  n2 = s21_sprintf(str2, "here is the number: %5.0g %5.0G",
                   123423421431.431431412, -121232124554534334.345678908765);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_gG_5) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %-5.0g %-5.0G",
               123423421431.431431412, -121232124554534334.345678908765);
  n2 = s21_sprintf(str2, "here is the number: %-5.0g %-5.0G",
                   123423421431.431431412, -121232124554534334.345678908765);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_gG_6) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %+-5.3g %+-5.3G",
               123423421431.431431412, -121232124554534334.345678908765);
  n2 = s21_sprintf(str2, "here is the number: %+-5.3g %+-5.3G",
                   123423421431.431431412, -121232124554534334.345678908765);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_gG_7) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %-#5.0g %-#5.0G",
               123423421431.431431412, -121232124554534334.345678908765);
  n2 = s21_sprintf(str2, "here is the number: %-#5.0g %-#5.0G",
                   123423421431.431431412, -121232124554534334.345678908765);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_gG_8) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: % -#5.0g % -#5.0G",
               123423421431.431431412, -121232124554534334.345678908765);
  n2 = s21_sprintf(str2, "here is the number: % -#5.0g % -#5.0G",
                   123423421431.431431412, -121232124554534334.345678908765);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_gG_9) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: % -#*.0g % -#*.0G", 50,
               123423421431.431431412, 50, -121232124554534334.345678908765);
  n2 =
      s21_sprintf(str2, "here is the number: % -#*.0g % -#*.0G", 50,
                  123423421431.431431412, 50, -121232124554534334.345678908765);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_gG_10) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: % -#*.*g % -#*.*G", 50, 4,
               123423421431.431431412, 50, 4, -121232124554534334.345678908765);
  n2 = s21_sprintf(str2, "here is the number: % -#*.*g % -#*.*G", 50, 4,
                   123423421431.431431412, 50, 4,
                   -121232124554534334.345678908765);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_gG_11) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: % -#5.*g % -#5.*G", -60,
               123423421431.431431412, 0, -121232124554534334.345678908765);
  n2 = s21_sprintf(str2, "here is the number: % -#5.*g % -#5.*G", -60,
                   123423421431.431431412, 0, -121232124554534334.345678908765);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_gG_12) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 =
      sprintf(str1, "here is the number: %+05.3g %+05.3lG",
              123423421431.431431412, (double)-121232124554534334.345678908765);
  n2 = s21_sprintf(str2, "here is the number: %+05.3g %+05.3lG",
                   123423421431.431431412,
                   (double)-121232124554534334.345678908765);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_gG_13) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %+5.3g %+5.3LG",
               123423421431.431431412,
               (long double)-121232124554534334.345678908765);
  n2 = s21_sprintf(str2, "here is the number: %+5.3g %+5.3LG",
                   123423421431.431431412,
                   (long double)-121232124554534334.345678908765);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_gG_14) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %+100.3g %+100.3G",
               123423421431.431431412, -121232124554534334.345678908765);
  n2 = s21_sprintf(str2, "here is the number: %+100.3g %+100.3G",
                   123423421431.431431412, -121232124554534334.345678908765);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_gG_15) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %+5.0g %+5.0G", 2.3, -1.5);
  n2 = s21_sprintf(str2, "here is the number: %+5.0g %+5.0G", 2.3, -1.5);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_gG_16) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %+5.0g %+5.0G", INFINITY, INFINITY);
  n2 = s21_sprintf(str2, "here is the number: %+5.0g %+5.0G", INFINITY,
                   INFINITY);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_gG_17) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %5.0g %5.0G", NAN, NAN);
  n2 = s21_sprintf(str2, "here is the number: %5.0g %5.0G", NAN, NAN);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_eE_1) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %e %E", 123423421431.431431412,
               -121232124554534334.345678908765);
  n2 = s21_sprintf(str2, "here is the number: %e %E", 123423421431.431431412,
                   -121232124554534334.345678908765);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_eE_2) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %5.e %5.E", 2.431431412,
               -4.345678908765);
  n2 = s21_sprintf(str2, "here is the number: %5.e %5.E", 2.431431412,
                   -4.345678908765);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_eE_3) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %5.3e %5.3E", 1.431431412,
               -121232124554534334.345678908765);
  n2 = s21_sprintf(str2, "here is the number: %5.3e %5.3E", 1.431431412,
                   -121232124554534334.345678908765);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_eE_4) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %5.0e %5.0E", 123423421431.431431412,
               -121232124554534334.345678908765);
  n2 = s21_sprintf(str2, "here is the number: %5.0e %5.0E",
                   123423421431.431431412, -121232124554534334.345678908765);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_eE_5) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %-5.0e %-5.0E",
               123423421431.431431412, -121232124554534334.345678908765);
  n2 = s21_sprintf(str2, "here is the number: %-5.0e %-5.0E",
                   123423421431.431431412, -121232124554534334.345678908765);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_eE_6) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %+-5.3e %+-5.3E",
               123423421431.431431412, -121232124554534334.345678908765);
  n2 = s21_sprintf(str2, "here is the number: %+-5.3e %+-5.3E",
                   123423421431.431431412, -121232124554534334.345678908765);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_eE_7) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %-#5.0e %-#5.0E",
               123423421431.431431412, -121232124554534334.345678908765);
  n2 = s21_sprintf(str2, "here is the number: %-#5.0e %-#5.0E",
                   123423421431.431431412, -121232124554534334.345678908765);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_eE_8) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: % -#5.0e % -#5.0E",
               123423421431.431431412, -121232124554534334.345678908765);
  n2 = s21_sprintf(str2, "here is the number: % -#5.0e % -#5.0E",
                   123423421431.431431412, -121232124554534334.345678908765);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_eE_9) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: % -#*.0e % -#*.0E", 50,
               123423421431.431431412, 50, -121232124554534334.345678908765);
  n2 =
      s21_sprintf(str2, "here is the number: % -#*.0e % -#*.0E", 50,
                  123423421431.431431412, 50, -121232124554534334.345678908765);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_eE_10) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 =
      sprintf(str1, "here is the number: % -#*.*e % -#*.*E", 50, 4,
              123423421431.431431412, 50, 15, -121232124554534334.345678908765);
  n2 = s21_sprintf(str2, "here is the number: % -#*.*e % -#*.*E", 50, 4,
                   123423421431.431431412, 50, 15,
                   -121232124554534334.345678908765);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_eE_11) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: % -#5.*e % -#5.*E", -60,
               123423421431.431431412, 0, -121232124554534334.345678908765);
  n2 = s21_sprintf(str2, "here is the number: % -#5.*e % -#5.*E", -60,
                   123423421431.431431412, 0, -121232124554534334.345678908765);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_eE_12) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %+05.3e %+05.3E",
               123423421431.431431412, -121232124554534334.345678908765);
  n2 = s21_sprintf(str2, "here is the number: %+05.3e %+05.3E",
                   123423421431.431431412, -121232124554534334.345678908765);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_eE_13) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %+5.3e %+5.3E",
               123423421431.431431412, -121232124554534334.345678908765);
  n2 = s21_sprintf(str2, "here is the number: %+5.3e %+5.3E",
                   123423421431.431431412, -121232124554534334.345678908765);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_eE_14) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %+100.3e %+100.3E",
               123423421431.431431412, -121232124554534334.345678908765);
  n2 = s21_sprintf(str2, "here is the number: %+100.3e %+100.3E",
                   123423421431.431431412, -121232124554534334.345678908765);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_eE_15) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %+5.0e %+5.0E", 0.009, -0.9);
  n2 = s21_sprintf(str2, "here is the number: %+5.0e %+5.0E", 0.009, -0.9);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_eE_16) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %+5.0e %+5.0E", INFINITY, INFINITY);
  n2 = s21_sprintf(str2, "here is the number: %+5.0e %+5.0E", INFINITY,
                   INFINITY);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_eE_17) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %+5.0e %+5.0E", 2.9, -0.9);
  n2 = s21_sprintf(str2, "here is the number: %+5.0e %+5.0E", 2.9, -0.9);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_eE_21) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %5.0e %5.0E", NAN, NAN);
  n2 = s21_sprintf(str2, "here is the number: %5.0e %5.0E", NAN, NAN);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_eE_18) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %5.0Le %5.0LE", (long double)56e-278,
               (long double)-56e-278);
  n2 = s21_sprintf(str2, "here is the number: %5.0Le %5.0LE",
                   (long double)56e-278, (long double)-56e-278);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_eE_19) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %Le %LE", (long double)56e-278,
               (long double)-56e-278);
  n2 = s21_sprintf(str2, "here is the number: %Le %LE", (long double)56e-278,
                   (long double)-56e-278);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_eE_20) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %Le %LE", (long double)56e-28,
               (long double)-56e278);
  n2 = s21_sprintf(str2, "here is the number: %Le %LE", (long double)56e-28,
                   (long double)-56e278);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_eE_22) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %5.3e %5.2E", 3.988888, -0.9999999);
  n2 = s21_sprintf(str2, "here is the number: %5.3e %5.2E", 3.988888,
                   -0.9999999);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_p_1) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %p", &n1);
  n2 = s21_sprintf(str2, "here is the number: %p", &n1);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_p_2) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %p", &n1);
  n2 = s21_sprintf(str2, "here is the number: %p", &n1);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_p_3) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  char *pointer = S21_NULL;
  n1 = sprintf(str1, "here is the number: %p", pointer);
  n2 = s21_sprintf(str2, "here is the number: %p", pointer);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_p_4) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %5p", &n1);
  n2 = s21_sprintf(str2, "here is the number: %5p", &n1);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_p_5) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %-30p", &n1);
  n2 = s21_sprintf(str2, "here is the number: %-30p", &n1);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_p_6) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %-5p", &n1);
  n2 = s21_sprintf(str2, "here is the number: %-5p", &n1);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_p_7) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %*p", -5, &n1);
  n2 = s21_sprintf(str2, "here is the number: %*p", -5, &n1);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_xX_1) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %x %X", 0xf54321, 0xf54321);
  n2 = s21_sprintf(str2, "here is the number: %x %X", 0xf54321, 0xf54321);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_xX_2) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %x %X", 6543, -543);
  n2 = s21_sprintf(str2, "here is the number: %x %X", 6543, -543);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_xX_3) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %-10.x %-10.0X", 6543, -543);
  n2 = s21_sprintf(str2, "here is the number: %-10.x %-10.0X", 6543, -543);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_xX_5) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %-#10.0x %-#10.0X", 6543, -543);
  n2 = s21_sprintf(str2, "here is the number: %-#10.0x %-#10.0X", 6543, -543);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_xX_6) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %-#10.5x %-#10.5X", 6543, -543);
  n2 = s21_sprintf(str2, "here is the number: %-#10.5x %-#10.5X", 6543, -543);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_xX_7) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %#10.0x %#10.0X", 6543, -543);
  n2 = s21_sprintf(str2, "here is the number: %#10.0x %#10.0X", 6543, -543);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}

START_TEST(spec_xX_9) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %0hx %0lX", (short)6543, (long)-543);
  n2 = s21_sprintf(str2, "here is the number: %0hx %0lX", (short)6543,
                   (long)-543);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}

START_TEST(spec_o_1) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %o %o", -1332, 228);
  n2 = s21_sprintf(str2, "here is the number: %o %o", -1332, 228);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_o_2) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %o %o", 6543, -543);
  n2 = s21_sprintf(str2, "here is the number: %o %o", 6543, -543);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_o_3) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %-10.o %-10.0o", 6543, -543);
  n2 = s21_sprintf(str2, "here is the number: %-10.o %-10.0o", 6543, -543);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_o_4) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %-10.4o %-10.10o", 6543, -543);
  n2 = s21_sprintf(str2, "here is the number: %-10.4o %-10.10o", 6543, -543);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_o_5) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %-#10.0o %-#10.0o", 6543, -543);
  n2 = s21_sprintf(str2, "here is the number: %-#10.0o %-#10.0o", 6543, -543);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_o_6) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %-#10.5o %-#10.5o", 6543, -543);
  n2 = s21_sprintf(str2, "here is the number: %-#10.5o %-#10.5o", 6543, -543);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(spec_o_7) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %#10.0o %#10.0o", 6543, -543);
  n2 = s21_sprintf(str2, "here is the number: %#10.0o %#10.0o", 6543, -543);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}

START_TEST(spec_o_8) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %*.*o %*.*o", 15, 10, 6543, -15, 10,
               -543);
  n2 = s21_sprintf(str2, "here is the number: %*.*o %*.*o", 15, 10, 6543, -15,
                   10, -543);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}

START_TEST(spec_o_9) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %0o %0o", 6543, -543);
  n2 = s21_sprintf(str2, "here is the number: %0o %0o", 6543, -543);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}

START_TEST(spec_o_10) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %0ho %0lo", (short)6543, (long)-543);
  n2 = s21_sprintf(str2, "here is the number: %0ho %0lo", (short)6543,
                   (long)-543);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}

START_TEST(spec_o_11) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %#ho %#lo", (short)0, (long)543);
  n2 = s21_sprintf(str2, "here is the number: %#ho %#lo", (short)0, (long)543);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
}

TCase *s21_sprintf_create_tcase(void) {
  TCase *temp_case = tcase_create("S21_SPRINTF_TESTING:\n");
  tcase_add_test(temp_case, spec_c_1);
  tcase_add_test(temp_case, spec_c_2);
  tcase_add_test(temp_case, spec_c_3);
  tcase_add_test(temp_case, spec_c_4);
  tcase_add_test(temp_case, spec_c_5);
  tcase_add_test(temp_case, spec_c_6);
  tcase_add_test(temp_case, spec_c_7);
  tcase_add_test(temp_case, spec_c_8);
  tcase_add_test(temp_case, spec_c_9);
  tcase_add_test(temp_case, spec_c_10);
  tcase_add_test(temp_case, returning_value_tests);
  tcase_add_test(temp_case, spec_d_1);
  tcase_add_test(temp_case, spec_d_2);
  tcase_add_test(temp_case, spec_d_3);
  tcase_add_test(temp_case, spec_d_4);
  tcase_add_test(temp_case, spec_d_5);
  tcase_add_test(temp_case, spec_d_6);
  tcase_add_test(temp_case, spec_d_7);
  tcase_add_test(temp_case, spec_d_8);
  tcase_add_test(temp_case, spec_d_9);
  tcase_add_test(temp_case, spec_d_10);
  tcase_add_test(temp_case, spec_d_11);
  tcase_add_test(temp_case, spec_d_13);
  tcase_add_test(temp_case, spec_d_14);
  tcase_add_test(temp_case, spec_d_15);
  tcase_add_test(temp_case, spec_d_18);
  tcase_add_test(temp_case, spec_d_19);
  tcase_add_test(temp_case, spec_d_20);
  tcase_add_test(temp_case, spec_d_21);
  tcase_add_test(temp_case, spec_d_22);
  tcase_add_test(temp_case, spec_d_23);
  tcase_add_test(temp_case, spec_d_24);
  tcase_add_test(temp_case, spec_d_25);
  tcase_add_test(temp_case, spec_d_26);
  tcase_add_test(temp_case, spec_d_27);
  tcase_add_test(temp_case, spec_d_28);
  tcase_add_test(temp_case, spec_d_29);
  tcase_add_test(temp_case, spec_d_30);
  tcase_add_test(temp_case, spec_d_31);
  tcase_add_test(temp_case, spec_d_32);
  tcase_add_test(temp_case, spec_d_33);
  tcase_add_test(temp_case, spec_d_34);
  tcase_add_test(temp_case, spec_d_36);
  tcase_add_test(temp_case, spec_d_37);
  tcase_add_test(temp_case, spec_d_38);
  tcase_add_test(temp_case, spec_d_special_1);
  tcase_add_test(temp_case, spec_f_1);
  tcase_add_test(temp_case, spec_f_2);
  tcase_add_test(temp_case, spec_f_3);
  tcase_add_test(temp_case, spec_f_4);
  tcase_add_test(temp_case, spec_f_5);
  tcase_add_test(temp_case, spec_f_7);
  tcase_add_test(temp_case, spec_f_9);
  tcase_add_test(temp_case, spec_f_11);
  tcase_add_test(temp_case, spec_f_12);
  tcase_add_test(temp_case, spec_f_13);
  tcase_add_test(temp_case, spec_f_14);
  tcase_add_test(temp_case, spec_f_15);
  tcase_add_test(temp_case, spec_f_16);
  tcase_add_test(temp_case, spec_f_17);
  tcase_add_test(temp_case, spec_f_18);
  tcase_add_test(temp_case, spec_f_19);
  tcase_add_test(temp_case, spec_f_20);
  tcase_add_test(temp_case, spec_f_21);
  tcase_add_test(temp_case, spec_f_22);
  tcase_add_test(temp_case, spec_f_23);
  tcase_add_test(temp_case, spec_f_24);
  tcase_add_test(temp_case, spec_f_25);
  tcase_add_test(temp_case, spec_f_26);
  tcase_add_test(temp_case, spec_f_27);
  tcase_add_test(temp_case, spec_f_28);
  tcase_add_test(temp_case, spec_f_29);
  tcase_add_test(temp_case, spec_f_30);
  tcase_add_test(temp_case, spec_f_31);
  tcase_add_test(temp_case, spec_s_1);
  tcase_add_test(temp_case, spec_s_2);
  tcase_add_test(temp_case, spec_s_5);
  tcase_add_test(temp_case, spec_s_6);
  tcase_add_test(temp_case, spec_s_7);
  tcase_add_test(temp_case, spec_s_8);
  tcase_add_test(temp_case, spec_s_9);
  tcase_add_test(temp_case, spec_s_10);
  tcase_add_test(temp_case, spec_s_11);
  tcase_add_test(temp_case, spec_s_12);
  tcase_add_test(temp_case, spec_u_1);
  tcase_add_test(temp_case, spec_u_2);
  tcase_add_test(temp_case, spec_u_3);
  tcase_add_test(temp_case, spec_u_4);
  tcase_add_test(temp_case, spec_u_5);
  tcase_add_test(temp_case, spec_u_6);
  tcase_add_test(temp_case, spec_u_7);
  tcase_add_test(temp_case, spec_u_9);
  tcase_add_test(temp_case, spec_u_10);
  tcase_add_test(temp_case, spec_u_11);
  tcase_add_test(temp_case, spec_percnet_1);
  tcase_add_test(temp_case, spec_percnet_2);
  tcase_add_test(temp_case, spec_gG_1);
  tcase_add_test(temp_case, spec_gG_2);
  tcase_add_test(temp_case, spec_gG_3);
  tcase_add_test(temp_case, spec_gG_4);
  tcase_add_test(temp_case, spec_gG_5);
  tcase_add_test(temp_case, spec_gG_6);
  tcase_add_test(temp_case, spec_gG_7);
  tcase_add_test(temp_case, spec_gG_8);
  tcase_add_test(temp_case, spec_gG_9);
  tcase_add_test(temp_case, spec_gG_10);
  tcase_add_test(temp_case, spec_gG_11);
  tcase_add_test(temp_case, spec_gG_12);
  tcase_add_test(temp_case, spec_gG_13);
  tcase_add_test(temp_case, spec_gG_14);
  tcase_add_test(temp_case, spec_gG_15);
  tcase_add_test(temp_case, spec_gG_16);
  tcase_add_test(temp_case, spec_gG_17);
  tcase_add_test(temp_case, spec_eE_1);
  tcase_add_test(temp_case, spec_eE_2);
  tcase_add_test(temp_case, spec_eE_3);
  tcase_add_test(temp_case, spec_eE_4);
  tcase_add_test(temp_case, spec_eE_5);
  tcase_add_test(temp_case, spec_eE_6);
  tcase_add_test(temp_case, spec_eE_7);
  tcase_add_test(temp_case, spec_eE_8);
  tcase_add_test(temp_case, spec_eE_9);
  tcase_add_test(temp_case, spec_eE_10);
  tcase_add_test(temp_case, spec_eE_11);
  tcase_add_test(temp_case, spec_eE_12);
  tcase_add_test(temp_case, spec_eE_13);
  tcase_add_test(temp_case, spec_eE_14);
  tcase_add_test(temp_case, spec_eE_15);
  tcase_add_test(temp_case, spec_eE_16);
  tcase_add_test(temp_case, spec_eE_17);
  tcase_add_test(temp_case, spec_eE_18);
  tcase_add_test(temp_case, spec_eE_19);
  tcase_add_test(temp_case, spec_eE_20);
  tcase_add_test(temp_case, spec_eE_21);
  tcase_add_test(temp_case, spec_eE_22);
  tcase_add_test(temp_case, spec_p_1);
  tcase_add_test(temp_case, spec_p_2);
  tcase_add_test(temp_case, spec_p_3);
  tcase_add_test(temp_case, spec_p_4);
  tcase_add_test(temp_case, spec_p_5);
  tcase_add_test(temp_case, spec_p_6);
  tcase_add_test(temp_case, spec_p_7);
  tcase_add_test(temp_case, spec_xX_1);
  tcase_add_test(temp_case, spec_xX_2);
  tcase_add_test(temp_case, spec_xX_3);
  tcase_add_test(temp_case, spec_xX_5);
  tcase_add_test(temp_case, spec_xX_6);
  tcase_add_test(temp_case, spec_xX_7);
  tcase_add_test(temp_case, spec_xX_9);
  tcase_add_test(temp_case, spec_o_1);
  tcase_add_test(temp_case, spec_o_2);
  tcase_add_test(temp_case, spec_o_3);
  tcase_add_test(temp_case, spec_o_4);
  tcase_add_test(temp_case, spec_o_5);
  tcase_add_test(temp_case, spec_o_6);
  tcase_add_test(temp_case, spec_o_7);
  tcase_add_test(temp_case, spec_o_8);
  tcase_add_test(temp_case, spec_o_9);
  tcase_add_test(temp_case, spec_o_10);
  tcase_add_test(temp_case, spec_o_11);
  return temp_case;
}