/*You're working with a device that has a 16-bit register at 0x1000 that controls an LED bank
If the bit is set, the LED is on; if it is cleared, the LED is off. Write a function that toggles
the state of one of the LEDs*/
#include <stdio.h>
#include <stdint.h>
// this register mapping is super important
volatile uint16_t * REG = (uint16_t *)0x1000;

void enable_led(uint8_t pin_select)
{
    // utilize XOR to toggle the reg
     *REG ^= (1<<pin_select);
}



/* in my impelmentation I messed up the register mapping
I ended up creating a :

volatile uint16_t status = 0x0; 

this register is write only 
so basically I would be able to do:

*REG = status ^ (1 << pin_select);
status ^= (1<< pin_selct);

one to track the status and antoher to write to the reg
to keep track of the state;

*/

