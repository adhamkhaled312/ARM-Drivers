/******************************************************/
/* Author    : Adham Khaled                           */
/* Date      : 27 JUNE 2024                           */
/* Version   : V01                                    */
/******************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

static void (* EXTI0_CallBack) (void) = 0 ;

void MEXTI_voidInit()
{
    #if   EXTI_MODE==EXTI_RISING
        SET_BIT(EXTI->RTSR,EXTI_LINE);
    #elif     EXTI_MODE==EXTI_FALLING
        SET_BIT(EXTI->FTSR,EXTI_LINE);
    #elif   EXTI_MODE==EXTI_ON_CHANGE
        SET_BIT(EXTI->RTSR,EXTI_LINE);
        SET_BIT(EXTI->FTSR,EXTI_LINE);
    #else
        #error "Wrong mode"
    #endif
    CLR_BIT(EXTI->IMR,EXTI_LINE);
}
void MEXTI_voidEnableEXTI(u8 Copy_u8Line)
{
    SET_BIT(EXTI->IMR,Copy_u8Line);
}
void MEXTI_voidDisableEXTI(u8 Copy_u8Line)
{
    CLR_BIT(EXTI->IMR,Copy_u8Line);
}
void MEXTI_voidSwTrigger(u8 Copy_u8Line)
{
    SET_BIT(EXTI->SWIER,Copy_u8Line);
}
void MEXTI_voidSetSignalLatch(u8 Copy_u8Line , u8 Copy_u8Mode)
{
    switch (Copy_u8Mode)
    {
    case EXTI_RISING:    SET_BIT(EXTI->RTSR,Copy_u8Line);   break;
    case EXTI_FALLING:   SET_BIT(EXTI->FTSR,Copy_u8Line);   break;
    case EXTI_ON_CHANGE: SET_BIT(EXTI->RTSR,Copy_u8Line);
                    SET_BIT(EXTI->FTSR,Copy_u8Line);   break;
    default: /* report error */ break;
    }
    SET_BIT(EXTI -> IMR , Copy_u8Line);
}
void MEXTI_voidSetCallBack(void (*ptr) (void)) // ahmed
{
		EXTI0_CallBack = ptr ; /*ahmed*/
}

void	EXTI0_IRQHandler(void)
{
	EXTI0_CallBack();
	/*	Clear pending Bit		*/
	SET_BIT(EXTI -> PR , 0);
}
