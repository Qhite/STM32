#ifndef _I2C_H
#define _I2C_H

#include <stdint.h>

#define I2C1_ADDRESS 0x40005400

#define I2C1_CR1        *(unsigned long*)   (I2C1_ADDRESS+0x00)
#define I2C1_CR2        *(unsigned long*)   (I2C1_ADDRESS+0x04)
#define I2C1_OAR1       *(unsigned long*)   (I2C1_ADDRESS+0x08)
#define I2C1_OAR2       *(unsigned long*)   (I2C1_ADDRESS+0x0C)
#define I2C1_TIMINGR    *(unsigned long*)   (I2C1_ADDRESS+0x10)
#define I2C1_TIMEOUTR   *(unsigned long*)   (I2C1_ADDRESS+0x14)
#define I2C1_ISR        *(unsigned long*)   (I2C1_ADDRESS+0x18)
#define I2C1_ICR        *(unsigned long*)   (I2C1_ADDRESS+0x1C)
#define I2C1_PECR       *(unsigned long*)   (I2C1_ADDRESS+0x20)
#define I2C1_RXDR       *(unsigned long*)   (I2C1_ADDRESS+0x24)
#define I2C1_TXDR       *(unsigned long*)   (I2C1_ADDRESS+0x28)

void init_i2c1();
void i2c1_write(uint8_t desADDR, uint8_t regADDR, uint8_t data);
void i2c1_read(uint8_t desADDR, uint8_t regADDR, uint8_t *data, uint8_t len);

#endif