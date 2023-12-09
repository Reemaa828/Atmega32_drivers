#ifndef HAL_LED_INTERFACE_H_
#define HAL_LED_INTERFACE_H_

typedef enum
{
    LED_pin0,
    LED_pin1,
    LED_pin2,
    LED_pin3,
    LED_pin4,
    LED_pin5,
    LED_pin6,
    LED_pin7
}LED_Pin;

typedef enum
{
    LED_sink,
    LED_source
}LED_Connection;

typedef struct{
    u8 port;
    u8 pin;
    u8 connection;
}LED_Config;
void LED_voidInit(LED_Config LED);
void LED_voidTurnOn(LED_Config LED);
void LED_voidTurnOff(LED_Config LED);
void LED_voidToggle(LED_Config LED);
#endif