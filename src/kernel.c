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
* Comment the pre processor directives and run the commaned below:
i686-linux-gnu-gcc-10 -c kernel.c -o kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
*/

//static int x=0;
void kernel_main(void){
	gdt_config();
	idt_config();
	isr_config();
	char arq[1700] = {"ELF                      l      4     (         Hello World!\n       óûL$ƒäðÿqüU‰åSèüÿÿÿÃ   Qƒìƒ    PèüÿÿÿƒÄeø1ÀY[]aüÃ‹$Ã GCC: (Ubuntu 10.3.0-1ubuntu1~20.04) 10.3.0          GNU   À             zR |ˆ  0          <    H Iu Au|LuxXÁ AÃAÅC   P                                          ñÿ                                                                                                 \n                                          	               	       <                 $              :               hello.c main __x86.get_pc_thunk.bx _GLOBAL_OFFSET_TABLE_ terminal_writestring          \n         	              H  O                                È  £                  \n"};
	
	
	/* Initialize terminal interface */
	terminal_initialize();
	

	/*//terminal_writestring("Hello, I'm a simple kernel!\n\0");

	//int y=x/x;
	//int j= div(1,x); // Infinite loop and doesn't print the exception code (for I/O and clock exceptions it works normally)
	while(true){
		//terminal_putchar(translate(inb(0x60))); // For collect keyboard codes of each key pressed
		//terminal_readString(buffer);
		//terminal_writestring("Hello, I'm a simple kernel2!\n\0");
		//terminal_writestring(buffer); // To check if the buffer gets the right input
		//command(buffer);
	}*/
}