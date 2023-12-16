#ifndef MCAL_EXTI_EXTI_CONFIG_H_
#define MCAL_EXTI_EXTI_CONFIG_H_

/**********OPTIONS*****************
 *     EXTI0 FOR INTERRUPT 0
 *     EXTI1 FOR INTERRUPT 1
 *     EXTI2 FOR INTERRUPT 2
************************************/
#define EXTERNAL_INTERRUPT                  EXTI0
/**********OPTIONS*****************
 *   
 * EXTI_LowLevel          
   EXTI_AnyLogicalChange  
   EXTI_FallingEdge       
   EXTI_RisingEdge        

************************************/
#define EXTERNAL_INTERRUPT_TRIGGER         EXTI_FallingEdge 

#endif