#ifndef _INTERRUPTS_H_
#define _INTERRUPTS_H_

#include <stdint.h>
#include <stddef.h>

void handler();
void IOInt();

extern void gdt_config();
extern void idt_config();
extern void isr_config();

#endif