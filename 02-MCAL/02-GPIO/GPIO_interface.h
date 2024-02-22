/******************************************************/
/* Author    : Adham Khaled                           */
/* Date      : 22 FEB 2024                            */
/* Version   : V01                                    */
/******************************************************/
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

/*Pin input modes */
#define GPIO_INPUT_ANALOG               0b0000
#define GPIO_INPUT_FLOATING             0b0100
#define GPIO_INPUT_PULLUP_PULLDOWN      0b1000

/*Pin output modes */
#define GPIO_OUTPUT_SPEED_10MHZ_PP      0b0001
#define GPIO_OUTPUT_SPEED_10MHZ_OD      0b0101
#define GPIO_OUTPUT_SPEED_10MHZ_AFPP    0b1001
#define GPIO_OUTPUT_SPEED_10MHZ_AFOP    0b1101

#define GPIO_OUTPUT_SPEED_2MHZ_PP       0b0010
#define GPIO_OUTPUT_SPEED_2MHZ_OD       0b0110
#define GPIO_OUTPUT_SPEED_2MHZ_AFPP     0b1010
#define GPIO_OUTPUT_SPEED_2MHZ_AFOP     0b1110
 
#define GPIO_OUTPUT_SPEED_50MHZ_PP      0b0011
#define GPIO_OUTPUT_SPEED_50MHZ_OD      0b0111
#define GPIO_OUTPUT_SPEED_50MHZ_AFPP    0b1011
#define GPIO_OUTPUT_SPEED_50MHZ_AFOP    0b1111

/* Port options*/
#define GPIO_PORTA                      1
#define GPIO_PORTB                      2
#define GPIO_PORTC                      3

/* Pins options */
#define GPIO_PIN0                       0
#define GPIO_PIN1                       1                   
#define GPIO_PIN2                       2
#define GPIO_PIN3                       3
#define GPIO_PIN4                       4
#define GPIO_PIN5                       5
#define GPIO_PIN6                       6
#define GPIO_PIN7                       7
#define GPIO_PIN8                       8
#define GPIO_PIN9                       9
#define GPIO_PIN10                      10
#define GPIO_PIN11                      11
#define GPIO_PIN12                      12
#define GPIO_PIN13                      13
#define GPIO_PIN14                      14
#define GPIO_PIN15                      15

/* Pin values options*/
#define GPIO_HIGH                       1
#define GPIO_LOW                        0

/**
 * @brief set the pin direction and mode
 * 
 * @param copy_u8Port the port (PORTA,PORTB,PORTC)
 * @param copy_u8Pin pin (from PIN1 to PIN16)
 * @param copy_u8Mode mode of the pin
 */
void MGPIO_voidSetPinDirection(u8 copy_u8Port , u8 copy_u8Pin,u8 copy_u8Mode);
/**
 * @brief set the value of the pin
 * 
 * @param copy_u8Port the port (PORTA,PORTB,PORTC)
 * @param copy_u8Pin pin (from PIN0 to PIN15)
 * @param copy_u8Value the value to be set (GPIO_HIGH , GPIO_LOW )
 */
void MGPIO_voidSetPinValue(u8 copy_u8Port , u8 copy_u8Pin,u8 copy_u8Value);
/**
 * @brief get the value of the pin
 * 
 * @param copy_u8Port the port (PORTA,PORTB,PORTC)
 * @param copy_u8Pin pin (from PIN0 to PIN15)
 * @return u8 the value of the pin (GPIO_HIGH , GPIO_LOW )
 */
u8 MGPIO_u8GetPinValue(u8 copy_u8Port , u8 copy_u8Pin);

#endif
