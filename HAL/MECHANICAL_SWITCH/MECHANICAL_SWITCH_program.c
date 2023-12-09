#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "MECHANICAL_SWITCH_interface.h"
#include "MECHANICAL_SWITCH_config.h"
#include "MECHANICAL_SWITCH_private.h"

void SW_voidInit(SW_Config switch1){
    if(switch1.connection==SW_INT_PULL_UP){
        DIO_voidEnablePullupResistor(switch1.port,switch1.pin);
    }
    DIO_voidSetPinDirection(switch1.port,switch1.pin,DIO_input);
}

u8 SW_u8ReadSwitch(SW_Config switch1){
    u8 pinval;
    u8 retval;
    pinval= DIO_u8GetPinValue(switch1.port,switch1.pin);
    if(switch1.connection==SW_INT_PULL_UP||switch1.connection==SW_EXT_PULL_UP){
       
       if(pinval==0){
        retval=SW_PRESSED;
       }
       else if(pinval==1){
        retval=SW_NOT_PRESSED;
       }
    }
    else if (switch1.connection==SW_EXT_PULL_DOWN)
    {
        if(pinval==1){
        retval=SW_PRESSED;
       }
       else if(pinval==0){
        retval=SW_NOT_PRESSED;
    }
    }
    
    return retval;
}

