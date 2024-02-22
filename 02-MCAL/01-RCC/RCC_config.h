/******************************************************/
/* Author    : Adham Khaled                           */
/* Date      : 19 FEB 2024                            */
/* Version   : V01                                    */
/******************************************************/
#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/* Options: RCC_HSI
            RCC_HSE_CRYSTAL
            RCC_HSE_RC
            RCC_PLL
*/
#define RCC_CLOCK_TYPE      RCC_HSI

/* Options: RCC_PLL_HSI_DIV_2
            RCC_PLL_HSE
            RCC_PLL_HSE_DIV_2
*/
#define RCC_PLL_INPUT
/* Options: RCC_CSS_ENABLE
            RCC_CSS_DISABLE
*/
#define RCC_CLOCK_SECURITY_SYSTEM   RCC_CSS_DISABLE
/* Options: RCC_PLL_MUL_2
            RCC_PLL_MUL_3
            RCC_PLL_MUL_4
            RCC_PLL_MUL_5
            RCC_PLL_MUL_6
            RCC_PLL_MUL_7
            RCC_PLL_MUL_8
            RCC_PLL_MUL_9
            RCC_PLL_MUL_10
            RCC_PLL_MUL_11
            RCC_PLL_MUL_12
            RCC_PLL_MUL_13
            RCC_PLL_MUL_14
            RCC_PLL_MUL_16
            RCC_PLL_MUL_15
*/
#define RCC_PLL_MUL_VAL    RCC_PLL_MUL_2 

/* Options: RCC_AHB_PRESCALE_0
            RCC_AHB_PRESCALE_2
            RCC_AHB_PRESCALE_4
            RCC_AHB_PRESCALE_8
            RCC_AHB_PRESCALE_16
            RCC_AHB_PRESCALE_64
            RCC_AHB_PRESCALE_128
            RCC_AHB_PRESCALE_256
            RCC_AHB_PRESCALE_512
*/
#define RCC_AHB_PRESCALE    RCC_AHB_PRESCALE_0

/* Options: RCC_APB1_PRESCALE_0
            RCC_APB1_PRESCALE_2
            RCC_APB1_PRESCALE_4
            RCC_APB1_PRESCALE_8
            RCC_APB1_PRESCALE_16
*/
#define RCC_APB1_PRESCALE   RCC_APB1_PRESCALE_0

/* Options: RCC_APB2_PRESCALE_0
            RCC_APB2_PRESCALE_2
            RCC_APB2_PRESCALE_4
            RCC_APB2_PRESCALE_8
            RCC_APB2_PRESCALE_16
*/
#define RCC_APB2_PRESCALE   RCC_APB2_PRESCALE_0

#endif
