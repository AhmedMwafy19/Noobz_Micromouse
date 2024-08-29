#ifndef DCMOTOR_INTERFACE_H
#define DCMOTOR_INTERFACE_H

typedef enum{
	Timer0 ,Timer2
}EN_PWM;
typedef struct{
	uint8 Connection_Port; /*Which Port Motor Is connected to*/
	uint8 Pin1Connection; /*When this pin is high , Motor rotates cw*/
	uint8 Pin2Connection;/*When this pin is high , Motor rotates ccw*/
	EN_PWM PWM_timer; /*Pick from Timer0 &Timer2*/
}MOTOR_DIRECTION_CONTROL;
/*Example for Configuring a motor in your application
MOTOR_CONNECTIONS Motor1 = {
	.Connection_Port = DIO_u8PORTC,
	.Pin1Connection = DIO_u8PIN0,
	.Pin2Connection = DIO_u8PIN1 ,
	.PWM_timer = Timer0
};*/

void DCMotor_Init(void);

uint8 MOTOR_u8RotateClockWise(MOTOR_DIRECTION_CONTROL * Copy_pstructMotor, uint8 Copy_u8Speed);
uint8 MOTOR_u8RotateCounterClockWise(MOTOR_DIRECTION_CONTROL * Copy_pstructMotor,uint8 Copy_u8Speed);
uint8 MOTOR_u8Stop(MOTOR_DIRECTION_CONTROL * Copy_pstructMotor);

#endif
