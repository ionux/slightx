#ifndef __ISR_H
#define __ISR_H

/*!
 * \file isr.h
 * \brief ISR handlers
 * \author David Delassus
 */

#include <types.h>

/* A few defines to make life a little easier */
#define IRQ0  32
#define IRQ1  33
#define IRQ2  34
#define IRQ3  35
#define IRQ4  36
#define IRQ5  37
#define IRQ6  38
#define IRQ7  39
#define IRQ8  40
#define IRQ9  41
#define IRQ10 42
#define IRQ11 43
#define IRQ12 44
#define IRQ13 45
#define IRQ14 46
#define IRQ15 47

/*!
 * \struct registers_t
 * \brief Structure describing registers used by the ISR handler.
 */
struct registers_t
{
    uint32_t ds;                                        /*!< Data segment selector */
    uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax;    /*!< Pushed by pusha */
    uint32_t int_no, err_code;                          /*!< Interrupt number and error code (if applicable) */
    uint32_t eip, cs, eflags, useresp, ss;              /*!< Pushed by the processor automatically */
};

typedef void (*isr_t)(struct registers_t *);
void set_interrupt_handler (uint8_t n, isr_t handler);

#endif /* __ISR_H */
