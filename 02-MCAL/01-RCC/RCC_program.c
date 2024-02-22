/******************************************************/
/* Author    : Adham Khaled                           */
/* Date      : 19 FEB 2024                            */
/* Version   : V01                                    */
/******************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void MRCC_voidInitSysClock(void)
{
    /* Configurations for system clock */
    #if RCC_CLOCK_TYPE==RCC_HSI
        SET_BIT(RCC_CR,0);              /* Enable HSI */
        while(!GET_BIT(RCC_CR,1));      /* Wait until it's stable */
        RCC_CFGR=0x00000000;            /* Select HSI */

    #elif RCC_CLOCK_TYPE==RCC_HSE_CRYSTAL
        SET_BIT(RCC_CR,16);             /* Enable HSE */
        CLR_BIT(RCC_CR,18);             /* Disable bypass */
        while(!GET_BIT(RCC_CR,17));     /* wait until it's stable */
        RCC_CFGR=0x00000001;            /* select HSE */

    #elif RCC_CLOCK_TYPE==RCC_HSE_RC
        SET_BIT(RCC_CR,16);             /* Enable HSE */
        SET_BIT(RCC_CR,18);             /* Disable bypass */
        while(!GET_BIT(RCC_CR,17));     /* wait until it's stable */
        RCC_CFGR=0x00000001;            /* select HSE */

    #elif RCC_CLOCK_TYPE==RCC_PLL
        CLR_BIT(RCC_CR,24);             /* Disable PLL for configurations*/

        /* Select PLL as system clock  bit 1:0 = 0b10*/
        SET_BIT(RCC_CFGR,1);        
        CLR_BIT(RCC_CFGR,0);
        
        RCC_CR &= ~((0b1111)<<18);        /* Clear multiplication bits */
        RCC_CR |= (RCC_PLL_MUL_VAL)<<18; /* Set multiplication value */

        /* Configure PLL source clock*/
        #if RCC_PLL_INPUT==RCC_PLL_HSE
            SET_BIT(RCC_CR,16);         /* Enable HSE */
            SET_BIT(RCC_CFGR,16);       /* Enable HSE as PLL source clock*/
            CLR_BIT(RCC_CFGR,17);       /* No prescale*/
        #elif RCC_PLL_INPUT==RCC_PLL_HSE_DIV_2
            SET_BIT(RCC_CR,16);         /* Enable HSE */
            SET_BIT(RCC_CFGR,16);       /*Enable HSE as PLL source clock*/    
            SET_BIT(RCC_CFGR,17);       /*Divide by 2*/
        #elif RCC_PLL_INPUT==RCC_PLL_HSI_DIV_2
            SET_BIT(RCC_CR,0);           /* Enable HSI */
            CLR_BIT(RCC_CFGR,16);       /*Enable HSI as PLL source clock*/
        #else 
            #error("YOU CHOOSE WRONG CLOCK SOURCE FOR PLL")
        #endif       
        
        SET_BIT(RC_CR,24);              /* Enable PLL */
        while(!(GET_BIT(RCC_CR,25)));   /* Wait until stable */
    #else
        #error("YOU CHOOSE WRONG CLOCK TYPE")
    #endif
    /*Configurations for bus prescalers */
    RCC_CFGR |= (RCC_AHB_PRESCALE<<4);
    RCC_CFGR |= (RCC_APB1_PRESCALE<<8);
    RCC_CFGR |= (RCC_APB2_PRESCALE<<11);
    
    #if RCC_CLOCK_SECURITY_SYSTEM==RCC_CSS_DISABLE
        CLR_BIT(RCC_CR,19);
    #elif RCC_CLOCK_SECURITY_SYSTEM==RCC_CSS_ENABLE
        SET_BIT(RCC_CR,19);
    #endif
}

void MRCC_voidEnableClock(u8 copy_u8BusId, u8 copy_u8PerId)
{
    if(copy_u8PerId <= 31)
    {
        switch (copy_u8BusId)
        {
            case RCC_AHB:  SET_BIT(RCC_AHBENR,copy_u8PerId); break;
            case RCC_APB1: SET_BIT(RCC_APB1ENR,copy_u8PerId); break;
            case RCC_APB2: SET_BIT(RCC_APB2ENR,copy_u8PerId); break;
        }
    }
    else 
    {
        /* Return Error */
    }
}
void MRCC_voidDisabeClock(u8 copy_u8BusId, u8 copy_u8PerId)
{
    if(copy_u8PerId <= 31)
    {
        switch (copy_u8BusId)
        {
            case RCC_AHB:  CLR_BIT(RCC_AHBENR,copy_u8PerId); break;
            case RCC_APB1: CLR_BIT(RCC_APB1ENR,copy_u8PerId); break;
            case RCC_APB2: CLR_BIT(RCC_APB2ENR,copy_u8PerId); break;
        }
    }
    else 
    {
        /* Return Error */
    }
}