#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define TIME_REQ 10

enum States{
    IDLE = 0,
    PUSH_UNSTABLE,
    PUSH,
    RELEASE_UNSTABLE
};

int main(void)
{
    long getTime;
    long startTime;
    uint8_t currentState = IDLE;
    uint8_t currentGPIOlvl;
    while(1)
    {
	    getTime = millis();
	    currentGPIOlvl = isbuttonpushed(); 
      switch(currentState)
      {
            case IDLE:
                if(currentGPIOlvl == 0){ startTime = getTime; currentState = PUSH_UNSTABLE;}
                break;
            case PUSH_UNSTABLE:
                if((currentGPIOlvl == 0) && (getTime - startTime >= TIME_REQ)) { currentState = PUSH; toggleLED(); }
                break;
            case PUSH:
                if((currentGPIOlvl == 1)){startTime = getTime; currentState = RELEASE_UNSTABLE;}
                break;
            case RELEASE_UNSTABLE:
                if((currentGPIOlvl == 1)&&(getTime - startTime >= TIME_REQ)) {currentState = IDLE; }
                break;
            default:
                break;
        }
        
    }
   
}
