#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "LED_config.h"
#include "LED_interface.h"
#include "LED_private.h"

void LED_voidInit(LED_Config LED){
    DIO_voidSetPinDirection(LED.port,LED.pin,DIO_output);
}

void LED_voidTurnOn(LED_Config LED){
    if(LED.connection==LED_sink){
    DIO_voidSetPinValue(LED.port,LED.pin,DIO_low);
    }
    else if(LED.connection==LED_source){
        DIO_voidSetPinValue(LED.port,LED.pin,DIO_high);
    }
}

void LED_voidTurnOff(LED_Config LED){
    if(LED.connection==LED_sink){
    DIO_voidSetPinValue(LED.port,LED.pin,DIO_high);
    }
    else if(LED.connection==LED_source){
        DIO_voidSetPinValue(LED.port,LED.pin,DIO_low);
    }
}

void LED_voidToggle(LED_Config LED){
    DIO_voidTogglePin(LED.port,LED.pin);
}

