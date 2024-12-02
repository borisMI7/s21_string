#include "suite_test_runner.h"

START_TEST(s21_strlen_test_number_1) {
  char str[10] = "Abobalol";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(s21_strlen_test_number_2) {
  char str[10] = "";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(s21_strlen_test_number_3) {
  ck_assert_int_eq(0, s21_strlen(S21_NULL));
}
END_TEST

TCase *s21_strlen_create_tcase(void) {
  TCase *temp_case = tcase_create("S21_STRLEN_TESTING:\n");
  tcase_add_test(temp_case, s21_strlen_test_number_1);
  tcase_add_test(temp_case, s21_strlen_test_number_2);
  tcase_add_test(temp_case, s21_strlen_test_number_3);
  return temp_case;
}