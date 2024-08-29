#ifndef I2C_REG_H
#define I2C_REG_H
#define TWCR    *((volatile uint8 *) 0x56)             /*TWI Control Register */
#define TWCR_TWINT 7u  /*TWI INTERRUPT FLAG*/
#define TWCR_TWEA   6u    /*TWI Enable Acknowledge Bit*/
#define TWCR_TWSTA  5u     /* TWI START Condition Bit  */
#define TWCR_TWSTO  4u     /*TWI STOP Condition Bit*/
#define TWCR_TWWC   3u      /* TWI Write Collision Flag */
#define TWCR_TWEN	2u       /* TWI Enable Bit */
#define TWCR_Res	1u			/* Reserved Bit*/
#define TWCR_TWIE   0u        /* TWI Interrupt Enable */
/*--------------------------------------------------------------------------------------------------------------------------------------*/
#define TWSR   *((volatile uint8 *) 0x21 )                                         /*  TWI Status Register */ 
/*--------------------------------------------------------------------------------------------------------------------------------------*/
#define TWDR   *((volatile uint8 *) 0x23 ) 																 /* TWI Data Register*/
/*--------------------------------------------------------------------------------------------------------------------------------------*/
#define TWAR   *((volatile uint8 *) 0x22 ) /* TWI (Slave) Address Register */
/*--------------------------------------------------------------------------------------------------------------------------------------*/
#define TWBR   *((volatile uint8 *) 0x20 )                               /*TWI Bit Rate Register */

#endif
