#ifndef _STRING_H_
#define _STRING_H_

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

inline size_t atoi(char c){
    return (size_t)c;
}

inline char itoa(size_t v){
    return (char)v;
}

size_t strlen(const char* str);

bool scmp(char *str1, char *str2);

void printAton(char *str, uint8_t base);

bool find(char *str, char *string);

#endif