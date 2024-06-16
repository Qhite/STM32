#include <rcc.h>

void set_clock() {
    RCC_CFGR    =   0x04080002; // MCO[26:24] 100 | PLLMUL 0010 | SW 10
    RCC_CR      =   0x01000080; // PLLON
}