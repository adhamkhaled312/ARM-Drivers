/******************************************************/
/* Author    : Adham Khaled                           */
/* Date      : 24 JUNE 2024                           */
/* Version   : V01                                    */
/******************************************************/
#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

/* Registers */
#define NVIC_BASE_ADDRESS  0xE000EF00

#define NVIC_ISER0                  (*((volatile u32*)(NVIC_BASE_ADDRESS+0x000))) /* Enable external interrupts from 0 to 31  */
#define NVIC_ISER1                  (*((volatile u32*)(NVIC_BASE_ADDRESS+0x004))) /* Enable external interrupts from 32 to 59 */

#define NVIC_ICER0                  (*((volatile u32*)(NVIC_BASE_ADDRESS+0x080))) /* Disable external interrupts from 0 to 31  */
#define NVIC_ICER1                  (*((volatile u32*)(NVIC_BASE_ADDRESS+0x084))) /* Disable external interrupts from 32 to 59 */

#define NVIC_ISPR0                  (*((volatile u32*)(NVIC_BASE_ADDRESS+0x100))) /* Set pending flag for interrupts from 0 to 31  */
#define NVIC_ISPR1                  (*((volatile u32*)(NVIC_BASE_ADDRESS+0x104))) /* Set pending flag for interrupts from 32 to 59 */

#define NVIC_ICPR0                  (*((volatile u32*)(NVIC_BASE_ADDRESS+0x180))) /* Disable pending flag for interrupts from 0 to 31  */
#define NVIC_ICPR1                  (*((volatile u32*)(NVIC_BASE_ADDRESS+0x184))) /* Disable pending flag for interrupts from 32 to 59 */

#define NVIC_IABR0                  (*((volatile u32*)(NVIC_BASE_ADDRESS+0x200))) /* Get active flag for interrupts from 0 to 31  */
#define NVIC_IABR1                  (*((volatile u32*)(NVIC_BASE_ADDRESS+0x204))) /* Get active flag for interrupts from 32 to 59 */

#define NVIC_IPR                    ((volatile u8*)(NVIC_BASE_ADDRESS+0x300))
#define SCB_AIRCR		            (*((volatile u32*)(0xE000ED00 + 0x0C)))

/* Priority groups */

/* 4 Groups 0 sub */
#define NVIC_PRIORITY_GROUP1        0x05FA0300  
/* 3 Groups 1 sub */
#define NVIC_PRIORITY_GROUP2        0x05FA0400  
/* 2 Groups 2 sub */
#define NVIC_PRIORITY_GROUP3        0x05FA0500  
/* 1 Groups 3 sub */
#define NVIC_PRIORITY_GROUP4        0x05FA0600  
/* 0 Groups 4 sub */
#define NVIC_PRIORITY_GROUP5        0x05FA0700  

#endif
