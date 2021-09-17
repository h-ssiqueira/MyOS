#ifndef _DRIVER_KEYBOARD_H_
#define _DRIVER_KEYBOARD_H_

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#define MAX 100 // Limit of keyboard buffer

// Get input from keyboard
uint8_t inb(uint16_t port);

// Send data to a specific port
static inline void outb(uint16_t port, uint8_t val){
    asm volatile("outb %0, %1" : : "a"(val), "Nd"(port));
    /* There's an outb %al, $imm8  encoding, for compile-time constant port numbers that fit in 8b.  (N constraint).
     * Wider immediate constants would be truncated at assemble-time (e.g. "i" constraint).
     * The  outb  %al, %dx  encoding is the only option for all other cases.
     * %1 expands to %dx because  port  is a uint16_t.  %w1 could be used if we had the port number a wider C type */
}

// Translate the code from keyboard to character (ascii)
char translate(uint8_t key);

// Read and store input from keyboard in a buffer
void terminal_readString(char *buffer);

#endif