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

/*void outb(uint16_t value, uint16_t port){
	asm volatile("outb %1, %0" : "=a"(port) : "Nd"(value));
}*/

void command(char *cmd){
    char inst[20];
    uint8_t i;
    for(i ^= i; cmd[i] != '-' && cmd[i] != '\n' && cmd[i] != '\0'; i++)
        inst[i] = cmd[i];
    inst[i] ^= inst[i];
    if(scmp(inst,"bgcolor ")){
        switch(cmd[++i]){
            case '0':
                terminal_setbgcolor(0);
                break;
            case '1':
                terminal_setbgcolor(1);
                break;
            case '2':
                terminal_setbgcolor(2);
                break;
            case '3':
                terminal_setbgcolor(3);
                break;
            case '4':
                terminal_setbgcolor(4);
                break;
            case '5':
                terminal_setbgcolor(5);
                break;
            case '6':
                terminal_setbgcolor(6);
                break;
            case '7':
                terminal_setbgcolor(7);
                break;
            case '8':
                terminal_setbgcolor(8);
                break;
            case '9':
                terminal_setbgcolor(9);
                break;
            case 'a':
            case 'A':
                terminal_setbgcolor(10);
                break;
            case 'b':
            case 'B':
                terminal_setbgcolor(11);
                break;
            case 'c':
            case 'C':
                terminal_setbgcolor(12);
                break;
            case 'd':
            case 'D':
                terminal_setbgcolor(13);
                break;
            case 'e':
            case 'E':
                terminal_setbgcolor(14);
                break;
            case 'f':
            case 'F':
                terminal_setbgcolor(15);
                break;
            default:
                terminal_writestring("Missing color to change.\n\0");
        }
    }
    else if(scmp(inst,"fgcolor ")){
        switch(cmd[++i]){
            case '0':
                terminal_setfgcolor(0);
                break;
            case '1':
                terminal_setfgcolor(1);
                break;
            case '2':
                terminal_setfgcolor(2);
                break;
            case '3':
                terminal_setfgcolor(3);
                break;
            case '4':
                terminal_setfgcolor(4);
                break;
            case '5':
                terminal_setfgcolor(5);
                break;
            case '6':
                terminal_setfgcolor(6);
                break;
            case '7':
                terminal_setfgcolor(7);
                break;
            case '8':
                terminal_setfgcolor(8);
                break;
            case '9':
                terminal_setfgcolor(9);
                break;
            case 'a':
            case 'A':
                terminal_setfgcolor(10);
                break;
            case 'b':
            case 'B':
                terminal_setfgcolor(11);
                break;
            case 'c':
            case 'C':
                terminal_setfgcolor(12);
                break;
            case 'd':
            case 'D':
                terminal_setfgcolor(13);
                break;
            case 'e':
            case 'E':
                terminal_setfgcolor(14);
                break;
            case 'f':
            case 'F':
                terminal_setfgcolor(15);
                break;
            default:
                terminal_writestring("Missing color to change.\n\0");
        }
    }
    else if(scmp(inst,"info"))
        terminal_writestring("Developed by Henrique Sartori Siqueira V1.0.\n\0");
    else if(scmp(inst,"clear"))
        clear();
    /*else if(scmp(inst,"reboot"))
        outb(0xFE,0x64);

        outb(0x64, 0xFE)
        porta 0x64 para reset (0xFE)
    */
    else
        terminal_writestring("Command not found.\n\0");
}