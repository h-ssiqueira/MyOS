#include <stddef.h>
#include <stdint.h>
#include "driver_keyboard.h"
#include "driver_video.h"
#include "commands.h"

char buffer[MAX];
uint16_t buffer_index = 0;

extern void gdt_config();
extern void idt_config();
extern void isr_config();

void handler(uint32_t id){
	char c;
	switch (id){ // clock interruptions
		case 32:
			return;
			break;
		case 33: // I/O interruption
			c = terminal_readString();
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
					buffer_index = 0;
                    break;
                }
            }
            if(buffer_index == MAX-2){
                buffer[buffer_index] = '\n';
                buffer[buffer_index+1] = 0;
            }			
			break;	
		
		default:
			break;
    }
    //terminal_writenum(id,10); 

	//terminal_writestring("Hello, funfou!\n\0");
	//while(true);
}