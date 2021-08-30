#include <stdint.h>
#include <stdbool.h>
#include "driver_video.h"

/*
bgcolor -cor: deve trocar a cor do texto;
fgcolor -cor: deve trocar a cor do fundo da fonte do terminal;
info: deve listar o nome dos desenvolvedores e a versão do SO;
reboot: deve reiniciar o sistema operacional;
clear: limpar a tela
*/

uint8_t slen(char *str){
    uint8_t i;
    for(i ^= i; str[i] != '\0'; i++)
        continue;
    return i;
}

bool scmp(char *str1, char *str2){
    uint8_t i;
    for(i ^= i; str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i]; i++)
        continue;
    if(str1[i] == str2[i])
        return true;
    return false;
}

void command(char *cmd){
    char inst[20];
    uint8_t i;
    for(i ^= i; cmd[i] != ' '; i++)
        inst[i] = cmd[i];
    inst[i] ^= inst[i];
    i ^= i;
    if(scmp(inst,"bgcolor")){
//TODO
    }
    else if(scmp(inst,"fgcolor")){
//TODO
    }
    else if(scmp(inst,"info"))
        terminal_writestring("Developed by Henrique Sartori Siqueira V1.0\n\0");
    else if(scmp(inst,"clear"))
        clear();
    else if(scmp(inst,"reboot")){
//TODO
/*

outb(0x64, 0xFE)
porta 0x64 para reset (0xFE)
*/
    }
    else
        terminal_writestring("Command not found\n\0");
}