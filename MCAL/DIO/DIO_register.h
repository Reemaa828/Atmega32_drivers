#ifndef _DIO_REGISTER_H
#define _DIO_REGISTER_H


#define DDRA    *((volatile u8*)(0X3A))
#define DDRB    *((volatile u8*)(0X37))
#define DDRC    *((volatile u8*)(0X34))
#define DDRD    *((volatile u8*)(0X31))

#define PORTA   *((volatile u8*)(0X3B))
#define PORTB   *((volatile u8*)(0X38))
#define PORTC   *((volatile u8*)(0X35))
#define PORTD   *((volatile u8*)(0X32))

#define PINA   *((volatile u8*)(0X39))
#define PINB   *((volatile u8*)(0X36))
#define PINC   *((volatile u8*)(0X33))
#define PIND   *((volatile u8*)(0X30))

#endif