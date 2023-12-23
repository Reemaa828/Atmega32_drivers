#ifndef MCAL_TIMER_TIMER_CONFIG_H_
#define MCAL_TIMER_TIMER_CONFIG_H_
#define DDRB        *((volatile u8*)(0X37))
#define _1_                         1
#define _8_                         2
#define _64_                        3
#define _256_                       4
#define _1024_                      5
#define EXTERNAL_CLOCK_FALLING_EDGE 6
#define EXTERNAL_CLOCK_RISING_EDGE  7
#define  PORT_VALUE                 0                
#define  TOGGLE_OCO                 1  
#define  CLEAR_OCO                  2
#define  SET_OCO                    3
#endif