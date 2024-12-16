#include "suite_test_runner.h"

START_TEST(s21_trim_test_number_1) {
  char str[100] = "         is Aoba real?                                ";
  char *ptr = s21_trim(str, " ()90180");
  ck_assert_str_eq("is Aoba real?", ptr);
  if (ptr) free(ptr);
}
END_TEST

START_TEST(s21_trim_test_number_2) {
  char str[100] =
      "   ()))((0011))      is Aoba real?                  ((00()0))           "
      "   ";
  char *ptr = s21_trim(str, " ()90180");
  ck_assert_str_eq("is Aoba real?", ptr);
  if (ptr) free(ptr);
}
END_TEST

START_TEST(s21_trim_test_number_3) {
  char str[100] = "01))     p(   is Aoba real?  ()";
  char *ptr = s21_trim(str, " ()90180");
  ck_assert_str_eq("p(   is Aoba real?", ptr);
  if (ptr) free(ptr);
}
END_TEST

START_TEST(s21_trim_test_number_4) {
  char str[100] = {0};
  char *ptr = s21_trim(str, " ()90180");
  ck_assert_str_eq("", ptr);
  if (ptr) free(ptr);
}
END_TEST

START_TEST(s21_trim_test_number_5) {
  char str[100] = "           ()()()909091";
  char *ptr = s21_trim(str, " ()90180");
  ck_assert_str_eq("", ptr);
  if (ptr) free(ptr);
}
END_TEST

START_TEST(s21_trim_test_number_6) {
  char str[100] = "ABOOOBA ";
  char *ptr = s21_trim(str, "mn");
  ck_assert_str_eq("ABOOOBA ", ptr);
  if (ptr) free(ptr);
}
END_TEST

START_TEST(s21_trim_test_number_7) {
  char str[100] = "ABOOOBA ";
  char *ptr = s21_trim(str, "");
  ck_assert_str_eq("ABOOOBA ", ptr);
  if (ptr) free(ptr);
}
END_TEST

START_TEST(s21_trim_test_number_8) {
  char *ptr = s21_trim(S21_NULL, "mn");
  ck_assert_ptr_eq(S21_NULL, ptr);
  if (ptr) free(ptr);
}
END_TEST

START_TEST(s21_trim_test_number_9) {
  char str[100] = " ABOOOBA ";
  char *ptr = s21_trim(str, S21_NULL);
  ck_assert_str_eq("ABOOOBA", ptr);
  if (ptr) free(ptr);
}
END_TEST

START_TEST(s21_trim_test_number_10) {
  char *ptr = s21_trim(S21_NULL, S21_NULL);
  ck_assert_ptr_eq(S21_NULL, ptr);
  if (ptr) free(ptr);
}
END_TEST

TCase *s21_trim_create_tcase(void) {
  TCase *temp_case = tcase_create("S21_TRIM_TESTING:\n");
  tcase_add_test(temp_case, s21_trim_test_number_1);
  tcase_add_test(temp_case, s21_trim_test_number_2);
  tcase_add_test(temp_case, s21_trim_test_number_3);
  tcase_add_test(temp_case, s21_trim_test_number_4);
  tcase_add_test(temp_case, s21_trim_test_number_5);
  tcase_add_test(temp_case, s21_trim_test_number_6);
  tcase_add_test(temp_case, s21_trim_test_number_7);
  tcase_add_test(temp_case, s21_trim_test_number_8);
  tcase_add_test(temp_case, s21_trim_test_number_9);
  tcase_add_test(temp_case, s21_trim_test_number_10);
  return temp_case;
}