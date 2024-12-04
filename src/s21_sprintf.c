#include <math.h>
#include <stdarg.h>
#include <stdio.h>
// #include <string.h>
#include <limits.h>

#include "s21_string.h"

typedef long double s21_ldouble;
typedef unsigned int s21_uint;
typedef long int s21_lint;
typedef short int s21_sint;

typedef struct spec {
  size_t width;    // ширина вывода
  int left_allig;  // выравнивание слева или справа
  int accuracy;  // количество знаков после запятой
  int print_plus;  // печатать ли плюсы
  int space;  // печатать ли пробел если знак не выведен
  int hash_spec;   // флаг #
  int is_zero;     // Является ли число не нулём
  int field_zero;  // нужно ли  заполнять слева нулями
  char spec;       // какой спецификатор
  char spec_size;  // длина спецификатора 
} spec;

void apply_padding(char **result, size_t curr_len, size_t padding_size,
                   char pad_char, int left_align) {
  if (left_align) {
    for (size_t i = 0; i < padding_size; i++) {
      (*result)[curr_len + i] = pad_char;
    }
  } else {
    for (size_t i = curr_len - 1; i < curr_len; i--) {
      (*result)[i + padding_size] = (*result)[i];
    }
    for (size_t i = 0; i < padding_size; i++) {
      (*result)[i] = pad_char;
    }
  }
  (*result)[curr_len + padding_size] = '\0';
}

char *reallocate_and_shift(char **result, size_t *curr_len,
                           size_t add_space) {  // Don't work sprinf("%#3x",37);
  char *temp = realloc(*result, sizeof(char) * (*curr_len + add_space + 1));
  if (!temp) {
    if (*result) {free(*result); *result = S21_NULL;}
  } else {
    for (size_t i = *curr_len; i > 0; i--) {
      temp[i + add_space - 1] = temp[i - 1];
    }

    for (size_t i = 0; i < add_space; i++) {
      temp[i] = '\0';
    }
    temp[*curr_len + add_space + 1] = '\0';

    *result = temp;
    *curr_len += add_space;
  }
  return temp;
}

void handle_numeric_specifiers(
    spec *sp, char **result, size_t *curr_len,
    size_t *padding_size) {  // Don't work sprinf("%#3x",37);
  if (s21_strchr("oxX", sp->spec) && sp->hash_spec && !sp->is_zero) {
    int hz = 0;
    if (*padding_size > 0) {
      if (sp->spec != 'o' && *padding_size > 1)
        hz = 2;
      else
        hz = 1;
    }
    if (!(sp->spec == 'o' && (*result)[*padding_size] == '0')) {
      size_t realloc_size = (sp->spec == 'o') ? 1 : 2;
      if (*padding_size < realloc_size) {
        reallocate_and_shift(result, curr_len, realloc_size);
      }
      (*result)[*padding_size - hz] = '0';
      if (sp->spec != 'o') {
        (*result)[*padding_size - hz + 1] = sp->spec;
      }
    }
  }

  if (s21_strchr("difeEgG", sp->spec) && (sp->print_plus || sp->space) &&
      (*result)[*padding_size] != '-') {
    char sign = sp->print_plus ? '+' : ' ';
    if (*padding_size < 1) {
      reallocate_and_shift(result, curr_len, 1);
    }
    (*result)[*padding_size - 1] = sign;
  }
}

char *format_string(spec *sp, char *buff) {
  if (sp == S21_NULL || buff == S21_NULL) {
    return S21_NULL;
  }

  size_t curr_len = s21_strlen(buff);
  size_t padding_size = sp->width > curr_len ? sp->width - curr_len : 0;
  size_t result_size = curr_len + padding_size + 1;

  char *result = malloc(sizeof(char) * (result_size));
  if (result != S21_NULL) {
    s21_memset(result, 0, result_size);
    s21_strcpy(result, buff);

    char pad_char = (sp->field_zero && !sp->left_allig) ? '0' : ' ';
    apply_padding(&result, curr_len, padding_size, pad_char, sp->left_allig);

    handle_numeric_specifiers(sp, &result, &curr_len, &padding_size);
  }
  result[result_size - 1] = '\0';
  return result;
}

s21_size_t s21_intlen(long long n) {
  s21_size_t count = 1;
  if (n == 0) count = 0;
  while ((n = n / 10) != 0) {
    count++;
  }
  return count;
}

void reverse_string(char *str) {
  int j, k;
  int len = s21_strlen(str);
  for (j = 0, k = len - 1; j < k; j++, k--) {
    char temp = str[j];
    str[j] = str[k];
    str[k] = temp;
  }
}

char *handle_high_precision_fraction(double fract_part, int prec, int *zero) {
  *zero = 0;
  char *fract_str = calloc(prec + 1, sizeof(char));

  for (int i = 0; i < 14; i++) {
    fract_part *= 10;
  }
  fract_part = round(fract_part);

  long int tempi = (long int)fract_part;
  int k = 0;
  for (int i = 0; i < 14; i++) {
    if (!(k == 0 && tempi % 10 == 0)) {
      fract_str[k] = (int)(tempi % 10) + '0';
      k++;
    }
    tempi /= 10;

    if (i == 13) {
      while (k < prec) {
        (*zero)++;
        fract_str[k] = '\0';
        k++;
      }
    }
  }

  fract_str[prec] = '\0';
  reverse_string(fract_str);

  return fract_str;
}

char *handle_low_precision_fraction(double fract_part, int prec) {
  char *fract_str = malloc((prec + 1) * sizeof(char));

  for (int i = 0; i < prec; i++) {
    fract_part *= 10;
    fract_str[i] = (int)fract_part + '0';
    fract_part -= (int)fract_part;
  }
  fract_str[prec] = '\0';

  return fract_str;
}

char *my_itoa(long num, char *str) {
  int i = 0;
  int sign = 1;

  if (num < 0) {
    sign = -1;
    num = -num;
  }

  do {
    str[i++] = num % 10 + '0';
  } while ((num /= 10) > 0);

  if (sign == -1) {
    str[i++] = '-';
  }
  str[i] = '\0';

  reverse_string(str);
  return str;
}

char *my_uitoa(s21_uint num, char *str) {
  int i = 0;
  do {
    str[i++] = num % 10 + '0';
  } while ((num /= 10) > 0);
  str[i] = '\0';

  reverse_string(str);
  return str;
}

// Преобразование чисел с плавающей точкой
char *my_gftoa(long double num, int prec, int zero_y_n, int hash_spec) {
  if (prec < 0) return S21_NULL;

  int integer_part = (int)num;
  long double fract_part = fabsl(num - integer_part);

  s21_size_t int_len = s21_intlen(integer_part);
  s21_size_t total_len = int_len + prec + 2;

  char *str = malloc(total_len * sizeof(char));

  for (int i = 0; i < prec; i++) {
    fract_part *= 10;
  }
  fract_part = round(fract_part);

  for (int i = 0; i < prec; i++) fract_part /= 10;

  if (fract_part >= 1.0) {
    integer_part++;
    fract_part -= 1;
  }

  my_itoa(integer_part, str);
  int zero = 0;
  char *fract_str = NULL;
  if (prec < 14) {
    fract_str = handle_high_precision_fraction(fract_part, prec, &zero);
  } else {
    fract_str = handle_low_precision_fraction(fract_part, prec);
  }

  if ((prec != 0 && (s21_strlen(fract_str) != 0 || zero_y_n)) || hash_spec) {
    s21_strcat(str, ".");
  }
  s21_strcat(str, fract_str);

  if (zero_y_n || hash_spec) {
    int zero_count = prec - s21_strlen(fract_str);
    for (int i = 0; i < zero_count; i++) {
      s21_strcat(str, "0");
    }
  }

  if (fract_str) {free(fract_str); fract_str = S21_NULL;}
  return str;
}

int s21_uintlen(s21_uint n) {
  int count = 1;
  if (n == 0) count = 0;
  while ((n = n / 10) != 0) {
    count++;
  }
  return count;
}

long double count_e(long double num, int prec, int *e) {
  while (num >= 10.0) {
    num /= 10;
    (*e)++;
    if (num < 10) {
      for (int i = 0; i < prec; i++) num *= 10;
      num = round(num);
      for (int i = 0; i < prec; i++) num /= 10;
    }
  }

  while (num < 1.0 && num != 0.0) {
    num *= 10;
    (*e)++;
    if (num > 1) {
      for (int i = 0; i < prec; i++) num *= 10;
      num = round(num);
      for (int i = 0; i < prec; i++) num /= 10;
      if (num >= 10.0) {
        num /= 10;
        (*e)--;
      }
    }
  }
  return num;
}

char *etoa(long double num, int prec, int e_or_E, int e_or_g, int hash_spec) {
  int e = 0;
  int sign_e = 1;
  int sign = 1;
  if (num < 0) {
    sign = -1;
    num *= sign;
  }
  if (num < 1.0 && num != 0.0) sign_e = 0;

  num = count_e(num, prec, &e);

  num *= sign;
  char *temp = my_gftoa(num, prec, e_or_g, hash_spec);
  char *result = malloc((s21_strlen(temp) + 2) * sizeof(char));
  s21_strcat(result, temp);
  s21_strcat(result, e_or_E ? "E" : "e");
  s21_strcat(result, sign_e ? "+" : "-");
  char number[3] = {(e / 10 % 10) + '0', (e % 10) + '0'};
  s21_strcat(result, number);
  if (temp) {free(temp); temp = S21_NULL;}

  return (result);
}

int chackE(double num, int prec, int *e) {
  if (num == 0.0) return 0;
  *e = 0;
  int sign_e = 1;

  if (num < 0) num *= -1;
  if (num < 1.0) sign_e = 0;

  num = count_e(num, prec - 1, e);

  return (*e >= prec || (sign_e == 0 && *e > 4)) ? 1 : 0;
}

char *my_xtoa(unsigned long num, char *str, int x_or_X) {
  int i = 0;
  unsigned long temp = 0;

  do {
    temp = num % 16;
    if (temp > 9)
      str[i++] = x_or_X ? 'A' + (temp - 10) : 'a' + (temp - 10);
    else
      str[i++] = temp + '0';
  } while ((num /= 16) > 0);
  str[i] = '\0';
  int j, k;
  for (j = 0, k = s21_strlen(str) - 1; j < k; j++, k--) {
    char temp_char = str[j];
    str[j] = str[k];
    str[k] = temp_char;
  }
  return str;
}

char *my_otoa(unsigned long num, char *str) {
  int i = 0;

  do {
    str[i++] = num % 8 + '0';
  } while ((num /= 8) > 0);

  str[i] = '\0';
  int j, k;
  for (j = 0, k = s21_strlen(str) - 1; j < k; j++, k--) {
    char temp = str[j];
    str[j] = str[k];
    str[k] = temp;
  }

  return str;
}

char *vtoa(void *num, char *str) {
  char buf[15] = "0x000000000000";
  for (int *j = num, k = 13; j; j = (void *)(((s21_size_t)j) >> 4), --k) {
    s21_uint dig = ((s21_size_t)j) % 0x10;
    if (dig < 10)
      buf[k] = '0' + dig;
    else
      buf[k] = 'a' + (dig - 10);
  }
  s21_strcat(str, buf);
  return str;
}

int set_spec(spec *sp, char ch) {
  int result = 0;
  if (ch == '-') {
    sp->left_allig = 1;
  } else if (ch == '+') {
    sp->print_plus = 1;
  } else if (ch == ' ') {
    sp->space = 1;
  } else if (ch == '#') {
    sp->hash_spec = 1;
  } else if (ch == '0') {
    sp->field_zero = 1;
  } else {
    result = 1;
  }
  return result;
}

void set_default_spec(spec *sp) {
  sp->width = 0;
  sp->accuracy = -1;
  sp->left_allig = 0;
  sp->print_plus = 0;
  sp->space = 0;
  sp->hash_spec = 0;
  sp->is_zero = 0;
  sp->field_zero = 0;
  sp->spec = 0;
  sp->spec_size = 0;
}

int process_specifiers(spec *sp, const char *string, int i) {
  while (set_spec(sp, string[i]) == 0) {
    i++;
  }
  return i;
}

int process_width(spec *sp, const char *string, int i, va_list *perm) {
  if (string[i] == '*') {
    sp->width = va_arg(*perm, int);
    i++;  //!
  } else {
    while (string[i] >= '0' && string[i] <= '9') {
      sp->width = sp->width * 10 + (string[i] - '0');
      i++;
    }
  }

  return i;
}

int process_accuracy(spec *sp, const char *string, int i, va_list *perm) {
  if (string[i] == '.') {
    i++;
    if (string[i] == '*') {
      sp->accuracy = va_arg(*perm, int);
      i++;  //!
    } else {
      sp->accuracy = 0;
      while (string[i] >= '0' && string[i] <= '9') {
        sp->accuracy = sp->accuracy * 10 + (string[i] - '0');
        i++;
      }
    }
  }

  return i;
}

int process_spec_size(spec *sp, const char *string, int i) {
  if (string[i] == 'h' || string[i] == 'l' || string[i] == 'L') {
    sp->spec_size = (string[i] == 'L') ? 'a' : string[i];
    i++;

    if (string[i] == 'h' && string[i - 1] == 'h') {
      sp->spec_size = 'H';
      i++;
    }

    if (string[i] == 'l' && string[i - 1] == 'l') {
      sp->spec_size = 'L';
      i++;
    }
  }

  return i;
}

int process_spec(spec *sp, const char *string, int i) {
  if (s21_strchr("cdfsu%gGeExXop", string[i])) {
    sp->spec = string[i];
  }
  return i;
}

int parse(spec *sp, const char *string, va_list *perm) {
  set_default_spec(sp);
  int i = 1;  // пропуск %

  i = process_specifiers(sp, string, i);  // обработка спецификаторов
  i = process_width(sp, string, i, perm);  // обработка ширины
  i = process_accuracy(sp, string, i, perm);  // обработка точности
  i = process_spec_size(sp, string, i);  // обработка размера спецификатора
  i = process_spec(sp, string, i);  // обработка спецификатора

  return i;
}

char *convert_signed_integer(long temp, int *sign) {
  if (temp == LONG_MIN) {
    *sign = 1;
    char *temp3 = malloc(21);
    if (temp3 == NULL) {
      return NULL;
    }
    s21_strcpy(temp3, "9223372036854775808");
    return temp3;
  }
  if (temp < 0) {
    *sign = 1;
    temp = -temp;
  }
  int temp_len = s21_intlen(temp);
  char *temp3 = malloc(temp_len + 1);
  if (temp3 == S21_NULL) return S21_NULL;

  my_itoa(temp, temp3);
  return temp3;
}

void spec_d(char *buffer, va_list peremn, spec sp) {
  if (sp.accuracy < 0) sp.accuracy = 1;

  int sign = 0;
  char *temp3 = S21_NULL;

  if (sp.spec_size == 'h') {
    s21_sint temp = (short)va_arg(peremn, int);
    temp3 = convert_signed_integer(temp, &sign);
  } else if (sp.spec_size == 'l') {
    long temp = va_arg(peremn, long);
    temp3 = convert_signed_integer(temp, &sign);
  } else {
    int temp = va_arg(peremn, int);
    temp3 = convert_signed_integer(temp, &sign);
  }

  if (temp3 != S21_NULL) {
    int temp_len = s21_strlen(temp3);

    if (sign) s21_strcat(buffer, "-");

    // ведущие нули
    for (int i = sp.accuracy - temp_len; i > 0; i--) {
      s21_strcat(buffer, "0");
    }

    s21_strcat(buffer, temp3);
    if (temp3) {free(temp3); temp3 = S21_NULL;}
  }
}

void spec_f(char *buffer, va_list *peremn, spec sp) {
  if (sp.accuracy < 0) sp.accuracy = 6;

  char *temp2 = S21_NULL;

  if (sp.spec_size == 'a') {
    long double temp = va_arg(*peremn, long double);
    temp2 = my_gftoa(temp, sp.accuracy, 1, sp.hash_spec);
  } else {
    double temp = va_arg(*peremn, double);
    temp2 = my_gftoa(temp, sp.accuracy, 1, sp.hash_spec);
  }

  if (temp2 != S21_NULL) {
    s21_strcat(buffer, temp2);
    if (temp2) {free(temp2); temp2 = S21_NULL;}
  }
}

void spec_u(char *buffer, va_list *peremn, spec sp) {
  if (sp.accuracy < 0) sp.accuracy = 1;

  s21_uint temp;
  if (sp.spec_size == 'h') {
    temp = (unsigned short int)va_arg(*peremn, unsigned int);
  } else if (sp.spec_size == 'l') {
    temp = va_arg(*peremn, unsigned long int);
  } else {
    temp = va_arg(*peremn, unsigned int);
  }

  int temp_len = s21_uintlen(temp);
  char temp2[temp_len];

  for (int i = sp.accuracy - temp_len; i > 0; i--) {
    s21_strcat(buffer, "0");
  }

  my_uitoa(temp, temp2);
  s21_strcat(buffer, temp2);
}

void spec_g_G(char *buffer, va_list *peremn, spec sp) {
  if (sp.accuracy < 0) sp.accuracy = 6;

  long double temp;
  if (sp.spec_size == 'a') {
    temp = va_arg(*peremn, long double);
  } else {
    temp = va_arg(*peremn, double);
  }

  char *temp2;
  int e = 0;
  if (chackE(temp, sp.accuracy, &e)) {
    if (sp.accuracy == 0) sp.accuracy = 1;
    temp2 =
        etoa(temp, sp.accuracy - 1, (sp.spec == 'G') ? 1 : 0, 0, sp.hash_spec);
  } else {
    int int_temp_len;
    if (sp.spec_size == 'L') {
      int_temp_len = s21_intlen((long long)temp);
    } else {
      int_temp_len = s21_intlen((int)temp);
    }
    if (int_temp_len == 0) int_temp_len = -1 * (e - 1);
    if (temp == 0.0) int_temp_len = 1;
    temp2 = my_gftoa(temp, sp.accuracy - int_temp_len, 0, sp.hash_spec);
  }
  s21_strcat(buffer, temp2);
  if (temp2) {free(temp2); temp2 = S21_NULL;}
}

void spec_e_E(char *buffer, va_list *peremn, spec sp) {
  if (sp.accuracy < 0) sp.accuracy = 6;

  s21_ldouble temp = 1;
  if (sp.spec_size == 'a') {
    temp = va_arg(*peremn, s21_ldouble);
  } else {
    temp = va_arg(*peremn, double);
  }

  char *temp2 =
      etoa(temp, sp.accuracy, (sp.spec == 'E') ? 1 : 0, 1, sp.hash_spec);
  if (temp2) {free(temp2); temp2 = S21_NULL;}
  s21_strcat(buffer, temp2);
}

void spec_x_X(char *buffer, va_list *peremn, spec *sp, int x_or_X) {
  if ((*sp).accuracy < 0) (*sp).accuracy = 1;

  s21_uint temp;
  if ((*sp).spec_size == 'h') {
    temp = (unsigned short)va_arg(*peremn, int);
  } else if ((*sp).spec_size == 'l') {
    temp = va_arg(*peremn, unsigned long);
  } else {
    temp = va_arg(*peremn, unsigned int);
  }

  int len_temp = s21_intlen(temp);
  char *temp2 = (char *)malloc(len_temp + 1);
  my_xtoa(temp, temp2, x_or_X);

  if (temp == 0) (*sp).is_zero = 1;

  for (int i = len_temp; i < (*sp).accuracy && temp != 0; i++) {
    s21_strcat(buffer, "0");
  }

  s21_strcat(buffer, temp2);
  if (temp2) {free(temp2); temp2 = S21_NULL;}
}

void spec_o(char *buffer, va_list *peremn, spec *sp) {
  if ((*sp).accuracy < 0) (*sp).accuracy = 1;

  unsigned long temp;
  if ((*sp).spec_size == 'h') {
    temp = (unsigned short)va_arg(*peremn, unsigned int);
  } else if ((*sp).spec_size == 'l') {
    temp = va_arg(*peremn, unsigned long);
  } else {
    temp = va_arg(*peremn, unsigned int);
  }

  int len_temp = s21_intlen(temp);
  char *temp2 = (char *)malloc(len_temp * 2 + 1);
  my_otoa(temp, temp2);

  if (temp == 0) (*sp).is_zero = 1;

  for (int i = s21_strlen(temp2); i < (*sp).accuracy; i++) {
    s21_strcat(buffer, "0");
  }

  s21_strcat(buffer, temp2);
  if (temp2) {free(temp2); temp2 = S21_NULL;}
}

void spec_p(char *buffer, va_list *peremn) {
  void *temp = va_arg(*peremn, void *);
  char temp2[15];
  vtoa(temp, temp2);
  s21_strcat(buffer, temp2);
}

void check_spec(spec *sp, va_list *peremn, char *buffer) {
  if (sp->spec == 'c') {
    char temp = va_arg(*peremn, int);
    buffer[0] = temp;
  } else if (sp->spec == 'd') {
    spec_d(buffer, *peremn, *sp);
  } else if (sp->spec == 'f') {
    spec_f(buffer, peremn, *sp);
  } else if (sp->spec == 's') {
    char *temp = va_arg(*peremn, char *);
    if ((*sp).accuracy >= 0) {
      s21_strncat(buffer, temp, (*sp).accuracy);
    } else {
      s21_strcat(buffer, temp);
    }
  } else if (sp->spec == 'u') {
    spec_u(buffer, peremn, *sp);
  } else if (sp->spec == '%') {
    buffer[0] = '%';
  } else if (sp->spec == 'g') {
    spec_g_G(buffer, peremn, *sp);
  } else if (sp->spec == 'G') {
    spec_g_G(buffer, peremn, *sp);
  } else if (sp->spec == 'e') {
    spec_e_E(buffer, peremn, *sp);
  } else if (sp->spec == 'E') {
    spec_e_E(buffer, peremn, *sp);
  } else if (sp->spec == 'x') {
    spec_x_X(buffer, peremn, sp, 0);
  } else if (sp->spec == 'X') {
    spec_x_X(buffer, peremn, sp, 1);
  } else if (sp->spec == 'o') {
    spec_o(buffer, peremn, sp);
  } else if (sp->spec == 'p') {
    spec_p(buffer, peremn);
  }
}

int s21_sprintf(char *str, const char *format, ...) {
  s21_size_t length = s21_strlen(format);
  va_list peremn;
  va_start(peremn, format);
  int j = 0;
  spec sp;
  int len = (int)s21_strlen(str);
  for (char *p = str; p - str < len; p++) *p = '\0';
  for (s21_size_t i = 0; i < length && format[i]; i++) {
    if (format[i] != '%') {
      str[j++] = format[i];
    } else {
      str[j] = '\0';
      i += parse(&sp, &format[i], &peremn);
      char buffer[2048] = {0};
      check_spec(&sp, &peremn, buffer);
      char *temp = format_string(&sp, buffer);
      s21_strcat(str, temp);
      if (temp) {free(temp); temp = S21_NULL;}
      j = s21_strlen(str);
    }
  }
  va_end(peremn);

  return j;
}
