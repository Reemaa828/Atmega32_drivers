#ifndef MCAL_TIMER_TIMER_CONFIG_H_
#define MCAL_TIMER_TIMER_CONFIG_H_

/***************************************/
/*          TIMER_MODE options         */
/*    1- NORMAL_MODE                   */
/*    2- CTC_MODE                      */
/*    3- FAST_PHASE_MODE               */
/*    4- PHASE_CORRECT_MODE            */
/***************************************/
#define TIMER_MODE               NORMAL_MODE

/***************************************/
/*       TIMER_OCO_NON_PWM options     */
/*    1- PORT_VALUE                    */
/*    2- TOGGLE_OCO                    */
/*    3- CLEAR_OCO                     */
/*    4- SET_OCO                       */
/***************************************/
#define TIMER_OCO_NON_PWM        TOGGLE_OCO 

/***************************************/
/*       TIMER_PRESCALER options       */
/*    1- _1_                           */
/*    2- _8_                           */
/*    3- _64_                          */
/*    4- _256_                         */
/*    5- _1024_                        */
/*    6- EXTERNAL_cLOCK_FALLING_EDGE   */
/*    7- EXTERNAL_cLOCK_RISING_EDGE    */
/***************************************/
#define TIMER_PRESCALER        _1_ 

#define OVERFLOW_COUNTS 256
#define TIMER_RESOLUTION 8


#endif