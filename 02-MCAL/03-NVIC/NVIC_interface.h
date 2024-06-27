/******************************************************/
/* Author    : Adham Khaled                           */
/* Date      : 24 JUNE 2024                           */
/* Version   : V01                                    */
/******************************************************/
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

void MNVIC_VoidEnableInterrupt(u8 Copy_u8IntNumber);
void MNVIC_VoidDisableInterrupt(u8 Copy_u8IntNumber);
void MNVIC_VoidSetPendingFlag(u8 Copy_u8IntNumber);
void MNVIC_VoidDisablePendingFlag(u8 Copy_u8IntNumber);
u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNumber);
void MNVIC_voidSetPriority(s8 Copy_s8IntID , u8 Copy_u8GroupPriority ,u8 Copy_u8SubPriority );

#endif
