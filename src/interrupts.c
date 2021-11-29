#include <stddef.h>
#include <stdint.h>
#include "driver_keyboard.h"
#include "driver_video.h"
#include "commands.h"
#include "register.h"

char buffer[MAX];
uint16_t buffer_index = 0;

extern void gdt_config();
extern void idt_config();
extern void isr_config();

void IOInt(){
    char c = terminal_readString();
	if(c != -1){
        if(c == '\b'){
            if(buffer_index > 0)
                buffer_index--;
        }
        if(c != '\b')
            buffer[buffer_index++] = c;
        terminal_putchar(c);
        if(c == '\n'){
            buffer[buffer_index] ^= buffer[buffer_index];
			command(buffer);
			buffer_index ^= buffer_index;
            return;
        }
    }
    if(buffer_index == MAX-2){
        buffer[buffer_index] = '\n';
        buffer[buffer_index+1] = 0;
     	buffer_index ^= buffer_index;
    }
}

void handler(uint32_t id, struct Registers *registers){
	switch (id){
		case 32: // clock interruptions
			return;
			break;
		case 33: // I/O interruption
			IOInt();
			break;
        case 0: // Division by 0
            command("reboot");
            break;
        case 128:
            /*terminal_writenum(registers->r2, 16);
            terminal_writestring("entrou1\n\0");*/
            /*terminal_writenum(registers->r0,16);
            terminal_putchar('\n');/*
            terminal_writenum(registers->r2+0x2000,16);
            terminal_putchar('\n');*/
            //terminal_write((const char*)((registers->r2+(0x2000))), registers->r3);
            //if(registers->r0 == (uintr_t)0x2000 /*&& registers->r1 == (uintr_t)1*/){
                registers->r1 -= 0x100000;
                registers->r2 -= 0x100000;
                terminal_writenum(registers->r0,16);
                terminal_putchar('\n');
                terminal_writenum(registers->r1,16);
                terminal_putchar('\n');
                terminal_writenum(registers->r2,16);
                terminal_putchar('\n');
                terminal_writenum(registers->r3,10);
                terminal_putchar('\n');
                terminal_writenum(registers->r4,16);
                terminal_putchar('\n');
                terminal_writenum(registers->r5,16);
                terminal_putchar('\n');
                terminal_writenum(registers->r6,16);
                terminal_putchar('\n');
                terminal_writenum(registers->pc,16);
                terminal_putchar('\n');
                //terminal_writestring((const char*)registers->r2);
                //terminal_write((const char*)((registers->r2)), registers->r3);
                terminal_write((const char*)(registers->r2+0x2000), registers->r3);
            ///}
            if(registers->r0 == (uintr_t)0x10AFB8 /*&& registers->r1 == (uintr_t)1*/){
                //registers->
                //terminal_writestring("entrou2\n\0");
                terminal_writenum(registers->r2,16);
                terminal_putchar('\n');
                terminal_writenum(registers->r3,10);
                terminal_putchar('\n');
                terminal_writestring((const char*)registers->r2);
                terminal_write((const char*)((registers->r2+(0x2000))), registers->r3);
            }else if(registers->r0==1 && registers->r1 == 0){
                //terminal_writestring("entrou3\n\0");
                return;
            }
            break;
		default:
            break;
    }
    //terminal_writenum(id,10);

	//terminal_writestring("Hello, funfou!\n\0");
	//while(true);
}
