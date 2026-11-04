/*Header Guard*/
#ifndef STRING_UTILS_H
#define STRING_UTILS_H

/*Includes*/
#include <stddef.h>

/*Constants*/
#define OFFSET ('a' - 'A')
#define STR_BUFFER 256


/*Prototypes*/
size_t my_strlen(char* str);
char* my_toupper(char* str);
char* my_tolower(char* str);
int my_strcmp(char* str1, char* str2);
double my_strcmp_percent(char* str1, char* str2);

/*Closing Header Guard Condition*/
#endif