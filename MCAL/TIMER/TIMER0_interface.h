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

#define _1_                         1
#define _8_                         2
#define _64_                        3
#define _256_                       4
#define _1024_                      5
#define EXTERNAL_cLOCK_FALLING_EDGE 6
#define EXTERNAL_cLOCK_RISING_EDGE  7

u8 preScale[]={0,1,8,64,256,1024};
void TIMER_voidInit(void);
void TIMER_voidSetPreload(u8 Copy_u8PreloadValue);
void TIMER_voidEnable(void);
void TIMER_voidDisable(void);
void TIMER_voidSetCallBackFun(void (* Copy_pvCallBack)(void), Timers_Interrupt interruptNum);
u8 TIMER_u8GetCounts(void);
void TIMER_voidSetDesiredTime_ms(u8 Copy_u8DesiredTime);
#endif