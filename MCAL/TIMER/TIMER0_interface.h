#ifndef MCAL_TIMER_TIMER_INTERFACE_H_
#define MCAL_TIMER_TIMER_INTERFACE_H_

typedef enum {
 TIMER2_COMP   =     5,
 TIMER2_OVF    =     6,
 TIMER1_CAPT   =     7,
 TIMER1_COMPA  =     8,
 TIMER1_COMPB  =     9,
 TIMER1_OVF    =     10,
 TIMER0_COMP   =     11,
 TIMER0_OVF    =     12
}Timers_Interrupt ;

void TIMER_voidInit(void);
void TIMER_voidSetPreload(u8 Copy_u8PreloadValue);
void TIMER_voidEnable(void);
void TIMER_voidDisable(void);
void TIMER_voidSetCallBackFun(void (* Copy_pvCallBack)(void), Timers_Interrupt interruptNum);
u8 TIMER_u8GetCounts(void);
#endif