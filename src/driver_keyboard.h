#ifndef _DRIVER_KEYBOARD_H_
#define _DRIVER_KEYBOARD_H_

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#define MAX 80 // Limit of keyboard buffer

/* Functions for keyboard */

// Get input from keyboard
uint8_t inb(uint16_t port);

// Translate the code from keyboard to character (ascii)
char translate(uint8_t key);

// Function to print the digit of key in keyboard
void printDigit(int N);

// Read and store input from keyboard in a buffer
void terminal_readString(char *buffer);

#endif