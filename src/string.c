#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "string.h"
#include "driver_video.h"

bool scmp(char *str1, char *str2){
    uint8_t i;
    for(i ^= i; str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i]; i++)
        continue;
    if(str1[i] == str2[i])
        return true;
    return false;
}

size_t strlen(const char* str){
	size_t len;
	len ^= len;
	while(str[len])
		len++;
	return len;
}

void printAton(char *str, uint8_t base){
    char *x = str, *len;
    len = x + strlen(str);
    while(x < len){
        terminal_writenum(atoi(*x++),base);
        terminal_putchar(' ');
    }
    terminal_putchar('\n');
}

bool find(char *str, char *string){
    char *len = strlen(str) - strlen(string) + str;
    char lenstr = strlen(string),*size;
    char *i,*j;
    for(char *index = str; index < len; index++){
        i = index;
        size = lenstr + i;
        j = string;
        while(*i == *j && i < size){
            i++;
            j++;
        }
        if(i == size)
            return true;
    }
    return false;
}