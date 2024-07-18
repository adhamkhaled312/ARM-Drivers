/******************************************************/
/* Author    : Adham Khaled                           */
/* Date      : 17 July 2024                           */
/* Version   : V01                                    */
/******************************************************/
#ifndef USART_PRIVATE_H
#define USART_PRIVATE_H

typedef struct{
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 BRR;
	volatile u32 CR[3];
	volatile u32 GTPR;
}USART_Register;


#define 	USART1 		((USART_Register *) 0x40013800)

#endif