#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../DIO/DIO_interface.h"
#include "GIE_register.h"
#include "GIE_private.h"
#include "GIE_config.h"
#include "GIE_interface.h"
#include "GIE_program.h"

void GIE_voidInterruptEnable(){
    SET_BIT(SREG,SREG_INT_Pin); 
}

void GIE_voidInterruptDisable(){
    CLR_BIT(SREG,SREG_INT_Pin); 
}
