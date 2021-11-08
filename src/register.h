#ifndef REGISTERS_H
#define REGISTERS_H

#include <stdint.h>

    typedef uint32_t uintr_t;

    struct Registers{
        uintr_t r5; // EDI
        uintr_t r6; // ESI
        uintr_t r4; // EBP
        uintr_t sp; // ESP
        uintr_t r1; // EBX
        uintr_t r3; // EDX
        uintr_t r2; // ECX
        uintr_t r0; // EAX
        uintr_t pc; // EIP

        
    }__attribute__((packed));
#endif