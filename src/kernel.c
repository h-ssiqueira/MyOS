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
#include "register.h"

/*
To compile:
* Comment the pre processor directives and run the command below:
i686-linux-gnu-gcc-10 -c kernel.c -o kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
*/

void kernel_main(void){
	gdt_config();
	idt_config();
	isr_config();


	/* Initialize terminal interface */
	terminal_initialize();



	uint16_t prog[] = {0xb866,0x0004,0x0000,0xbb66,0x0001,0x0000,0xb966,0x0028,
0x0000,0xba66,0x000d,0x0000,0x80cd,0xb866,0x0001,0x0000,
0xbb66,0x0000,0x0000,0x80cd,0x6548,0x6c6c,0x206f,0x6f77,
0x6c72,0x2164,0x000a};

	//terminal_writenum((size_t)&prog,16);
	//terminal_putchar('\n');
	uint16_t *c = (uint16_t *)0x2000;
	//terminal_writenum(0x2000,10);
	for(uint16_t i = 0; i < 27; i++){
		c[i] = prog[i];
	}

	//terminal_writestring("Hello, I'm a simple kernel!\n\0");

	while(true){

		//terminal_putchar(translate(inb(0x60))); // For collect keyboard codes of each key pressed
		//terminal_readString(buffer);
		//terminal_writestring("Hello, I'm a simple kernel2!\n\0");
		//terminal_writestring(buffer); // To check if the buffer gets the right input
		//command(buffer);
	}
}