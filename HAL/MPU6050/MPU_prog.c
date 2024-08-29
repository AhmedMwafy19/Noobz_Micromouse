#include "STD_TYPES.h"
#include "ErrorState.h"

#include "I2C_interface.h"
#include "MPU_interface.h"
void MPU6050_init(void) {
    // Wake up the MPU6050 (set PWR_MGMT_1 register to 0x00)
    MPU6050_write_reg(MPU6050_REG_PWR_MGMT_1, 0x00);
}

void MPU6050_write_reg(uint8 reg_addr, uint8 data) {
    I2C_start();                           // Start I2C communication
    I2C_write(MPU6050_ADDRESS << 1);      // Send MPU6050 address with write flag (0)
    I2C_write(reg_addr);                  // Send register address
    I2C_write(data);                     // Send data to register
    I2C_stop();                            // Stop I2C communication
}

static uint8 MPU6050_read_reg(uint8 reg_addr) {
    uint8 data;

    I2C_start();                           // Start I2C communication
    I2C_write(MPU6050_ADDRESS << 1);      // Send MPU6050 address with write flag (0)
    I2C_write(reg_addr);                  // Send register address
    I2C_start();                           // Re-start I2C communication for read
    I2C_write((MPU6050_ADDRESS << 1) | 1); // Send MPU6050 address with read flag (1)
    data = I2C_read_nack();               // Read data with NACK
    I2C_stop();                            // Stop I2C communication

    return data;
}

void MPU6050_read_all_data(uint16* ax, uint16* ay, uint16* az, uint16* gx, uint16* gy, uint16* gz) {
    uint8 high_byte, low_byte;

    // Read accelerometer X-axis
    high_byte = MPU6050_read_reg(MPU6050_REG_ACCEL_XOUT_H);
    low_byte = MPU6050_read_reg(MPU6050_REG_ACCEL_XOUT_L);
    *ax = (high_byte << 8) | low_byte;

    // Read accelerometer Y-axis
    high_byte = MPU6050_read_reg(MPU6050_REG_ACCEL_YOUT_H);
    low_byte = MPU6050_read_reg(MPU6050_REG_ACCEL_YOUT_L);
    *ay = (high_byte << 8) | low_byte;

    // Read accelerometer Z-axis
    high_byte = MPU6050_read_reg(MPU6050_REG_ACCEL_ZOUT_H);
    low_byte = MPU6050_read_reg(MPU6050_REG_ACCEL_ZOUT_L);
    *az = (high_byte << 8) | low_byte;

    // Read gyroscope X-axis
    high_byte = MPU6050_read_reg(MPU6050_REG_GYRO_XOUT_H);
    low_byte = MPU6050_read_reg(MPU6050_REG_GYRO_XOUT_L);
    *gx = (high_byte << 8) | low_byte;

    // Read gyroscope Y-axis
    high_byte = MPU6050_read_reg(MPU6050_REG_GYRO_YOUT_H);
    low_byte = MPU6050_read_reg(MPU6050_REG_GYRO_YOUT_L);
    *gy = (high_byte << 8) | low_byte;

    // Read gyroscope Z-axis
    high_byte = MPU6050_read_reg(MPU6050_REG_GYRO_ZOUT_H);
    low_byte = MPU6050_read_reg(MPU6050_REG_GYRO_ZOUT_L);
    *gz = (high_byte << 8) | low_byte;
}
