#include "STD_TYPES.h"
#include "ErrorState.h"
#include "TIMER_interface.h"
#include "DIO_interface.h"
#include "DCMOTOR_interface.h"


void DCMotor_Init(void) {
    // Initialize Timer0 and Timer2 for PWM generation for Motor1 and Motor2
    TIMER0_cfg_t timer0Config;
    TIMER2_cfg_t timer2Config;

    // Configure Timer0 for Motor1
    timer0Config.WFG_Mode = T0_FAST_PWM;
    timer0Config.Prescaler = TIMER_NO_PRESCALER;
    timer0Config.Out_HW_Opt = T0_OC0_FAST_PWM_SETON_COM_CLRON_TOP;
    timer0Config.INT_State = T0_INT_DISABLED;
    TIMER0_u8Init(&timer0Config);

    // Configure Timer2 for Motor2
    timer2Config.WFG_Mode = T2_FAST_PWM;
    timer2Config.Prescaler = TIMER_NO_PRESCALER;
    timer2Config.Out_HW_Opt = T2_OC2_FAST_PWM_SETON_COM_CLRON_TOP;
    timer2Config.INT_State = T2_INT_DISABLED;
    TIMER2_u8Init(&timer2Config);

    // Set initial PWM duty cycle for both motors
    TIMER0_voidSetCompareValue(0); // Motor1
    TIMER2_voidSetCompareValue(0); // Motor2
}




uint8 MOTOR_u8RotateClockWise(MOTOR_DIRECTION_CONTROL * Copy_pstructMotor,uint8 Copy_u8Speed){
	uint8 Local_u8ErrorState = OK;
	if(Copy_pstructMotor != NULL){/*Checking The validity of the pointer*/
		/*Start with low to protect the connection since it's h brigde it could cause the cct. to burn*/
		DIO_u8SetPinValue(Copy_pstructMotor -> Connection_Port , Copy_pstructMotor -> Pin2Connection,DIO_u8PINVALUE_LOW);
		DIO_u8SetPinValue(Copy_pstructMotor -> Connection_Port , Copy_pstructMotor -> Pin1Connection,DIO_u8PINVALUE_HIGH);
		/*Setting Pin1 Value High & pin2 Value Low for rotating cw*/

		/*For PWM*/
		if(Copy_pstructMotor -> PWM_timer == Timer0){
			TIMER0_voidSetCompareValue(Copy_u8Speed);
		}
		else if(Copy_pstructMotor->PWM_timer == Timer2){
			TIMER2_voidSetCompareValue(Copy_u8Speed);
		}
		else {
			Local_u8ErrorState= NOK ;
		}
		/*Setting Pin1 Value High & pin2 Value Low for rotating cw*/
	}
	else {
		Local_u8ErrorState =NULL_PTR_ERR;
	}

	return Local_u8ErrorState;
}
uint8 MOTOR_u8RotateCounterClockWise(MOTOR_DIRECTION_CONTROL * Copy_pstructMotor , uint8 Copy_u8Speed){
	uint8 Local_u8ErrorState = OK;
	if(Copy_pstructMotor != NULL){/*Checking The validity of the pointer*/
			/*Start with low to protect the connection since it's h brigde it could cause the cct. to burn*/
			DIO_u8SetPinValue(Copy_pstructMotor -> Connection_Port , Copy_pstructMotor -> Pin1Connection,DIO_u8PINVALUE_LOW);
			DIO_u8SetPinValue(Copy_pstructMotor -> Connection_Port , Copy_pstructMotor -> Pin2Connection,DIO_u8PINVALUE_HIGH);
			/*Setting Pin2 Value High & pin1 Value Low for rotating ccw*/

			/*For PWM*/
			if(Copy_pstructMotor -> PWM_timer == Timer0){
				TIMER0_voidSetCompareValue(Copy_u8Speed);
			}
			else if(Copy_pstructMotor->PWM_timer == Timer2){
				TIMER2_voidSetCompareValue(Copy_u8Speed);
			}
			else {
				Local_u8ErrorState= NOK ;
			}
		}
		else {
			Local_u8ErrorState =NULL_PTR_ERR;
		}
	return Local_u8ErrorState;
}
uint8 MOTOR_u8Stop(MOTOR_DIRECTION_CONTROL * Copy_pstructMotor){
	uint8 Local_u8ErrorState = OK;
	if(Copy_pstructMotor != NULL){/*Checking The validity of the pointer*/
			/*THis couldn't stop immediately if the hardware connection doesn't support it (No Not gate)*/
			DIO_u8SetPinValue(Copy_pstructMotor -> Connection_Port , Copy_pstructMotor -> Pin2Connection,DIO_u8PINVALUE_LOW);
			DIO_u8SetPinValue(Copy_pstructMotor -> Connection_Port , Copy_pstructMotor -> Pin1Connection,DIO_u8PINVALUE_LOW);
			TIMER0_voidSetCompareValue(0);
			TIMER2_voidSetCompareValue(0);
	}
		else {
			Local_u8ErrorState =NULL_PTR_ERR;
		}
	return Local_u8ErrorState;
}

