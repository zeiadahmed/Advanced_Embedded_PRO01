#include "IntCtrl.h"
#include "Dio.h"
#include "Std_Types.h"
#include "Port_Int.h"
#include "Port_Int_Cfg.h"
int main(void)
{
	Dio_PortType portA = PortA;
	Dio_PortLevelType value=0 ;
	Dio_ChannelType PORTA3 = {PortA,Pin3};
	Port_Init(ConfigType);
	uint32 i;
	while(1)
	{
		value=0;
		for(i=0;i<255;i++){
			value++;
			Dio_WritePort(PortB,value);
			
		
	}
		for(i=0;i<255;i++){
			value--;
			Dio_WritePort(PortB,value);
			
		
	}
}
	return 0;
}