#include "suite_test_runner.h"
#include "s21_memchr_tcase.c"

Suite *untie_tacses_to_suit(void) {
  Suite *s = suite_create("s21_strung_plus_testing");
  suite_add_tcase(s, s21_memchr_create_tcase());

  return s;
}


int main(void) {
  int failed_count = 0;
  Suite *s = untie_tacses_to_suit();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
//   failed_count = srunner_ntests_failed(runner);
//   srunner_free(runner);

  return failed_count == 0 ? 0 : 1;
}

