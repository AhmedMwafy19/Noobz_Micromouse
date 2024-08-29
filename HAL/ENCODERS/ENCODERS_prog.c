#include "STD_TYPES.h"

#include "ENCODERS_interface.h"
#include "DIO_interface.h"
#include "GIE_interface.h"
#include "EXTI_interface.h"

ENCODER_CONFIGURATION ENCODER1 = {
		.Encoder_PORT = DIO_u8PORTC ,
		.Encoder_PIN_A = DIO_u8PIN5 ,   //INT0
		.Encoder_PIN_B = DIO_u8PIN4
};
ENCODER_CONFIGURATION ENCODER2 = {
		.Encoder_PORT = DIO_u8PORTB ,
		.Encoder_PIN_A = DIO_u8PIN5 ,  //INT1
		.Encoder_PIN_B = DIO_u8PIN4
};
volatile uint32 Encoder_u32LeftTicks = 0 ;
volatile uint32 Encoder_u32Rightticks = 0 ;


void ENCODERS_voidInit(void){
	GIE_voidEnableGeneralInterrupts();
	EXTI_u8SetSenseCtrl(INT0 , ON_CHANGE);
	EXTI_u8SetSenseCtrl(INT1 , ON_CHANGE);
	EXTI_u8EnableIntChannel(INT0);
	EXTI_u8EnableIntChannel(INT1);

	EXTI_u8SetCallBack(INT0 , &ENCODER_voidRightTicks);
	EXTI_u8SetCallBack(INT1 , &ENCODER_voidLeftTicks);
}
static void ENCODER_voidRightTicks(void){
	uint8 Local_u8PinStateB ,Local_u8PinStateA ;
	DIO_u8ReadPinValue(ENCODER1.Encoder_PORT,ENCODER1.Encoder_PIN_A,&Local_u8PinStateA);
	DIO_u8ReadPinValue(ENCODER1.Encoder_PORT,ENCODER1.Encoder_PIN_B,&Local_u8PinStateB);
	if (Local_u8PinStateA != Local_u8PinStateB) {
	      Encoder_u32Rightticks++;
	    } else {
	      Encoder_u32Rightticks--;
	    }
}
static void ENCODER_voidLeftTicks(void){
	uint8 Local_u8PinStateB ,Local_u8PinStateA ;
	DIO_u8ReadPinValue(ENCODER2.Encoder_PORT,ENCODER2.Encoder_PIN_A,&Local_u8PinStateA);
	DIO_u8ReadPinValue(ENCODER2.Encoder_PORT,ENCODER2.Encoder_PIN_B,&Local_u8PinStateB);
	if (Local_u8PinStateA != Local_u8PinStateB) {
	      Encoder_u32LeftTicks++;
	    } else {
	    	Encoder_u32LeftTicks--;
	    }
}

