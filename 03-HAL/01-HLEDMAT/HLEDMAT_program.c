/******************************************************/
/* Author    : Adham Khaled                           */
/* Date      : 5 July 2024                            */
/* Version   : V01                                    */
/******************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "HLEDMAT_interface.h"
#include "HLEDMAT_private.h"
#include "HLEDMAT_config.h"

void HLEDMAT_voidInit(void)
{
	MGPIO_VoidSetPinDirection(HLEDMAT_ROW_0,GPIO_OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(HLEDMAT_ROW_1,GPIO_OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(HLEDMAT_ROW_2,GPIO_OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(HLEDMAT_ROW_3,GPIO_OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(HLEDMAT_ROW_4,GPIO_OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(HLEDMAT_ROW_5,GPIO_OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(HLEDMAT_ROW_6,GPIO_OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(HLEDMAT_ROW_7,GPIO_OUTPUT_SPEED_2MHZ_PP);

	MGPIO_VoidSetPinDirection(HLEDMAT_COL_0,GPIO_OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(HLEDMAT_COL_1,GPIO_OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(HLEDMAT_COL_2,GPIO_OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(HLEDMAT_COL_3,GPIO_OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(HLEDMAT_COL_4,GPIO_OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(HLEDMAT_COL_5,GPIO_OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(HLEDMAT_COL_6,GPIO_OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(HLEDMAT_COL_7,GPIO_OUTPUT_SPEED_2MHZ_PP);
}

void HLEDMAT_voidDisplayFrame(u8 *Copy_u8Frame)
{
	while(1){

	disableCol();
	activeRow(Copy_u8Frame[0]);
	MGPIO_voidSetPinValue(HLEDMAT_COL_0,GPIO_LOW);
	MSTK_voidSetBusyWait(2500);

	disableCol();
	activeRow(Copy_u8Frame[1]);
	MGPIO_voidSetPinValue(HLEDMAT_COL_1,GPIO_LOW);
	MSTK_voidSetBusyWait(2500);

	disableCol();
	activeRow(Copy_u8Frame[3]);
	MGPIO_voidSetPinValue(HLEDMAT_COL_3,GPIO_LOW);
	MSTK_voidSetBusyWait(2500);
	
	disableCol();
	activeRow(Copy_u8Frame[4]);
	MGPIO_voidSetPinValue(HLEDMAT_COL_4,GPIO_LOW);
	MSTK_voidSetBusyWait(2500);
	
	disableCol();
	activeRow(Copy_u8Frame[5]);
	MGPIO_voidSetPinValue(HLEDMAT_COL_5,GPIO_LOW);
	MSTK_voidSetBusyWait(2500);
	

	disableCol();
	activeRow(Copy_u8Frame[6]);
	MGPIO_voidSetPinValue(HLEDMAT_COL_6,GPIO_LOW);
	MSTK_voidSetBusyWait(2500);

	disableCol();
	activeRow(Copy_u8Frame[7]);
	MGPIO_voidSetPinValue(HLEDMAT_COL_7,GPIO_LOW);
	MSTK_voidSetBusyWait(2500);
	}
}

static void disableCol(){
	MGPIO_voidSetPinValue(HLEDMAT_COL_0,GPIO_HIGH);
	MGPIO_voidSetPinValue(HLEDMAT_COL_1,GPIO_HIGH);
	MGPIO_voidSetPinValue(HLEDMAT_COL_2,GPIO_HIGH);
	MGPIO_voidSetPinValue(HLEDMAT_COL_3,GPIO_HIGH);
	MGPIO_voidSetPinValue(HLEDMAT_COL_4,GPIO_HIGH);
	MGPIO_voidSetPinValue(HLEDMAT_COL_5,GPIO_HIGH);
	MGPIO_voidSetPinValue(HLEDMAT_COL_6,GPIO_HIGH);
	MGPIO_voidSetPinValue(HLEDMAT_COL_7,GPIO_HIGH);
}


static void activeRow(u8 Copy_u8Frame){
	u8 Local_u8Bit;
	Local_u8Bit=GET_BIT(Copy_u8Frame,0);
	MGPIO_voidSetPinValue(HLEDMAT_ROW_0,Local_u8Bit);
	Local_u8Bit=GET_BIT(Copy_u8Frame,1);
	MGPIO_voidSetPinValue(HLEDMAT_ROW_1,Local_u8Bit);
	Local_u8Bit=GET_BIT(Copy_u8Frame,2);
	MGPIO_voidSetPinValue(HLEDMAT_ROW_2,Local_u8Bit);
	Local_u8Bit=GET_BIT(Copy_u8Frame,3);
	MGPIO_voidSetPinValue(HLEDMAT_ROW_3,Local_u8Bit);
	Local_u8Bit=GET_BIT(Copy_u8Frame,4);
	MGPIO_voidSetPinValue(HLEDMAT_ROW_4,Local_u8Bit);
	Local_u8Bit=GET_BIT(Copy_u8Frame,5);
	MGPIO_voidSetPinValue(HLEDMAT_ROW_5,Local_u8Bit);

	Local_u8Bit=GET_BIT(Copy_u8Frame,6);
	MGPIO_voidSetPinValue(HLEDMAT_ROW_6,Local_u8Bit);
	Local_u8Bit=GET_BIT(Copy_u8Frame,7);
	MGPIO_voidSetPinValue(HLEDMAT_ROW_7,Local_u8Bit);
}