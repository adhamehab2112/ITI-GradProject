/*
 * STK_Private.h
 *
 *  Created on: Aug 15, 2023
 *      Author: Adham Ehab
 */

#ifndef MCAL_STK_STK_PRIVATE_H_
#define MCAL_STK_STK_PRIVATE_H_

#include "../../INC/STD_TYPES.h"

/************************STK Registers**********************/
typedef struct
{
	volatile uint32_t STK_CTRL 		;
	volatile uint32_t STK_LOAD		;
	volatile uint32_t STK_VAL		;
	volatile uint32_t STK_CALIB		;

}STK_Registers_t;

/************************Base addresses***********************/
#define STK_BASE 					0xE000E010

/**********************Instant***********************/
#define STK 						((volatile STK_Registers_t*)STK_BASE)

/**********************Macros*********************/

/*Control Register Bits*/
#define ENABLE				0
#define TICKINT				1
#define CLKSOURCE			2
#define COUNTFLAG			16


#endif /* MCAL_STK_STK_PRIVATE_H_ */
