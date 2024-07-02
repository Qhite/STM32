#include <rcc.h>
#include <stdint.h>
#define DMB() asm volatile ("dmb")

void set_clock() {
    RCC_CR |= RCC_CR_HSION; // HSI Activate 8MHz
    DMB();
    while (!(RCC_CR & RCC_CR_HSIRDY)); // HSI Ready

    uint32_t reg32;

    reg32 = RCC_CFGR;
    reg32 &= ~0xF0; // RCC_CFGR[7:4] HPRE
    RCC_CFGR = (reg32 | (PRESCALERDIV_NONE << 4)); // HPRE set DIV_NONE
    DMB();
    reg32 = RCC_CFGR;
    reg32 &= ~0x3800; // RCC_CFGR[13:11] PPRE2
    RCC_CFGR = (reg32 | (PRESCALERDIV_2 << 11)); // PPRE2 set DIV_NONE
    DMB();
    reg32 = RCC_CFGR;
    reg32 &= ~0x700; // RCC_CFGR[10:8] PPRE1
    RCC_CFGR = (reg32 | (PRESCALERDIV_NONE << 8)); // PPRE1 set DIV_NONE
    DMB();
    reg32 = RCC_CFGR;
    reg32 &= PLLMASK; // PLL Setting Mask 
    RCC_CFGR = (reg32 | (PLLNODIV << 31) | (MCOPRE << 28) | (MCO << 24) | (PLLMUL << 18) | (PLLSRC << 15) | (SW << 0)); // PLL Setting
    DMB();

    RCC_CR |= RCC_CR_PLLON;
    DMB();
    while (!(RCC_CR & RCC_CR_PLLRDY));
}