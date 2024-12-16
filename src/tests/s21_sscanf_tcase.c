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
  char c1 = 0, c2 = 0, c3= 0, c4 = 0;
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
  int c1 = 0, c2 = 0, c3= 0, c4 = 0, c5 = 0, c6 = 0;
  int n1 = 0, n2 = 0;
  n1 = sscanf(str, "%d %d %d", &c1, &c3, &c5);
  n2 = s21_sscanf(str, "%d %d %d", &c2, &c4, &c6);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(c3, c4);
  ck_assert_int_eq(c5, c6);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(sspec_d_2) {
  char str[] = "+52 .890 -134";
  int c1 = 0, c2 = 0, c3= 0, c4 = 0, c5 = 0, c6 = 0;
  int n1 = 0, n2 = 0;
  n1 = sscanf(str, "%1d %*d %d", &c1, &c3);
  n2 = s21_sscanf(str, "%1d %*d %d", &c2, &c4);
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
  char str[] = " aboba abob";
  char s1[200] = {0}, s2[200] = {0};
  int n1 = 0, n2 = 0;
  n1 = sscanf(str, "%s", s1);
  n2 = s21_sscanf(str, "%s", s2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(n1, n2);
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
  char str[] = "52.56789 3123.890 -134.456789";
  long double c1 = 0.0, c2 = 0.0;
  double c3 = 0.0, c4 = 0.0;
  float c5 = 0.0, c6 = 0.0;
  int n1 = 0, n2 = 0;
  n1 = sscanf(str, "%e %5le %2Le", &c5, &c3, &c1);
  n2 = s21_sscanf(str, "%e %5le %2Le", &c6, &c4, &c2);
  ck_assert_int_eq(c3, c4);
  ck_assert_int_eq(c5, c6);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(sspec_u_1) {
  char str[] = "52.56789 3123.890 -134.456789";
  unsigned long long int c1 = 0.0, c2 = 0.0;
  unsigned long int c3 = 0.0, c4 = 0.0;
  unsigned int c5 = 0.0, c6 = 0.0;
  int n1 = 0, n2 = 0;
  n1 = sscanf(str, "%u %5lu %2llu", &c5, &c3, &c1);
  n2 = s21_sscanf(str, "%u %5lu %2llu", &c6, &c4, &c2);
  ck_assert_int_eq(c3, c4);
  ck_assert_int_eq(c5, c6);
  ck_assert_int_eq(c1, c2);
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
  tcase_add_test(temp_case, sspec_u_1);
  return temp_case;
}