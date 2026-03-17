These are the required reading texts for this module. You can expect this content to appear in assignments or exams.

Read section 3.5(Memory System Mechanisms), 3.6(CPU Performance)  from textbook

This assignment is connected to the following student learning outcomes from the syllabus.

1. The quiz is covering your understanding your knowledge of Cache and MMU's
2. The Lab assignment is to give you exposure to using interrupts and using external inputs. 

Student Learning Outcomes 
Do you have questions about this assignment?
Post your questions in the Ask the Instructor Forum, located towards the top of the Modules area of this course.

Instructions
1.
Quiz #3

2.
Lab: In this assignment I want you to use the User button(blue colored) on the STM32 to create an interrupt when the button is pressed.
The button press interrupt should then cause the LED to toggle. You should use a global flag like "button_event" that should be set by the
interrupt handler and should be checked in the while loop in the main code. If the button_event is set, then the button_event flag should be reset and the LED should be toggled.
For this assignment, use the HAL_GPIO_EXTI_Callback() weak function.
A weak function is a default implementation that 
can be replaced (overridden) by your own function with the same name.
You will find the weak function defined in 
the Drivers-> Src -> stm32l4xx_hal_gpio.c


__weak void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)


{
/* Prevent unused argument(s) compilation warning */
UNUSED(GPIO_Pin);
/* NOTE: This function should not be modified, when the callback is needed,
the HAL_GPIO_EXTI_Callback could be implemented in the user file
*/
}


This weak function should be overridden in the main code by 
using an example like the following.
You can add this in the  "USER CODE BEGIN 4" section.
You will need to replace the "USER_Button_Pin" with the 
proper name used for the GPIO Pin used for 
the button. This information you will find by looking 
at the CubeMX application -> 
Pinout & Configuration section -> pinout view -> BUTTON_EXT??, 
now search for the exact BUTTON_EXT?? name in the main.h file, 
this will give you the #define pin# used for the button. 
Use this #define name in the place of the USER_Button_Pin. 
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  if(GPIO_Pin == USER_BUTTON_Pin)
  {
    button_event = 1;
  }
}

Note that the HAL_GPIO_EXTI_Callback function is called 
every time the GPIO external interrupt occurs.
The global button_event variable should be defined 
as a volatile before usage. 
It is set in the Call back function and should be 
polled in the main loop, if it is set, then it should
be reset and the LED should be toggled.
