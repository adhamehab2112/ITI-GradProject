/*
 * STK_Interface.h
 *
 *  Created on: Aug 15, 2023
 *      Author: Adham Ehab
 */

#ifndef MCAL_STK_STK_INTERFACE_H_
#define MCAL_STK_STK_INTERFACE_H_

#include  "../../INC/Macros.h"
#include "../../INC/STD_TYPES.h"

#define F_CPU_MHZ 16


/**********************APIs Supported by "MCAL NVIC DRIVER"**********************/
void	  MCAL_SYSTK_voidInit(void);						/* Initializing  SYSTK */
void 	  MCAL_SYSTK_voidSetPreload(uint32_t Value);				/* Set Load value */
uint32_t  MCAL_STK_u32GetRemaining(void);					/* Get remaining time */
uint32_t  MCAL_STK_u32GetElapsed(void);						/* Get elapsed time */
uint8_t	  MCAL_STK_u8ReadFlag(void);						/* Check Flag */
void	  MCAL_STK_voidDelay_us(uint32_t DelayUsec) ;		/* Delay in microsecond */
void	  MCAL_STK_voidDelay_ms(uint32_t DelayMsec);		/* Delay in milliseconds */
void 	  MCAL_STK_voidCallBack(void(*ptr)(void));			/* CallBack Function */
void 	  MSTK_vSetInterval_periodic (uint32_t A_u32Ticks, void (*CallbackFunction) (void));

#endif /* MCAL_STK_STK_INTERFACE_H_ */

