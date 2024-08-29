#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "I2C_reg.h"
#include "I2C_interface.h"

void I2C_init(void) {
    // Set bit rate
    uint8 prescaler = 1; // Prescaler is 1
    TWBR = ((Frequency_CPU / SCL_CLOCK) - 16) / (2 * prescaler);  //Most Likely 72
    TWSR = 0; // Prescaler = 1
}


void I2C_start(void) {
    /*Send start condition*/
    SET_BIT(TWCR , TWCR_TWSTA);
    SET_BIT(TWCR , TWCR_TWEN);
    SET_BIT(TWCR , TWCR_TWINT);

    while (!(GET_BIT(TWCR , TWCR_TWINT))); /* Wait for completion */
}

void I2C_stop(void) {
  /* Send stop condition  */
      SET_BIT(TWCR , TWCR_TWSTA);
      SET_BIT(TWCR , TWCR_TWEN);
      SET_BIT(TWCR , TWCR_TWINT);

    while ((GET_BIT(TWCR , TWCR_TWINT))); /*Wait for stop condition to be executed */
}


void I2C_write(uint8 Copy_u8data) {
    TWDR = 	Copy_u8data;               // Load data into the TWI data register

    SET_BIT(TWCR, TWCR_TWINT);      // Clear TWINT flag to start the data transmission
    SET_BIT(TWCR, TWCR_TWEN);       // Ensure TWI module is enabled

    while (!GET_BIT(TWCR, TWCR_TWINT)); // Wait for transmission to complete
}




uint8 I2C_read_ack(void) {
    // Enable TWI, clear TWINT flag, and enable acknowledgment
    SET_BIT(TWCR, TWCR_TWEN);    // Ensure TWI module is enabled
    SET_BIT(TWCR, TWCR_TWINT);   // Clear TWINT flag to start the data reception
    SET_BIT(TWCR, TWCR_TWEA);    // Enable acknowledgment for the next byte

    // Wait for data reception to complete
    while (!GET_BIT(TWCR, TWCR_TWINT)); // Wait until TWINT is set

    // Return received data
    return TWDR; // Read data from TWI data register
}


uint8 I2C_read_nack(void) {
    // Enable TWI, clear TWINT flag, and do not send acknowledgment
	CLR_BIT(TWCR, TWCR_TWEA);
    SET_BIT(TWCR, TWCR_TWEN);    // Ensure TWI module is enabled
    SET_BIT(TWCR, TWCR_TWINT);   // Clear TWINT flag to start the data reception

    // Wait for data reception to complete
    while (!GET_BIT(TWCR, TWCR_TWINT)); // Wait until TWINT is set

    // Return received data
    return TWDR; // Read data from TWI data register
}


