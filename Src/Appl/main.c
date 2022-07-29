
#include "Dio.h"
#include "Std_Types.h"
#include "Gpt.h"
#include "Mcu_Hw.h"
int main(void)
{

	Interrupt_Init();
	Timer_Init();
	Gpio_Init();

	while(1)
	{
		

			Detect_Press();
			Flip_Led();
		
		
			


			
		

}
	return 0;
}