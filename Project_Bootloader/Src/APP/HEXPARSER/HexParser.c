/*
 * HexParser.c
 *
 *  Created on: Sep 11, 2023
 *      Author: adham
 */
/*************************************Includes*********************************/
#include"../../INC/STD_TYPES.h"
#include"../../INC/Macros.h"
#include"HexParser.h"
#include"../../MCAL/FMI/FMI_Interface.h"
/******************************************************************************/
uint16_t Data[100];
/******************************************************************************/
void HexParser_EraseAppArea(void)
{
	MCALFMI_vMassErase();
}

/*Private Function*/
static uint8_t HexParser_hex_to_ASCII(uint8_t Digit)
{
	uint8_t Ascii_value ;
	if(Digit>='0' && Digit<='9')
	{
		Ascii_value = Digit -'0';
	}
	else(Digit>='A' && Digit <='F')
	{
		Ascii_value = Digit - 55 ;
	}
	return Ascii_value;
}

void HexParser_ParseData(uint8_t Record[])
{
	/*Character Count Variables*/
	uint8_t CC , CC_Low , CC_High;
	/*Convert the Character Count to ASCII*/
	CC_low  = HexParser_hex_to_ASCII(Record[1]);
	CC_High = HexParser_hex_to_ASCII(Record[2]);
	CC = (CC_High <<4)|CC_low ;



	/*Low Part of Address Digits*/
	uint8_t Digit0 , Digit1 , Digit2 , Digit3 ;
	uint32_t Address=0;
	Digit3 =  HexParser_hex_to_ASCII(Record[3]);
	Digit2 =  HexParser_hex_to_ASCII(Record[4]);
	Digit1 =  HexParser_hex_to_ASCII(Record[5]);
	Digit0 =  HexParser_hex_to_ASCII(Record[6]);

	Address = (FLASH_APP_START_ADDRESS)|(Digit3<<12)|(Digit2<<8)|(Digit1<<4)|(Digit0<<0);

	/*Start Converting the Data [9]->[40]*/
	for(uint8_t itr=0 ; itr<(CC/2) ; itr++)
	{
		Digit3 = HexParser_hex_to_ASCII(Record[(4*itr)+9]);
		Digit2 = HexParser_hex_to_ASCII(Record[(4*itr)+10]);
		Digit1 = HexParser_hex_to_ASCII(Record[(4*itr)+11]);
		Digit0 = HexParser_hex_to_ASCII(Record[(4*itr)+12]);

		Data[itr]= (Digit3<<12)|(Digit2<<8)|(Digit1<<4)|(Digit0<<0);
	}

	MCALFMI_vFlashWrite(Address , Data, CC/2); /*Half word*/

}

