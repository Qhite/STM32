#ifndef _GPIO_H
#define _GPIO_H

#define GPIOA_ADDRESS 0x48000000
#define GPIOB_ADDRESS 0x48000400

#define GPIOA_MODER     *(unsigned long*)   (GPIOA_ADDRESS+0x00)
#define GPIOA_OTYPER    *(unsigned long*)   (GPIOA_ADDRESS+0x04)
#define GPIOA_OSPEEDR   *(unsigned long*)   (GPIOA_ADDRESS+0x08)
#define GPIOA_PUPDR     *(unsigned long*)   (GPIOA_ADDRESS+0x0C)
#define GPIOA_IDR       *(unsigned long*)   (GPIOA_ADDRESS+0x10)
#define GPIOA_ODR       *(unsigned long*)   (GPIOA_ADDRESS+0x14)
#define GPIOA_BSRR      *(unsigned long*)   (GPIOA_ADDRESS+0x18)
#define GPIOA_LCKR      *(unsigned long*)   (GPIOA_ADDRESS+0x1C)
#define GPIOA_AFRL      *(unsigned long*)   (GPIOA_ADDRESS+0x20)
#define GPIOA_AFRH      *(unsigned long*)   (GPIOA_ADDRESS+0x24)
#define GPIOA_BRR       *(unsigned long*)   (GPIOA_ADDRESS+0x28)

#define GPIOB_MODER     *(unsigned long*)   (GPIOB_ADDRESS+0x00)
#define GPIOB_OTYPER    *(unsigned long*)   (GPIOB_ADDRESS+0x04)
#define GPIOB_OSPEEDR   *(unsigned long*)   (GPIOB_ADDRESS+0x08)
#define GPIOB_PUPDR     *(unsigned long*)   (GPIOB_ADDRESS+0x0C)
#define GPIOB_IDR       *(unsigned long*)   (GPIOB_ADDRESS+0x10)
#define GPIOB_ODR       *(unsigned long*)   (GPIOB_ADDRESS+0x14)
#define GPIOB_BSRR      *(unsigned long*)   (GPIOB_ADDRESS+0x18)
#define GPIOB_LCKR      *(unsigned long*)   (GPIOB_ADDRESS+0x1C)
#define GPIOB_AFRL      *(unsigned long*)   (GPIOB_ADDRESS+0x20)
#define GPIOB_AFRH      *(unsigned long*)   (GPIOB_ADDRESS+0x24)
#define GPIOB_BRR       *(unsigned long*)   (GPIOB_ADDRESS+0x28)

void set_gpio();

#endif