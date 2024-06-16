#include <gpio.h>

void set_gpio() {
    GPIOA_MODER     =   0xa8020001;    // PA8 -> AF(MCO), PA0 -> Output
}