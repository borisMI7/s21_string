#include "suite_test_runner.h"


START_TEST(s21_strstr_test_number_1) {
    char str1[10] = "Abobalol", str2[] = "oba";
    ck_assert_ptr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr_test_number_2) {
    char str1[10] = "Abobalol", str2[] = "";
    ck_assert_str_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr_test_number_3) {
    char str1[10] = "", str2[] = "oba";
    ck_assert_ptr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr_test_number_4) {
    char str1[10] = "", str2[] = "";
    ck_assert_ptr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr_test_number_5) {
    char str1[10] = "Abobalol", str2[] = "Abobalol";
    ck_assert_ptr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr_test_number_6) {
    char str1[10] = "Abobalol", str2[] = "pppppppppppppppppp";
    ck_assert_ptr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST


TCase *s21_strstr_create_tcase(void) {
    TCase *temp_case = tcase_create("S21_STRSTR_TESTING:\n");
    tcase_add_test(temp_case, s21_strstr_test_number_1);
    tcase_add_test(temp_case, s21_strstr_test_number_2);
    tcase_add_test(temp_case, s21_strstr_test_number_3);
    tcase_add_test(temp_case, s21_strstr_test_number_4);
    tcase_add_test(temp_case, s21_strstr_test_number_5);
    tcase_add_test(temp_case, s21_strstr_test_number_6);
    return temp_case;
}