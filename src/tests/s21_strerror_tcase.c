#include "suite_test_runner.h"

#if defined(__APPLE__)
#define MAX_ERRLIST 107
#define MIN_ERRLIST -1
#endif

#if defined(__linux__)
#define MAX_ERRLIST 134
#define MIN_ERRLIST -1
#endif

START_TEST(s21_strerror_test_number_1) {
  for (int i = -50; i <= MAX_ERRLIST + 50; i++) {
    ck_assert_str_eq(strerror(i), s21_strerror(i));
  }
}
END_TEST

TCase *s21_strerror_create_tcase(void) {
  TCase *temp_case = tcase_create("S21_STRERROR_TESTING:\n");
  tcase_add_test(temp_case, s21_strerror_test_number_1);
  return temp_case;
}