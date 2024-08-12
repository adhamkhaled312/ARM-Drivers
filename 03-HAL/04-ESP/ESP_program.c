/******************************************************/
/* Author    : Adham Khaled                           */
/* Date      : 22 July 2024                           */
/* Version   : V01                                    */
/******************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ESP_interface.h"
#include "ESP_private.h"
#include "ESP_config.h"
void ESP_voidInit(void)
{
	u8 Local_u8Result = 0;
	
	while(Local_u8Result == 0)
	{
		/* Stop ECHO */
		MUSART1_voidTransmit("ATE0\r\n");
		Local_u8Result = voidEspValidateCmd();
	}
	
	Local_u8Result = 0;
	
	while(Local_u8Result == 0)
	{
		/* Set station mode */
		MUSART1_voidTransmit("AT+CWMODE=1\r\n");
		Local_u8Result = voidEspValidateCmd();
	}
}


u8 voidEspValidateCmd(void)
{
	u8 Local_u8Response[100] = {0};
	u8 i = 0;
	u8 Dummy = 0;
	u8 Result = 0;
	
	while (Dummy != 255)
	{
		Dummy = MUSART1_u8Receive();
		Local_u8Response[i] = Dummy;
		i++;
	}
	
	/* Check if Ok */
	if (Local_u8Response[0] == 'O' && Local_u8Response[1] == 'K')
	{
		Result = 1;
	}
	
	return Result;
}
