#include <stdint.h>
#include <stdbool.h>
#include "driver_video.h"
#include "driver_keyboard.h"

bool scmp(char *str1, char *str2){
    uint8_t i;
    for(i ^= i; str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i]; i++)
        continue;
    if(str1[i] == str2[i])
        return true;
    return false;
}

void command(char *cmd){
    size_t i,j;
    char inst[20];
    for(i ^= i; cmd[i] != '-' && cmd[i] != '\n' && cmd[i] != '\0'; i++)
        inst[i] = cmd[i];
    inst[i] ^= inst[i];
    if(scmp(inst,"bgcolor ")){
        if(strlen(cmd) >= i+2 && cmd[i+2] == '\n'){
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
        else{
            for(j ^= j,i++; cmd[i] != '\n'; i++,j++)
                inst[j] = cmd[i];
            inst[j] ^= inst[j];
            if(scmp("black",inst))
                terminal_setbgcolor(0);
            else if(scmp("blue",inst))
                terminal_setbgcolor(1);
            else if(scmp("green",inst))
                terminal_setbgcolor(2);
            else if(scmp("cyan",inst))
                terminal_setbgcolor(3);
            else if(scmp("red",inst))
                terminal_setbgcolor(4);
            else if(scmp("magenta",inst))
                terminal_setbgcolor(5);
            else if(scmp("brown",inst))
                terminal_setbgcolor(6);
            else if(scmp("light grey",inst))
                terminal_setbgcolor(7);
            else if(scmp("dark grey",inst))
                terminal_setbgcolor(8);
            else if(scmp("light blue",inst))
                terminal_setbgcolor(9);
            else if(scmp("light green",inst))
                terminal_setbgcolor(10);
            else if(scmp("light cyan",inst))
                terminal_setbgcolor(11);
            else if(scmp("light red",inst))
                terminal_setbgcolor(12);
            else if(scmp("light magenta",inst))
                terminal_setbgcolor(13);
            else if(scmp("light brown",inst))
                terminal_setbgcolor(14);
            else if(scmp("white",inst))
                terminal_setbgcolor(15);
            else
                terminal_writestring("Missing color to change.\n\0");
        }
    }
    else if(scmp(inst,"fgcolor ")){
        if(strlen(cmd) >= i+2 && cmd[i+2] == '\n'){
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
        else{
            for(j ^= j,i++; cmd[i] != '\n'; i++,j++)
                inst[j] = cmd[i];
            inst[j] ^= inst[j];
            if(scmp("black",inst))
                terminal_setfgcolor(0);
            else if(scmp("blue",inst))
                terminal_setfgcolor(1);
            else if(scmp("green",inst))
                terminal_setfgcolor(2);
            else if(scmp("cyan",inst))
                terminal_setfgcolor(3);
            else if(scmp("red",inst))
                terminal_setfgcolor(4);
            else if(scmp("magenta",inst))
                terminal_setfgcolor(5);
            else if(scmp("brown",inst))
                terminal_setfgcolor(6);
            else if(scmp("light grey",inst))
                terminal_setfgcolor(7);
            else if(scmp("dark grey",inst))
                terminal_setfgcolor(8);
            else if(scmp("light blue",inst))
                terminal_setfgcolor(9);
            else if(scmp("light green",inst))
                terminal_setfgcolor(10);
            else if(scmp("light cyan",inst))
                terminal_setfgcolor(11);
            else if(scmp("light red",inst))
                terminal_setfgcolor(12);
            else if(scmp("light magenta",inst))
                terminal_setfgcolor(13);
            else if(scmp("light brown",inst))
                terminal_setfgcolor(14);
            else if(scmp("white",inst))
                terminal_setfgcolor(15);
            else
                terminal_writestring("Missing color to change.\n\0");
        }
    }
    else if(scmp(inst,"info"))
        terminal_writestring("Developed by Henrique Sartori Siqueira V1.0.\n\0");
    else if(scmp(inst,"clear"))
        clear();
    else if(scmp(inst,"reboot"))
        outb(0x64,0xFE); // Port 0x64 to reset (0xFE)
        //asm volatile("JMP 0xFFFF");
    else
        terminal_writestring("Command not found.\n\0");
}