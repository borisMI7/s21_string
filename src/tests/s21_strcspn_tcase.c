#include "suite_test_runner.h"

START_TEST(s21_strcspn_test_number_1) {
  char str1[30] = "aaaaaaaaaa1aaa2aaaa3aa", str2[10] = "123";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strcspn_test_number_2) {
  char str1[30] = "a1aaaaaaaaa2aaaa3aa", str2[10] = "123";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strcspn_test_number_3) {
  char str1[30] = "123", str2[10] = "123";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strcspn_test_number_4) {
  char str1[30] = "a1aaaaaaaaa2aaaa3aa", str2[10] = "";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strcspn_test_number_5) {
  char str1[30] = "", str2[10] = "123";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strcspn_test_number_6) {
  char str1[30] = "aaaaaaaaaaaaaaa", str2[10] = "123";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strcspn_test_number_7) {
  char str1[30] = "a1aaaaaaaaa2aaaa3aa", str2[10] = "321";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strcspn_test_number_8) {
  char str1[30] = "abcde";
  ck_assert_int_eq(5, s21_strcspn(str1, S21_NULL));
}
END_TEST

START_TEST(s21_strcspn_test_number_9) {
  char str2[10] = "123";
  ck_assert_int_eq(0, s21_strcspn(S21_NULL, str2));
}
END_TEST

START_TEST(s21_strcspn_test_number_10) {
  ;
  ck_assert_int_eq(0, s21_strcspn(S21_NULL, S21_NULL));
}
END_TEST

TCase *s21_strcspn_create_tcase(void) {
  TCase *temp_case = tcase_create("S21_STRCSPN_TESTING:\n");
  tcase_add_test(temp_case, s21_strcspn_test_number_1);
  tcase_add_test(temp_case, s21_strcspn_test_number_2);
  tcase_add_test(temp_case, s21_strcspn_test_number_3);
  tcase_add_test(temp_case, s21_strcspn_test_number_4);
  tcase_add_test(temp_case, s21_strcspn_test_number_5);
  tcase_add_test(temp_case, s21_strcspn_test_number_6);
  tcase_add_test(temp_case, s21_strcspn_test_number_7);
  tcase_add_test(temp_case, s21_strcspn_test_number_8);
  tcase_add_test(temp_case, s21_strcspn_test_number_9);
  tcase_add_test(temp_case, s21_strcspn_test_number_10);
  return temp_case;
}