#ifndef _RCC_H
#define _RCC_H

#define RCC_ADDRESS 0x40021000

#define RCC_CR          *(unsigned long*)   (RCC_ADDRESS+0x00)
#define RCC_CFGR        *(unsigned long*)   (RCC_ADDRESS+0x04)
#define RCC_CIR         *(unsigned long*)   (RCC_ADDRESS+0x08)
#define RCC_APB2RSTR    *(unsigned long*)   (RCC_ADDRESS+0x0C)
#define RCC_APB1RSTR    *(unsigned long*)   (RCC_ADDRESS+0x01)
#define RCC_AHBENR      *(unsigned long*)   (RCC_ADDRESS+0x14)
#define RCC_APB2ENR     *(unsigned long*)   (RCC_ADDRESS+0x18)
#define RCC_APB1ENR     *(unsigned long*)   (RCC_ADDRESS+0x1C)
#define RCC_BDCR        *(unsigned long*)   (RCC_ADDRESS+0x20)
#define RCC_CSR         *(unsigned long*)   (RCC_ADDRESS+0x24)
#define RCC_AHBRSTR     *(unsigned long*)   (RCC_ADDRESS+0x28)
#define RCC_CFGR2       *(unsigned long*)   (RCC_ADDRESS+0x2C)
#define RCC_CFGR2       *(unsigned long*)   (RCC_ADDRESS+0x30)

void set_clock();

#endif