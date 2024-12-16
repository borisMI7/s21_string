#include <stdio.h>
#include <string.h>

#include "s21_string.h"

int main() {
  char str1[1000] = {'\0'}, str2[1000] = {'\0'};
  int n1 = 0, n2 = 0;
  n1 = sprintf(str1, "here is the number: %#ho %#lo", (short)0, (long)543);
  n2 = s21_sprintf(str2, "here is the number: %#ho %#lo", (short)0, (long)543);
  n1 = sprintf(str1, "here is letter: %c", 'a');
  n2 = s21_sprintf(str2, "here is letter: %c", 'a');
  n1 = sprintf(str1, "here is letter: %c", 'a');
  n2 = s21_sprintf(str2, "here is letter: %c", 'a');
  n1 = sprintf(str1, "here is letter: %5c", 'a');
  n2 = s21_sprintf(str2, "here is letter: %5c", 'a');
  n1 = sprintf(str1, "here is letter: %-5c", 'a');
  n2 = s21_sprintf(str2, "here is letter: %-5c", 'a');
  n1 = sprintf(str1, "here is letter: %*c", 'a', 3);
  n2 = s21_sprintf(str2, "here is letter: %*c", 'a', 3);
  n1 = sprintf(str1, "here is letter: %*lc", 'a', 3);
  n2 = s21_sprintf(str2, "here is letter: %*lc", 'a', 3);
  n1 = sprintf(str1, "here is the number: %+d", 1234);
  n2 = s21_sprintf(str2, "here is the number: %+d", 1234);
  n1 = sprintf(str1, "here is the number: %-2.5d", 1234);
  n2 = s21_sprintf(str2, "here is the number: %-2.5d", 1234);
  n1 = sprintf(str1, "here is the number: %-+10.0d", 1234);
  n2 = s21_sprintf(str2, "here is the number: %-+10.0d", 1234);
  n1 = sprintf(str1, "here is the number: %+010d", 1234);
  n2 = s21_sprintf(str2, "here is the number: %+010d", 1234);
  n1 = sprintf(str1, "here is the number: %hd", (short)SHRT_MAX);
  n2 = s21_sprintf(str2, "here is the number: %hd", (short)SHRT_MAX);
  n1 = sprintf(str1, "here is the number: %-+20.10d lol", 123);
  n2 = s21_sprintf(str2, "here is the number: %-+20.10d lol", 123);
  n1 = sprintf(str1, "here is the number: %+.10d lol", 123);
  n2 = s21_sprintf(str2, "here is the number: %+.10d lol", 123);
  n1 = sprintf(str1, "here is the number: %*.*d lol", -123, 10, 5);
  n2 = s21_sprintf(str2, "here is the number: %*.*d lol", -123, 10, 5);
  n1 = sprintf(str1, "here is the number: %*d lol %-*.*d", 123, 10, 10, 20, 15);
  n2 = s21_sprintf(str2, "here is the number: %*d lol %-*.*d", 123, 10, 10, 20,
                   15);
  n1 = sprintf(str1, "here is the number: lol %Lf", (long double)15.12345e-35);
  n2 = s21_sprintf(str2, "here is the number: lol %Lf",
                   (long double)15.12345e-35);
  n1 =
      sprintf(str1, "here is the number: lol %25.10Lf", (long double)1337.1488);
  n2 = s21_sprintf(str2, "here is the number: lol %25.10Lf",
                   (long double)1337.1488);
  n1 = sprintf(str1, "here is the number: lol %#15Lf", (long double)1337.1488);
  n2 = s21_sprintf(str2, "here is the number: lol %#15Lf",
                   (long double)1337.1488);
  n1 = sprintf(str1, "here is the number: lol %#015Lf", (long double)1337.1488);
  n2 = s21_sprintf(str2, "here is the number: lol %#015Lf",
                   (long double)1337.1488);
  n1 =
      sprintf(str1, "here is the number: lol %#0+15Lf", (long double)1337.1488);
  n2 = s21_sprintf(str2, "here is the number: lol %#0+15Lf",
                   (long double)1337.1488);
  n1 = sprintf(str1, "here is the number: lol %#0+15.*Lf", 0,
               (long double)1337.1488);
  n2 = s21_sprintf(str2, "here is the number: lol %#0+15.*Lf", 0,
                   (long double)1337.1488);
  n1 = sprintf(str1, "here is the number: lol %#0+*.5Lf", 15,
               (long double)1337.1488);
  n2 = s21_sprintf(str2, "here is the number: lol %#0+*.5Lf", 15,
                   (long double)1337.1488);
  n1 = sprintf(str1, "here is the number: lol % *.*Lf", -15, 5,
               (long double)1337.1488);
  n2 = s21_sprintf(str2, "here is the number: lol % *.*Lf", -15, 5,
                   (long double)1337.1488);
  n1 = sprintf(str1, "here is the number: lol %s", "");
  n2 = s21_sprintf(str2, "here is the number: lol %s", "");
  n1 = sprintf(str1, "here is the number: lol %s", "aboba");
  n2 = s21_sprintf(str2, "here is the number: lol %s", "aboba");
  n1 = sprintf(str1, "here is the number: lol %50.2s", "ABOBABAABABABABAB");
  n2 = s21_sprintf(str2, "here is the number: lol %50.2s", "ABOBABAABABABABAB");
  n1 = sprintf(str1, "here is the number: lol %*.*s", 5, 50,
               "ABOBABAABABABABAB");
  n2 = s21_sprintf(str2, "here is the number: lol %*.*s", 5, 50,
                   "ABOBABAABABABABAB");
  n1 = sprintf(str1, "here is the number: lol %.0s", "ABOBABAABABABABAB");
  n2 = s21_sprintf(str2, "here is the number: lol %.0s", "ABOBABAABABABABAB");
  n1 = sprintf(str1, "here is the number: lol %-30.0s", "ABOBABAABABABABAB");
  n2 =
      s21_sprintf(str2, "here is the number: lol %-30.0s", "ABOBABAABABABABAB");
  n1 = sprintf(str1, "here is the number: %1u", 1234);
  n2 = s21_sprintf(str2, "here is the number: %1u", 1234);
  n1 = sprintf(str1, "here is the number: %-u", 1234);
  n2 = s21_sprintf(str2, "here is the number: %-u", 1234);
  n1 = sprintf(str1, "here is the number: %-10u", 1234);
  n2 = s21_sprintf(str2, "here is the number: %-10u", 1234);
  n1 = sprintf(str1, "here is the number: %-2.5u", 1234);
  n2 = s21_sprintf(str2, "here is the number: %-2.5u", 1234);
  n1 = sprintf(str1, "here is the number: %-10.0u", -1234);
  n2 = s21_sprintf(str2, "here is the number: %-10.0u", -1234);
  n1 = sprintf(str1, "here is the number: %010u", 1234);
  n2 = s21_sprintf(str2, "here is the number: %010u", 1234);
  n1 = sprintf(str1, "here is the number: %%%%%%%%%%%% %d", 1234);
  n2 = s21_sprintf(str2, "here is the number: %%%%%%%%%%%% %d", 1234);
  n1 = sprintf(str1, "here is the number: %5.g %5.G", 2.431431412,
               -4.345678908765);
  n2 = s21_sprintf(str2, "here is the number: %5.g %5.G", 2.431431412,
                   -4.345678908765);
  n1 = sprintf(str1, "here is the number: %5.0g %5.0G", 123423421431.431431412,
               -121232124554534334.345678908765);
  n2 = s21_sprintf(str2, "here is the number: %5.0g %5.0G",
                   123423421431.431431412, -121232124554534334.345678908765);
  n1 = sprintf(str1, "here is the number: %-5.0g %-5.0G",
               123423421431.431431412, -121232124554534334.345678908765);
  n2 = s21_sprintf(str2, "here is the number: %-5.0g %-5.0G",
                   123423421431.431431412, -121232124554534334.345678908765);
  n1 = sprintf(str1, "here is the number: %-#5.0g %-#5.0G",
               123423421431.431431412, -121232124554534334.345678908765);
  n2 = s21_sprintf(str2, "here is the number: %-#5.0g %-#5.0G",
                   123423421431.431431412, -121232124554534334.345678908765);
  n1 = sprintf(str1, "here is the number: % -#*.0g % -#*.0G", 50,
               123423421431.431431412, 50, -121232124554534334.345678908765);
  n2 =
      s21_sprintf(str2, "here is the number: % -#*.0g % -#*.0G", 50,
                  123423421431.431431412, 50, -121232124554534334.345678908765);
  n1 =
      sprintf(str1, "here is the number: %+05.3g %+05.3lG",
              123423421431.431431412, (double)-121232124554534334.345678908765);
  n2 = s21_sprintf(str2, "here is the number: %+05.3g %+05.3lG",
                   123423421431.431431412,
                   (double)-121232124554534334.345678908765);
  n1 = sprintf(str1, "here is the number: %+100.3g %+100.3G",
               123423421431.431431412, -121232124554534334.345678908765);
  n2 = s21_sprintf(str2, "here is the number: %+100.3g %+100.3G",
                   123423421431.431431412, -121232124554534334.345678908765);

  n1 = sprintf(str1, "here is the number: %+-5.3e %+-5.3E",
               123423421431.431431412, -121232124554534334.345678908765);
  n2 = s21_sprintf(str2, "here is the number: %+-5.3e %+-5.3E",
                   123423421431.431431412, -121232124554534334.345678908765);
  n1 = sprintf(str1, "here is the number: % -#5.0e % -#5.0E",
               123423421431.431431412, -121232124554534334.345678908765);
  n2 = s21_sprintf(str2, "here is the number: % -#5.0e % -#5.0E",
                   123423421431.431431412, -121232124554534334.345678908765);
  n1 =
      sprintf(str1, "here is the number: % -#*.*e % -#*.*E", 50, 4,
              123423421431.431431412, 50, 15, -121232124554534334.345678908765);
  n2 = s21_sprintf(str2, "here is the number: % -#*.*e % -#*.*E", 50, 4,
                   123423421431.431431412, 50, 15,
                   -121232124554534334.345678908765);
  n1 = sprintf(str1, "here is the number: %+100.3e %+100.3E",
               123423421431.431431412, -121232124554534334.345678908765);
  n2 = s21_sprintf(str2, "here is the number: %+100.3e %+100.3E",
                   123423421431.431431412, -121232124554534334.345678908765);
  n1 = sprintf(str1, "here is the number: %Le %LE", (long double)56e-28,
               (long double)-56e278);
  n2 = s21_sprintf(str2, "here is the number: %Le %LE", (long double)56e-28,
                   (long double)-56e278);
  n1 = sprintf(str1, "here is the number: %-30p", &n1);
  n2 = s21_sprintf(str2, "here is the number: %-30p", &n1);
  n1 = sprintf(str1, "here is the number: %-5p", &n1);
  n2 = s21_sprintf(str2, "here is the number: %-5p", &n1);
  n1 = sprintf(str1, "here is the number: %x %X", 0xf54321, 0xf54321);
  n2 = s21_sprintf(str2, "here is the number: %x %X", 0xf54321, 0xf54321);
  n1 = sprintf(str1, "here is the number: %-#10.5x %-#10.5X", 6543, -543);
  n2 = s21_sprintf(str2, "here is the number: %-#10.5x %-#10.5X", 6543, -543);
  n1 = sprintf(str1, "here is the number: %0hx %0lX", (short)6543, (long)-543);
  n2 = s21_sprintf(str2, "here is the number: %0hx %0lX", (short)6543,
                   (long)-543);
  n1 = sprintf(str1, "here is the number: %-10.o %-10.0o", 6543, -543);
  n2 = s21_sprintf(str2, "here is the number: %-10.o %-10.0o", 6543, -543);
  n1 = sprintf(str1, "here is the number: %-#10.5o %-#10.5o", 6543, -543);
  n2 = s21_sprintf(str2, "here is the number: %-#10.5o %-#10.5o", 6543, -543);
  n1 = sprintf(str1, "here is the number: %*.*o %*.*o", 15, 10, 6543, -15, 10,
               -543);
  n2 = s21_sprintf(str2, "here is the number: %*.*o %*.*o", 15, 10, 6543, -15,
                   10, -543);
  printf("%s\n%s", str1, str2);
  char str[] = "here is letter: %c";
  char c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0, c6 = 0;
  n1 = sscanf(str, "here is letter: %c", &c1);
  n2 = s21_sscanf(str, "here is letter: %c", &c2);
  n1 = sscanf(str, "hereis letter: %c", &c1);
  n2 = s21_sscanf(str, "heris letter: %c", &c2);
    n1 = sscanf(str, "%c %c", &c1, &c3);
  n2 = s21_sscanf(str, "%c %c", &c2, &c4);
  char stra[] = "aboba abob";
  char s1[200] = {0}, s2[200] = {0}, s3[200] = {0}, s4[200] = {0};
  n1 = sscanf(stra, "%s %s", s1, s3);
  n2 = s21_sscanf(stra, "%s %s", s2, s4);
  int d1 = 0, d2 = 0;
  n1 = sscanf(str, "%s %d", s1, &d1);
  n2 = s21_sscanf(str, "%s %d", s2, &d2);
  n1 = sscanf(str, "%3s", s1);
  n2 = s21_sscanf(str, "%3s", s2);
  char stre[] = "-52.56789 -3123.890";
  long double ca1 = 0.0, ca2 = 0.0;
  n1 = sscanf(stre, "%2Lf", &ca1);
  n2 = s21_sscanf(stre, "%2Lf", &ca2);
  char strv[] = "52.56789 0xf54321 0xF54321 89";
  long int x1 = 0, x2 = 0;
  short int x3 = 0, x4 = 0;
  n1 = sscanf(strv, "%2hx %3lX", &x3, &x1);
  n2 = s21_sscanf(strv, "%2hx %3lX", &x4, &x2);
  char strx[] = "1a 13 0xF5C321 89";
  n1 = sscanf(strx, "%hx %lX", &x3, &x1);
  n2 = s21_sscanf(strx, "%hx %lX", &x4, &x2);
  char strp[] = "0x7ff7bedf73e4";
  int *p1 = S21_NULL, *p2 = S21_NULL;
  n1 = sscanf(strp, "%p", &p1);
  n2 = s21_sscanf(strp, "%p", &p2);
  char strd[] = "-2.13213e+07 +1.34346E+09";
  double g1 = 0.0, g2 = 0.0, g3 = 0.0, g4 = 0.0;
  n1 = sscanf(strd, "%lg %lG", &g1, &g2);
  n2 = s21_sscanf(strd, "%lg %lG", &g3, &g4);
  return 0;
}