#include <stdio.h>

#include "suite_test_runner.h"

START_TEST(s21_strtok_test_number_1) {
  char str1[] = "zxc/cxz/p[k]_kopaf/lkdpojad1dmsalda";
  char str2[] = "zxc/cxz/p[k]_kopaf/lkdpojad1dmsalda";
  char *ptr1 = strtok(str1, "1/_"), *ptr2 = s21_strtok(str2, "1/_");
  ck_assert_str_eq(ptr1, ptr2);
  ck_assert_str_eq(str1, str2);
  while (ptr1 != S21_NULL) {
    ck_assert_str_eq(ptr1, ptr2);
    ptr1 = strtok(S21_NULL, "1/_");
    ptr2 = s21_strtok(S21_NULL, "1/_");
    ck_assert_str_eq(str1, str2);
  }
}
END_TEST

START_TEST(s21_strtok_test_number_2) {
  char str1[] = "zxc/cxz/p[k]_kopaf/lkdpojad1dmsalda";
  char str2[] = "zxc/cxz/p[k]_kopaf/lkdpojad1dmsalda";
  char *ptr1 = strtok(str1, "1/_"), *ptr2 = s21_strtok(str2, "1/_");
  ck_assert_str_eq(ptr1, ptr2);
  ck_assert_str_eq(str1, str2);
  ptr1 = strtok(str1, "1/_");
  ptr2 = s21_strtok(str2, "1/_");
  ck_assert_str_eq(ptr1, ptr2);
  ck_assert_str_eq(str1, str2);
  ptr1 = strtok(str1, "1/_");
  ptr2 = s21_strtok(str2, "1/_");
  ck_assert_str_eq(ptr1, ptr2);
  ck_assert_str_eq(str1, str2);
  ptr1 = strtok(str1, "1/_");
  ptr2 = s21_strtok(str2, "1/_");
  ck_assert_str_eq(ptr1, ptr2);
  ck_assert_str_eq(str1, str2);
  ptr1 = strtok(str1, "1/_");
  ptr2 = s21_strtok(str2, "1/_");
}
END_TEST

START_TEST(s21_strtok_test_number_3) {
  char str1[] = "zxc/cxz/p[k]_kopaf/lkdpojad1dmsalda";
  char str2[] = "zxc/cxz/p[k]_kopaf/lkdpojad1dmsalda";
  char *ptr1 = strtok(str1, "=+3"), *ptr2 = s21_strtok(str2, "=+3");
  ck_assert_str_eq(str1, str2);
  ck_assert_str_eq(ptr1, ptr2);
}
END_TEST

START_TEST(s21_strtok_test_number_4) {
  char str1[] = "zxc/cxz/p[k]_kopaf/lkdpojad1dmsalda";
  char str2[] = "zxc/cxz/p[k]_kopaf/lkdpojad1dmsalda";
  char *ptr1 = strtok(str1, ""), *ptr2 = s21_strtok(str2, "");
  ck_assert_str_eq(str1, str2);
  ck_assert_str_eq(ptr1, ptr2);
}
END_TEST

START_TEST(s21_strtok_test_number_5) {
  char str1[] = "";
  char str2[] = "";
  char *ptr1 = strtok(str1, "=+3"), *ptr2 = s21_strtok(str2, "=+3");
  ck_assert_str_eq(str1, str2);
  ck_assert_ptr_eq(ptr1, ptr2);
}
END_TEST

START_TEST(s21_strtok_test_number_6) {
  char *ptr2 = s21_strtok(S21_NULL, "=+3");
  ck_assert_ptr_eq(S21_NULL, ptr2);
}
END_TEST

START_TEST(s21_strtok_test_number_7) {
  char str2[] = "Aboba";
  char *ptr2 = s21_strtok(str2, S21_NULL);
  ck_assert_ptr_eq(S21_NULL, ptr2);
  ck_assert_str_eq("Aboba", str2);
}
END_TEST

START_TEST(s21_strtok_test_number_8) {
  char str1[] = "zxc/cxz/p[k]_kopaf/lkdpojad1dmsalda";
  char str2[] = "zxc/cxz/p[k]_kopaf/lkdpojad1dmsalda";
  char str3[] = "zxc/cxz_p[k]_kopaf1lkdpojad1dmsalda";
  char str4[] = "zxc/cxz_p[k]_kopaf1lkdpojad1dmsalda";
  char *ptr1 = strtok(str1, "1/_"), *ptr2 = s21_strtok(str2, "1/_");
  ck_assert_str_eq(ptr1, ptr2);
  ck_assert_str_eq(str1, str2);
  while (ptr1 != S21_NULL) {
    ck_assert_str_eq(ptr1, ptr2);
    ptr1 = strtok(S21_NULL, "1/_");
    ptr2 = s21_strtok(S21_NULL, "1/_");
    ck_assert_str_eq(str1, str2);
  }
  ptr1 = strtok(str3, "1/_");
  ptr2 = s21_strtok(str4, "1/_");
  while (ptr1 != S21_NULL) {
    ck_assert_str_eq(ptr1, ptr2);
    ptr1 = strtok(S21_NULL, "1/_");
    ptr2 = s21_strtok(S21_NULL, "1/_");
    ck_assert_str_eq(str1, str2);
  }
}
END_TEST

TCase *s21_strtok_create_tcase(void) {
  TCase *temp_case = tcase_create("S21_STRTOK_TESTING:\n");
  tcase_add_test(temp_case, s21_strtok_test_number_1);
  tcase_add_test(temp_case, s21_strtok_test_number_2);
  tcase_add_test(temp_case, s21_strtok_test_number_3);
  tcase_add_test(temp_case, s21_strtok_test_number_4);
  tcase_add_test(temp_case, s21_strtok_test_number_5);
  tcase_add_test(temp_case, s21_strtok_test_number_6);
  tcase_add_test(temp_case, s21_strtok_test_number_7);
  tcase_add_test(temp_case, s21_strtok_test_number_8);
  return temp_case;
}