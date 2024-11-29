#include "suite_test_runner.h"


START_TEST(s21_strrchr_test_number_1) {
    char str[10] = "Abobalol";
    ck_assert_ptr_eq(strrchr(str, 'a'), s21_strrchr(str, 'a'));
}
END_TEST

START_TEST(s21_strrchr_test_number_2) {
    char str[10] = "Abobalol";
    ck_assert_ptr_eq(strrchr(str, 'b'), s21_strrchr(str, 'b'));
}
END_TEST

START_TEST(s21_strrchr_test_number_3) {
    char str[10] = "Abobalol";
    ck_assert_ptr_eq(strrchr(str, 'l'), s21_strrchr(str, 'l'));
}
END_TEST

START_TEST(s21_strrchr_test_number_4) {
    char str[10] = "Abobalol";
    ck_assert_ptr_eq(strrchr(str, '\0'), s21_strrchr(str, '\0'));
}
END_TEST

START_TEST(s21_strrchr_test_number_5) {
    char str[10] = "Abobalol";
    ck_assert_ptr_eq(strrchr(str, '8'), s21_strrchr(str, '8'));
}
END_TEST

START_TEST(s21_strrchr_test_number_6) {
    ck_assert_ptr_eq(S21_NULL, s21_strrchr(S21_NULL, 'A'));
}
END_TEST

TCase *s21_strrchr_create_tcase(void) {
    TCase *temp_case = tcase_create("S21_STRRCHR_TESTING:\n");
    tcase_add_test(temp_case, s21_strrchr_test_number_1);
    tcase_add_test(temp_case, s21_strrchr_test_number_2);
    tcase_add_test(temp_case, s21_strrchr_test_number_3);
    tcase_add_test(temp_case, s21_strrchr_test_number_4);
    tcase_add_test(temp_case, s21_strrchr_test_number_5);
    tcase_add_test(temp_case, s21_strrchr_test_number_6);
    return temp_case;
}