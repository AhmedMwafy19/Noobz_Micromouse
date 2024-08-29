#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H

/*Set The MC serial clock & desired frequency for I2C*/
#define Frequency_CPU 16000000UL
#define SCL_CLOCK 100000UL


void I2C_init(void);
void I2C_start(void);
void I2C_stop(void);
void I2C_write(uint8 Copy_u8data);
uint8 I2C_read_ack(void);
uint8 I2C_read_nack(void);

#endif
