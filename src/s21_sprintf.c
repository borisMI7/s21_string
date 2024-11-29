#include <math.h>
#include <stdarg.h>
#include <stdio.h>
// #include <string.h>

#include "s21_string.h"

typedef long double s21_ldouble;
typedef unsigned int s21_uint;
typedef long int s21_lint;
typedef short int s21_sint;

typedef struct spec {
  size_t width;   // ширина вывода
  int left_allig; // выравнивание слева или справа
  int accuracy;   // количество знаков после запятой
  int print_plus; // печатать ли плюсы
  int space; // печатать ли пробел если знак не выведен
  int hash_spec;  // флаг #
  int is_zero;    // Является ли число не нулём
  int field_zero; // нужно ли  заполнять слева нулями
  char spec;      // какой спецификатор
  char spec_size; // длина спецификатора 
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
                           size_t add_space) {
  char *temp =
      realloc(*result, sizeof(char) * (*curr_len + add_space + 1));
  if (!temp) {
    free(*result);
  } else {
    for (size_t i = *curr_len; i > 0; i--) {
      temp[i + add_space - 1] = temp[i - 1];
    }

    for (size_t i = 0; i < add_space; i++) {
      temp[i] = '\0';
    }
    temp[*curr_len + add_space] = '\0';

    *result = temp;
    *curr_len += add_space;
  }
  return temp;
}

void handle_numeric_specifiers(spec *sp, char **result, size_t *curr_len,
                                      size_t *padding_size) {
  if (s21_strchr("oxX", sp->spec) && sp->hash_spec && !sp->is_zero) {
    size_t realloc_size = (sp->spec == 'o') ? 1 : 2;
    if (*padding_size < realloc_size) {
      reallocate_and_shift(result, curr_len, realloc_size);
    } 
    (*result)[0] = '0';
    if (sp->spec != 'o') {
      (*result)[1] = sp->spec;
    }
  }

  if (s21_strchr("dif", sp->spec) && (sp->print_plus || sp->space)) {
    char sign = sp->print_plus ? '+' : ' ';
    if (*padding_size < 1) {
      reallocate_and_shift(result, curr_len, 1);
    }
    (*result)[0] = sign;
  }
}

char *format_string(spec *sp, char *buff) {
  if (sp == NULL || buff == NULL) {
    return NULL;
  }

  size_t curr_len = s21_strlen(buff);
  size_t padding_size = sp->width > curr_len ? sp->width - curr_len : 0;
  size_t result_size = curr_len + padding_size + 1;

  char *result = malloc(sizeof(char) * (result_size));
  if (result != NULL) {
    s21_memset(result, 0, result_size);
    s21_strcpy(result, buff);

    char pad_char = (sp->field_zero && !sp->left_allig) ? '0' : ' ';
    apply_padding(&result, curr_len, padding_size, pad_char, sp->left_allig);

    handle_numeric_specifiers(sp, &result, &curr_len, &padding_size);
  }

  return result;
}


// длина для выделения памяти
s21_size_t count_digits(long long n) {
  s21_size_t count = 0;
  if (n == 0) return 1;
  if (n < 0) n = -n;
  while (n > 0) {
    n /= 10;
    count++;
  }
  return count;
}

int s21_intlen(long n) {
  int count = 1;
  if (n == 0) count = 0;
  while ((n = n / 10) != 0) {
    count++;
  }
  return count;
}

// Преобразование целых чисел в строки
// char *my_itoa(long num, char *str) {
//   int i = 0;
//   int sign = 1;

//   if (num < 0) {
//     sign = -1;
//     num = -num;
//   }

//   do {
//     str[i++] = num % 10 + '0';
//   } while ((num /= 10) > 0);

//   if (sign == -1) {
//     str[i++] = '-';
//   }
//   str[i] = '\0';

//   int j, k;

//   for (j = 0, k = s21_strlen(str) - 1; j < k; j++, k--) {
//     char temp;
//     temp = str[j];
//     str[j] = str[k];
//     str[k] = temp;
//   }
//   return str;
// }

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
  int j, k;
  for (j = 0, k = s21_strlen(str) - 1; j < k; j++, k--) {
    char temp = str[j];
    str[j] = str[k];
    str[k] = temp;
  }
  return str;
}

char *my_uitoa(s21_uint num, char *str) {
  int i = 0;

  do {
    str[i++] = num % 10 + '0';
  } while ((num /= 10) > 0);
  str[i] = '\0';

  int j, k;

  for (j = 0, k = s21_strlen(str) - 1; j < k; j++, k--) {
    char temp;
    temp = str[j];
    str[j] = str[k];
    str[k] = temp;
  }
  return str;
}

// Преобразование чисел с палвающей точкой
char *my_gftoa(double num, int prec, int zero_y_n, int hash_spec) {
  if (prec < 0) return S21_NULL;
  int integer_part = (int)num;
  double fract_part = fabs(num - integer_part);
  s21_size_t int_len = count_digits(integer_part);
  s21_size_t total_len = int_len + prec + 2;
  char *str = (char *)malloc(total_len);
  for (int i = 0; i < prec; i++) fract_part *= 10;
  fract_part = round(fract_part);
  for (int i = 0; i < prec; i++) fract_part /= 10;
  if (fract_part >= 1.0) {
    integer_part++;
    fract_part -= 1;
  }
  my_itoa(integer_part, str);
  if (prec < 14) {
    int zero = 0;
    for (int i = 0; i < 14; i++) fract_part *= 10;
    fract_part = round(fract_part);
    char fract_str[prec + 1];
    long int tempi = (long int)fract_part;
    for (int i = 0, k = 0; i < 14; i++) {
      if (!(k == 0 && tempi % 10 == 0)) {
        fract_str[k] = (int)(tempi % 10) + '0';
        k++;
      }
      tempi /= 10;
      if (i == 14 - 1) {
        for (; k < prec; k++) {
          zero++;
          fract_str[k] = '\0';
        }
      }
    }
    fract_str[prec] = '\0';
    for (int j = 0, k = s21_strlen(fract_str) - 1; j < k; j++, k--) {
      char temp;
      temp = fract_str[j];
      fract_str[j] = fract_str[k];
      fract_str[k] = temp;
    }
    if ((prec != 0 && (s21_strlen(fract_str) != 0 || zero_y_n)) || hash_spec)
      s21_strcat(str, ".");
    s21_strcat(str, fract_str);
    if (zero_y_n) {
      for (; zero > 0; zero--) {
        s21_strcat(str, "0");
      }
    }
  } else {
    prec -= s21_intlen(integer_part);
    char fract_str[prec + 1];
    for (int i = 0; i < prec; i++) {
      fract_part *= 10;
      fract_str[i] = (int)fract_part + '0';
      fract_part -= (int)fract_part;
    }
    fract_str[prec] = '\0';
    if ((prec != 0 && s21_strlen(fract_str) != 0) || hash_spec)
      s21_strcat(str, ".");
    s21_strcat(str, fract_str);
  }
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

char *etoa(double num, int prec, int e_or_E, int e_or_g, int hash_spec) {
  int e = 0;
  int sign_e = 1;
  int sign = 1;

  if (num < 0) {
    sign = -1;
    num *= sign;
  }
  if (num < 1.0 && num != 0.0) sign_e = 0;

  while (num >= 10.0) {
    num /= 10;
    e++;
  }

  while (num < 1.0 && num != 0.0) {
    num *= 10;
    e++;
  }
  num *= sign;
  char *temp = my_gftoa(num, prec, e_or_g, hash_spec);
  char *result = malloc((s21_strlen(temp) + 2) * sizeof(char));
  s21_strcat(result, temp);
  s21_strcat(result, e_or_E ? "E" : "e");
  s21_strcat(result, sign_e ? "+" : "-");
  char number[3] = {(e / 10 % 10) + '0', (e % 10) + '0'};
  s21_strcat(result, number);
  free(temp);
  return (result);
}

int chackE(double num, int prec) {
  if (num == 0.0) return 0;
  int e = 0;
  int sign_e = 1;

  if (num < 0) num *= -1;
  if (num < 1.0) sign_e = 0;

  while (num >= 10.0) {
    num /= 10;
    e++;
  }

  while (num < 1.0) {
    num *= 10;
    e++;
  }

  return (e >= prec || (sign_e == 0 && e > 4)) ? 1 : 0;
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

// char *my_otoa(int num, char *str) {
//   int i = 0;

//   do {
//     str[i++] = num % 8 + '0';
//   } while ((num /= 8) > 0);

//   str[i] = '\0';

//   int j, k;

//   for (j = 0, k = s21_strlen(str) - 1; j < k; j++, k--) {
//     char temp;
//     temp = str[j];
//     str[j] = str[k];
//     str[k] = temp;
//   }
//   return str;
// }

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
    sp->is_zero = 1;
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

int parse(spec *sp, char const *string, va_list *perm) {
  set_default_spec(sp);
  int i;
  for (i = 1; set_spec(sp, string[i]) == 0; i++) {
  }
  if (string[i] == '*') {
    sp->width = va_arg(*perm, int);
    i++;  //!
  } else {
    while (string[i] >= '0' && string[i] <= '9') {
      sp->width = sp->width * 10 + (string[i] - '0');
      i++;
    }
  }
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
  if (string[i] == 'h' || string[i] == 'l' ||
      string[i] == 'L') {  // l->l ll->a; h ->h; hh -> H; L->a;
    sp->spec_size = string[i] == 'L' ? 'a' : string[i];
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
  if (s21_strchr("cdfsu%gGeExXop", string[i])) {
    sp->spec = string[i];
  }
  return i;
}


void spec_d(char *buffer, va_list peremn, spec sp) {
  if (sp.accuracy < 0) sp.accuracy = 1;
  int sign = 0;
  int temp_len = 0;
  char *temp3;
  if (sp.spec_size == 'h') {
    s21_sint temp = (short)va_arg(peremn, int);
    if (temp < 0) {
      sign = 1;
      temp = -temp;
    }
    temp_len = s21_intlen(temp);
    temp3 = (char *)malloc(temp_len + 1);
    my_itoa(temp, temp3);
  } else if (sp.spec_size == 'l') {
    long temp = va_arg(peremn, long);
    if (temp < 0) {
      sign = 1;
      temp = -temp;
    }
    temp_len = s21_intlen(temp);
    temp3 = (char *)malloc(temp_len + 1);
    my_itoa(temp, temp3);

  } else {
    int temp = va_arg(peremn, int);
    if (temp < 0) {
      sign = 1;
      temp *= -1;
    }
    temp_len = s21_intlen(temp);
    char *temp2 = malloc(temp_len * sizeof(char));
    my_itoa(temp, temp2);
    temp3 = temp2;
  }
  if (sign) s21_strcat(buffer, "-");
  for (int i = sp.accuracy - temp_len; i > 0; i--) {
    s21_strcat(buffer, "0");
  }
  s21_strcat(buffer, temp3);
  free(temp3);
}

void spec_f(char *buffer, va_list *peremn, spec sp) {
  if (sp.accuracy < 0) sp.accuracy = 6;
  if (sp.spec_size == 'L') {
    long double temp = va_arg(*peremn, long double);
    char *temp2 = my_gftoa(temp, sp.accuracy, 1, sp.hash_spec);
    s21_strcat(buffer, temp2);
    free(temp2);
  } else {
    double temp = va_arg(*peremn, double);
    char *temp2 = my_gftoa(temp, sp.accuracy, 1, sp.hash_spec);
    s21_strcat(buffer, temp2);
    free(temp2);
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
  s21_strcat(buffer, my_uitoa(temp, temp2));
}

// void spec_g(char *buffer, va_list *peremn, spec sp) {
//   if (sp.accuracy < 0) sp.accuracy = 6;
//   long double temp;
//   if (sp.spec_size == 'L') {
//     temp = va_arg(*peremn, long double);
//   } else {
//     temp = va_arg(*peremn, double);
//   }
//   char *temp2;
//   if (chackE(temp, sp.accuracy)) {
//     if (sp.accuracy == 0) sp.accuracy = 1;
//     temp2 = etoa(temp, sp.accuracy - 1, 0, 0, sp.hash_spec);
//   } else {
//     int int_temp_len;
//     if (sp.spec_size == 'L') {
//       int_temp_len = s21_intlen((long long)temp);
//     } else {
//       int_temp_len = s21_intlen((int)temp);
//     }
//     temp2 = my_gftoa(temp, sp.accuracy - int_temp_len, 0, sp.hash_spec);
//   }
//   s21_strcat(buffer, temp2);
// }

// void spec_G(char *buffer, va_list *peremn, spec sp) {
//   if (sp.accuracy < 0) sp.accuracy = 6;
//   long double temp;
//   if (sp.spec_size == 'L') {
//     temp = va_arg(*peremn, long double);
//   } else {
//     temp = va_arg(*peremn, double);
//   }
//   char *temp2;
//   if (chackE(temp, sp.accuracy)) {
//     if (sp.accuracy == 0) sp.accuracy = 1;
//     temp2 = etoa(temp, sp.accuracy - 1, 1, 0, sp.hash_spec);
//   } else {
//     int int_temp_len;
//     if (sp.spec_size == 'L') {
//       int_temp_len = s21_intlen((long long)temp);
//     } else {
//       int_temp_len = s21_intlen((int)temp);
//     }
//     temp2 = my_gftoa(temp, sp.accuracy - int_temp_len, 0, sp.hash_spec);
//   }
//   s21_strcat(buffer, temp2);
// }

void spec_g_G(char *buffer, va_list *peremn, spec sp) {
  if (sp.accuracy < 0) sp.accuracy = 6;
  long double temp;
  if (sp.spec_size == 'L') {
    temp = va_arg(*peremn, long double);
  } else {
    temp = va_arg(*peremn, double);
  }
  char *temp2;
  if (chackE(temp, sp.accuracy)) {
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
    temp2 = my_gftoa(temp, sp.accuracy - int_temp_len, 0, sp.hash_spec);
  }
  s21_strcat(buffer, temp2);
}

// void spec_e(char *buffer, va_list *peremn, spec sp) {
//   if (sp.accuracy < 0) sp.accuracy = 6;
//   long double temp;
//   if (sp.spec_size == 'L') {
//     temp = va_arg(*peremn, long double);
//   } else {
//     temp = va_arg(*peremn, double);
//   }
//   char *temp2 = etoa(temp, sp.accuracy, 0, 1, sp.hash_spec);
//   s21_strcat(buffer, temp2);
// }

// void spec_E(char *buffer, va_list *peremn, spec sp) {
//   if (sp.accuracy < 0) sp.accuracy = 6;
//   long double temp;
//   if (sp.spec_size == 'L') {
//     temp = va_arg(*peremn, long double);
//   } else {
//     temp = va_arg(*peremn, double);
//   }
//   char *temp2 = etoa(temp, sp.accuracy, 1, 1, sp.hash_spec);
//   s21_strcat(buffer, temp2);
// }

void spec_e_E(char *buffer, va_list *peremn, spec sp) {
  if (sp.accuracy < 0) sp.accuracy = 6;
  long double temp;
  if (sp.spec_size == 'L') {
    temp = va_arg(*peremn, long double);
  } else {
    temp = va_arg(*peremn, double);
  }
  char *temp2 =
      etoa(temp, sp.accuracy, (sp.spec == 'E') ? 1 : 0, 1, sp.hash_spec);
  s21_strcat(buffer, temp2);
}

void spec_x_X(char *buffer, va_list *peremn, spec sp, int x_or_X) {
  if (sp.accuracy < 0) sp.accuracy = 1;
  s21_uint temp;
  if (sp.spec_size == 'h') {
    temp = (unsigned short)va_arg(*peremn, int);
  } else if (sp.spec_size == 'l') {
    temp = va_arg(*peremn, unsigned long);
  } else {
    temp = va_arg(*peremn, unsigned int);
  }
  int len_temp = s21_intlen(temp);
  char *temp2 = (char *)malloc(len_temp + 1);
  my_xtoa(temp, temp2, x_or_X);
  if (sp.hash_spec && temp != 0) {
    s21_strcat(buffer, x_or_X ? "0X" : "0x");
  }
  for (int i = len_temp; i < sp.accuracy; i++) {
    s21_strcat(buffer, "0");
  }
  s21_strcat(buffer, temp2);
  free(temp2);
}

void spec_o(char *buffer, va_list *peremn, spec sp) {
  if (sp.accuracy < 0) sp.accuracy = 1;
  unsigned long temp;
  if (sp.spec_size == 'h') {
    temp = (unsigned short)va_arg(*peremn, unsigned int);
  } else if (sp.spec_size == 'l') {
    temp = va_arg(*peremn, unsigned long);
  } else {
    temp = va_arg(*peremn, unsigned int);
  }
  int len_temp = s21_intlen(temp);
  char *temp2 = (char *)malloc(len_temp * 2 + 1);
  my_otoa(temp, temp2);
  if (temp != 0 && (int)s21_strlen(temp2) >= sp.accuracy && sp.hash_spec)
    s21_strcat(buffer, "0");

  for (int i = s21_strlen(temp2); i < sp.accuracy; i++) {
    s21_strcat(buffer, "0");
  }
  s21_strcat(buffer, temp2);
  free(temp2);
}

void spec_p(char *buffer, va_list *peremn) {
  void *temp = va_arg(*peremn, void *);
  char temp2[15];
  vtoa(temp, temp2);
  s21_strcat(buffer, temp2);
}

void check_spec(spec sp, va_list *peremn, char *buffer) {
  if (sp.spec == 'c') {
    char temp = va_arg(*peremn, int);
    buffer[0] = temp;
  } else if (sp.spec == 'd') {
    spec_d(buffer, *peremn, sp);
  } else if (sp.spec == 'f') {
    spec_f(buffer, peremn, sp);
  } else if (sp.spec == 's') {
    char *temp = va_arg(*peremn, char *);
    if (sp.accuracy >= 0) {
      s21_strncat(buffer, temp, sp.accuracy);
    } else {
      s21_strcat(buffer, temp);
    }
  } else if (sp.spec == 'u') {
    spec_u(buffer, peremn, sp);
  } else if (sp.spec == '%') {
    buffer[0] = '%';
  } else if (sp.spec == 'g') {
    spec_g_G(buffer, peremn, sp);
  } else if (sp.spec == 'G') {
    spec_g_G(buffer, peremn, sp);
  } else if (sp.spec == 'e') {
    spec_e_E(buffer, peremn, sp);
  } else if (sp.spec == 'E') {
    spec_e_E(buffer, peremn, sp);
  } else if (sp.spec == 'x') {
    spec_x_X(buffer, peremn, sp, 0);
  } else if (sp.spec == 'X') {
    spec_x_X(buffer, peremn, sp, 1);
  } else if (sp.spec == 'o') {
    spec_o(buffer, peremn, sp);
  } else if (sp.spec == 'p') {
    spec_p(buffer, peremn);
  }
}

int s21_sprintf(char *str, const char *format, ...) {
  s21_size_t length = s21_strlen(format);

  va_list peremn;
  va_start(peremn, format);
  int j = 0;
  spec sp;
  for (s21_size_t i = 0; i < length; i++) {
    if (format[i] != '%') {
      str[j] = format[i];
      j++;
    } else {
      i += parse(&sp, &format[i], &peremn);
      char buffer[2048] = {0};
      check_spec(sp, &peremn, buffer);
      char *temp = format_string(&sp, buffer);
      s21_strcat(str, temp);
      free(temp);

      j = s21_strlen(str);
    }
  }
  va_end(peremn);
  return 0;
}

int main(void) {
  // char str[100];
  // int p = 986;
  // s21_sprintf(str, "A%dB %c %% - %s// %n", -10, 'Q', "Hello world", &p);
  // char str[100];
  /*printf("%s\n",  my_ftoa(100.05697, 7));
  printf("%s\n",  my_gftoa(100.05699, 13));
  printf("%.13g", 100.05699);
  printf("\n%.7f", 100.05697);*/
  // char str[100];
  // s21_sprintf(str, " %#-10.0g %#.0e", 0.0, 100.05699);
  // printf("%s\n", str);
  // printf(" %lc %#.0e", 64, 507.05699);

  char buf1[100], buf2[100];

  // short test_h = 123;

  // sprintf(buf1, "%hd", test_h);
  // s21_sprintf(buf2, "%hd", test_h);
  // if (strcmp(buf1, buf2) != 0) {
  //   printf("Test 1 (l): Failed! sprintf: %s, s21_sprintf: %s\n", buf1, buf2);
  // } else {
  //   printf("Test 1 (l): Passed! Both outputs are the same.\n");
  // }

  // long test_value = 32767;

  // sprintf(buf1, "%ld", test_value);
  // s21_sprintf(buf2, "%ld", test_value);
  // if (strcmp(buf1, buf2) != 0) {
  //   printf("Test 1 (l): Failed! sprintf: %s, s21_sprintf: %s\n", buf1, buf2);
  // } else {
  //   printf("Test 1 (l): Passed! Both outputs are the same.\n");
  // }

  // long negative_value = -32767L;

  // sprintf(buf1, "%ld", negative_value);

  // s21_sprintf(buf2, "%ld", negative_value);

  // if (strcmp(buf1, buf2) != 0) {
  //   printf("Test 2 (l, negative): Failed! sprintf: %s, s21_sprintf: %s\n",
  //   buf1,
  //          buf2);
  // } else {
  //   printf("Test 2 (l, negative): Passed! Both outputs are the same.\n");
  // }

  // sprintf(buf1, "%.3Lf", -123.456789L);
  // s21_sprintf(buf2, "%.3Lf", -123.456789L);

  // if (strcmp(buf1, buf2) != 0)
  //   printf("Test 1 (L): Failed! sprintf: %s, s21_sprintf: %s\n", buf1, buf2);
  // else
  //   printf("Test 1 (L): Passed!\n");

  // sprintf(buf1, "%lo", (long unsigned)30071);
  // s21_sprintf(buf2, "%lo", (long unsigned)30071);
  // if (strcmp(buf1, buf2) != 0)
  //   printf("Test 1 (L): Failed! sprintf: %s, s21_sprintf: %s\n", buf1, buf2);
  // else
  //   printf("Test 1 (L): Passed!\n");

  // sprintf(buf1, "%lo", (long unsigned)0);
  // s21_sprintf(buf2, "%lo", (long unsigned)0);
  // if (strcmp(buf1, buf2) != 0)
  //   printf("Test 2 (L): Failed! sprintf: %s, s21_sprintf: %s\n", buf1, buf2);
  // else
  //   printf("Test 2 (L): Passed!\n");
  // sprintf(buf1, "%ho", (unsigned short)42);
  // s21_sprintf(buf2, "%ho", (unsigned short)42);
  // if (strcmp(buf1, buf2) != 0)
  //   printf("Test 1 (ho, basic value): Failed! sprintf: %s, s21_sprintf:
  //   %s\n",
  //          buf1, buf2);
  // else
  //   printf("Test 1 (ho, basic value): Passed!\n");

  // sprintf(buf1, "%ho", (unsigned short)0);  // Ожидаемый вывод: "0"
  // s21_sprintf(buf2, "%ho", (unsigned short)0);
  // if (strcmp(buf1, buf2) != 0)
  //   printf("Test 2 (ho, zero value): Failed! sprintf: %s, s21_sprintf: %s\n",
  //          buf1, buf2);
  // else
  //   printf("Test 2 (ho, zero value): Passed!\n");

  // unsigned short int val_hu = 12345;
  // sprintf(buf1, "%hu", val_hu);  // Используем стандартный sprintf
  // s21_sprintf(buf2, "%hu", val_hu);  // Наш кастомный s21_sprintf

  // if (strcmp(buf1, buf2) != 0)
  //   printf("Test 1 (hu, simple value): Failed! sprintf: %s, s21_sprintf:
  //   %s\n",
  //          buf1, buf2);
  // else
  //   printf("Test 1 (hu, simple value): Passed!\n");

  // unsigned short int val_hu = 1;
  // sprintf(buf1, "%hu", val_hu);  // Используем стандартный sprintf
  // s21_sprintf(buf2, "%hu", val_hu);  // Наш кастомный s21_sprintf

  // if (strcmp(buf1, buf2) != 0)
  //   printf("Test 3 (hu, minimal value): Failed! sprintf: %s, s21_sprintf:
  //   %s\n",
  //          buf1, buf2);
  // else
  //   printf("Test 3 (hu, minimal value): Passed!\n");

  // unsigned long int val_lu = 1234567890;
  // sprintf(buf1, "%lu", val_lu);  // Используем стандартный sprintf
  // s21_sprintf(buf2, "%lu", val_lu);  // Наш кастомный s21_sprintf

  // if (strcmp(buf1, buf2) != 0)
  //   printf("Test 1 (lu, simple value): Failed! sprintf: %s, s21_sprintf:
  //   %s\n",
  //          buf1, buf2);
  // else
  //   printf("Test 1 (lu, simple value): Passed!\n");
  // unsigned long int val_lu = 42;
  // sprintf(buf1, "%06lu", val_lu);  // Используем стандартный sprintf с
  // шириной 6 s21_sprintf(buf2, "%06lu", val_lu);  // Наш кастомный s21_sprintf
  // с шириной 6

  // if (strcmp(buf1, buf2) != 0)
  //   printf("Test 5 (lu, width padding): Failed! sprintf: %s, s21_sprintf:
  //   %s\n",
  //          buf1, buf2);
  // else
  //   printf("Test 5 (lu, width padding): Passed!\n");

  // long unsigned int val = 255;
  // sprintf(buf1, "%lx", val);
  // s21_sprintf(buf2, "%lx", val);
  // if (strcmp(buf1, buf2) != 0)
  //   printf("Test 4 ()): Failed! sprintf: %s, s21_sprintf: %s\n", buf1, buf2);
  // else
  //   printf("Test 4 (): Passed!\n");

  // double val = 123.456789L;
  // sprintf(buf1, "%.2E", val);
  // s21_sprintf(buf2, "%.2E", val);
  // if (strcmp(buf1, buf2) != 0) {
  //   printf("Test 1 (%%Lf): Failed! sprintf: %s, s21_sprintf: %s\n", buf1,
  //   buf2);
  // } else {
  //   printf("Test 1 (%%Lf): Passed!\n");
  // }
}
