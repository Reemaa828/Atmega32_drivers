#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "LED_config.h"
#include "LED_interface.h"
#include "LED_private.h"

void LED_voidinit(LED_Config LED){
    DIO_voidSetPinDirection(LED.port,LED.pin,output);
    DIO_voidSetPinValue(LED.port,LED.pin,LED.connection);
}

void LED_voidTurnOn(LED_Config LED){
    if(LED.connection==sink){
    DIO_voidSetPinValue(LED.port,LED.pin,low);
    }
    else if(LED.connection==source){
        DIO_voidSetPinValue(LED.port,LED.pin,high);
    }
}

void LED_voidTurnOFF(LED_Config LED){
    if(LED.connection==sink){
    DIO_voidSetPinValue(LED.port,LED.pin,high);
    }
    else if(LED.connection==source){
        DIO_voidSetPinValue(LED.port,LED.pin,low);
    }
}
