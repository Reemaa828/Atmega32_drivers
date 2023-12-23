#ifndef MCAL_TIMER_TIMER_INTERFACE_H_
#define MCAL_TIMER_TIMER_INTERFACE_H_

typedef enum {
 TIMER2_COMP   =     0,
 TIMER2_OVF    ,
 TIMER1_CAPT   ,
 TIMER1_COMPA  ,
 TIMER1_COMPB  ,
 TIMER1_OVF    ,
 TIMER0_COMP   ,
 TIMER0_OVF
}Timers_Interrupt ;

void TIMER_voidInit(void);
void TIMER_voidSetPreload(u8 Copy_u8PreloadValue);
void TIMER_voidEnable(void);
void TIMER_voidDisable(void);
void TIMER_voidSetCallBackFun(void (* Copy_pvCallBack)(void), Timers_Interrupt interruptNum);
u8 TIMER_u8GetCounts(void);
void TIMER_voidSetDesiredTime_ms(u8 Copy_u32DesiredTime);
void TIMER_voidSetCompareValue(u8 Copy_u8CompareVal);
#endif