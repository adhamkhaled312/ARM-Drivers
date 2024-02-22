/******************************************************/
/* Author    : Adham Khaled                           */
/* Date      : 19 FEB 2024                            */
/* Version   : V01                                    */
/******************************************************/
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#define RCC_AHB     0
#define RCC_APB1    1
#define RCC_APB2    2

void MRCC_voidInitSysClock(void);
void MRCC_voidEnableClock(u8 copy_u8BusId, u8 copy_u8PerId);
void MRCC_voidDisabeClock(u8 copy_u8BusId, u8 copy_u8PerId);

#endif
