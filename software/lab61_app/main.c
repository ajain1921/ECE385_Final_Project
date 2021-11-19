// Main.c - makes LEDG0 on DE2-115 board blink if NIOS II is set up correctly
// for ECE 385 - University of Illinois - Electrical and Computer Engineering
// Author: Zuofu Cheng

int main()
{
	int i = 0;
	volatile unsigned int *LED_PIO = (unsigned int*)0x70; //make a pointer to access the PIO block
	volatile unsigned int *SW_PIO = (unsigned int*)0x60; //make a pointer to access the PIO block
	volatile unsigned int *KEY_PIO = (unsigned int*)0x50; //make a pointer to access the PIO block

	*LED_PIO = 0; //clear all LEDs
	unsigned int sum = 0;
	while ( (1+1) != 3) //infinite loop
	{
		for (i = 0; i < 100000; i++); //software delay
		*LED_PIO |= 0x1; //set LSB
		for (i = 0; i < 100000; i++); //software delay
		*LED_PIO &= ~0x1; //clear LSB
		/*if (*KEY_PIO == 0){
			sum = *SW_PIO + *LED_PIO;
			if (sum > 0xFF){
				*LED_PIO = sum - 0x100;
			}
			else {
				*LED_PIO = sum;
			}
			while(*KEY_PIO == 0){}
		}*/
	}
	return 1; //never gets here
}
