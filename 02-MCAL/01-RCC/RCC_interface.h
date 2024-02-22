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

/**
 * @brief initialize system clock based on configurations
 * 
 */
void MRCC_voidInitSysClock(void);
/**
 * @brief Enable clock for a specific periphral
 * 
 * @param copy_u8BusId the bus that the periphral is connected to
 * @param copy_u8PerId the periphral ID number 
 */
void MRCC_voidEnableClock(u8 copy_u8BusId, u8 copy_u8PerId);
/**
 * @brief Disable clock for a specific periphral
 * 
 * @param copy_u8BusId the bus that the periphral is connected to
 * @param copy_u8PerId the periphral ID number 
 */
void MRCC_voidDisabeClock(u8 copy_u8BusId, u8 copy_u8PerId);

#endif
