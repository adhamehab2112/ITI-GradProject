#include"MCAL/RCC/RCC_Interface.h"
#include"MCAL/GPIO/GPIO_Interface.h"
#include"MCAL/EXTI/EXTI_Interface.h"
#include"MCAL/NVIC/NVIC_Interface.h"
#include"MCAL/STK/STK_Interface.h"
#include"OS/RTOS_Interface.h"
#include"HAL/LCD/LCD.h"
#include"HAL/KEYPAD/KEYPAD.h"

/*void MyISR(void)
{
	MCAL_GPIOx_Pin_Toggle(GPIOA, GPIO_PIN_0);
}*/

void TASK1(void)
{
	MCAL_GPIOx_Pin_Toggle(GPIOA, GPIO_PIN_0);
}
void TASK2(void)
{
	MCAL_GPIOx_Pin_Toggle(GPIOA, GPIO_PIN_1);
}
void TASK3(void)
{
	MCAL_GPIOx_Pin_Toggle(GPIOA, GPIO_PIN_2);
}
void TASK4(void)
{
	MCAL_GPIOx_Pin_Toggle(GPIOA, GPIO_PIN_3);
}
int main()
{
	/******************SYSTK Enable**************************/
	 MCAL_SYSTK_voidInit();
	 /*******************************************************/
	RCC_Config_t MyRCC ;
	MyRCC.RCC_SYS_CLK 	 =  HSI;
	MyRCC.RCC_PERIPHERAL = GPIOA_PERIPHERAL ;
	//MyRCC.RCC_HSE_MODE = HSE_MODE_BYPASS ;
	MyRCC.RCC_BUS_SELECT = AHB1_BUS  ;
	MCAL_RCC_voidInit(&MyRCC);
	MCAL_RCC_voidPeripheral_EN(MyRCC.RCC_PERIPHERAL,MyRCC.RCC_BUS_SELECT );
	MyRCC.RCC_PERIPHERAL = GPIOB_PERIPHERAL ;
	MyRCC.RCC_BUS_SELECT = AHB1_BUS  ;
	MCAL_RCC_voidPeripheral_EN(MyRCC.RCC_PERIPHERAL,MyRCC.RCC_BUS_SELECT );


	GPIOx_Config_t MyGPIO	;

	/*******************Output****************/

	/****************LED1*********************/
	MyGPIO.GPIO_PIN_MODE = GPIO_OUT_PP;
	MyGPIO.GPIO_PIN_NUMBER = GPIO_PIN_0;
	MyGPIO.GPIO_PIN_OUT_SPEED = GPIO_OUT_SPEED_LOW ;
	MCAL_GPIOx_Init(GPIOA ,&MyGPIO);
	/****************LED2*********************/
	MyGPIO.GPIO_PIN_MODE = GPIO_OUT_PP;
	MyGPIO.GPIO_PIN_NUMBER = GPIO_PIN_1;
	MyGPIO.GPIO_PIN_OUT_SPEED = GPIO_OUT_SPEED_LOW ;
	MCAL_GPIOx_Init(GPIOA ,&MyGPIO);
	/****************LED3*********************/
	MyGPIO.GPIO_PIN_MODE = GPIO_OUT_PP;
	MyGPIO.GPIO_PIN_NUMBER = GPIO_PIN_2;
	MyGPIO.GPIO_PIN_OUT_SPEED = GPIO_OUT_SPEED_LOW ;
	MCAL_GPIOx_Init(GPIOA ,&MyGPIO);
	/****************LED4*********************/
	MyGPIO.GPIO_PIN_MODE = GPIO_OUT_PP;
	MyGPIO.GPIO_PIN_NUMBER = GPIO_PIN_3;
	MyGPIO.GPIO_PIN_OUT_SPEED = GPIO_OUT_SPEED_LOW ;
	MCAL_GPIOx_Init(GPIOA ,&MyGPIO);

	/*******************OS Task Creation**************/
/*
	RTOS_uint8_tCreateTask(TASK1,100,0,0);
	RTOS_uint8_tCreateTask(TASK2,200,1,0);
	RTOS_uint8_tCreateTask(TASK3,300,2,0);
	RTOS_uint8_tCreateTask(TASK4,400,3,0);

	Start_OS();
*/


/*	*****************Input*****************
	MyGPIO.GPIO_PIN_MODE = GPIO_INPUT_FLOAT;
	MyGPIO.GPIO_PIN_NUMBER = GPIO_PIN_0;
	MCAL_GPIOx_Init(GPIOB ,&MyGPIO);
	**************************************
	EXTI_Config_t MyEXTI ;
	MyEXTI.EXTI_StateSelection = EXTI_ENABLE ;
	MyEXTI.EXTI_PortSelection = EXTI_PORTB ;
	MyEXTI.EXTI_LineSelection = EXTI_LINE_0 ;
	MyEXTI.EXTI_EdgeSelection = EXTI_ON_CHANGE ;
	MyEXTI.CallBack = MyISR ;
	MCAL_EXTI_Enable(&MyEXTI);
	***************************************
	MCAL_NVIC_EnIRQ(EXTI0);
	****************************************/
	HAL_LCD_Init();
	HAL_KEYPAD_Init();
	while (1)
	{
		while(HAL_KEYPAD_Get_PressedKey() == KEY_NOT_PRESSED);
		HAL_LCD_Display_Number(HAL_KEYPAD_Get_PressedKey());
	}
	return 0 ;
}
