#ifndef STRING_UTILS_H
#define STRING_UTILS_H


static const int OFFSET = 'a' - 'A'; 

#define STR_BUFFER 256


typedef char * string;


size_t my_strlen(string str);

string my_tolower(string str);

string my_toupper(string str);

int my_strcmp(string str1, string str2);

double my_strcmp_percent(string str1, string str2);

#endif