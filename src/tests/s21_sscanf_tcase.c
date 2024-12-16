#include "suite_test_runner.h"

START_TEST(sspec_c_1) {
  char str[] = "here is letter: %c";
  char c1 = 0, c2 = 0;
  int n1 = 0, n2 = 0;
  n1 = sscanf(str, "here is letter: %c", &c1);
  n2 = s21_sscanf(str, "here is letter: %c", &c2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(sspec_c_2) {
  char str[] = "here is letter: %c";
  char c1 = 0, c2 = 0;
  int n1 = 0, n2 = 0;
  n1 = sscanf(str, "hereis letter: %c", &c1);
  n2 = s21_sscanf(str, "heris letter: %c", &c2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(sspec_c_3) {
  char str[] = "g d a";
  char c1 = 0, c2 = 0, c3 = 0, c4 = 0;
  int n1 = 0, n2 = 0;
  n1 = sscanf(str, "%c %c", &c1, &c3);
  n2 = s21_sscanf(str, "%c %c", &c2, &c4);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(c3, c4);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(sspec_d_1) {
  char str[] = "+52 .890 -134";
  int c1 = 0, c2 = 0;
  short int c3 = 0, c4 = 0;
  long int c5 = 0, c6 = 0;
  int n1 = 0, n2 = 0;
  n1 = sscanf(str, "%d %hd %ld", &c1, &c3, &c5);
  n2 = s21_sscanf(str, "%hd %d %ld", &c2, &c4, &c6);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(c3, c4);
  ck_assert_int_eq(c5, c6);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(sspec_d_2) {
  char str[] = "+52%%.890 -134";
  int c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0, c6 = 0;
  int n1 = 0, n2 = 0;
  n1 = sscanf(str, "%1d%%%*d %d", &c1, &c3);
  n2 = s21_sscanf(str, "%1d%%%*d %d", &c2, &c4);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(c3, c4);
  ck_assert_int_eq(c5, c6);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(sspec_s_1) {
  char str[] = "aboba abob";
  char s1[200] = {0}, s2[200] = {0};
  int n1 = 0, n2 = 0;
  n1 = sscanf(str, "%s", s1);
  n2 = s21_sscanf(str, "%s", s2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(sspec_s_2) {
  char *str = S21_NULL;
  char s2[200] = {0};
  int n2 = 0;
  s21_sscanf(str, "%s", s2);
  ck_assert_str_eq("", s2);
  ck_assert_int_eq(0, n2);
}
END_TEST

START_TEST(sspec_s_3) {
  char str[] = "aboba abob";
  char s1[200] = {0}, s2[200] = {0}, s3[200] = {0}, s4[200] = {0};
  int n1 = 0, n2 = 0;
  n1 = sscanf(str, "%s %s", s1, s3);
  n2 = s21_sscanf(str, "%s %s", s2, s4);
  ck_assert_str_eq(s1, s2);
  ck_assert_str_eq(s3, s4);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(sspec_sd_1) {
  char str[] = "aboba 24.5";
  char s1[200] = {0}, s2[200] = {0};
  int d1 = 0, d2 = 0;
  int n1 = 0, n2 = 0;
  n1 = sscanf(str, "%s %d", s1, &d1);
  n2 = s21_sscanf(str, "%s %d", s2, &d2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(d1, d2);
}

START_TEST(sspec_s_4) {
  char str[] = "aboba abob";
  char s1[200] = {0}, s2[200] = {0};
  int n1 = 0, n2 = 0;
  n1 = sscanf(str, "%3s", s1);
  n2 = s21_sscanf(str, "%3s", s2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(sspec_sd_2) {
  char str[] = "aboba 24.5";
  char s1[200] = {0}, s2[200] = {0};
  int d1 = 0, d2 = 0;
  sscanf(str, "%*s %d", &d1);
  s21_sscanf(str, "%*s %d", &d2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(d1, d2);
}

START_TEST(sspec_f_1) {
  char str[] = "+52.56789 3123.890";
  double c3 = 0.0, c4 = 0.0;
  float c5 = 0.0, c6 = 0.0;
  int n1 = 0, n2 = 0;
  n1 = sscanf(str, "%f %5lf", &c5, &c3);
  n2 = s21_sscanf(str, "%f %5lf", &c6, &c4);
  ck_assert_float_eq(c5, c6);
  ck_assert_float_eq(c3, c4);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(sspec_f_2) {
  char str[] = "-52.56789 -3123.890";
  long double c1 = 0.0, c2 = 0.0;
  int n1 = 0, n2 = 0;
  n1 = sscanf(str, "%2Lf", &c1);
  n2 = s21_sscanf(str, "%2Lf", &c2);
  ck_assert_float_eq(c1, c2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(sspec_u_1) {
  char str[] = "52.56789 3123.890 -134.456789 89";
  unsigned long long int c1 = 0.0, c2 = 0.0;
  unsigned long int c3 = 0.0, c4 = 0.0;
  unsigned int c5 = 0.0, c6 = 0.0;
  unsigned short int c7 = 0, c8 = 0;
  int n1 = 0, n2 = 0;
  n1 = sscanf(str, "%u %5lu %2llu %hu", &c5, &c3, &c1, &c7);
  n2 = s21_sscanf(str, "%u %5lu %2llu %hu", &c6, &c4, &c2, &c8);
  ck_assert_int_eq(c3, c4);
  ck_assert_int_eq(c5, c6);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(c7, c8);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(sspec_xX_1) {
  char str[] = "52.56789 0xf54321 0xF54321 89";
  long int x1 = 0, x2 = 0;
  short int x3 = 0, x4 = 0;
  int n1 = 0, n2 = 0;
  n1 = sscanf(str, "%2hx %3lX", &x3, &x1);
  n2 = s21_sscanf(str, "%2hx %3lX", &x4, &x2);
  ck_assert_int_eq(x2, x1);
  ck_assert_int_eq(x4, x3);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(sspec_xX_2) {
  char str[] = "52.56789 0xf54321 0xF54321 89";
  long int x1 = 0, x2 = 0;
  int x3 = 0, x4 = 0;
  int n1 = 0, n2 = 0;
  n1 = sscanf(str, "%x %lX", &x3, &x1);
  n2 = s21_sscanf(str, "%x %lX", &x4, &x2);
  ck_assert_int_eq(x2, x1);
  ck_assert_int_eq(x4, x3);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(sspec_xX_3) {
  char str[] = "1a 13 0xF5C321 89";
  long int x1 = 0, x2 = 0;
  int x3 = 0, x4 = 0;
  int n1 = 0, n2 = 0;
  n1 = sscanf(str, "%x %lX", &x3, &x1);
  n2 = s21_sscanf(str, "%x %lX", &x4, &x2);
  ck_assert_int_eq(x2, x1);
  ck_assert_int_eq(x4, x3);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(sspec_p_1) {
  char str[] = "0x7ff7bedf73e4";
  int *p1 = S21_NULL, *p2 = S21_NULL, n1 = 0, n2 = 0;
  n1 = sscanf(str, "%p", &p1);
  n2 = s21_sscanf(str, "%p", &p2);
  ck_assert_ptr_eq(p2, p1);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(sspec_p_2) {
  char str[] = "NULL";
  int *p1 = S21_NULL, *p2 = S21_NULL, n1 = 0, n2 = 0;
  n1 = sscanf(str, "%p", &p1);
  n2 = s21_sscanf(str, "%p", &p2);
  ck_assert_ptr_eq(p2, p1);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(sspec_o_1) {
  char str[] = "2454";
  int o1 = 0, o2 = 0, n1 = 0, n2 = 0;
  n1 = sscanf(str, "%o", &o1);
  n2 = s21_sscanf(str, "%o", &o2);
  ck_assert_int_eq(o2, o1);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(sspec_gG_1) {
  char str[] = "-2.13213e+07 +1.34346E+09";
  int n1 = 0, n2 = 0;
  double d1 = 0.0, d2 = 0.0, d3 = 0.0, d4 = 0.0;
  n1 = sscanf(str, "%lg %lG", &d1, &d2);
  n2 = s21_sscanf(str, "%lg %lG", &d3, &d4);
  ck_assert_double_eq(d1, d3);
  ck_assert_double_eq(d2, d4);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(sspec_eE_1) {
  char str[] = "-3.143143e-08 +1.342341E+09";
  int n1 = 0, n2 = 0;
  double d1 = 0.0, d2 = 0.0, d3 = 0.0, d4 = 0.0;
  n1 = sscanf(str, "%le %lE", &d1, &d2);
  n2 = s21_sscanf(str, "%le %lE", &d3, &d4);
  ck_assert_double_eq(d1, d3);
  ck_assert_double_eq(d2, d4);
  ck_assert_int_eq(n1, n2);
}
END_TEST

TCase *s21_sscanf_create_tcase(void) {
  TCase *temp_case = tcase_create("S21_SSCANF_TESTING:\n");
  tcase_add_test(temp_case, sspec_c_1);
  tcase_add_test(temp_case, sspec_c_2);
  tcase_add_test(temp_case, sspec_c_3);
  tcase_add_test(temp_case, sspec_d_1);
  tcase_add_test(temp_case, sspec_d_2);
  tcase_add_test(temp_case, sspec_s_1);
  tcase_add_test(temp_case, sspec_s_2);
  tcase_add_test(temp_case, sspec_s_3);
  tcase_add_test(temp_case, sspec_s_4);
  tcase_add_test(temp_case, sspec_sd_1);
  tcase_add_test(temp_case, sspec_sd_2);
  tcase_add_test(temp_case, sspec_f_1);
  tcase_add_test(temp_case, sspec_f_2);
  tcase_add_test(temp_case, sspec_u_1);
  tcase_add_test(temp_case, sspec_xX_1);
  tcase_add_test(temp_case, sspec_xX_2);
  tcase_add_test(temp_case, sspec_xX_3);
  tcase_add_test(temp_case, sspec_p_1);
  tcase_add_test(temp_case, sspec_p_2);
  tcase_add_test(temp_case, sspec_o_1);
  tcase_add_test(temp_case, sspec_gG_1);
  tcase_add_test(temp_case, sspec_eE_1);
  return temp_case;
}