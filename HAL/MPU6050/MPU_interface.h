#ifndef MPU6050_H
#define MPU6050_H

#define MPU6050_ADDRESS 0x68 /* Change as needed for your setup , Depending on AD0 
If AD0 is LOW (GND): The I2C address is 0x68 (7-bit address).
If AD0 is HIGH (VCC): The I2C address is 0x69 (7-bit address).*/

/*MPU6050 Register Addresses From Internet*/

#define MPU6050_REG_PWR_MGMT_1 0x6B
#define MPU6050_REG_ACCEL_XOUT_H 0x3B
#define MPU6050_REG_ACCEL_XOUT_L 0x3C
#define MPU6050_REG_ACCEL_YOUT_H 0x3D
#define MPU6050_REG_ACCEL_YOUT_L 0x3E
#define MPU6050_REG_ACCEL_ZOUT_H 0x3F
#define MPU6050_REG_ACCEL_ZOUT_L 0x40
#define MPU6050_REG_GYRO_XOUT_H 0x43
#define MPU6050_REG_GYRO_XOUT_L 0x44
#define MPU6050_REG_GYRO_YOUT_H 0x45
#define MPU6050_REG_GYRO_YOUT_L 0x46
#define MPU6050_REG_GYRO_ZOUT_H 0x47
#define MPU6050_REG_GYRO_ZOUT_L 0x48


void MPU6050_init(void);
void MPU6050_write_reg(uint8 reg_addr, uint8 data);
static uint8 MPU6050_read_reg(uint8 reg_addr);
/*Use it to read all data*/
void MPU6050_read_all_data(uint16* ax, uint16* ay, uint16* az, uint16* gx, uint16* gy, uint16* gz);
#endif

