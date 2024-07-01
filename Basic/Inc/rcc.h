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

#define RCC_CR_PLLRDY   (1 << 25)
#define RCC_CR_PLLON    (1 << 24)
#define RCC_CR_HSERDY   (1 << 17)
#define RCC_CR_HSEON    (1 << 16)
#define RCC_CR_HSIRDY   (1 << 1)
#define RCC_CR_HSION    (1 << 0)

#define PRESCALERDIV_NONE   0   // 000
#define PRESCALERDIV_2      4   // 100
#define PRESCALERDIV_4      5   // 101

#define PLLMASK 0xF73D8003 // 1111 0111 0011 1101 1000 0000 0000 0011
#define PLLNODIV    1 // 1      [31] No PLL divide before MCO 
#define MCOPRE      0 // 000    [30:28] MCO divide by 1
#define MCO         4 // 100    [26:24] SYSCLK
#define PLLMUL      2 // 0010   [21:18] x4
#define PLLSRC      0 // 00     [16:15] HSI/2
#define SW          2 // 10     [1:0] PLL as system clk

void set_clock();

#endif