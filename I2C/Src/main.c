/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32 VS Code Extension
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <rcc.h>
#include <gpio.h>
#include <i2c.h>

#define MPU6050_ADDRESS 0x68
#define MPU6050_PWR_MGMT_1 0x6B
#define MPU6050_ACCEL_XOUT_H 0x3B

uint8_t data[14];
int16_t accel_x, accel_y, accel_z;
int16_t temp;
int16_t gyro_x, gyro_y, gyro_z;

int main(void) {
    set_clock();
    set_gpio();
    init_i2c1();

    i2c1_write(MPU6050_ADDRESS, MPU6050_PWR_MGMT_1, 0x00); // Init MPU6050

    /* Loop forever */
	// for(int i=0; i < 1; i++) {
    //     i2c1_read(MPU6050_ADDRESS, MPU6050_ACCEL_XOUT_H, data, 6);
    //     accel_x = (data[0] << 8) | data[1];
    //     accel_y = (data[2] << 8) | data[3];
    //     accel_z = (data[4] << 8) | data[5];
    //     temp    = (data[6] << 8) | data[7];
    //     gyro_x  = (data[8] << 8) | data[9];
    //     gyro_y  = (data[10] << 8) | data[11];
    //     gyro_z  = (data[12] << 8) | data[13];
    // }
    while(1);
}
