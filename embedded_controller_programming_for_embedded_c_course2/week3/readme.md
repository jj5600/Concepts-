Week 3:
Overview:
We continue building our Embedded Controller Programming with Embedded C skills by focusing on the HAL, or Hardware Abstraction Layer.

HAL Concepts
HAL Data Structures
HAL Functions and Macros

Video 1:
https://www.youtube.com/watch?v=RMWx-gYd3ZQ
Video 2:
https://www.youtube.com/watch?v=adyBnmAqzNw
Video 3:
https://www.youtube.com/watch?v=kG0u2_b_8SE
Video 4:
https://www.youtube.com/watch?v=8QjNURmsHjo
Bonus Vid:
https://www.youtube.com/watch?v=1aNvt06m06c

Assignment 3:
This Assignment will certify your Embedded C skills related to the following:

Your skills for using the STM32CubeIDE to generate a project that uses HAL
Your skills for using the HAL driver to turn an LED on/off (LED2)
Your skills for using the HAL to read the state of a Push Button (BUTTON_EXTI13)
Your skills for using STM32CubeIDE tool to generate code that include HAL drivers.
 

Here are the requirements for this assignment:

=1= Use STM32CubeIDE to generate the default code for the STM32 Discovery Board, being sure to include the HAL when generating the code.
=2= Add code to blink the LED2 at 250 ms when the Blue Push Button in GPIO_PIN_SET condition
=3= Add code to blink the LED2 at 1000 ms when the Blue Push Button is in GPIO_PIN_RESET condition
=4= Use HAL to read the state of the Blue Push Button, hence changing the rate of LED flash (as in #2 and #3)

NOTE! If you have not yet received your STM32 Discovery board, you do not have to run the code. Rather, just build the code and you can run the code later once you receive your STM32 Discovery Board.

To certify that you have completed the above skills, you should create a PDF document similar to the one attached to this assignment. The PDF document should include screen shots from your system and also clearly state your name. Use the attached PDF as a template or guide, but you should replace the screen shots with your specific screen shots and your name.

NOTE: Please name your PDF using this naming convention: UCSD-Embedded-C-Assignment-3-HAL-FirstName-LastName.pdf and then submit for grading.

 
Quiz 3:
Question 1
1 / 1 pts
What is the definition of HAL?
  Hardware Abstraction Layer 
  Handle Absolute Lower 
  Handle All Layers 
  High Abstraction Level 
 
Correct answer
Question 2
1 / 1 pts
HAL drivers provide three programming modes. Which mode listed below is NOT one of the HAL programming modes?
  Polling Mode 
  Turbo Mode 
  DMA Driven Mode 
  Interrupt Mode 
 
Correct answer
Question 3
1 / 1 pts
Which answer listed below is NOT a HAL feature?
  HAL APIs are not RTOS compliant. 
  HAL provides cross-family portability across the STM32 portfolio. 
  HAL supports peripheral muli-instance operation. 
  HAL provides an object locking mechanism to ensure safe hardware access. 
 
Correct answer
Question 4
1 / 1 pts
Select the item below that is FALSE as it relates to HAL APIs.
  HAL Extension APIs provide specific functions that go beyond the generic HAL APIs. 
  Including a single include file (e.g. stm32l4xx_hal.h) in the user-mode code will include common configs and the other HAL include files. 
  HAL Generic APIs apply to a subset of STM32 devices. 
  Related to a generic peripheral PPP, two of the state and error functions are:
HAL_PPP_GetState()
HAL_PPP_GetError()
 
Correct answer
Question 5
1 / 1 pts
Select the answer below that is NOT a HAL data tytpe.
  UART_InitTypeDef 
  HAL_LockTypeDef 
  HAL_StatusTypeDef 
  DataType_HAL 
Attachments

