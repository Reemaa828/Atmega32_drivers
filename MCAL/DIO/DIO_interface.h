#ifndef _DIO_INTERFACE_H
#define _DIO_INTERFACE_H

typedef enum {
    DIO_allinput=0x00,
    DIO_alloutput=0xff
} DIO_PortDirection;


typedef enum{
    DIO_input,
    DIO_output
}DIO_PinDirection;

typedef enum {
    DIO_pin0,
    DIO_pin1,
    DIO_pin2,
    DIO_pin3,
    DIO_pin4,
    DIO_pin5,
    DIO_pin6,
    DIO_pin7,
} DIO_PinNumber;

typedef enum{
    DIO_low,
    DIO_high
}DIO_PinValue;
typedef enum{
    DIO_alllow=0x00,
    DIO_allhigh=0xff
}DIO_PortValue;

void DIO_voidSetPortDirection(u8  Copy_u8Port, DIO_PortDirection direction);
void DIO_voidSetPortValue(u8 Copy_u8Port,DIO_PortValue value);
void DIO_voidSetPinDirection(u8 Copy_u8Port,DIO_PinNumber pin,DIO_PinDirection direction);
void DIO_voidSetPinValue(u8 Copy_u8Port,DIO_PinNumber pin,DIO_PinValue value);
u8   DIO_u8GetPinValue(u8 Copy_u8Port,DIO_PinNumber pin);
void DIO_voidEnablePullupResistor(u8 Copy_u8Port,DIO_PinNumber pin);
void DIO_voidTogglePin(u8 Copy_u8Port,DIO_PinNumber pin);

#endif