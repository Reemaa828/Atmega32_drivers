#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../DIO/DIO_interface.h"
#include "TIMER0_register.h"
#include "TIMER0_private.h"
#include "TIMER0_config.h"
#include "TIMER0_interface.h"

static u32 Global_u32OverFlowCounts=0;
static u32 Global_u32Counter=0;
u8 Global_CompareVal=0;
u16 preScale[]={0,1,8,64,256,1024};
volatile void (* TIMER_pCallBack[8])(void)={NULL};

void TIMER_voidInit(void){

    #if  TIMER_MODE == NORMAL_MODE
            CLR_BIT(TCCR0,WGM00);
            CLR_BIT(TCCR0,WGM01);
    
    #elif TIMER_MODE == CTC_MODE
             CLR_BIT(TCCR0,WGM00);
             SET_BIT(TCCR0,WGM01);
             TCCR0&=0b11001111;
             TCCR0|=(TIMER_OCO_NON_PWM<<4);

    #elif TIMER_MODE == FAST_PHASE_MODE
             SET_BIT(TCCR0,WGM00);
             SET_BIT(TCCR0,WGM01);
             TCCR0&=0b11001111;
             TCCR0|=(TIMER_OCO_NON_PWM<<4);

    #elif TIMER_MODE == PHASE_CORRECT_MODE
             SET_BIT(TCCR0,WGM00);
             CLR_BIT(TCCR0,WGM01);
             TCCR0&=0b11001111;
             TCCR0|=(TIMER_OCO_PWM<<4);

 #endif
    /***ENABLE INTERUPT***/
    SET_BIT(TIMSK,TOIE0);
    SET_BIT(TIMSK,OCIE0);
}

void TIMER_voidSetPreload(u8 Copy_u8PreloadValue){
    TCNT0=Copy_u8PreloadValue;
}

void TIMER_voidEnable(void){
      
        TCCR0&=0b11111000;
        TCCR0|=TIMER_PRESCALER;
}

void TIMER_voidDisable(void){
             CLR_BIT(TCCR0,CS00);              
             CLR_BIT(TCCR0,CS01);              
             CLR_BIT(TCCR0,CS10);  
}

void TIMER_voidSetCallBackFun(void (* Copy_pvCallBack)(void),Timers_Interrupt interruptNum){
      
       if(Copy_pvCallBack!=NULL){
            TIMER_pCallBack[interruptNum]=Copy_pvCallBack;
       }  
}


void __vector_10(void) __attribute__((signal));
void __vector_10(void){
       
		    	  TIMER_pCallBack[TIMER0_COMP]();
       	    	
    
}

void __vector_11(void) __attribute__((signal));
void __vector_11(void){

	 Global_u32Counter++;

		      if(Global_u32Counter==Global_u32OverFlowCounts){
		    	  TIMER_pCallBack[TIMER0_OVF]();
		    	  Global_u32Counter=0;
		      }
}

u8 TIMER_u8GetCounts(void){
      return TCNT0;
}


void TIMER_voidSetDesiredTime_ms(u32 Copy_u32DesiredTime){
       u32 Local_u32TickTime          = preScale[TIMER_PRESCALER]*1000000/(F_CPU*1000000);
       u32 Local_u32TotalTicks        = Copy_u32DesiredTime*1000/Local_u32TickTime;
       #if TIMER_MODE == NORMAL_MODE
       u32 Local_u32OverflowTime      = Local_u32TickTime*OVERFLOW_COUNTS*1000;
       Global_u32OverFlowCounts       = Copy_u32DesiredTime/Local_u32OverflowTime;
       u32  Local_u32Reminder         = Local_u32TotalTicks%OVERFLOW_COUNTS;
      #elif TIMER_MODE == CTC_MODE
       u32 Local_u32OverflowTime      = Local_u32TickTime*Global_CompareVal*1000;
       Global_u32OverFlowCounts       = Copy_u32DesiredTime/Local_u32OverflowTime;
       u32  Local_u32Reminder         = Local_u32TotalTicks%Global_CompareVal;
      #endif 
        if(Local_u32Reminder!=0){
            Global_u32OverFlowCounts++;
        }

     TIMER_voidSetPreload(Local_u32OverflowTime-Local_u32Reminder);
}

void TIMER_voidSetCompareValue(u8 Copy_u8CompareVal){
    Global_CompareVal=Copy_u8CompareVal
	OCR0=Copy_u8CompareVal;
}


