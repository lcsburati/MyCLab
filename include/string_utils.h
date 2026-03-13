#ifndef STRING_UTILS_H
#define STRING_UTILS_H

static const int OFFSET = 'a' - 'A'; 

int my_strlen(const char *str);

char *my_tolower(const char *str);

char *my_toupper(const char *str);

int my_strcmp(const char *str1, const char *str2);

double my_strcmp_percent(const char *str1, const char *str2);

#endif