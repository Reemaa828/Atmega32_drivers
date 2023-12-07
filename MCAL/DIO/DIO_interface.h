#ifndef _DIO_INTERFACE_H
#define _DIO_INTERFACE_H

typedef enum {
    allinput=0x00,
    alloutput=0xff
} DIO_PortDirection;

typedef enum{
    input,
    output
}DIO_PinDirection;

typedef enum {
    Pin0,
    Pin1,
    Pin2,
    Pin3,
    Pin4,
    Pin5,
    Pin6,
    Pin7,
} DIO_PinNumber;

typedef enum{
    low,
    high
}DIO_PinValue;

void DIO_voidSetPortDirection(u8  Copy_u8Port, DIO_PortDirection direction);
void DIO_voidSetPortValue(u8 Copy_u8Port,u8 Copy_u8Value);
void DIO_voidSetPinDirection(u8 Copy_u8Port,DIO_PinNumber pin,DIO_PinDirection direction);
void DIO_voidSetPinValue(u8 Copy_u8Port,DIO_PinNumber pin,DIO_PinValue value);
u8   DIO_u8GetPinValue(u8 Copy_u8Port,DIO_PinNumber pin);
void DIO_voidEnablePullupResistor(u8 Copy_u8Port,DIO_PinNumber pin);

#endif