#include "suite_test_runner.h"

START_TEST(s21_insert_test_number_1) {
  char *ptr = s21_insert("Aboba is", " the real boba", 8);
  ck_assert_str_eq("Aboba is the real boba", ptr);
  if (ptr) free(ptr);
}
END_TEST

START_TEST(s21_insert_test_number_2) {
  char *ptr = s21_insert("Aboba is", " the real boba", 0);
  ck_assert_str_eq(" the real bobaAboba is", ptr);
  if (ptr) free(ptr);
}
END_TEST

START_TEST(s21_insert_test_number_3) {
  char *ptr = s21_insert("Aboba is", " the real boba", 5);
  ck_assert_str_eq("Aboba the real boba is", ptr);
  if (ptr) free(ptr);
}
END_TEST

START_TEST(s21_insert_test_number_4) {
  char *ptr = s21_insert("Aboba is", " the real boba", 20);
  ck_assert_ptr_eq(S21_NULL, ptr);
  if (ptr) free(ptr);
}
END_TEST

START_TEST(s21_insert_test_number_5) {
  char *ptr = s21_insert(S21_NULL, " the real boba", 20);
  ck_assert_ptr_eq(S21_NULL, ptr);
  if (ptr) free(ptr);
}
END_TEST

START_TEST(s21_insert_test_number_6) {
  char *ptr = s21_insert("Aboba is", S21_NULL, 20);
  ck_assert_ptr_eq(S21_NULL, ptr);
  if (ptr) free(ptr);
}
END_TEST

START_TEST(s21_insert_test_number_7) {
  char *ptr = s21_insert(S21_NULL, S21_NULL, 20);
  ck_assert_ptr_eq(S21_NULL, ptr);
  if (ptr) free(ptr);
}
END_TEST

START_TEST(s21_insert_test_number_8) {
  char *ptr = s21_insert("Aboba is", " the real boba", -5);
  ck_assert_ptr_eq(S21_NULL, ptr);
  if (ptr) free(ptr);
}
END_TEST

START_TEST(s21_insert_test_number_9) {
  char *ptr = s21_insert("", " the real boba", 0);
  ck_assert_str_eq(" the real boba", ptr);
  if (ptr) free(ptr);
}
END_TEST

START_TEST(s21_insert_test_number_10) {
  char *ptr = s21_insert("ABOBA", "", 2);
  ck_assert_str_eq("ABOBA", ptr);
  if (ptr) free(ptr);
}
END_TEST

START_TEST(s21_insert_test_number_11) {
  char *ptr = s21_insert("", "", 0);
  ck_assert_str_eq("", ptr);
  if (ptr) free(ptr);
}
END_TEST

TCase *s21_insert_create_tcase(void) {
  TCase *temp_case = tcase_create("S21_INSERT_TESTING:\n");
  tcase_add_test(temp_case, s21_insert_test_number_1);
  tcase_add_test(temp_case, s21_insert_test_number_2);
  tcase_add_test(temp_case, s21_insert_test_number_3);
  tcase_add_test(temp_case, s21_insert_test_number_4);
  tcase_add_test(temp_case, s21_insert_test_number_5);
  tcase_add_test(temp_case, s21_insert_test_number_6);
  tcase_add_test(temp_case, s21_insert_test_number_7);
  tcase_add_test(temp_case, s21_insert_test_number_8);
  tcase_add_test(temp_case, s21_insert_test_number_9);
  tcase_add_test(temp_case, s21_insert_test_number_10);
  tcase_add_test(temp_case, s21_insert_test_number_11);
  return temp_case;
}