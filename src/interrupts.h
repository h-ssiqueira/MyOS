#ifndef _INTERRUPTS_H_
#define _INTERRUPTS_H_

#include <stdint.h>
#include <stddef.h>
#include "register.h"

void handler(uint32_t id, struct Registers *registers);

void IOInt();

extern void gdt_config();
extern void idt_config();
extern void isr_config();

#endif