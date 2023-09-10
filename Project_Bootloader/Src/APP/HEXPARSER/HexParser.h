/*
 * HexParser.h
 *
 *  Created on: Sep 11, 2023
 *      Author: adham
 */

#ifndef APP_HEXPARSER_HEXPARSER_H_
#define APP_HEXPARSER_HEXPARSER_H_

/***************************************************************/
void HexParser_EraseAppArea(void);
void HexParser_ParseData(uint8_t Record[]);
/***************************************************************/
#define FLASH_APP_START_ADDRESS			0x08000000
#endif /* APP_HEXPARSER_HEXPARSER_H_ */
