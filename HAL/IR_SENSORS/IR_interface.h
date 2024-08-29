#ifndef IR_INTERFACE_H
#define IR_INTERFACE_H
#define OBSTACLE_DETECTED 1u
#define NO_OBSTACLE_DETECTED 2u


typedef struct{
	uint8 IR_PORT ;  //pick the port you're connecting the sensor to it
	uint8 IR_PIN ;   //pick the pin you're connecting the sensor to it
}IR_CONFIGURATION_DIGITAL; /*For configuring Digital IR*/

/*
typedef struct{
	uint8 IR_CHANNEL ; //Pick the ADC channel the sensor is connected to it
}IR_CONFIGURATION_ANALOG; //For configuring Analog IR

//When you add a sensor add it to main


*/
uint8 IR_u8ReadDIGITALDistance(IR_CONFIGURATION_DIGITAL * Copy_pstructIR); /*For digital reading*/
//f32 IR_u16ReadSingleDistance(IR_CONFIGURATION_ANALOG * Copy_pstructIR); /*Get the reading in the calling moment*/
//f32 IR_u16ReadAverageDistance(IR_CONFIGURATION_ANALOG * Copy_pstructIR , uint8 Copy_u8NUmOfReadings);/*Get the Average of A number
//of readings*/

#endif
