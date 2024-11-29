#include "suite_test_runner.h"


START_TEST(s21_strncmp_test_number_1) {
    char str1[10] = "abob", str2[] = "", str3[10] = "abob";
    ck_assert_str_eq(s21_strncat(str3, str2, 10), s21_strncat(str1, str2, 10));
    ck_assert_str_eq(str3, str1);
}
END_TEST

TCase *s21_strncmp_create_tcase(void) {
    TCase *temp_case = tcase_create("S21_STRNCMP_TESTING:\n");
    tcase_add_test(temp_case, s21_strncmp_test_number_1);
    return temp_case;
}