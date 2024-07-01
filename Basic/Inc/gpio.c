#include <gpio.h>
#include <rcc.h>
#include <stdint.h>

void set_gpio() {
    RCC_AHBENR  |= (1 << 17);

    GPIOA_MODER &= ~(0x03 << 16);    // PA8 PinMode Reset
    GPIOA_MODER |= (0x02 << 16);    // PA8 -> AF(MCO)
}