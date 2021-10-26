#ifndef _INTERRUPTS_H_
#define _INTERRUPTS_H_

#include <stdint.h>
#include <stddef.h>

void handler();

extern void gdt_config();
extern void idt_config();
extern void isr_config();

#endif