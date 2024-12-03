#include <stdio.h>
#include <string.h>

void reverse_string(char *str) {
  int j, k;
  int len = strlen(str);
  for (j = 0, k = len - 1; j < k; j++, k--) {
    char temp = str[j];
    str[j] = str[k];
    str[k] = temp;
  }
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

int main() {
  int n = 6;
  char str[50];
  my_itoa(n, str);
  printf("%s", str);
  return 1;
}