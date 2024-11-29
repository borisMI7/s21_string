#include "suite_test_runner.h"

START_TEST(s21_memcpy_test_number_1) {
    char str1[] = "Aboba", str2[] = "Aboba", dest1[] = "lolaboba", dest2[] = "lolaboba";
    ck_assert_str_eq(memcpy(dest1, str1, 5), s21_memcpy(dest2, str2, 5));
    ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(s21_memcpy_test_number_2) {
    char str1[10] = "Aboba", str2[10] = "Aboba", dest1[] = "lolaboba", dest2[] = "lolaboba";
    ck_assert_str_eq(memcpy(dest1, str1, 9), s21_memcpy(dest2, str2, 9));
    ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(s21_memcpy_test_number_3) {
    char str1[] = "Aboba", str2[] = "Aboba", dest1[] = "lolaboba", dest2[] = "lolaboba";
    ck_assert_str_eq(memcpy(dest1, str1, 0), s21_memcpy(dest2, str2, 0));
    ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(s21_memcpy_test_number_4) {
    char str1[] = "Aboba", str2[] = "Aboba", dest1[] = "lolaboba", dest2[] = "lolaboba";
    ck_assert_str_eq(memcpy(dest1, str1, 2), s21_memcpy(dest2, str2, 2));
    ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(s21_memcpy_test_number_5) {
    char str1[5] = "", str2[5] = "", dest1[] = "lolaboba", dest2[] = "lolaboba";
    ck_assert_str_eq(memcpy(dest1, str1, 2), s21_memcpy(dest2, str2, 2));
    ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(s21_memcpy_test_number_6) {
    char str1[15] = "Aboba", str2[15] = "Aboba", dest1[20] = "lolaboba", dest2[20] = "lolaboba";
    ck_assert_str_eq(memcpy(dest1, str1, 10), s21_memcpy(dest2, str2, 10));
    ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(s21_memcpy_test_number_7) {
    char str1[10] = "Aboba", str2[10] = "Aboba", dest1[20] = "", dest2[20] = "";
    ck_assert_str_eq(memcpy(dest1, str1, 10), s21_memcpy(dest2, str2, 10));
    ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(s21_memcpy_test_number_8) {
    char str1[10] = "", str2[10] = "", dest1[20] = "", dest2[20] = "";
    ck_assert_str_eq(memcpy(dest1, str1, 10), s21_memcpy(dest2, str2, 10));
    ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(s21_memcpy_test_number_9) {
    char  dest2[20] = "asd";
    ck_assert_str_eq(dest2, s21_memcpy(dest2, S21_NULL, 10));
}
END_TEST

START_TEST(s21_memcpy_test_number_10) {
    ck_assert_ptr_eq(S21_NULL, s21_memcpy(S21_NULL, S21_NULL, 10));
}
END_TEST

START_TEST(s21_memcpy_test_number_11) {
    char  dest2[20] = "asd";
    ck_assert_ptr_eq(S21_NULL, s21_memcpy(S21_NULL, dest2, 10));
}
END_TEST

START_TEST(s21_memcpy_test_number_12) {
    char str1[] = "Aboba", str2[] = "Aboba", dest1[] = "lolaboba", dest2[] = "lolaboba";
    ck_assert_str_eq(memcpy(dest1, str1, 6), s21_memcpy(dest2, str2, 6));
    ck_assert_str_eq(dest1, dest2);
}
END_TEST

TCase *s21_memcpy_create_tcase(void) {
    TCase *temp_case = tcase_create("S21_MEMCPY_TESTING:\n");
    tcase_add_test(temp_case, s21_memcpy_test_number_1);
    tcase_add_test(temp_case, s21_memcpy_test_number_2);
    tcase_add_test(temp_case, s21_memcpy_test_number_3);
    tcase_add_test(temp_case, s21_memcpy_test_number_4);
    tcase_add_test(temp_case, s21_memcpy_test_number_5);
    tcase_add_test(temp_case, s21_memcpy_test_number_6);
    tcase_add_test(temp_case, s21_memcpy_test_number_7);
    tcase_add_test(temp_case, s21_memcpy_test_number_8);
    tcase_add_test(temp_case, s21_memcpy_test_number_9);
    tcase_add_test(temp_case, s21_memcpy_test_number_10);
    tcase_add_test(temp_case, s21_memcpy_test_number_11);
    tcase_add_test(temp_case, s21_memcpy_test_number_12);
    return temp_case;
}