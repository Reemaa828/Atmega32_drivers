#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include "DIO_cofig.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_register.h"

void DIO_voidSetPortDirection(u8 Copy_u8Port, DIO_PortDirection direction)
{
   switch (Copy_u8Port)
   {
   case 'A':
   case 'a':
      DDRA = direction;
      break;

   case 'B':
   case 'b':
      DDRB = direction;
      break;

   case 'C':
   case 'c':
      DDRC = direction;
      break;

   case 'D':
   case 'd':
      DDRD = direction;
      break;
   }
}

void DIO_voidSetPortValue(u8 Copy_u8Port, DIO_PortValue value)
{
   switch (Copy_u8Port)
   {

   case 'A':
   case 'a':
      PORTA = value;
      break;

   case 'B':
   case 'b':
      PORTB = value;
      break;

   case 'C':
   case 'c':
      PORTC = value;
      break;

   case 'D':
   case 'd':
      PORTD = value;
      break;
   }
}

void DIO_voidSetPinDirection(u8 Copy_u8Port, DIO_PinNumber pin, DIO_PinDirection direction)
{
   if (direction == DIO_input)
   {
      switch (Copy_u8Port)
      {
      case 'A':
      case 'a':
         CLR_BIT(DDRA, pin);
         break;
      case 'B':
      case 'b':
         CLR_BIT(DDRB, pin);
         break;
      case 'C':
      case 'c':
         CLR_BIT(DDRC, pin);
         break;
      case 'D':
      case 'd':
         CLR_BIT(DDRD, pin);
         break;
      }
   }
   else if (direction == DIO_output)
   {
      switch (Copy_u8Port)
      {
      case 'A':
      case 'a':
         SET_BIT(DDRA, pin);
         break;
      case 'B':
      case 'b':
         SET_BIT(DDRB, pin);
         break;
      case 'C':
      case 'c':
         SET_BIT(DDRC, pin);
         break;
      case 'D':
      case 'd':
         SET_BIT(DDRD, pin);
         break;
      }
   }
}

void DIO_voidSetPinValue(u8 Copy_u8Port, DIO_PinNumber pin, DIO_PinValue value)
{
   if (value == DIO_low)
   {
      switch (Copy_u8Port)
      {
      case 'A':
      case 'a':
         CLR_BIT(PORTA, pin);
         break;
      case 'B':
      case 'b':
         CLR_BIT(PORTB, pin);
         break;
      case 'C':
      case 'c':
         CLR_BIT(PORTC, pin);
         break;
      case 'D':
      case 'd':
         CLR_BIT(PORTD, pin);
         break;
      }
   }
   else if (value == DIO_high)
   {
      switch (Copy_u8Port)
      {
      case 'A':
      case 'a':
         SET_BIT(PORTA, pin);
         break;
      case 'B':
      case 'b':
         SET_BIT(PORTB, pin);
         break;
      case 'C':
      case 'c':
         SET_BIT(PORTC, pin);
         break;
      case 'D':
      case 'd':
         SET_BIT(PORTD, pin);
         break;
      }
   }
}

u8 DIO_u8GetPinValue(u8 Copy_u8Port, DIO_PinNumber pin)
{
   u8 retval;
   switch (Copy_u8Port)
   {
   case 'A':
   case 'a':
      retval = GET_BIT(PINA, pin);
      break;
   case 'B':
   case 'b':
      retval = GET_BIT(PINB, pin);
      break;
   case 'C':
   case 'c':
      retval = GET_BIT(PINC, pin);
      break;
   case 'D':
   case 'd':
      retval = GET_BIT(PIND, pin);
      break;
   }
   return retval;
}

void DIO_voidEnablePullupResistor(u8 Copy_u8Port, DIO_PinNumber pin)
{
   switch (Copy_u8Port)
   {
   case 'A':
   case 'a':
      SET_BIT(PORTA, pin);
      break;
   case 'B':
   case 'b':
      SET_BIT(PORTB, pin);
      break;
   case 'C':
   case 'c':
      SET_BIT(PORTC, pin);
      break;
   case 'D':
   case 'd':
      SET_BIT(PORTD, pin);
      break;
   }
}

void DIO_voidTogglePin(u8 Copy_u8Port, DIO_PinNumber pin)
{
   switch (Copy_u8Port)
   {
   case 'A':
   case 'a':
      TOGGLE_BIT(PORTA,pin);
      
      break;
   case 'B':
   case 'b':
      TOGGLE_BIT(PORTB,pin);
      break;
   case 'C':
   case 'c':
      TOGGLE_BIT(PORTC,pin);
      break;
   case 'D':
   case 'd':
      TOGGLE_BIT(PORTD,pin);
      break;
   }
}
