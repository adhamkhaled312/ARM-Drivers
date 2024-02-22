/******************************************************/
/* Author    : Adham Khaled                           */
/* Date      : 19 FEB 2024                            */
/* Version   : V01                                    */
/******************************************************/
#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

#define RCC_BASE_ADDRESS    0x40021000 
/* RCC registers */
#define RCC_CR              (*((volatile u32*)(RCC_BASE_ADDRESS+0x000)))
#define RCC_CFGR            (*((volatile u32*)(RCC_BASE_ADDRESS+0x004)))
#define RCC_CIR             (*((volatile u32*)(RCC_BASE_ADDRESS+0x008)))
#define RCC_APB2RSTR        (*((volatile u32*)(RCC_BASE_ADDRESS+0x00C)))
#define RCC_APB1RSTR        (*((volatile u32*)(RCC_BASE_ADDRESS+0x010)))
#define RCC_AHBENR          (*((volatile u32*)(RCC_BASE_ADDRESS+0x014)))
#define RCC_APB2ENR         (*((volatile u32*)(RCC_BASE_ADDRESS+0x018)))
#define RCC_APB1ENR         (*((volatile u32*)(RCC_BASE_ADDRESS+0x01C)))
#define RCC_BDCR            (*((volatile u32*)(RCC_BASE_ADDRESS+0x020)))
#define RCC_CSR             (*((volatile u32*)(RCC_BASE_ADDRESS+0x024)))
#define RCC_AHBSTR          (*((volatile u32*)(RCC_BASE_ADDRESS+0x028)))
#define RCC_CFGR2           (*((volatile u32*)(RCC_BASE_ADDRESS+0x02C)))

/* RCC clock options */
#define RCC_HSI             0
#define RCC_HSE_CRYSTAL     1
#define RCC_HSE_RC          2
#define RCC_PLL             3

/* CSS options */
#define RCC_CSS_ENABLE      1
#define RCC_CSS_DISABLE     0

/* PLL clock source options*/
#define RCC_PLL_HSI_DIV_2   0
#define RCC_PLL_HSE         1
#define RCC_PLL_HSE_DIV_2   2

/* PLL multiply options */
#define RCC_PLL_MUL_2       0b0000
#define RCC_PLL_MUL_3       0b0001
#define RCC_PLL_MUL_4       0b0010
#define RCC_PLL_MUL_5       0b0011
#define RCC_PLL_MUL_6       0b0100
#define RCC_PLL_MUL_7       0b0101
#define RCC_PLL_MUL_8       0b0110
#define RCC_PLL_MUL_9       0b0111
#define RCC_PLL_MUL_10      0b1000
#define RCC_PLL_MUL_11      0b1001
#define RCC_PLL_MUL_12      0b1010
#define RCC_PLL_MUL_13      0b1011
#define RCC_PLL_MUL_14      0b1100
#define RCC_PLL_MUL_16      0b1101
#define RCC_PLL_MUL_15      0b1110

/* AHB prescale options */
#define RCC_AHB_PRESCALE_0      0b0000
#define RCC_AHB_PRESCALE_2      0b1000
#define RCC_AHB_PRESCALE_4      0b1001
#define RCC_AHB_PRESCALE_8      0b1010
#define RCC_AHB_PRESCALE_16     0b1011
#define RCC_AHB_PRESCALE_64     0b1100
#define RCC_AHB_PRESCALE_128    0b1101 
#define RCC_AHB_PRESCALE_256    0b1110
#define RCC_AHB_PRESCALE_512    0b1111


/*APB1 prescale options */
#define RCC_APB1_PRESCALE_0     0b000
#define RCC_APB1_PRESCALE_2     0b100
#define RCC_APB1_PRESCALE_4     0b101
#define RCC_APB1_PRESCALE_8     0b110
#define RCC_APB1_PRESCALE_16    0b111

/*APB2 prescale options */
#define RCC_APB2_PRESCALE_0     0b000 
#define RCC_APB2_PRESCALE_2     0b100
#define RCC_APB2_PRESCALE_4     0b101
#define RCC_APB2_PRESCALE_8     0b110
#define RCC_APB2_PRESCALE_16    0b111
#endif
