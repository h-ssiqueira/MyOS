#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/* Created libraries */
#include "driver_keyboard.h"
#include "driver_video.h"
#include "commands.h"
#include "interrupts.h"

/*
To compile:
* Comment the pre processor directives and run the command below:
i686-linux-gnu-gcc-10 -c kernel.c -o kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
*/

void kernel_main(void){
	char buffer[50];
	/* Initialize terminal interface */
	terminal_initialize();
	//idt_init();

	//terminal_writestring("Hello, I'm a simple kernel!\n");
	while(true){
		//terminal_putchar(translate(inb(0x60))); // For collect keyboard codes of each key pressed

		terminal_readString(buffer);//terminal_readString(buffer);
		//terminal_writestring(buffer);
		command(buffer);
	}
}