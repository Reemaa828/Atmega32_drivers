#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../DIO/DIO_interface.h"
#include "TIMER0_register.h"
#include "TIMER0_private.h"
#include "TIMER0_config.h"
#include "TIMER0_interface.h"

static u32 Global_u32OverFlowCounts=0;
static u32 Global_u32Counter=0;

volatile void (* TIMER_pCallBack[8])(void)={NULL};

void TIMER_voidInit(void){

    #if TIMER_MODE == NORMAL_MODE
       CLR_BIT(TCCR0,WGM00);
       CLR_BIT(TCCR0,WGM01);
        #if   TIMER_OCO_NON_PWN == PORT_VALUE  
             CLR_BIT(TCCR0,COM00);              
             CLR_BIT(TCCR0,COM01);              
       #elif TIMER_OCO_NON_PWN == TOGGLE_OCO   
             SET_BIT(DDRB,3);
             SET_BIT(TCCR0,COM00);              
             CLR_BIT(TCCR0,COM01);           
       #elif TIMER_OCO_NON_PWN == CLEAR_OCO  
             SET_BIT(DDRB,3);
             CLR_BIT(TCCR0,COM00);              
             SET_BIT(TCCR0,COM01);  
       #elif TIMER_OCO_NON_PWN == SET_OCO  
             SET_BIT(DDRB,3);
             SET_BIT(TCCR0,COM00);              
             SET_BIT(TCCR0,COM01);   
        #endif
    #endif
    /***ENABLE INTERUPT***/
    SET_BIT(TIMSK,TOIE0);
    SET_BIT(TIMSK,OCIE0);
}

void TIMER_voidSetPreload(u8 Copy_u8PreloadValue){
    TCNT0=Copy_u8PreloadValue;
}

void TIMER_voidEnable(void){
      
        TCCR0|=0b11111000;
        TCCR0|=TIMER_PRESCALER;
}

void TIMER_voidDisable(void){
             CLR_BIT(TCCR0,CS00);              
             CLR_BIT(TCCR0,CS01);              
             CLR_BIT(TCCR0,CS10);  
}

void TIMER_voidSetCallBackFun(void (* Copy_pvCallBack)(void),Timers_Interrupt interruptNum){
      Global_u32Counter++;

      if(Global_u32Counter>=Global_u32OverFlowCounts){

            TIMER_pCallBack[interruptNum]=Copy_pvCallBack;
            Global_u32Counter=0;
      }
      
}

void __vector_12(void) __attribute__((signal));
void __vector_12(void){

      TIMER_pCallBack[TIMER0_OVF];
}

void __vector_11(void) __attribute__((signal));
void __vector_11(void){
      TIMER_pCallBack[TIMER0_COMP];
}

u8 TIMER_u8GetCounts(void){
      return TCNT0;
}

void TIMER_voidSetDesiredTime_ms(u32 Copy_u8DesiredTime){
      u32 Local_u32TickTime       = preScale[TIMER_PRESCALER]*1000000/(TIMER_RESOLUTION*1000000);
      u32 Local_u32OverflowTime   = Local_u8TickTime*OVERFLOW_COUNTS*1000;
      Global_u32OverFlowCounts       = Copy_u8DesiredTime/Local_u32OverflowTime;
        u32  Local_u32Reminder = Copy_u8DesiredTime%Local_u32OverflowTime;
        if(Local_u32Reminder!=0){
            Global_u32OverFlowCounts++;
        }
     TIMER_voidSetPreload(Local_u32OverflowTime-Local_u32Reminder);
}

