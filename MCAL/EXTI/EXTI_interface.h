#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_

typedef enum{
    EXTI0 =6,
    EXTI1 =7,
    EXTI2 =5
}External_Interrupt;


#define EXTI_LowLevel            0
#define EXTI_AnyLogicalChange    1
#define EXTI_FallingEdge         2
#define EXTI_RisingEdge          3

void EXTI_voidInterruptInit(); //prebuild config fuction
void EXTI_voidInterruptEnable(External_Interrupt interrupt_num,u8 Copy_u8SenseMode);
void EXTI_voidInterruptDisable(External_Interrupt interrupt_num);
u8 EXTI_u8GetFlag(External_Interrupt interrupt_num);
void EXTI_voidCLearFlag(External_Interrupt interrupt_num);

#endif