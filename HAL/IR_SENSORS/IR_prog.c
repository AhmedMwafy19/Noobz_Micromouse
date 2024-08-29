#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "PORT_interface.h"
#include "IR_interface.h"

uint8 IR_u8ReadDIGITALDistance(IR_CONFIGURATION_DIGITAL * Copy_pstructIR){
	uint8 Local_u8Reading ;
	DIO_u8ReadPinValue(Copy_pstructIR -> IR_PORT , Copy_pstructIR -> IR_PIN , &Local_u8Reading);
	if(Local_u8Reading == DIO_u8PINVALUE_LOW){ /*Low is because it sends low if it detects obstacle*/
		return OBSTACLE_DETECTED ;
	}
	else {
		return NO_OBSTACLE_DETECTED ;
	}
}

/*
f32 IR_u16ReadSingleDistance(IR_CONFIGURATION_ANALOG * Copy_pstructIR){
	uint8 Local_u8Reading;
	f32 Local_f32Voltage , Local_f32Distance ;
	Local_u8Reading = ADC_u8GetChannelReading(Copy_pstructIR->IR_CHANNEL);
	Local_f32Voltage = (Local_u8Reading * 255.0 ) / 5 ; //Because we use AVCC as reference so 5V & 8 bit resolution then 255
	Distance = TEST TO GET THE EQUATION

	return Local_f32Distance;

}
f32 IR_u16ReadAverageDistance(IR_CONFIGURATION_ANALOG * Copy_pstructIR , uint8 Copy_u8NUmOfReadings){
	uint8 Local_u8Reading ,Local_u8LoopCounter;
	uint16 Local_u16Sum = 0;
	f32 Local_f32Voltage , Local_f32Distance ;
	for(Local_u8LoopCounter=0;Local_u8LoopCounter<Copy_u8NUmOfReadings;Local_u8LoopCounter++){
	Local_u16Sum += ADC_u8GetChannelReading(Copy_pstructIR->IR_CHANNEL);
	}
	Local_u8Reading = (uint8) (Local_u16Sum / Copy_u8NUmOfReadings) ;
	Local_f32Voltage = (Local_u8Reading * 255.0 ) / 5 ; //Because we use AVCC as reference so 5V & 8 bit resolution then 255
	Distance = TEST TO GET THE EQUATION

	return Local_f32Distance;

}
*/
