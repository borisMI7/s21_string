#include "suite_test_runner.h"

START_TEST(s21_strncmp_test_number_1) {
  char str1[10] = "abob", str2[10] = "abob";
  ck_assert_int_eq(s21_strncmp(str1, str2, 2), strncmp(str1, str2, 2));
}
END_TEST

START_TEST(s21_strncmp_test_number_2) {
  char str1[10] = "abob", str2[10] = "abob";
  ck_assert_int_eq(s21_strncmp(str1, str2, 0), strncmp(str1, str2, 0));
}
END_TEST

START_TEST(s21_strncmp_test_number_3) {
  char str1[10] = "abob", str2[10] = "abob";
  ck_assert_int_eq(s21_strncmp(str1, str2, 4), strncmp(str1, str2, 4));
}
END_TEST

START_TEST(s21_strncmp_test_number_4) {
  char str1[10] = "abob", str2[10] = "abob";
  ck_assert_int_eq(s21_strncmp(str1, str2, 5), strncmp(str1, str2, 5));
}
END_TEST

START_TEST(s21_strncmp_test_number_5) {
  char str1[10] = "abob", str2[10] = "abob";
  ck_assert_int_eq(s21_strncmp(str1, str2, 10), strncmp(str1, str2, 10));
}
END_TEST

START_TEST(s21_strncmp_test_number_6) {
  char str1[10] = "", str2[10] = "abob";
  ck_assert_int_eq((s21_strncmp(str1, str2, 10) && strncmp(str1, str2, 10) < 0),
                   1);
}
END_TEST

START_TEST(s21_strncmp_test_number_7) {
  char str1[10] = "abob", str2[10] = "";
  ck_assert_int_eq(s21_strncmp(str1, str2, 10), strncmp(str1, str2, 10));
}
END_TEST

START_TEST(s21_strncmp_test_number_8) {
  char str1[10] = "", str2[10] = "";
  ck_assert_int_eq(s21_strncmp(str1, str2, 5), strncmp(str1, str2, 5));
}
END_TEST

START_TEST(s21_strncmp_test_number_9) {
  char str1[10] = "aboba", str2[10] = "ab123";
  ck_assert_int_eq(s21_strncmp(str1, str2, 2), strncmp(str1, str2, 2));
}
END_TEST

START_TEST(s21_strncmp_test_number_10) {
  char str1[10] = "aboba", str2[10] = "ab123";
  ck_assert_int_eq(s21_strncmp(str1, str2, 3), strncmp(str1, str2, 3));
}
END_TEST

START_TEST(s21_strncmp_test_number_11) {
  char str1[10] = "abo", str2[10] = "aba";
  ck_assert_int_eq(s21_strncmp(str1, str2, 3), strncmp(str1, str2, 3));
}
END_TEST

START_TEST(s21_strncmp_test_number_12) {
  char str1[10] = "abo";
  ck_assert_int_eq(s21_strncmp(str1, S21_NULL, 3), 1);
}
END_TEST

START_TEST(s21_strncmp_test_number_13) {
  char str1[10] = "abo";
  ck_assert_int_eq(s21_strncmp(S21_NULL, str1, 3), -1);
}
END_TEST

START_TEST(s21_strncmp_test_number_14) {
  ck_assert_int_eq(s21_strncmp(S21_NULL, S21_NULL, 3), 0);
}
END_TEST

TCase *s21_strncmp_create_tcase(void) {
  TCase *temp_case = tcase_create("S21_STRNCMP_TESTING:\n");
  tcase_add_test(temp_case, s21_strncmp_test_number_1);
  tcase_add_test(temp_case, s21_strncmp_test_number_2);
  tcase_add_test(temp_case, s21_strncmp_test_number_3);
  tcase_add_test(temp_case, s21_strncmp_test_number_4);
  tcase_add_test(temp_case, s21_strncmp_test_number_5);
  tcase_add_test(temp_case, s21_strncmp_test_number_6);
  tcase_add_test(temp_case, s21_strncmp_test_number_7);
  tcase_add_test(temp_case, s21_strncmp_test_number_8);
  tcase_add_test(temp_case, s21_strncmp_test_number_9);
  tcase_add_test(temp_case, s21_strncmp_test_number_11);
  tcase_add_test(temp_case, s21_strncmp_test_number_10);
  tcase_add_test(temp_case, s21_strncmp_test_number_12);
  tcase_add_test(temp_case, s21_strncmp_test_number_13);
  tcase_add_test(temp_case, s21_strncmp_test_number_14);
  return temp_case;
}