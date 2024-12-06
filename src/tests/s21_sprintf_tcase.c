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

// illigal unstruction and prohibbiten GNU flag usage
// START_TEST(spec_d_12) {
//   char str1[1000], str2[1000];
//   sprintf(str1, "here is the number: %0+10.*d", 1234, 5);
//   s21_sprintf(str2, "here is the number: %0+10.*d", 1234, 5);
//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

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

// ingored by GNU but works on MAC
//  START_TEST(spec_d_28) {
//    char str1[1000], str2[1000];
//    sprintf(str1, "here is the number: %+0.10d lol", -123);
//    s21_sprintf(str2, "here is the number: %+0.10d lol", -123);
//    ck_assert_str_eq(str1, str2);
//  }
//  END_TEST

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

// Ignored by Linux
// START_TEST(spec_d_35) {
// char str1[1000] = {'\0'}, str2[1000] = {'\0'};
//   int n1 = 0, n2 = 0;
//   n1 = sprintf(str1, "here is the number: %015.10d lol", 123);
//   n2 = s21_sprintf(str2, "here is the number: %015.10d lol", 123);
//   ck_assert_int_eq(n1, n2);
//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

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

// error: flag '0' is ignored when flag '-' is present [-Werror,-Wformat] on MAC
// and probably Linux START_TEST(spec_d_36) { char str1[1000] = {'\0'},
// str2[1000] = {'\0'};
//   int n1 = 0, n2 = 0;
//   n1 = sprintf(str1, "here is the number: %+-015.20d lol", 123);
//   n2 = s21_sprintf(str2, "here is the number: %+-015.20d lol", 123);
//   ck_assert_int_eq(n1, n2);
//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

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

START_TEST(spec_f_6) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: lol %f", FLT_MAX);
  n2 = s21_sprintf(str2, "here is the number: lol %f", FLT_MAX);
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

START_TEST(spec_f_8) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: lol %lf", DBL_MAX);
  n2 = s21_sprintf(str2, "here is the number: lol %lf", DBL_MAX);
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

// illigal instruction for original one
// START_TEST(spec_f_10) {
// char str1[1000] = {'\0'}, str2[1000] = {'\0'};
//   int n1 = 0, n2 = 0;
//   n1 = sprintf(str1, "here is the number: lol %Lf", LDBL_MAX);
//   n2 = s21_sprintf(str2, "here is the number: lol %Lf", LDBL_MAX);
//   ck_assert_str_eq(str1, str2);
//   ck_assert_int_eq(n1, n2);
// }
// END_TEST

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

// ignored by GNU, btw fixed function to work on MAC comp
//  START_TEST(spec_s_3) {
//  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
//    int n1 = 0, n2 = 0;
//    n1 = sprintf(str1, "here is the number: lol %s", (char*)S21_NULL);
//    n2 = s21_sprintf(str2, "here is the number: lol %s", (char*)S21_NULL);
//    ck_assert_str_eq(str1, str2);
//    ck_assert_int_eq(n1, n2);
//  }
//  END_TEST

// START_TEST(spec_s_4) {
// char str1[1000] = {'\0'}, str2[1000] = {'\0'};
//   int n1 = 0, n2 = 0;
//   n1 = sprintf(str1, "here is the number: lol %.2s", (char*)S21_NULL);
//   n2 = s21_sprintf(str2, "here is the number: lol %.2s", (char*)S21_NULL);
//   ck_assert_str_eq(str1, str2);
//   ck_assert_int_eq(n1, n2);
// }
// END_TEST

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

// ignored by GNU
START_TEST(spec_s_13) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: lol %-30.0s", (char *)S21_NULL);
  n2 = s21_sprintf(str2, "here is the number: lol %-30.0s", (char *)S21_NULL);
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

// ingored by GNU
START_TEST(spec_u_8) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %020.10u lol", 123);
  n2 = s21_sprintf(str2, "here is the number: %020.10u lol", 123);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(spec_u_9) {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %-10.0u", 1234);
  n2 = s21_sprintf(str2, "here is the number: %-10.0u", 1234);
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
  // tcase_add_test(temp_case, spec_d_12);
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
  tcase_add_test(temp_case, spec_f_6);
  tcase_add_test(temp_case, spec_f_7);
  tcase_add_test(temp_case, spec_f_8);
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
  // tcase_add_test(temp_case, spec_s_3);
  // tcase_add_test(temp_case, spec_s_4);
  tcase_add_test(temp_case, spec_s_5);
  tcase_add_test(temp_case, spec_s_6);
  tcase_add_test(temp_case, spec_s_7);
  tcase_add_test(temp_case, spec_s_8);
  tcase_add_test(temp_case, spec_s_9);
  tcase_add_test(temp_case, spec_s_10);
  tcase_add_test(temp_case, spec_s_11);
  tcase_add_test(temp_case, spec_s_12);
  tcase_add_test(temp_case, spec_s_13);
  tcase_add_test(temp_case, spec_u_1);
  tcase_add_test(temp_case, spec_u_2);
  tcase_add_test(temp_case, spec_u_3);
  tcase_add_test(temp_case, spec_u_4);
  tcase_add_test(temp_case, spec_u_5);
  tcase_add_test(temp_case, spec_u_6);
  tcase_add_test(temp_case, spec_u_7);
  tcase_add_test(temp_case, spec_u_8);
  tcase_add_test(temp_case, spec_u_9);
  tcase_add_test(temp_case, spec_u_10);
  tcase_add_test(temp_case, spec_u_11);
  return temp_case;
}