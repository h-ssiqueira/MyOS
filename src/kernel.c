#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/* Created libraries */
#include "driver_keyboard.h"
#include "driver_video.h"
#include "commands.h"
#include "interrupts.h"
#include "string.h"
#include "math.h"

/*
To compile:
* Comment the pre processor directives and run the command below:
i686-linux-gnu-gcc-10 -c kernel.c -o kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
*/

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

//static int x=0;
void kernel_main(void){
	gdt_config();
	idt_config();
	isr_config();
	
	/* Initialize terminal interface */
	terminal_initialize();
	//idt_init();

	//terminal_writestring("Hello, I'm a simple kernel!\n\0");

	//int y=x/x;
	//int j= div(1,x); // Infinite loop and doesn't print the exception code (for I/O and clock exceptions it works normally)
	while(true){
		//terminal_putchar(translate(inb(0x60))); // For collect keyboard codes of each key pressed
		//terminal_readString(buffer);
		//terminal_writestring("Hello, I'm a simple kernel2!\n\0");
		//terminal_writestring(buffer); // To check if the buffer gets the right input
		//command(buffer);
	}
}