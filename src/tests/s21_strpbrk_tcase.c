#include "suite_test_runner.h"

START_TEST(s21_strpbrk_test_number_1) {
  char str[10] = "aboba", str2[] = "1b4p";
  ck_assert_ptr_eq(strpbrk(str, str2), s21_strpbrk(str, str2));
}
END_TEST

START_TEST(s21_strpbrk_test_number_2) {
  char str[10] = "aboba", str2[] = "mmmmmmm";
  ck_assert_ptr_eq(strpbrk(str, str2), s21_strpbrk(str, str2));
}
END_TEST

START_TEST(s21_strpbrk_test_number_3) {
  char str[10] = "aboba", str2[] = "";
  ck_assert_ptr_eq(strpbrk(str, str2), s21_strpbrk(str, str2));
}
END_TEST

START_TEST(s21_strpbrk_test_number_4) {
  char str[10] = "aboba4", str2[] = "1b4p";
  ck_assert_ptr_eq(strpbrk(str, str2), s21_strpbrk(str, str2));
}
END_TEST

START_TEST(s21_strpbrk_test_number_5) {
  char str[10] = "", str2[] = "1b4p";
  ck_assert_ptr_eq(strpbrk(str, str2), s21_strpbrk(str, str2));
}
END_TEST

START_TEST(s21_strpbrk_test_number_6) {
  char str[10] = "", str2[] = "";
  ck_assert_ptr_eq(strpbrk(str, str2), s21_strpbrk(str, str2));
}
END_TEST

START_TEST(s21_strpbrk_test_number_7) {
  char str[10] = "aboba";
  ck_assert_ptr_eq(S21_NULL, s21_strpbrk(str, S21_NULL));
}
END_TEST

START_TEST(s21_strpbrk_test_number_8) {
  char str2[] = "1b4p";
  ck_assert_ptr_eq(S21_NULL, s21_strpbrk(S21_NULL, str2));
}
END_TEST

START_TEST(s21_strpbrk_test_number_9) {
  ck_assert_ptr_eq(S21_NULL, s21_strpbrk(S21_NULL, S21_NULL));
}
END_TEST

TCase *s21_strpbrk_create_tcase(void) {
  TCase *temp_case = tcase_create("S21_STRPBRK_TESTING:\n");
  tcase_add_test(temp_case, s21_strpbrk_test_number_1);
  tcase_add_test(temp_case, s21_strpbrk_test_number_2);
  tcase_add_test(temp_case, s21_strpbrk_test_number_3);
  tcase_add_test(temp_case, s21_strpbrk_test_number_4);
  tcase_add_test(temp_case, s21_strpbrk_test_number_5);
  tcase_add_test(temp_case, s21_strpbrk_test_number_6);
  tcase_add_test(temp_case, s21_strpbrk_test_number_7);
  tcase_add_test(temp_case, s21_strpbrk_test_number_8);
  tcase_add_test(temp_case, s21_strpbrk_test_number_9);
  return temp_case;
}