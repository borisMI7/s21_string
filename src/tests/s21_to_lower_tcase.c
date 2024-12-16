#include "suite_test_runner.h"

START_TEST(s21_to_lower_test_number_1) {
  char *ptr = s21_to_lower("JFNKJASDDDSAJKNIFURWUVOWNIVOVNDSIVDFJCMOEF-=-0=L0 "
                           "Z12839JFNS(F9281JED91WMFRW)");
  ck_assert_str_eq("jfnkjasdddsajknifurwuvownivovndsivdfjcmoef-=-0=l0 "
                   "z12839jfns(f9281jed91wmfrw)",
                   ptr);
  if (ptr)
    free(ptr);
}
END_TEST

START_TEST(s21_to_lower_test_number_2) {
  char *ptr = s21_to_lower("");
  ck_assert_str_eq("", ptr);
  if (ptr)
    free(ptr);
}
END_TEST

START_TEST(s21_to_lower_test_number_3) {
  char *ptr = s21_to_lower("lowert_aboba_is_great_again");
  ck_assert_str_eq("lowert_aboba_is_great_again", ptr);
  if (ptr)
    free(ptr);
}
END_TEST

START_TEST(s21_to_lower_test_number_4) {
  char *ptr = s21_to_lower(S21_NULL);
  ck_assert_ptr_eq(S21_NULL, ptr);
  if (ptr)
    free(ptr);
}
END_TEST

START_TEST(s21_to_lower_test_number_5) {
  char *ptr =
      s21_to_lower("1232132_+-=-+-())().;,:№№?><>:|::|~~```±±±§§§§:,.;()");
  ck_assert_str_eq("1232132_+-=-+-())().;,:№№?><>:|::|~~```±±±§§§§:,.;()", ptr);
  if (ptr)
    free(ptr);
}
END_TEST

TCase *s21_to_lower_create_tcase(void) {
  TCase *temp_case = tcase_create("S21_TO_LOWER_TESTING:\n");
  tcase_add_test(temp_case, s21_to_lower_test_number_1);
  tcase_add_test(temp_case, s21_to_lower_test_number_2);
  tcase_add_test(temp_case, s21_to_lower_test_number_3);
  tcase_add_test(temp_case, s21_to_lower_test_number_4);
  tcase_add_test(temp_case, s21_to_lower_test_number_5);
  return temp_case;
}