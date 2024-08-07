/******************************************************/
/* Author    : Adham Khaled                           */
/* Date      : 27 JUNE 2024                           */
/* Version   : V01                                    */
/******************************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

void MEXTI_voidInit();
void MEXTI_voidEnableEXTI(u8 Copy_u8Line);
void MEXTI_voidDisableEXTI(u8 Copy_u8Line);
void MEXTI_voidSwTrigger(u8 Copy_u8Line);
void MEXTI_voidSetSignalLatch(u8 Copy_u8Line , u8 Copy_u8Mode);

void MEXTI_voidSetCallBack(void (*ptr) (void));


/* EXTI Lines */
#define EXTI_LINE0      0
#define EXTI_LINE1      1
#define EXTI_LINE2      2
#define EXTI_LINE3      3
#define EXTI_LINE4      4
#define EXTI_LINE5      5
#define EXTI_LINE6      6
#define EXTI_LINE7      7
#define EXTI_LINE8      8
#define EXTI_LINE9      9
#define EXTI_LINE10     10
#define EXTI_LINE11     11
#define EXTI_LINE12     12
#define EXTI_LINE13     13
#define EXTI_LINE14     14
#define EXTI_LINE15     15
#define EXTI_LINE16     16
#define EXTI_LINE17     17
#define EXTI_LINE18     18
#define EXTI_LINE19     19

/* EXTI modes */
#define EXTI_RISING          0
#define EXTI_FALLING         1
#define EXTI_ON_CHANGE       2
#endif
