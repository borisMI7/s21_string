
#include "s21_string.h"

/*typedef long double s21_ldouble;
typedef unsigned int s21_uint;
typedef long int s21_lint;
typedef short int s21_sint;*/

typedef struct sspec {
  size_t width;    // ширина вывода
  int less;        //  пропестить значение
  char spec;       // какой спецификатор
  char spec_size;  // длина спецификатора 
} sspec;

void sset_default_spec(sspec *sp) {
  sp->width = 0;
  sp->less = 0;
  sp->spec = 0;
  sp->spec_size = 0;
}

int sprocess_width(sspec *sp, const char *string, int i) {
  if (string[i] == '*') {
    sp->less = 1;
    i++;  //!
  }
  while (string[i] >= '0' && string[i] <= '9') {
    sp->width = sp->width * 10 + (string[i] - '0');
    i++;
  }
  return i;
}

int sprocess_spec_size(sspec *sp, const char *string, int i) {
  if (string[i] == 'h' || string[i] == 'l' || string[i] == 'L') {
    sp->spec_size = (string[i] == 'L') ? 'L' : string[i];
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

int sprocess_spec(sspec *sp, const char *string, int i) {
  if (s21_strchr("cdfsu%gGeExXop", string[i])) {
    sp->spec = string[i];
  }
  return i;
}

int sparse(sspec *sp, const char *string) {
  sset_default_spec(sp);
  int i = 1;  // пропуск %

  i = sprocess_width(sp, string, i);  // обработка ширины
  i = sprocess_spec_size(sp, string, i);  // обработка размера спецификатора
  i = sprocess_spec(sp, string, i);  // обработка спецификатора

  return i;
}

int my_atoi(const char *str, int *j, int width, int *error) {
  int result = 0;
  int i = *j;
  int sign = 1;
  int in = 0;

  if (str != S21_NULL) {
    while (str[i] == ' ') {
      i++;
      (*j)++;
    }

    if (str[i] == '-') {
      sign = -1;
      i++;
    } else if (str[i] == '+') {
      i++;
    }

    while (str[i] >= '0' && str[i] <= '9' && (i - *j < width || width == 0)) {
      result = result * 10 + (str[i] - '0');
      i++;
      in = 1;
    }
    *j = i;
  }

  if (in == 0) {
    *error = 1;
  }

  return result * sign;
}

double my_atof(char const *str, int *j, int width, int *error) {
  double result = 0.0;
  int sign = 1;
  int i = *j;
  int in = 0;
  if (str != S21_NULL) {
    while (str[i] == ' ') {
      i++;
      (*j)++;
    }
    if (str[i] == '-') {
      sign = -1;
      i++;
    } else if (str[i] == '+') {
      i++;
    }

    double integer_part = 0;
    while (str[i] >= '0' && str[i] <= '9' && (i - *j < width || width == 0)) {
      integer_part = integer_part * 10 + (str[i] - '0');
      i++;
      in = 1;
    }

    double fract_part = 0;
    double fract_divisor = 1.0;
    if (str[i] == '.') {
      i++;
      while (str[i] >= '0' && str[i] <= '9' && (i - *j < width || width == 0)) {
        fract_part = fract_part * 10 + (str[i] - '0');
        fract_divisor *= 10.0;
        i++;
        in = 1;
      }
    }

    result = sign * (integer_part + fract_part / fract_divisor);
    *(j) = i;
  }

  if (in == 0) *error = 1;

  return result;
}

double my_pow10(int n) {
  if (n == 0) return 1;
  double result = 1.0;
  for (int i = 0; i < abs(n); i++) {
    result *= 10.0;
  }
  return (n < 0) ? (1.0 / result) : result;
}

double my_atoe(char const *str, int *j, int width, int *error) {
  int i = *j, in = 0;
  double mantissa = 0.0;
  int decimal_pos = -1, sign = 1, exponent = 0, exp_sign = 1;

  if (str != S21_NULL) {
    while (str[i] == ' ') {
      i++;
      (*j)++;
    }
    if (str[i] == '-') {
      sign = -1;
      i++;
    } else if (str[i] == '+') {
      i++;
    }

    while ((i - *j < width || width == 0) &&
           ((str[i] >= '0' && str[i] <= '9') || str[i] == '.')) {
      if (str[i] == '.') {
        decimal_pos = 0;
      } else {
        mantissa = mantissa * 10 + (str[i] - '0');
        if (decimal_pos >= 0) decimal_pos++;
      }
      i++;
      in = 1;
    }
    if (decimal_pos > 0) mantissa /= my_pow10(decimal_pos);

    if (str[i] == 'e' || str[i] == 'E') {
      i++;
      if (str[i] == '-') {
        exp_sign = -1;
        i++;
      } else if (str[i] == '+') {
        i++;
      }
      while (str[i] >= '0' && str[i] <= '9' && (i - *j < width || width == 0)) {
        exponent = exponent * 10 + (str[i] - '0');
        i++;
      }
    }
    *j = i;
  }

  if (!in) *error = 1;

  return sign * mantissa * my_pow10(exponent * exp_sign);
}

long long my_atox(char const *str, int *j, int width, int *error) {
  int in = 0;
  long long result = 0;
  if (str != NULL) {
    long long power = 1;
    int i = *j;
    while (((str[i] >= '0' && str[i] <= '9') ||
            (str[i] >= 'a' && str[i] <= 'f') ||
            (str[i] >= 'A' && str[i] <= 'F')) &&
           (i - *j < width || width == 0)) {
      i++;
    }
    int temp = i;
    i--;
    while (i >= *j) {
      char c = str[i];
      long long val = 0;
      if (c >= '0' && c <= '9') {
        val = c - '0';
      } else if (c >= 'a' && c <= 'f') {
        val = c - 'a' + 10;
      } else if (c >= 'A' && c <= 'F') {
        val = c - 'A' + 10;
      }
      result += val * power;
      power *= 16;
      i--;
      in = 1;
    }
    *j = temp;
  }
  if (!in) *error = 1;

  return result;
}

long long my_atoo(char const *str, int *j, int width, int *error) {
  int in = 0;
  long long result = 0;
  if (str != NULL) {
    long long power = 1;
    int i = *j, temp = 0;
    while (str[i] >= '0' && str[i] <= '7' && (i - *j < width || width == 0))
      i++;
    temp = i;
    i--;
    while (i >= *j) {
      char c = str[i];
      result += (c - '0') * power;
      power *= 8;
      i--;
      in = 1;
    }
    *j = temp;
  }

  if (!in) *error = 0;

  return result;
}

unsigned int my_atoui(const char *str, int *j, int width, int *error) {
  unsigned int result = 0;
  int i = *j;
  int in = 0;
  if (str != S21_NULL) {
    while (str[i] == ' ') {
      i++;
      (*j)++;
    }
    while (str[i] >= '0' && str[i] <= '9' && (i - *j < width || width == 0)) {
      result = result * 10 + (str[i] - '0');
      i++;
      in = 1;
    }
    *j = i;
  }
  if (in == 0) {
    *error = 1;
  }

  return result;
}

void *my_atop(const char *str, int *j, int width, int *error) {
  void *result = NULL;
  int i = *j;
  int in = 0;
  while (str[i] == ' ') {
    i++;
    (*j)++;
  }
  if (str[i] == '0' && (str[i + 1] == 'x' || str[i + 1] == 'X')) {
    i += 2;
  }
  unsigned long long address = 0;
  while ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'f') ||
         (str[i] >= 'A' && str[i] <= 'F')) {
    address = address * 16;
    if (str[i] >= '0' && str[i] <= '9') {
      address += str[i] - '0';
    } else if (str[i] >= 'a' && str[i] <= 'f') {
      address += str[i] - 'a' + 10;
    } else if (str[i] >= 'A' && str[i] <= 'F') {
      address += str[i] - 'A' + 10;
    }
    i++;
    in = 1;
    if (width != 0 && (i - *j) >= width) break;
  }
  *j = i;
  if (in == 0) {
    *error = 1;
  } else {
    result = (void *)address;
  }

  return result;
}

int sspec_d(char const *str, va_list *peremn, sspec *sp, int *j) {
  int error = 0;
  long long int temp = 0;
  temp = my_atoi(str, j, sp->width, &error);
  if (!sp->less && error == 0) {
    if (sp->spec_size == 'h') {
      short *temp2 = va_arg(*peremn, short *);
      *temp2 = (short)temp;
    } else if (sp->spec_size == 'l') {
      long *temp2 = va_arg(*peremn, long *);
      *temp2 = (long)temp;
    } else {
      int *temp2 = va_arg(*peremn, int *);
      *temp2 = (int)temp;
    }
  }

  return error;
}

int sspec_f(char const *str, va_list *peremn, sspec *sp, int *j) {
  int error = 0;
  long double temp = 0;
  temp = my_atof(str, j, sp->width, &error);
  if (!sp->less && error == 0) {
    double *temp2 = NULL;
    temp2 = va_arg(*peremn, double *);
    *temp2 = temp;
  }
  return error;
}

int sspec_s(char const *str, va_list *peremn, sspec *sp, int *j) {
  s21_size_t length = s21_strlen(str + (*j));
  char *temp = malloc(length * sizeof(char));
  if (str == NULL) temp = NULL;
  int in = 0, flag = 1;
  if (temp != NULL) {
    s21_size_t i = 0;
    while (flag) {
      temp[i++] = str[(*j)++];
      if (str[*j] == ' ' || str[*j] == '\0' ||
          (i >= sp->width && sp->width != 0))
        flag = 0;
      if (flag) in = 1;
    }
    temp[i] = '\0';
    if (!sp->less) {
      char *temp2 = va_arg(*peremn, char *);
      s21_strcat(temp2, temp);
    }
    free(temp);
  }
  return in == 1 ? 0 : 1;
}

int sspec_e_E(char const *str, va_list *peremn, sspec *sp, int *j) {
  int error = 0;
  long double temp = 0;
  temp = my_atoe(str, j, sp->width, &error);
  if (!sp->less && error == 0) {
    if (sp->spec_size == 'L') {
      long double *temp2 = va_arg(*peremn, long double *);
      *temp2 = temp;
    } else {
      float *temp2 = va_arg(*peremn, float *);
      *temp2 = (float)temp;
    }
  }

  return error;
}

int sspec_x_X(char const *str, va_list *peremn, sspec *sp, int *j) {
  int error = 0;
  long long temp = 0;
  temp = my_atox(str, j, sp->width, &error);
  if (!sp->less && error == 0) {
    if (sp->spec_size == 'h') {
      short *temp2 = va_arg(*peremn, short *);
      *temp2 = (short)temp;
    } else if (sp->spec_size == 'l') {
      long *temp2 = va_arg(*peremn, long *);
      *temp2 = (long)temp;
    } else {
      int *temp2 = va_arg(*peremn, int *);
      *temp2 = (int)temp;
    }
  }
  return error;
}

int sspec_o(char const *str, va_list *peremn, sspec *sp, int *j) {
  int error = 0;
  long long temp = 0;

  temp = my_atoo(str, j, sp->width, &error);

  if (!sp->less && error == 0) {
    if (sp->spec_size == 'h') {
      short *temp2 = va_arg(*peremn, short *);
      *temp2 = (short)temp;
    } else if (sp->spec_size == 'l') {
      long *temp2 = va_arg(*peremn, long *);
      *temp2 = (long)temp;
    } else {
      int *temp2 = va_arg(*peremn, int *);
      *temp2 = (int)temp;
    }
  }

  return error;
}

int sspec_u(char const *str, va_list *peremn, sspec *sp, int *j) {
  int error = 0;
  unsigned long long int temp = 0;
  temp = my_atoui(str, j, sp->width, &error);
  if (!sp->less && error == 0) {
    if (sp->spec_size == 'h') {
      unsigned short *temp2 = va_arg(*peremn, unsigned short *);
      *temp2 = (unsigned short)temp;
    } else if (sp->spec_size == 'l') {
      unsigned long *temp2 = va_arg(*peremn, unsigned long *);
      *temp2 = (unsigned long)temp;
    } else {
      unsigned int *temp2 = va_arg(*peremn, unsigned int *);
      *temp2 = (unsigned int)temp;
    }
  }
  return error;
}

int sspec_p(char const *str, va_list *peremn, sspec *sp, int *j) {
  int error = 0;
  void *temp = NULL;
  temp = my_atop(str, j, sp->width, &error);
  if (!sp->less && error == 0) {
    void **temp2 = va_arg(*peremn, void **);
    *temp2 = temp;
  }
  return error;
}

int scheck_spec(sspec *sp, va_list *peremn, char const *str, int *j) {
  int error = 0;
  if (sp->spec == 'c') {
    if (!sp->less) {
      char *temp = va_arg(*peremn, char *);
      *temp = str[(*j)++];
    }
  } else if (sp->spec == 'd') {
    error = sspec_d(str, peremn, sp, j);
  } else if (sp->spec == 'f') {
    // error = spec_f(str, peremn, sp, j); // надо исправить
    error = sspec_e_E(str, peremn, sp, j);  // Проверить на сколько это корректно
  } else if (sp->spec == 's') {
    error = sspec_s(str, peremn, sp, j);
  } else if (sp->spec == 'u') {
    error = sspec_u(str, peremn, sp, j);
  } else if (sp->spec == '%') {
    char *temp = va_arg(*peremn, char *);
    *temp = '%';
  } else if (sp->spec == 'g') {
    error = sspec_e_E(str, peremn, sp, j);  // Проверить на сколько это корректно
  } else if (sp->spec == 'G') {
    error = sspec_e_E(str, peremn, sp, j);  // Проверить на сколько это корректно
  } else if (sp->spec == 'e') {
    error = sspec_e_E(str, peremn, sp, j);
  } else if (sp->spec == 'E') {
    error = sspec_e_E(str, peremn, sp, j);
  } else if (sp->spec == 'x') {
    sspec_x_X(str, peremn, sp, j);
  } else if (sp->spec == 'X') {
    sspec_x_X(str, peremn, sp, j);
  } else if (sp->spec == 'o') {
    error = sspec_o(str, peremn, sp, j);
  } else if (sp->spec == 'p') {
    error = sspec_p(str, peremn, sp, j);
  }
  return error;
}

int s21_sscanf(const char *str, const char *format, ...) {
  s21_size_t length = s21_strlen(format);

  va_list peremn;
  va_start(peremn, format);
  int error = 0;
  int j = 0;
  int read_count = 0;
  sspec sp;
  for (s21_size_t i = 0; i < length && error == 0; i++) {
    if (format[i] != '%') {
      if (format[i] != str[j++]) error = 1;
    } else {
      i += sparse(&sp, &format[i]);

      error = scheck_spec(&sp, &peremn, str, &j);
      if (error == 0) {
        read_count++;
      }
    }
  }
  va_end(peremn);

  return read_count;
}