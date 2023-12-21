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
void TIMER_voidSetDesiredTime_ms(u8 Copy_u32DesiredTime);
#endif