/*
 * STK.c
 *
 *  Created on: Aug 15, 2023
 *      Author: Adham Ehab
 */

#include "STK_Private.h"
#include "STK_Config.h"
#include "STK_Interface.h"

/****************************Global Variables*****************************/
static void (*GlobalcallBackPtr)(void) = NULL ;

/******************************APIs Implementation************************/
void MCAL_SYSTK_voidInit(void)
{
#if	STK_CLK_SOURCE==STK_CLK_SOURCE_AHB
	SET_BIT(STK->STK_CTRL,CLKSOURCE);
#elif  STK_CLK_SOURCE==STK_CLK_SOURCE_AHB_DIV_8
	CLR_BIT(STK->STK_CTRL,CLKSOURCE);
#endif

#if	STK_INT_SOURCE==STK_INT_SOURCE_ENABLE
	SET_BIT(STK->STK_CTRL,TICKINT);
#elif  STK_INT_SOURCE==STK_INT_SOURCE_DISABLE
	CLR_BIT(STK->STK_CTRL,TICKINT);

#endif
}

void MCAL_SYSTK_voidSetPreload(uint32_t Value)
{

	/*
	 * 	load -> Preloadvalue
		value = 0
		enable SYSTIK
	 */
	STK->STK_LOAD = Value;			/* load reload value */
	STK->STK_VAL  = 0;				/* clear value register */
	SET_BIT(STK->STK_CTRL,ENABLE);	/* enable STK */

}

uint32_t  MCAL_STK_u32GetRemaining(void)					/* Get remaining time */
{
	return STK->STK_VAL;
}
uint32_t  MCAL_STK_u32GetElapsed(void)					/* Get elapsed time */
{
	return (STK->STK_LOAD - STK->STK_VAL);
}
uint8_t	  MCAL_STK_u8ReadFlag(void)
{
	return GET_BIT(STK->STK_CTRL,COUNTFLAG);
}

void MCAL_STK_voidDelayUsec(uint32_t DelayUsec) 		/* Delay in microsecond */
{
	MCAL_STK_voidInit();
	uint32_t TICKn;
#if	STK_CLK_SOURCE==STK_CLK_SOURCE_AHB
	TICKn=(DelayUsec * F_CPU_MHZ);
#elif  STK_CLK_SOURCE==STK_CLK_SOURCE_AHB_DIV_8
	TICKn=(DelayUsec * (F_CPU_MHZ/8));
#endif
	STK->STK_VAL  = 0;				/* clear value register */
	STK->STK_LOAD = TICKn;			/* load reload value */
	while(!MCAL_STK_u8ReadFlag());
	CLR_BIT(STK->STK_CTRL,ENABLE);	/*Stop Timer */

}
void	  MCAL_STK_voidDelayMsec(uint32_t DelayMsec)		/* Delay in milliseconds */
{
	MCAL_STK_voidInit();
	uint32_t TICKn;
#if	STK_CLK_SOURCE==STK_CLK_SOURCE_AHB
	TICKn=(DelayMsec * F_CPU_MHZ * 1000);
#elif  STK_CLK_SOURCE==STK_CLK_SOURCE_AHB_DIV_8
	TICKn=(DelayMsec * (F_CPU_MHZ/8)*1000);
#endif
	STK->STK_VAL  = 0;				/* clear value register */
	STK->STK_LOAD = TICKn;			/* load reload value */
	while(!MCAL_STK_u8ReadFlag());
	CLR_BIT(STK->STK_CTRL,ENABLE); 	/*Stop Timer */

}

void 	  MCAL_STK_voidCallBack(void(*ptr)(void)) 			/* CallBack Function */
{
	GlobalcallBackPtr = ptr ;
}

void MSTK_vSetInterval_periodic (uint32_t A_u32Ticks, void (*CallbackFunction) (void))
{
	/* 0- set Callback function */
		GlobalcallBackPtr = CallbackFunction;
		/* 1- reset timer value */
		STK->STK_VAL = 0;
		/* 2- Load timer with Value */
		STK->STK_LOAD = A_u32Ticks;
		/*3- Start the timer */
		SET_BIT(STK->STK_CTRL, ENABLE);
}

/***********************IRQ Handler***********************/
void SysTick_Handler(void)
{
	if(GlobalcallBackPtr != NULL)
	{
		GlobalcallBackPtr();
	}

}
