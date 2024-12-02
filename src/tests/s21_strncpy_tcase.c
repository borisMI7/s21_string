#include "suite_test_runner.h"

START_TEST(s21_strncpy_test_number_1) {
  char str1[10] = "abob", str2[10] = "abob", str3[10] = "ABOBA";
  ck_assert_str_eq(strncpy(str1, str3, 5), s21_strncpy(str2, str3, 5));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_strncpy_test_number_2) {
  char str1[10] = "abob", str2[10] = "abob", str3[10] = "ABOBA";
  ck_assert_str_eq(strncpy(str1, str3, 6), s21_strncpy(str2, str3, 6));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_strncpy_test_number_3) {
  char str1[10] = "abob", str2[10] = "abob", str3[10] = "ABOBA";
  ck_assert_str_eq(strncpy(str1, str3, 10), s21_strncpy(str2, str3, 10));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_strncpy_test_number_4) {
  char str1[10] = "abob", str2[10] = "abob", str3[10] = "ABOBA";
  ck_assert_str_eq(strncpy(str1, str3, 3), s21_strncpy(str2, str3, 3));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_strncpy_test_number_5) {
  char str1[10] = "abob", str2[10] = "abob", str3[10] = "ABOBA";
  ck_assert_str_eq(strncpy(str1, str3, 0), s21_strncpy(str2, str3, 0));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_strncpy_test_number_6) {
  char str1[10] = "abob", str2[10] = "abob", str3[10] = "";
  ck_assert_str_eq(strncpy(str1, str3, 10), s21_strncpy(str2, str3, 10));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_strncpy_test_number_7) {
  char str1[10] = "", str2[10] = "", str3[10] = "ABOBA";
  ck_assert_str_eq(strncpy(str1, str3, 10), s21_strncpy(str2, str3, 10));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_strncpy_test_number_8) {
  char str1[10] = "", str2[10] = "", str3[10] = "";
  ck_assert_str_eq(strncpy(str1, str3, 10), s21_strncpy(str2, str3, 10));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_strncpy_test_number_9) {
  char str2[10] = "abob";
  ck_assert_str_eq("abob", s21_strncpy(str2, S21_NULL, 10));
  ck_assert_str_eq("abob", str2);
}
END_TEST

START_TEST(s21_strncpy_test_number_10) {
  char str3[10] = "ABOBA";
  ck_assert_ptr_eq(S21_NULL, s21_strncpy(S21_NULL, str3, 10));
}
END_TEST

START_TEST(s21_strncpy_test_number_11) {
  ck_assert_ptr_eq(S21_NULL, s21_strncpy(S21_NULL, S21_NULL, 10));
}
END_TEST

TCase *s21_strncpy_create_tcase(void) {
  TCase *temp_case = tcase_create("S21_STRNCPY_TESTING:\n");
  tcase_add_test(temp_case, s21_strncpy_test_number_1);
  tcase_add_test(temp_case, s21_strncpy_test_number_2);
  tcase_add_test(temp_case, s21_strncpy_test_number_3);
  tcase_add_test(temp_case, s21_strncpy_test_number_4);
  tcase_add_test(temp_case, s21_strncpy_test_number_5);
  tcase_add_test(temp_case, s21_strncpy_test_number_6);
  tcase_add_test(temp_case, s21_strncpy_test_number_7);
  tcase_add_test(temp_case, s21_strncpy_test_number_8);
  tcase_add_test(temp_case, s21_strncpy_test_number_9);
  tcase_add_test(temp_case, s21_strncpy_test_number_10);
  tcase_add_test(temp_case, s21_strncpy_test_number_11);
  return temp_case;
}