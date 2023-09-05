/*
 * STK_Config.h
 *
 *  Created on: Aug 15, 2023
 *      Author: Adham Ehab
 */

#ifndef MCAL_STK_STK_CONFIG_H_
#define MCAL_STK_STK_CONFIG_H_


#define STK_CLK_SOURCE			 STK_CLK_SOURCE_AHB_DIV_8	/*@ref: STK_CLK_SOURCE_define*/
#define STK_INT_SOURCE			 STK_INT_SOURCE_ENABLE		/*@ref: STK_INT_SOURCE_define*/


/*@ref: STK_CLK_SOURCE_define*/
#define STK_CLK_SOURCE_AHB			0
#define STK_CLK_SOURCE_AHB_DIV_8	1

/*@ref: STK_INT_SOURCE_define*/
#define STK_INT_SOURCE_DISABLE		0
#define STK_INT_SOURCE_ENABLE		1

#define F_CPU_MHZ					16
#endif /* MCAL_STK_STK_CONFIG_H_ */
