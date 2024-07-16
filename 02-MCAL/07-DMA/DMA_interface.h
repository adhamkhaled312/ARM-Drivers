/******************************************************/
/* Author    : Adham Khaled                           */
/* Date      : 13 July 2024                           */
/* Version   : V01                                    */
/******************************************************/
#ifndef DMA_INTERFACE_H_
#define DMA_INTERFACE_H_

void DMA_voidChannel1Init(void);


void DMA_voidChannel1Start(u32 Copy_pu32SourceAddress, u32 Copy_pu32DestinationAddress, u16 Copy_u16BlockLength);

#endif