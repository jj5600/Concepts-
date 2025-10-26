/*
Write a function, in C, called " ReverseBits
that takes in a ovte value and returns it in reverse bit order. 
In other words, bit O becomes bit 7, bit 1 becomes bit 6, etc. 
The argument should be passed by value not by pointer.
Choose the parameter type you feel is most appropriate For ar
embedded system
Example input: 0x58 . // binary =
01011000
Correct output: 0x1A. // binary =
00011010
*/

#include <stdint.h>
#include <stdio.h>

uint8_t ReverseBits(uint8_t param)
{
  uint8_t R = 0;
  for(int x =0; x<8; x++)
  {
    R = (R << 1U) | (param & 1U);
    param >>=1U;
  }
  return R;
}
