#include "IntCtrl.h"
#include "Dio.h"
#include "Std_Types.h"
#include "Port_Int.h"
#include "Port_Int_Cfg.h"
#include "Gpt.h"
int main(void)
{
	// Dio_PortType portA = PortB;
	// Dio_PortLevelType value=0 ;
	// Dio_ChannelType PORTA3 = {PortA,Pin3};
	
	// uint32 i;
	
	IntCtrl_Init();
	
	Gpt_Init(Gpt_Cfg);


	Port_Init(ConfigType);
	while(1)
	{
		
	// 	value=0;
	// 	for(i=0;i<255;i++){
	// 		value++;
			Gpt_ValueType time = Gpt_GetTimeRemaining(Gpt_Cfg[0].channelId);
			Dio_WritePort(PortB,time);
			
		
	// }
	// 	for(i=0;i<255;i++){
	// 		value--;
	// 		Dio_WritePort(PortB,value);
			
		
	// }
}
	return 0;
}