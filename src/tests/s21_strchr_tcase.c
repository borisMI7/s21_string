#include "suite_test_runner.h"


START_TEST(s21_strchr_test_number_1) {
    char str1[10] = "aboba";
    ck_assert_ptr_eq(strchr(str1, 'a'), s21_strchr(str1, 'a'));
}
END_TEST

START_TEST(s21_strchr_test_number_2) {
    char str1[10] = "aboba";
    ck_assert_ptr_eq(strchr(str1, '\0'), s21_strchr(str1, '\0'));
}
END_TEST

START_TEST(s21_strchr_test_number_3) {
    char str1[10] = "aboba";
    ck_assert_ptr_eq(strchr(str1, 'A'), s21_strchr(str1, 'A'));
}
END_TEST

START_TEST(s21_strchr_test_number_4) {
    ck_assert_ptr_eq(S21_NULL, s21_strchr(S21_NULL, 'A'));
}
END_TEST

START_TEST(s21_strchr_test_number_5) {
    char str1[10] = "";
    ck_assert_ptr_eq(strchr(str1, 'A'), s21_strchr(str1, 'A'));
}
END_TEST

TCase *s21_strchr_create_tcase(void) {
    TCase *temp_case = tcase_create("S21_STRCHR_TESTING:\n");
    tcase_add_test(temp_case, s21_strchr_test_number_1);
    tcase_add_test(temp_case, s21_strchr_test_number_2);
    tcase_add_test(temp_case, s21_strchr_test_number_3);
    tcase_add_test(temp_case, s21_strchr_test_number_4);
    tcase_add_test(temp_case, s21_strchr_test_number_5);
    return temp_case;
}