#include "suite_test_runner.h"
#include "s21_memchr_tcase.c"
#include "s21_memcmp_tcase.c"
#include "s21_memcpy_tcase.c"
#include "s21_memset_tcase.c"
#include "s21_strncat_tcase.c"
#include "s21_strchr_tcase.c"
#include "s21_strncmp_tcase.c"
#include "s21_strncpy_tcase.c"
#include "s21_strcspn_tcase.c"
#include "s21_strerror_tcase.c"
#include "s21_strlen_tcase.c"
#include "s21_strpbrk_tcase.c"
#include "s21_strrchr_tcase.c"
#include "s21_strstr_tcase.c"
#include "s21_strtok_tcase.c"



Suite *untie_tacses_to_suit(void) {
  Suite *s = suite_create("s21_strung_plus_testing");
  suite_add_tcase(s, s21_memchr_create_tcase());
  suite_add_tcase(s, s21_memcmp_create_tcase());
  suite_add_tcase(s, s21_memcpy_create_tcase());
  suite_add_tcase(s, s21_memset_create_tcase());
  suite_add_tcase(s, s21_strncat_create_tcase());
  suite_add_tcase(s, s21_strchr_create_tcase());
  suite_add_tcase(s, s21_strncmp_create_tcase());
  suite_add_tcase(s, s21_strncpy_create_tcase());
  suite_add_tcase(s, s21_strcspn_create_tcase());
  suite_add_tcase(s, s21_strerror_create_tcase());
  suite_add_tcase(s, s21_strlen_create_tcase());
  suite_add_tcase(s, s21_strpbrk_create_tcase());
  suite_add_tcase(s, s21_strrchr_create_tcase());
  suite_add_tcase(s, s21_strstr_create_tcase());
  suite_add_tcase(s, s21_strtok_create_tcase());
  return s;
}


int main(void) {
  int failed_count = 0;
  SRunner *runner = srunner_create(untie_tacses_to_suit());

  srunner_run_all(runner, CK_NORMAL);
  failed_count = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed_count == 0 ? 0 : 1;
}

