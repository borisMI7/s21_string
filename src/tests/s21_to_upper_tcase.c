#include "suite_test_runner.h"

START_TEST(s21_to_upper_test_number_1) {
  char *ptr1 = s21_to_upper("jfnkjASdddsajknifurwuvownivOVNdsivdfjcmoef-=-0=l0 "
                            "z12839jFNS(f9281jed91wmfrw)");
  ck_assert_str_eq(ptr1, "JFNKJASDDDSAJKNIFURWUVOWNIVOVNDSIVDFJCMOEF-=-0=L0 "
                         "Z12839JFNS(F9281JED91WMFRW)");
  if (ptr1)
    free(ptr1);
}
END_TEST

START_TEST(s21_to_upper_test_number_2) {
  char *ptr1 = s21_to_upper("");
  ck_assert_str_eq(ptr1, "");
  if (ptr1)
    free(ptr1);
}
END_TEST

START_TEST(s21_to_upper_test_number_3) {
  char *ptr1 = s21_to_upper("12345");
  ck_assert_str_eq(ptr1, "12345");
  if (ptr1)
    free(ptr1);
}
END_TEST

START_TEST(s21_to_upper_test_number_4) {
  char *ptr1 = s21_to_upper("ABOBA");
  ck_assert_str_eq(ptr1, "ABOBA");
  if (ptr1)
    free(ptr1);
}
END_TEST

START_TEST(s21_to_upper_test_number_5) {
  char *ptr1 = s21_to_upper(S21_NULL);
  ck_assert_ptr_eq(ptr1, S21_NULL);
  if (ptr1)
    free(ptr1);
}
END_TEST

TCase *s21_to_upper_create_tcase(void) {
  TCase *temp_case = tcase_create("S21_TO_UPPER_TESTING:\n");
  tcase_add_test(temp_case, s21_to_upper_test_number_1);
  tcase_add_test(temp_case, s21_to_upper_test_number_2);
  tcase_add_test(temp_case, s21_to_upper_test_number_3);
  tcase_add_test(temp_case, s21_to_upper_test_number_4);
  tcase_add_test(temp_case, s21_to_upper_test_number_5);

  return temp_case;
}