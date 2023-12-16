#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "7SEG_config.h"
#include "7SEG_interface.h"
#include "7SEG_private.h"

void SEVEN_voidInit(SEVEN_Config seven1)
{
  for (int i = 0; i < 7; i++)
  {
    DIO_voidSetPortDirection(seven1.port, DIO_alloutput);
  }
}
void SEVEN_voidDisplay(SEVEN_Config seven1, u8 num)
{
  if (num >= 0 && num <= 9)
  {
#if defined COMMAN_CATHODE
    DIO_voidSetPortValue(seven1.port, seven_seg[num]);
#elif defined COMMAN_ANODE
    DIO_voidSetPortValue(seven1.port, ~(seven_seg[num]));
  }
#endif
  }
