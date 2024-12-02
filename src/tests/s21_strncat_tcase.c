#include "suite_test_runner.h"

START_TEST(s21_mstrncat_test_number_1) {
  char str1[10] = "abob", str2[] = "", str3[10] = "abob";
  ck_assert_str_eq(s21_strncat(str3, str2, 10), s21_strncat(str1, str2, 10));
  ck_assert_str_eq(str3, str1);
}
END_TEST

START_TEST(s21_mstrncat_test_number_2) {
  char str1[10] = "abob", str2[] = "", str3[10] = "abob";
  ck_assert_str_eq(s21_strncat(str3, str2, 0), s21_strncat(str1, str2, 0));
  ck_assert_str_eq(str3, str1);
}
END_TEST

START_TEST(s21_mstrncat_test_number_3) {
  char str1[10] = "abob", str2[] = "ABOBA", str3[10] = "abob";
  ck_assert_str_eq(s21_strncat(str3, str2, 5), s21_strncat(str1, str2, 5));
  ck_assert_str_eq(str3, str1);
}
END_TEST

START_TEST(s21_mstrncat_test_number_4) {
  char str1[10] = "abob", str2[] = "ABOBA", str3[10] = "abob";
  ck_assert_str_eq(s21_strncat(str3, str2, 6), s21_strncat(str1, str2, 6));
  ck_assert_str_eq(str3, str1);
}
END_TEST

START_TEST(s21_mstrncat_test_number_5) {
  char str1[10] = "abob", str2[] = "ABOBA", str3[10] = "abob";
  ck_assert_str_eq(s21_strncat(str3, str2, 10), s21_strncat(str1, str2, 10));
  ck_assert_str_eq(str3, str1);
}
END_TEST

START_TEST(s21_mstrncat_test_number_6) {
  char str1[10] = "abob", str2[] = "ABOBA", str3[10] = "abob";
  ck_assert_str_eq(s21_strncat(str3, str2, 0), s21_strncat(str1, str2, 0));
  ck_assert_str_eq(str3, str1);
}
END_TEST

START_TEST(s21_mstrncat_test_number_7) {
  char *str1 = S21_NULL, str2[] = "ABOBA";
  ck_assert_ptr_eq(S21_NULL, s21_strncat(str1, str2, 5));
  ck_assert_ptr_eq(S21_NULL, str1);
}
END_TEST

START_TEST(s21_mstrncat_test_number_8) {
  char *str1 = S21_NULL, *str2 = S21_NULL;
  ck_assert_ptr_eq(S21_NULL, s21_strncat(str1, str2, 5));
  ck_assert_ptr_eq(S21_NULL, str1);
}
END_TEST

START_TEST(s21_mstrncat_test_number_9) {
  char str1[] = "aboba", *str2 = S21_NULL;
  ck_assert_str_eq("aboba", s21_strncat(str1, str2, 5));
  ck_assert_str_eq("aboba", str1);
}
END_TEST

TCase *s21_strncat_create_tcase(void) {
  TCase *temp_case = tcase_create("S21_STRNCAT_TESTING:\n");
  tcase_add_test(temp_case, s21_mstrncat_test_number_1);
  tcase_add_test(temp_case, s21_mstrncat_test_number_2);
  tcase_add_test(temp_case, s21_mstrncat_test_number_3);
  tcase_add_test(temp_case, s21_mstrncat_test_number_4);
  tcase_add_test(temp_case, s21_mstrncat_test_number_5);
  tcase_add_test(temp_case, s21_mstrncat_test_number_6);
  tcase_add_test(temp_case, s21_mstrncat_test_number_7);
  tcase_add_test(temp_case, s21_mstrncat_test_number_8);
  tcase_add_test(temp_case, s21_mstrncat_test_number_9);
  return temp_case;
}
