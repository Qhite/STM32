#include <stdint.h>
#include <rcc.h>
#include <gpio.h>
#include <i2c.h>

void init_i2c1() {    
    uint32_t reg32;

    /* GPIO Pin Setting */
    RCC_AHBENR |= (1 << 18);       //GPIOB Clock Enable

    GPIOB_MODER &= ~((3 << 12) | (3 << 14));    // PB6, PB7 PinMode Reset
    GPIOB_MODER |= ((2 << 12) | (2 << 14));     // PB6 -> AF(SCL), PB7 -> AF(SDL)

    GPIOB_OTYPER |= (1 << 6) | (1 << 7);        // PB6, PB7 Open-Drain

    GPIOB_OSPEEDR |= (3 << 12) | (3 << 14);     // PB6, PB7 High Speed

    GPIOB_PUPDR |= (1 << 12) | (1 << 14);       // PB6, PB7 PullUp

    reg32 = GPIOB_AFRL & ~(0xf << (6 * 4));
    GPIOB_AFRL = reg32 | (4 << (6 * 4));            // PB6 -> AF4(I2C1 SCL)

    reg32 = GPIOB_AFRL & ~(0xf << (7 * 4));
    GPIOB_AFRL = reg32 | (4 << (7 * 4));            // PB7 -> AF4(I2C1 SDL)

    /* I2C1 Setting */
    RCC_CFGR3 |= (1 << 4);          // I2C1 Clock Source -> SYSCLK
    RCC_APB1ENR |= (1 << 21);       // I2C1 Clock Enable

    I2C1_CR1 &= ~(1 << 0);          // Disable I2C1
    I2C1_TIMINGR = 0x00303D5B;      // 100KHz
    I2C1_CR1 |= (1 << 0);           // Enable I2C1
}


void i2c1_write(uint8_t desADDR, uint8_t regADDR, uint8_t data) {
    while(!(I2C1_ISR & (1 << 0)));              // Wait until TXDR Empty
    
    I2C1_CR2 = I2C1_CR2 & ~(0xff << 1);         // Clear SADD
    I2C1_CR2 |= (desADDR << 1) | (1 << 16);     // Destination Address & 1byte Data
    I2C1_CR2 |= (1 << 13);                      // Start
    while(!(I2C1_ISR & (1 << 1)));              // ISR TXIS, Transmit Interrput Status
    I2C1_TXDR |= regADDR;                       // Register Address
    // while(!(I2C1_ISR & (1 << 1)));              // ISR TXIS, Transmit Interrput Status
}

void i2c1_read(uint8_t desADDR, uint8_t regADDR, uint8_t *data, uint8_t len) {
    
}