#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "interrupts.h"
#include "driver_video.h"

// Quantidade de interrupções na tabela
const uint8_t IDT_MAX_DESCRIPTORS = 32;

//setting the entries 
extern void* isr_stub_table[];

//As said above, the IDT (Interrupt Descriptor Table) loads much the same way as the GDT and its structure is roughly the same except that it only contains gates and not segments.
//Each gate gives a full reference to a piece of code (code segment, privilege level and offset to the code in that segment) that is now bound to a number between 0 and 255 (the slot in the IDT)
//The IDT will be one of the first things to be enabled in your kernel sequence, so that you can catch hardware exceptions, listen to external events, etc. 
// Creating an IDT
__attribute__((aligned(0x10)))
static idt_entry_t idt[256]; // Create an array of IDT entries; aligned for performance

static idtr_t idtr;

// Defining the general exception handler
__attribute__((noreturn))
void exception_handler(){
    terminal_writestring("Funfou\0"); // Print para teste
    __asm__ volatile("cli; hlt"); // Completely hangs the computer
    while(true);
}

void idt_set_descriptor(uint8_t vector, void* isr, uint8_t flags){
    idt_entry_t* descriptor = &idt[vector];
 
    descriptor->isr_low        = (uint32_t)isr & 0xFFFF;
    descriptor->kernel_cs      = 0x08; // this value can be whatever offset your kernel code selector is in your GDT
    descriptor->attributes     = flags;
    descriptor->isr_high       = (uint32_t)isr >> 16;
    descriptor->reserved       = 0;
}

void idt_init(){
    idtr.base = (uintptr_t)&idt[0];
    idtr.limit = (uint16_t)sizeof(idt_entry_t) * IDT_MAX_DESCRIPTORS - 1;
 
    for(uint8_t vector = 0; vector < 32; vector++){
        idt_set_descriptor(vector, isr_stub_table[vector], 0x8E);
        //vectors[vector] = true;
    }
    __asm__ volatile("lidt %0" : : "m"(idtr)); // load the new IDT
    __asm__ volatile("sti"); // set the interrupt flag
}