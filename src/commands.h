#ifndef _COMMANDS_H_
#define _COMMANDS_H_

#include <stdint.h>
#include <stdbool.h>

void bgcolor_num(char n);

void bgcolor_txt(char *txt);

void fgcolor_num(char n);

void fgcolor_txt(char *txt);

void command(char *cmd);

#endif