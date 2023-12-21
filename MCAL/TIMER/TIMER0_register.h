#ifndef MCAL_TIMER_TIMER_REGISTER_H_
#define MCAL_TIMER_TIMER_REGISTER_H_


#define TCCR0                          *((volatile u8 *)(0x53))
#define CS00                            0
#define CS01                            1
#define CS10                            2
#define WGM01                           3
#define WGM00                           6
#define COM00                           4
#define COM01                           5
#define F0C0                            7

#define TCNT0                           *((volatile u8 *)(0x52))

#define TIMSK                           *((volatile u8 *)(0x59))
#define TOIE0                           0
#define OCIE0                           1

#define TIFR                            *((volatile u8 *)(0x58))
#define TOV0                            0
#define OCF0                            1
#endif