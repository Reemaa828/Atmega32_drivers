#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../DIO/DIO_interface.h"
#include "TIMER0_register.h"
#include "TIMER0_private.h"
#include "TIMER0_config.h"
#include "TIMER0_interface.h"



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
      #if   TIMER_PRESCALER == _1_ 
             SET_BIT(TCCR0,CS00);              
             CLR_BIT(TCCR0,CS01);              
             CLR_BIT(TCCR0,CS10);              
       #elif TIMER_PRESCALER == _8_   
             CLR_BIT(TCCR0,CS00);              
             SET_BIT(TCCR0,CS01);              
             CLR_BIT(TCCR0,CS10);             
       #elif TIMER_PRESCALER == _64_ 
             CLR_BIT(TCCR0,CS00);              
             SET_BIT(TCCR0,CS01);              
             SET_BIT(TCCR0,CS10);      
       #elif TIMER_PRESCALER == _256_  
             CLR_BIT(TCCR0,CS00);              
             CLR_BIT(TCCR0,CS01);              
             SET_BIT(TCCR0,CS10);      
      #elif TIMER_PRESCALER == _1024_  
             SET_BIT(TCCR0,CS00);              
             CLR_BIT(TCCR0,CS01);              
             SET_BIT(TCCR0,CS10);    
      #elif TIMER_PRESCALER == EXTERNAL_cLOCK_FALLING_EDGE 
             CLR_BIT(TCCR0,CS00);              
             SET_BIT(TCCR0,CS01);              
             SET_BIT(TCCR0,CS10);   
      #elif TIMER_PRESCALER == EXTERNAL_cLOCK_RISING_EDGE 
            SET_BIT(TCCR0,CS00);              
            SET_BIT(TCCR0,CS01);              
            SET_BIT(TCCR0,CS10);   
        #endif
}

void TIMER_voidDisable(void){
             CLR_BIT(TCCR0,CS00);              
             CLR_BIT(TCCR0,CS01);              
             CLR_BIT(TCCR0,CS10);  
}

void TIMER_voidSetCallBackFun(void (* Copy_pvCallBack)(void),Timers_Interrupt interruptNum){
      TIMER_pCallBack[interruptNum]=Copy_pvCallBack;
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


