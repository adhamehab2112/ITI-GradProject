/*
 * FMI_Interface.h
 *
 *  Created on: Sep 4, 2023
 *      Author: adham
 */

#ifndef MCAL_FMI_FMI_INTERFACE_H_
#define MCAL_FMI_FMI_INTERFACE_H_

#include"../../INC/STD_TYPES.h"
#include"../../INC/Macros.h"
void FMI_vMassErase(void);
void FMI_vSectorErase(uint8_t A_u8SectorNo);
void FMI_vFlashWrite(uint32_t A_u32Address,uint16_t* A_pu16Data,uint16_t  A_u16Length);

#endif /* MCAL_FMI_FMI_INTERFACE_H_ */
