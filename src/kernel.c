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
extern void gdt_config();
extern void idt_config();
extern void isr_config();
void handler(uint32_t id){
	if(id==32){
		return;
	}
	printDigit(id);

	terminal_writestring("Hello, funfou!\n\0");
	//while(true);
}
#define MAX 100
  
// Function to print the digit of
// number N
void printDigit(int N)
{
    // To store the digit
    // of the number N
    int arr[MAX];
    int i = 0;
    int j, r;
  
    // Till N becomes 0
    while (N != 0) {
  
        // Extract the last digit of N
        r = N % 10;
  
        // Put the digit in arr[]
        arr[i] = r;
        i++;
  
        // Update N to N/10 to extract
        // next last digit
        N = N / 10;
    }
  
    // Print the digit of N by traversing
    // arr[] reverse
    for (j = i - 1; j > -1; j--) {
     terminal_putchar('0'+arr[j]);
    }
}

void div_by_zero(){
	terminal_writestring("Div by zero!\n\0");
	while(true);
}
static int x=0;
void kernel_main(void){
	gdt_config();
	idt_config();
	isr_config();
	char buffer[50];
	/* Initialize terminal interface */
	terminal_initialize();
	//idt_init();

	terminal_writestring("Hello, I'm a simple kernel!\n");

	int y=x/x;
	int j=1/x;
	while(true){
		//terminal_putchar(translate(inb(0x60))); // For collect keyboard codes of each key pressed

		terminal_readString(buffer);//terminal_readString(buffer);
		//terminal_writestring(buffer);
		command(buffer);
	}
}