/*
 * FMI_Priv.h
 *
 *  Created on: Sep 4, 2023
 *      Author: adham
 */

#ifndef MCAL_FMI_FMI_PRIV_H_
#define MCAL_FMI_FMI_PRIV_H_

#include"../../INC/STD_TYPES.h"

/***************************Base Address************************/
#define FMI_BASE_ADDR	0x40023C00
/****************************************************************/
#define FMI_KEY1	0x45670123
#define FMI_KEY2    0xCDEF89AB
/****************************************************************/

typedef struct
{
	volatile uint32_t   ACR   ;
	volatile uint32_t  KEYR   ;
	volatile uint32_t  OPTKEYR;
	volatile uint32_t   SR    ;
	volatile uint32_t   CR    ;
	volatile uint32_t   OPTCR ;
}FMI_Registers_t;

#define FMI   ((volatile FMI_Registers_t*)(FMI_BASE_ADDR))

#endif /* MCAL_FMI_FMI_PRIV_H_ */
