#include "suite_test_runner.h"

START_TEST(s21_memcmp_test_number_1) {
    char s1[] = "Aboba", s2[] = "Aboba";
    ck_assert_int_eq(s21_memcmp(s1, s2, 5), memcmp(s1, s2, 5));
}
END_TEST

START_TEST(s21_memcmp_test_number_2) {
    char s1[] = "Aboba", s2[] = "Aboba";
    ck_assert_int_eq(s21_memcmp(s1, s2, 10), memcmp(s1, s2, 10));
}
END_TEST

START_TEST(s21_memcmp_test_number_3) {
    char s1[] = "Aboba", s2[] = "Aboba";
    ck_assert_int_eq(s21_memcmp(s1, s2, 0), memcmp(s1, s2, 0));
}
END_TEST

START_TEST(s21_memcmp_test_number_4) {
    char s1[] = "", s2[] = "Aboba";
    ck_assert_int_eq(s21_memcmp(s1, s2, 10), memcmp(s1, s2, 10));
}
END_TEST

START_TEST(s21_memcmp_test_number_5) {
    char s1[] = "Aboba", s2[] = "";
    ck_assert_int_eq(s21_memcmp(s1, s2, 10), memcmp(s1, s2, 10));
}
END_TEST

START_TEST(s21_memcmp_test_number_6) {
    char s1[] = "", s2[] = "";
    ck_assert_int_eq(s21_memcmp(s1, s2, 10), memcmp(s1, s2, 10));
}
END_TEST

START_TEST(s21_memcmp_test_number_7) {
    char s1[] = "Cboba", s2[] = "Bboba";
    ck_assert_int_eq(s21_memcmp(s1, s2, 10), memcmp(s1, s2, 10));
}
END_TEST

START_TEST(s21_memcmp_test_number_8) {
    char s1[] = "Aboba", s2[] = "Bboba";
    ck_assert_int_eq(s21_memcmp(s1, s2, 10), memcmp(s1, s2, 10));
}
END_TEST

START_TEST(s21_memcmp_test_number_9) {
    char s1[] = "Aboba", s2[] = "Abobb";
    ck_assert_int_eq(s21_memcmp(s1, s2, 2), memcmp(s1, s2, 2));
}
END_TEST

START_TEST(s21_memcmp_test_number_10) {
    char s1[] = "abcdefg", s2[] = "abc";
    ck_assert_int_eq(s21_memcmp(s1, s2, 7), memcmp(s1, s2, 7));
}
END_TEST

START_TEST(s21_memcmp_test_number_11) {
    char s2[] = "abc";
    ck_assert_int_eq(s21_memcmp(NULL, s2, 7), -1);
}
END_TEST

START_TEST(s21_memcmp_test_number_12) {
    char s1[] = "abcdefg";
    ck_assert_int_eq(s21_memcmp(s1, NULL, 10), 1);
}
END_TEST


START_TEST(s21_memcmp_test_number_13) {
    ck_assert_int_eq(s21_memcmp(NULL, NULL, 10), 0);
}
END_TEST

TCase *s21_memcmp_create_tcase(void) {
    TCase *temp_case = tcase_create("S21_MEMCMP_TESTING:\n");
    tcase_add_test(temp_case, s21_memcmp_test_number_1);
    tcase_add_test(temp_case, s21_memcmp_test_number_2);
    tcase_add_test(temp_case, s21_memcmp_test_number_3);
    tcase_add_test(temp_case, s21_memcmp_test_number_4);
    tcase_add_test(temp_case, s21_memcmp_test_number_5);
    tcase_add_test(temp_case, s21_memcmp_test_number_6);
    tcase_add_test(temp_case, s21_memcmp_test_number_7);
    tcase_add_test(temp_case, s21_memcmp_test_number_8);
    tcase_add_test(temp_case, s21_memcmp_test_number_9);
    tcase_add_test(temp_case, s21_memcmp_test_number_10);
    tcase_add_test(temp_case, s21_memcmp_test_number_11);
    tcase_add_test(temp_case, s21_memcmp_test_number_12);
    tcase_add_test(temp_case, s21_memcmp_test_number_13);
    
    return temp_case;
}