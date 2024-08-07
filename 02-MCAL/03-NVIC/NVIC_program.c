/******************************************************/
/* Author    : Adham Khaled                           */
/* Date      : 24 JUNE 2024                           */
/* Version   : V01                                    */
/******************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"
void MNVIC_voidEnableInterrupt(u8 Copy_u8IntNumber)
{
    if(Copy_u8IntNumber <= 31)
    {
        NVIC_ISER0=(1<<Copy_u8IntNumber);
    }
    else if(Copy_u8IntNumber <=59)
    {
        Copy_u8IntNumber-=32;
        NVIC_ISER1=(1<<Copy_u8IntNumber);
    }
    else
    {
        /* Return Error */
    }
}
void MNVIC_voidDisableInterrupt(u8 Copy_u8IntNumber)
{
    if(Copy_u8IntNumber <= 31)
    {
        NVIC_ICER0=(1<<Copy_u8IntNumber);
    }
    else if(Copy_u8IntNumber <=59)
    {
        Copy_u8IntNumber-=32;
        NVIC_ICER1=(1<<Copy_u8IntNumber);
    }
    else
    {
        /* Return Error */
    }
}
void MNVIC_voidSetPendingFlag(u8 Copy_u8IntNumber)
{
    if(Copy_u8IntNumber <= 31)
    {
        NVIC_ISPR0=(1<<Copy_u8IntNumber);
    }
    else if(Copy_u8IntNumber <=59)
    {
        Copy_u8IntNumber-=32;
        NVIC_ISPR1=(1<<Copy_u8IntNumber);
    }
    else
    {
        /* Return Error */
    }
}
void MNVIC_voidDisablePendingFlag(u8 Copy_u8IntNumber)
{
    if(Copy_u8IntNumber <= 31)
    {
        NVIC_ICPR0=(1<<Copy_u8IntNumber);
    }
    else if(Copy_u8IntNumber <=59)
    {
        Copy_u8IntNumber-=32;
        NVIC_ICPR1=(1<<Copy_u8IntNumber);
    }
    else
    {
        /* Return Error */
    }
}
u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNumber)
{
    u8 Local_u8Result=0;
    if(Copy_u8IntNumber <= 31)
    {
        Local_u8Result=GET_BIT(NVIC_IABR0,Copy_u8IntNumber);
    }
    else if(Copy_u8IntNumber <=59)
    {
        Copy_u8IntNumber-=32;
        Local_u8Result=GET_BIT(NVIC_IABR1,Copy_u8IntNumber);
    }
    else
    {
        /* Return Error */
    }
    return Local_u8Result;
}
void MNVIC_voidSetPriority(s8 Copy_s8IntID, u8 Copy_u8GroupPriority,u8 Copy_u8SubPriority)
{
    u8 Local_u8Priority=Copy_u8SubPriority | (Copy_u8GroupPriority<<((NVIC_NO_OF_GROUPS_SUB - 0x05FA0300)/256));
    /* External Interrupt */
    if(Copy_s8IntID>=0)
    {
        NVIC_IPR[Copy_s8IntID]=Local_u8Priority<<4;
    }
    SCB_AIRCR=NVIC_NO_OF_GROUPS_SUB;
}

