#include "s21_string.h"
#include <stdio.h>

// FUNCTION NUMBER 1
void *s21_memchr(const void *str, int c, s21_size_t n) {
  char *p = (char *)str;
  void *res = S21_NULL;
  while (p != S21_NULL && n-- > 0) {
    if (*p == c) {
      n = 0;
      res = (void *)p;
    } else if (*p == '\0') {
      n = 0;
    } else
      p++;
  }
  return res;
}

// FUNCTION NUMBER 2
int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  char *p1 = (char *)str1, *p2 = (char *)str2;
  int res = 0;
  while (p1 != S21_NULL && p2 != S21_NULL && !res && n) {
    if (*p1 != *p2) {
      res = (int)(*p1 - *p2);
      n = 0;
    } else {
      p1++;
      p2++;
      n--;
    }
  }
  if (str1 == S21_NULL && str2 != S21_NULL) res = -1;
  else if (str1 != S21_NULL && str2 == S21_NULL) res = 1;
  return res;
}

// 3
void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *p1 = (char *)dest, *p2 = (char *)src;
  while (p1 != S21_NULL && p2 != S21_NULL && n > 0) {
    *(p1++) = *(p2++);
    n--;
  }
  return dest;
}

// 4
void *s21_memset(void *str, int c, s21_size_t n) {
  if (str == S21_NULL || n < 1) return str;
  char *p = (char *)str;
  while (n > 0) {
    *(p++) = c;
    n--;
  }
  return str;
}
// 5
char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  if (dest == S21_NULL || src == S21_NULL) return dest;
  s21_size_t i = 0;
  for (i = 0; dest[i] != '\0'; i++) {
  }
  for (s21_size_t j = 0; j < n && src[j] != '\0'; j++, i++) {
    dest[i] = src[j];
  }
  dest[i] = '\0';
  return dest;
}

// 6
char *s21_strchr(const char *str, int c) {
  if (str == S21_NULL) return S21_NULL;
  int symbol_found = 0;
  s21_size_t index = 0;
  for (; symbol_found == 0 && str[index]; index++)
    if (c == str[index]) {
      symbol_found = 1;
      index--;
    }
  if (c == 0) symbol_found = 1;
  return symbol_found ? (char *)str + index : S21_NULL;
}

// 7
int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  s21_size_t i = 0;
  int result = 0;
  if (str1 != S21_NULL && str2 != S21_NULL) {
    for (i = 0; i < n && str1[i] != '\0' && str1[i] == str2[i]; i++) {
    }
    if (n == i) {
      result = 0;
    } else {
      result = (unsigned char)str1[i] - (unsigned char)str2[i];
    }
  }
  if (str1 == S21_NULL && str2 != S21_NULL) result = -1;
  else if (str1 != S21_NULL && str2 == S21_NULL) result = 1;
  return result;
}

// 8

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  if (src == S21_NULL || dest == S21_NULL) return dest;
  s21_size_t i = 0;
  for (i = 0; i < n && src[i] != '\0'; i++) {
    dest[i] = src[i];
  }
  while (i < n) {
    dest[i] = '\0';
    i++;
  }

  return dest;
}
// 9
s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t i = 0;
  int found = 0;
  int result;
  for (i = 0; str1[i] != '\0' && found == 0; i++) {
    for (s21_size_t j = 0; str2[j] != '\0'; j++) {
      if (str1[i] == str2[j]) {
        found = 1;
        result = i;
      }
    }
  }
  if (found == 0) {
    result = i;
  }
  return result;
}

#if defined(__linux__)
#define MAX_ERRLIST 134
#define MIN_ERRLIST -1
#define ERROR "Unknown error "

static const char *errorList[] = {
    "Success",
    "Operation not permitted",
    "No such file or directory",
    "No such process",
    "Interrupted system call",
    "Input/output error",
    "No such device or address",
    "Argument list too long",
    "Exec format error",
    "Bad file descriptor",
    "No child processes",
    "Resource temporarily unavailable",
    "Cannot allocate memory",
    "Permission denied",
    "Bad address",
    "Block device required",
    "Device or resource busy",
    "File exists",
    "Invalid cross-device link",
    "No such device",
    "Not a directory",
    "Is a directory",
    "Invalid argument",
    "Too many open files in system",
    "Too many open files",
    "Inappropriate ioctl for device",
    "Text file busy",
    "File too large",
    "No space left on device",
    "Illegal seek",
    "Read-only file system",
    "Too many links",
    "Broken pipe",
    "Numerical argument out of domain",
    "Numerical result out of range",
    "Resource deadlock avoided",
    "File name too long",
    "No locks available",
    "Function not implemented",
    "Directory not empty",
    "Too many levels of symbolic links",
    "Resource temporarily unavailable",
    "No message of desired type",
    "Identifier removed",
    "Channel number out of range",
    "Level 2 not synchronized",
    "Level 3 halted",
    "Level 3 reset",
    "Link number out of range",
    "Protocol driver not attached",
    "No CSI structure available",
    "Level 2 halted",
    "Invalid exchange",
    "Invalid request descriptor",
    "Exchange full",
    "No anode",
    "Invalid request code",
    "Invalid slot",
    "Resource deadlock avoided",
    "Bad font file format",
    "Device not a stream",
    "No data available",
    "Timer expired",
    "Out of streams resources",
    "Machine is not on the network",
    "Package not installed",
    "Object is remote",
    "Link has been severed",
    "Advertise error",
    "Srmount error",
    "Communication error on send",
    "Protocol error",
    "Multihop attempted",
    "RFS specific error",
    "Bad message",
    "Value too large for defined data type",
    "Name not unique on network",
    "File descriptor in bad state",
    "Remote address changed",
    "Can not access a needed shared library",
    "Accessing a corrupted shared library",
    ".lib section in a.out corrupted",
    "Attempting to link in too many shared libraries",
    "Cannot exec a shared library directly",
    "Invalid or incomplete multibyte or wide character",
    "Interrupted system call should be restarted",
    "Streams pipe error",
    "Too many users",
    "Socket operation on non-socket",
    "Destination address required",
    "Message too long",
    "Protocol wrong type for socket",
    "Protocol not available",
    "Protocol not supported",
    "Socket type not supported",
    "Operation not supported",
    "Protocol family not supported",
    "Address family not supported by protocol",
    "Address already in use",
    "Cannot assign requested address",
    "Network is down",
    "Network is unreachable",
    "Network dropped connection on reset",
    "Software caused connection abort",
    "Connection reset by peer",
    "No buffer space available",
    "Transport endpoint is already connected",
    "Transport endpoint is not connected",
    "Cannot send after transport endpoint shutdown",
    "Too many references: cannot splice",
    "Connection timed out",
    "Connection refused",
    "Host is down",
    "No route to host",
    "Operation already in progress",
    "Operation now in progress",
    "Stale file handle",
    "Structure needs cleaning",
    "Not a XENIX named type file",
    "No XENIX semaphores available",
    "Is a named type file",
    "Remote I/O error",
    "Disk quota exceeded",
    "No medium found",
    "Wrong medium type",
    "Operation canceled",
    "Required key not available",
    "Key has expired",
    "Key has been revoked",
    "Key was rejected by service",
    "Owner died",
    "State not recoverable",
    "Operation not possible due to RF-kill",
    "Memory page has hardware error"};

#elif defined(__APPLE__)
#define MAX_ERRLIST 107
#define MIN_ERRLIST -1
#define ERROR "Unknown error: "

static const char *errorList[] = {
    "Undefined error: 0",
    "Operation not permitted",
    "No such file or directory",
    "No such process",
    "Interrupted system call",
    "Input/output error",
    "Device not configured",
    "Argument list too long",
    "Exec format error",
    "Bad file descriptor",
    "No child processes",
    "Resource deadlock avoided",
    "Cannot allocate memory",
    "Permission denied",
    "Bad address",
    "Block device required",
    "Resource busy",
    "File exists",
    "Cross-device link",
    "Operation not supported by device",
    "Not a directory",
    "Is a directory",
    "Invalid argument",
    "Too many open files in system",
    "Too many open files",
    "Inappropriate ioctl for device",
    "Text file busy",
    "File too large",
    "No space left on device",
    "Illegal seek",
    "Read-only file system",
    "Too many links",
    "Broken pipe",
    "Numerical argument out of domain",
    "Result too large",
    "Resource temporarily unavailable",
    "Operation now in progress",
    "Operation already in progress",
    "Socket operation on non-socket",
    "Destination address required",
    "Message too long",
    "Protocol wrong type for socket",
    "Protocol not available",
    "Protocol not supported",
    "Socket type not supported",
    "Operation not supported",
    "Protocol family not supported",
    "Address family not supported by protocol family",
    "Address already in use",
    "Can't assign requested address",
    "Network is down",
    "Network is unreachable",
    "Network dropped connection on reset",
    "Software caused connection abort",
    "Connection reset by peer",
    "No buffer space available",
    "Socket is already connected",
    "Socket is not connected",
    "Can't send after socket shutdown",
    "Too many references: can't splice",
    "Operation timed out",
    "Connection refused",
    "Too many levels of symbolic links",
    "File name too long",
    "Host is down",
    "No route to host",
    "Directory not empty",
    "Too many processes",
    "Too many users",
    "Disc quota exceeded",
    "Stale NFS file handle",
    "Too many levels of remote in path",
    "RPC struct is bad",
    "RPC version wrong",
    "RPC prog. not avail",
    "Program version wrong",
    "Bad procedure for program",
    "No locks available",
    "Function not implemented",
    "Inappropriate file type or format",
    "Authentication error",
    "Need authenticator",
    "Device power is off",
    "Device error",
    "Value too large to be stored in data type",
    "Bad executable (or shared library)",
    "Bad CPU type in executable",
    "Shared library version mismatch",
    "Malformed Mach-o file",
    "Operation canceled",
    "Identifier removed",
    "No message of desired type",
    "Illegal byte sequence",
    "Attribute not found",
    "Bad message",
    "EMULTIHOP (Reserved)",
    "No message available on STREAM",
    "ENOLINK (Reserved)",
    "No STREAM resources",
    "Not a STREAM",
    "Protocol error",
    "STREAM ioctl timeout",
    "Operation not supported on socket",
    "Policy not found",
    "State not recoverable",
    "Previous owner died",
    "Interface output queue is full"};
#endif

void s21_strcpy(char *dest, const char *src) { while ((*dest++ = *src++)); }

void s21_strcat(char *dest, const char *src) {
  char *p = dest;
  while (*p) p++;
  while ((*p++ = *src++));
}

char *s21_itoa(int num, char *str) {
  int i = 0;
  int isNegative = 0;

  if (num < 0) {
    isNegative = 1;
    num = -num;
  }

  do {
    str[i++] = num % 10 + '0';
  } while ((num /= 10) > 0);

  if (isNegative) {
    str[i++] = '-';
  }
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
// 10
char *s21_strerror(int errnum) {
  static char result[512] = {'\0'};

  if (errnum <= MIN_ERRLIST || errnum >= MAX_ERRLIST || errnum == 41 ||
      errnum == 58) {
    char numStr[32];
    s21_strcpy(result, ERROR);
    s21_strcat(result, s21_itoa(errnum, numStr));
  } else {
    s21_strcpy(result, errorList[errnum]);
  }

  return result;
}

// 11
s21_size_t s21_strlen(const char *str) {
  if (str == S21_NULL) return 0;
  s21_size_t len = 0;
  for (; str[len]; len++);
  return len;
}

// 12
char *s21_strpbrk(const char *str1, const char *str2) {
  if (str1 == S21_NULL || str2 == S21_NULL || *str2 == '\0') {
    return S21_NULL;
  }
  char *result = S21_NULL;

  while (*str1 != '\0' && result == S21_NULL) {
    const char *p = str2;
    while (*p != '\0') {
      if (*str1 == *p) {
        result = (char *)str1;
      }
      p++;
    }
    str1++;
  }
  return result;
}

// 13
char *s21_strrchr(const char *str, int c) {
  if (str == S21_NULL) return S21_NULL;
  int symbol_found = 0;
  s21_size_t index = 0;
  s21_size_t length = 0;
  for (; str[length]; length++)
    if (c == str[length]) {
      index = length;
      symbol_found = 1;
    }
  if (c == 0) {
    symbol_found = 1;
    index = length;
  }
  return symbol_found ? (char *)str + index : S21_NULL;
}

// 14
char *s21_strstr(const char *haystack, const char *needle) {
  if (haystack == S21_NULL || needle == S21_NULL) return S21_NULL;
  s21_size_t index_for_str1 = 0, index_for_str2 = 0, answer_index = 0;
  int start_symbol_found = 0, str_found = 0;
  while (haystack[index_for_str1] != '\0' && str_found != 2) {
    if (haystack[index_for_str1] == needle[index_for_str2]) {
      ++index_for_str2;
      if (start_symbol_found == 0) {
        answer_index = index_for_str1;
        start_symbol_found = 1;
      }
    } else {
      if (start_symbol_found != 0) index_for_str1--;
      start_symbol_found = 0;
      index_for_str2 = 0;
    }
    ++index_for_str1;
    if (needle[index_for_str2] == '\0' && start_symbol_found != 0) {
      str_found = 1;
    }
  }
  return str_found ? (char *)haystack + answer_index : S21_NULL;
}

// 15
char *s21_strtok(char *str, const char *delim) {
  static char *next = S21_NULL;
  char *result = S21_NULL;
  int e = 0;

  if (str != S21_NULL) {
    next = str;
  }

  if (next == S21_NULL || *next == '\0') {
    e = 1;
  }

  if (delim == S21_NULL || *delim == '\0') {
    result = next;
    next += s21_strlen(next);
  } else {
    while (*next != '\0' && s21_strchr(delim, *next)) {
      next++;
    }
    if (*next != '\0') {
      result = next;
      while (*next != '\0' && !s21_strchr(delim, *next)) {
        next++;
      }
      if (*next != '\0') {
        *next++ = '\0';
      }
    }
  }

  if (e) result = S21_NULL;
  return result;
}


// 16
void *s21_to_upper(const char *str) {
  if (str == S21_NULL) {
    return S21_NULL;
  }

  char *result = S21_NULL;
  s21_size_t length = s21_strlen(str);

  result = (char *)malloc((length + 1) * sizeof(char));

  if (result != S21_NULL) {
    for (s21_size_t i = 0; i < length; i++) {
      if (str[i] >= 'a' && str[i] <= 'z') {
        result[i] = str[i] - 32;
      } else {
        result[i] = str[i];
      }
    }
    result[length] = '\0';
  }

  return result;
}

// 17
void *s21_to_lower(const char *str) {
  if (str == S21_NULL) {
    return S21_NULL;
  }

  char *result = S21_NULL;
  s21_size_t length = s21_strlen(str);

  result = (char *)malloc((length + 1) * sizeof(char));

  if (result != S21_NULL) {
    for (s21_size_t i = 0; i < length; i++) {
      if (str[i] >= 'A' && str[i] <= 'Z') {
        result[i] = str[i] + 32;
      } else {
        result[i] = str[i];
      }
    }
    result[length] = '\0';
  }

  return result;
}

// 18
void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  if (src == S21_NULL || str == S21_NULL) {
    return S21_NULL;
  }

  s21_size_t src_length = s21_strlen(src);
  s21_size_t str_length = s21_strlen(str);

  if (start_index > src_length) {
    return S21_NULL;
  }

  s21_size_t new_length = src_length + str_length;
  char *new_str = (char *)malloc((new_length + 1) * sizeof(char));

  if (new_str != S21_NULL) {
    s21_memcpy(new_str, src, start_index);
    s21_memcpy(new_str + start_index, str, str_length);
    s21_memcpy(new_str + start_index + str_length, src + start_index,
               src_length - start_index);
    new_str[new_length] = '\0';
  }

  return new_str;
}

// 19
void *s21_trim(const char *src, const char *trim_chars) {
  if (src == S21_NULL) {
    return S21_NULL;
  }

  if (trim_chars == S21_NULL) {
    trim_chars = " \t";
  }

  s21_size_t src_len = s21_strlen(src);

  s21_size_t start = 0;
  while (start < src_len && is_trim_symbol(trim_chars, src[start])) {
    start++;
  }

  s21_size_t end = src_len - 1;
  while (end > start && is_trim_symbol(trim_chars, src[end])) {
    end--;
  }

  s21_size_t result_len = end - start + 1;

  char *result = (char *)malloc((result_len + 1) * sizeof(char));
  if (result != S21_NULL) {
    s21_memcpy(result, src + start, result_len);
    result[result_len] = '\0';
  }

  return result;
}

int is_trim_symbol(const char *trim_chars, char symbol) {
  int result = 0;
  while (*trim_chars != '\0') {
    if (symbol == *trim_chars) {
      result = 1;
    }
    trim_chars++;
  }
  return result;
}


// int main() { return 0; }