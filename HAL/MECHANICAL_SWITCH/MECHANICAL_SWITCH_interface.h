#ifndef HAL_MECHANICAL_SWITCH_MECHANICAL_SWITCH_INTERFACE_H_
#define HAL_MECHANICAL_SWITCH_MECHANICAL_SWITCH_INTERFACE_H_

typedef enum
{
    SW_pin0,
    SW_pin1,
    SW_pin2,
    SW_pin3,
    SW_pin4,
    SW_pin5,
    SW_pin6,
    SW_pin7
}SW_Pin;

typedef enum{
    SW_INT_PULL_UP,
    SW_EXT_PULL_UP,
    SW_EXT_PULL_DOWN,
    SW_FLOATING
}SW_Connections;

typedef enum{
    SW_NOT_PRESSED,
    SW_PRESSED
}SW_State;

typedef struct{
    u8 port;
    u8 pin;
    SW_Connections connection;
}SW_Config;

void SW_voidInit(SW_Config switch1);

u8 SW_u8ReadSwitch(SW_Config switch1);

#endif