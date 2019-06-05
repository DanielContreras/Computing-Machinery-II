#include <unistd.h>
#include "GPIO_INIT.h"

#define GPIO_BASE 0x3F200000

static unsigned *gpio = (unsigned*)GPIO_BASE;

#define INP_GPIO(g) *(gpio + ((g)/10)) &= ~(7<<(((g)%10)*3))
#define OUT_GPIO(g) *(gpio + ((g)/10)) |= (1<<(((g)%10)*3))
#define SET_GPIO_ALT(g, a) *(gpio + (((g)/10))) |= (((a) <= 3? (a) + 4: (a) == 4 ? 3 : 2) << (((g)%10)*3))

#define CLK 11
#define LAT 9
#define DAT 10

#define CLO_REG 0x3F003004

unsigned *clo = (unsigned*)CLO_REG;


int main()
{
	//unsigned int *gpio = gpioPtr();
    
	
	// Set GPIO 17 function (set output function 001 in Function Select Register 1 bits 21-23
	//gpio[1] = ((gpio[1] & ~(0b111<<21)) | (0b001<<21));
	
	//while (1)
    //{
		
        // Write 1 in set register 0 bit 17 (Set GPIO 17)
		//gpio[7] = 1<<17;
		
		// Delay for 1 second
		//sleep(1);
		
		// Write 1 in clear register 0 bit 17 (Clear GPIO 17)
		//gpio[10] = 1<<17;
		
		// Delay for 1 second
		//sleep(1);
	//}
}

void initSNES()
{
    INP_GPIO(CLK);
    OUT_GPIO(CLK);
    INP_GPIO(LAT);
    OUT_GPIO(LAT);
    INP_GPIO(DAT);
    OUT_GPIO(DAT);
}

