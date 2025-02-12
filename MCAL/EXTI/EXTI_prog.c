#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ErrorState.h"

#include "EXTI_prv.h"
#include "EXTI_reg.h"
#include "EXTI_interface.h"
#include "EXTI_cfg.h"

static void (*Copy_funcptr[3])(void) = {0};
void EXTI_voidINIT(void){
#if INT0_SENSE_CTRL == EXTI_LOW_LEVEL
	CLR_BIT(MCUCR , MCUCR_ISC00);
	CLR_BIT(MCUCR , MCUCR_ISC01);
#elif INT0_SENSE_CTRL == EXTI_ON_CHANGE
	SET_BIT(MCUCR , MCUCR_ISC00);
	CLR_BIT(MCUCR , MCUCR_ISC01);
#elif INT0_SENSE_CTRL == EXTI_FALLING_EDGE
	CLR_BIT(MCUCR , MCUCR_ISC00);
	SET_BIT(MCUCR , MCUCR_ISC01);
#elif INT0_SENSE_CTRL == EXTI_RISING_EDGE
	SET_BIT(MCUCR , MCUCR_ISC00);
	SET_BIT(MCUCR , MCUCR_ISC01);
#else
#error WRONG CONFIGURATION
#endif


#if INT1_SENSE_CTRL == EXTI_LOW_LEVEL
	CLR_BIT(MCUCR , MCUCR_ISC10);
	CLR_BIT(MCUCR , MCUCR_ISC11);
#elif INT1_SENSE_CTRL == EXTI_ON_CHANGE
	SET_BIT(MCUCR , MCUCR_ISC10);
	CLR_BIT(MCUCR , MCUCR_ISC11);
#elif INT1_SENSE_CTRL == EXTI_FALLING_EDGE
	CLR_BIT(MCUCR , MCUCR_ISC10);
	SET_BIT(MCUCR , MCUCR_ISC11);
#elif INT1_SENSE_CTRL == EXTI_RISING_EDGE
	SET_BIT(MCUCR , MCUCR_ISC10);
	SET_BIT(MCUCR , MCUCR_ISC11);
#else
#error WRONG CONFIGURATION
#endif




#if INT2_SENSE_CTRL == EXTI_FALLING_EDGE
	CLR_BIT(MCUCSR , MCUCSR_ISC2);
#elif INT2_SENSE_CTRL == EXTI_RISING_EDGE
	SET_BIT(MCUCSR , MCUCSR_ISC2);
#else
#error WRONG CONFIGURATION
#endif


#if INT0_INIT_STATE == ENABLED
	SET_BIT(GICR , GICR_INT0);
#elif INT0_INIT_STATE == DISABLED
	CLR_BIT(GICR , GICR_INT0);
#else
#error Wrong Configuration
#endif


#if INT1_INIT_STATE == ENABLED
	SET_BIT(GICR , GICR_INT1);
#elif INT1_INIT_STATE == DISABLED
	CLR_BIT(GICR , GICR_INT1);
#else
#error Wrong Configuration
#endif


#if INT2_INIT_STATE == ENABLED
	SET_BIT(GICR , GICR_INT2);
#elif INT2_INIT_STATE == DISABLED
	CLR_BIT(GICR , GICR_INT2);
#else
#error Wrong Configuration
#endif
}

uint8 EXTI_u8SetSenseCtrl(INT_CHANNEL Copy_IntChannel , SenseCtrl Copy_SenseCtrl){
	uint8 Local_u8ErrorState = OK ;
	if(Copy_IntChannel == INT0){
		switch(Copy_SenseCtrl)
		{
		case LOW_LEVEL: CLR_BIT(MCUCR , MCUCR_ISC00); CLR_BIT(MCUCR , MCUCR_ISC01); break ;
		case ON_CHANGE: SET_BIT(MCUCR , MCUCR_ISC00); CLR_BIT(MCUCR , MCUCR_ISC01); break ;
		case FALLING_EDGE: CLR_BIT(MCUCR , MCUCR_ISC00); SET_BIT(MCUCR , MCUCR_ISC01); break ;
		case RISING_EGDE: SET_BIT(MCUCR , MCUCR_ISC00); SET_BIT(MCUCR , MCUCR_ISC01); break ;
		default : Local_u8ErrorState = NOK ; break;

		}
	}
	else if(Copy_IntChannel == INT1){
		switch(Copy_SenseCtrl)
		{
		case LOW_LEVEL: CLR_BIT(MCUCR , MCUCR_ISC10); CLR_BIT(MCUCR , MCUCR_ISC11); break ;
		case ON_CHANGE: SET_BIT(MCUCR , MCUCR_ISC10); CLR_BIT(MCUCR , MCUCR_ISC11); break ;
		case FALLING_EDGE: CLR_BIT(MCUCR , MCUCR_ISC10); SET_BIT(MCUCR , MCUCR_ISC11); break ;
		case RISING_EGDE: SET_BIT(MCUCR , MCUCR_ISC10); SET_BIT(MCUCR , MCUCR_ISC11); break ;
		default : Local_u8ErrorState = NOK ; break;

		}
	}

	else if(Copy_IntChannel == INT2){
		switch(Copy_SenseCtrl)
		{
		case FALLING_EDGE: CLR_BIT(MCUCSR , MCUCSR_ISC2);  break ;
		case RISING_EGDE: SET_BIT(MCUCSR , MCUCSR_ISC2);  break ;
		default : Local_u8ErrorState = NOK ; break;

		}
	}
	else
		{
		Local_u8ErrorState = NOK ;
		}

	return Local_u8ErrorState;
}

uint8 EXTI_u8EnableIntChannel(INT_CHANNEL Copy_IntChannel){
	uint8 Local_u8ErrorState = OK;
	switch(Copy_IntChannel)
	{
	case INT0: SET_BIT(GICR,GICR_INT0); break;
	case INT1: SET_BIT(GICR,GICR_INT1); break;
	case INT2: SET_BIT(GICR,GICR_INT2); break;
	default : Local_u8ErrorState = NOK; break;
	}

	return Local_u8ErrorState;
}


uint8 EXTI_u8DisableIntChannel(INT_CHANNEL Copy_IntChannel){
	uint8 Local_u8ErrorState = OK;
	switch(Copy_IntChannel)
	{
	case INT0: CLR_BIT(GICR,GICR_INT0); break;
	case INT1: CLR_BIT(GICR,GICR_INT1); break;
	case INT2: CLR_BIT(GICR,GICR_INT2); break;
	default : Local_u8ErrorState = NOK; break;
	}

	return Local_u8ErrorState;
}

uint8 EXTI_u8SetCallBack(uint8 Copy_u8Channel , void(*Funcptr)(void)){
	uint8 Local_u8ErrorState =OK;
	if(Funcptr != NULL){
		Copy_funcptr[Copy_u8Channel] = Funcptr ;
	}
	else {
		Local_u8ErrorState = NULL_PTR_ERR;
	}

	return Local_u8ErrorState;
}

__attribute__((signal)) void __vector_1 (void);
void __vector_1 (void){
if(Copy_funcptr[0] != NULL){
	Copy_funcptr[0]();
}
}

__attribute__((signal)) void __vector_2 (void);
void __vector_2 (void){
	if(Copy_funcptr[1] != NULL){
		Copy_funcptr[1]();
	}
}

__attribute__((signal)) void __vector_3 (void);
void __vector_3 (void){
	if(Copy_funcptr[2] != NULL){
		Copy_funcptr[2]();
	}
}
