#ifndef ENCODERS_INTERFACE_H
#define ENCODERS_INTERFACE_H


typedef struct{
	uint8 Encoder_PORT ;
	uint8 Encoder_PIN_B ;
	uint8 Encoder_PIN_A ;

}ENCODER_CONFIGURATION;


void ENCODERS_voidInit(void);
static void ENCODER_voidRightTicks(void);
static void ENCODER_voidLeftTicks(void);



#endif
