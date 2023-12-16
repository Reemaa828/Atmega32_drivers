#ifndef HAL_7SEG_7SEG_INTERFACE_H_
#define HAL_7SEG_7SEG_INTERFACE_H_

typedef struct{
    u8 port;
    
}SEVEN_Config;

void SEVEN_voidInit(SEVEN_Config seven1);
void SEVEN_voidDisplay(SEVEN_Config seven1,u8 num);

#endif