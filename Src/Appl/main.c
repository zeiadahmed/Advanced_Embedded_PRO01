


int main(void)
{

	Interrupt_Init();
	Timer_Init();
	Gpio_Init();

	while (1)
	{

		Detect_Press();
		Flip_Led();
	}
	return 0;
}