#include <stdint.h>
#include <stdbool.h>

#define DEBOUNCE_TIME_MS 20

extern bool read_button_gpio(void);
extern uint32_t get_system_time_ms(void);

typedef enum states {
    FREE,
    UNSTABLE_PRESS,
    PRESSED,
    UNSTABLE_RELEASE
} eSTATES;

bool check_button_debounced(void) {
    static uint32_t StartTime = 0;
    static eSTATES buttonState = FREE;
    bool buttonSample = read_button_gpio();
    
    switch(buttonState) {
        case FREE:
            if(buttonSample == false) // button is pushed
            {
                StartTime = get_system_time_ms();
                buttonState = UNSTABLE_PRESS;
            }
            break;
            
        case UNSTABLE_PRESS:
            if(buttonSample == false)
            {
                if(get_system_time_ms() - StartTime >= DEBOUNCE_TIME_MS)
                {
                    buttonState = PRESSED;
                    return true;
                }
            }
            else 
            {
                buttonState = FREE; // Bounce detected, reset
            }
            break;
            
       case PRESSED:
            if(buttonSample == true)
            {
                StartTime = get_system_time_ms();
                buttonState = UNSTABLE_RELEASE;
            }
            break;
            
        case UNSTABLE_RELEASE:
            if(buttonSample == true)
            {
                if((get_system_time_ms() - StartTime) >= DEBOUNCE_TIME_MS)
                {
                    buttonState = FREE;
                }
            }
            else 
            {
                buttonState = PRESSED; // Bounce detected, reset
            }
            break;
            
        default:
            buttonState = FREE;
            break;
    }
    return false;
}
