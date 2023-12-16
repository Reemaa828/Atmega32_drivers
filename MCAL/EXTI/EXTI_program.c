#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../DIO/DIO_interface.h"
#include "EXTI_register.h"
#include "EXTI_private.h"
#include "EXTI_config.h"
#include "EXTI_interface.h"
#include "EXTI_program.h"
//---------------------------------------------------------------------------------------
/*****************************************************************
 *                   prebuild config function
 *****************************************************************/
void (*EXTI_pvCallBack[3])(void)={NULL};
void EXTI_voidInterruptInit()
{
#if EXTERNAL_INTERRUPT == EXTI0
     SET_BIT(GICR,6);
      #if EXTERNAL_INTERRUPT_TRIGGER == EXTI_LowLevel
    CLR_BIT(MCUCR, 0);
    CLR_BIT(MCUCR, 1);
      #elif EXTERNAL_INTERRUPT_TRIGGER == EXTI_AnyLogicalChange
    SET_BIT(MCUCR, 0);
    CLR_BIT(MCUCR, 1);
      #elif EXTERNAL_INTERRUPT_TRIGGER == EXTI_FallingEdge
    CLR_BIT(MCUCR, 0);
    SET_BIT(MCUCR, 1);
      #elif EXTERNAL_INTERRUPT_TRIGGER == EXTI_RisingEdge
    SET_BIT(MCUCR, 0);
    SET_BIT(MCUCR, 1);
      #endif
#elif EXTERNAL_INTERRUPT == EXTI1
     SET_BIT(GICR,7);
      #if EXTERNAL_INTERRUPT_TRIGGER == EXTI_LowLevel
    CLR_BIT(MCUCR, 2);
    CLR_BIT(MCUCR, 3);
      #elif EXTERNAL_INTERRUPT_TRIGGER == EXTI_AnyLogicalChange
    SET_BIT(MCUCR, 2);
    CLR_BIT(MCUCR, 3);
      #elif EXTERNAL_INTERRUPT_TRIGGER == EXTI_FallingEdge
    CLR_BIT(MCUCR, 2);
    SET_BIT(MCUCR, 3);
      #elif EXTERNAL_INTERRUPT_TRIGGER == EXTI_RisingEdge
    SET_BIT(MCUCR, 2);
    SET_BIT(MCUCR, 3);
      #endif
#elif EXTERNAL_INTERRUPT == EXTI2
       SET_BIT(GICR,5);
        #if EXTERNAL_INTERRUPT_TRIGGER == EXTI_FallingEdge
    CLR_BIT(MCUCSR, 6);
       #elif EXTERNAL_INTERRUPT_TRIGGER == EXTI_RisingEdge
    SET_BIT(MCUCSR, 6);
       #endif
#endif
}

void EXTI_voidInterruptEnable(External_Interrupt interrupt_num,u8 Copy_u8SenseMode){
    switch (interrupt_num){
        case EXTI0:
        SET_BIT(GICR,EXTI0);
         switch (Copy_u8SenseMode){
            case EXTI_LowLevel:          CLR_BIT(MCUCR, 0);
                                         CLR_BIT(MCUCR, 1);
                                         break;
            case EXTI_AnyLogicalChange:  SET_BIT(MCUCR, 0);
                                         CLR_BIT(MCUCR, 1);
                                          break;
            case EXTI_FallingEdge:       CLR_BIT(MCUCR, 0);
                                         SET_BIT(MCUCR, 1);
                                         break;
            case EXTI_RisingEdge:        SET_BIT(MCUCR, 0);
                                         SET_BIT(MCUCR, 1);
                                          break;
        }
        break;
        case EXTI1:
        SET_BIT(GICR,EXTI1);
         switch (Copy_u8SenseMode){
            case EXTI_LowLevel:          CLR_BIT(MCUCR, 2);
                                         CLR_BIT(MCUCR, 3);
                                         break;
            case EXTI_AnyLogicalChange:  SET_BIT(MCUCR, 2);
                                         CLR_BIT(MCUCR, 3);
                                          break;
            case EXTI_FallingEdge:       CLR_BIT(MCUCR, 2);
                                         SET_BIT(MCUCR, 3);
                                         break;
            case EXTI_RisingEdge:        SET_BIT(MCUCR, 2);
                                         SET_BIT(MCUCR, 3);
                                          break;
        }
        break;
        case EXTI2:
        SET_BIT(GICR,EXTI2);
         switch (Copy_u8SenseMode){
            case EXTI_FallingEdge:       CLR_BIT(MCUCSR, 6);
                                         break;
            case EXTI_RisingEdge:        SET_BIT(MCUCSR, 6);
                                          break;
        }
        break;
       

    }
 
}
void EXTI_voidInterruptDisable(External_Interrupt interrupt_num){
      switch (interrupt_num){
        case EXTI0:
        SET_BIT(GICR,EXTI0);
        break;

        case EXTI1:
        SET_BIT(GICR,EXTI1);
        break;

        case EXTI2:
        SET_BIT(GICR,EXTI2);
        break;
    }

}
u8 EXTI_u8GetFlag(External_Interrupt interrupt_num){
     return GET_BIT(GIFR,interrupt_num);
}
void EXTI_voidCLearFlag(External_Interrupt interrupt_num){
    CLR_BIT(GIFR,interrupt_num);
}

void EXTI_voidSetCallBack(void (*Copy_pvCallBack)(void),External_Interrupt interrupt_num){
    EXTI_pvCallBack[interrupt_num]=Copy_pvCallBack;
}

void _vector_1(void) __attribute__((signal));
void _vector_1(void) {
    EXTI_pvCallBack[0]();
}
void _vector_2(void) __attribute__((signal));
void _vector_2(void) {
    EXTI_pvCallBack[1]();
}
void _vector_3(void) __attribute__((signal));
void _vector_3(void) {
    EXTI_pvCallBack[2]();
}
