#include <stdint.h>
#include <rcc.h>
#include <gpio.h>

void init_i2c1() {
    /* GPIO Pin Setting */
    RCC_AHBENR |= (1 << 18);       //GPIOB Clock Enable

    GPIOB_MODER &= ~((3 << 12) | (3 << 14));    // PB6, PB7 PinMode Reset
    GPIOB_MODER |= ((2 << 12) | (2 << 14));     // PB6 -> AF(SCL), PB7 -> AF(SDL)

    GPIOB_OTYPER |= (1 << 6) | (1 << 7);        // PB6, PB7 Open-Drain

    GPIOB_OSPEEDR |= (3 << 12) | (3 << 14);     // PB6, PB7 High Speed

    uint32_t reg32;

    reg32 = GPIOB_AFRL & ~(0xf << (6 * 4));
    GPIOB_AFRL = reg32 | (4 << (6 * 4));            // PB6 -> AF4(I2C1 SCL)

    reg32 = GPIOB_AFRL & ~(0xf << (7 * 4));
    GPIOB_AFRL = reg32 | (4 << (7 * 4));            // PB7 -> AF4(I2C1 SDL)

    /* I2C1 Setting */
    RCC_APB1ENR |= (1 << 21);       // I2C1 Clock Enable
}

    