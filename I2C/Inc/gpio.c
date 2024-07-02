#include <stdint.h>
#include <rcc.h>
#include <gpio.h>

void set_gpio() {
    RCC_AHBENR  |= (1 << 17);       // GPIOA Clock Enable

    GPIOA_MODER &= ~(0x03 << 16);   // PA8 PinMode Reset
    GPIOA_MODER |= (0x02 << 16);    // PA8 -> AF(MCO)
}