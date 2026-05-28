Lesson 4 Overview:
We continue building our Embedded Controller Programming with Embedded C skills by focusing on the BSP, or Board Support Package.

BSP Concepts
BSP Data Structures
BSP Functions and Macros
Video 1:
https://www.youtube.com/watch?v=3q_WmjtiVQo
Video 2:
https://www.youtube.com/watch?v=Ril75UEUM0Q
Video 3:
https://www.youtube.com/watch?v=bxA4iFcD6R0
Video 4:
https://www.youtube.com/watch?v=3GMU6gtP0b0
Video 5:
https://www.youtube.com/watch?v=Cd39JVr0sFY
Video 6:
https://www.youtube.com/watch?v=WBnayXpbp78
Video 7 BOnus:
https://www.youtube.com/watch?v=8wYlvXojq7g
Lesson 4: assignment:
This Assignment will certify your Embedded C skills related to the following:

Your skills for using the BSP driver to read the status of the Blue button on the STM32 Discovery Board
Your skills for using the BSP driver to turn an LED on/off
Your skills for using the BSP driver to read the temperature from the HTS221 Humidity/Temperature Sensor 
Your skills for using STM32CubeIDE tool to generate code that include BSP drivers.
Here are the requirements for this assignment:

=1= Use STM32CubeIDE to generate the default code for the STM32 Discovery Board.
=2= Include BSP code in your project
=3= Use STM32CubeIDE to edit, build, run, and debug the code that uses the BSP API to (1) read the temperature, BSP_TSENSOR_ReadTemp(), read the blue push button status, BSP_PB_GetState(), and turn the LED on if button pressed, BSP_LED_On(), or turn LED off, BSP_LED_Off(), if button not pressed. Repeat this loop every 1 second.

To certify that you have completed the above skills, you should create a PDF document similar to the one attached to this assignment. The PDF document should include screen shots from your system and also clearly state your name. Use the attached PDF as a template or guide, but you should replace the screen shots with your specific screen shots and your name.

NOTE: Please name your PDF using this naming convention: UCSD-Embedded-C-Assignment-4-BSP-FirstName-LastName.pdf and then submit for grading.

Lesson 4 Quiz;
As related to Embedded C development, what is the definition of BSP?
  Boot Support Package 
  Board Support Package 
  Boot Support Protocol 
  Bad Serial Protocol 
 
Correct answer
Question 2
1 / 1 pts
Select the statement below that is TRUE when comparing BSP and HAL.
  BSP and HAL are different names for the same API 
  BSP is a newer API that has replaced HAL 
  HAL is a higher-level API than BSP, i.e. HAL functions call BSP functions. 
  BSP is a higher-level API than HAL, i.e., BSP functions call HAL functions. 
 
Correct answer
Question 3
1 / 1 pts
Select the TRUE statement below about the Drivers/BSP/Components directory.
  The Drivers/BSP/Components directory contains the LL implementation code.
  The Drivers/BSP/Components directory contains directories for each board supported, e.g. B-L475-IOT01 directory.
  The Drivers/BSP/Components directory contains subdirectories that contain .h and .c files for actual hardware components, e.g. hts221.h, hts221.c. 
  The Drivers/BSP/Components directory contains the HAL implementation code.
 
Correct answer
Question 4
1 / 1 pts
You are writing an embedded application for the STM32 Discovery board. You want to read from the temperature sensor. Which answer below provides the highest-level of abstraction, and hence the easiest for you to use?
  BSP_TSENSOR_ReadTemp() 
  HTS221_T_ReadTemp() 
  LL_SENSOR_Read() 
  HAL_SENSOR_Read() 
 
Correct answer
Question 5
1 / 1 pts
When using TrueStudio with BSP, what did we do differently compared to what we did with LL and HAL APIs?
  No change was required. BSP APis "just worked" in the same manner as HAL APIs.
  We had to reconfigure the stm32l4xx_ll_conf.h to work with BSP. 
  We had to drag/drop the Drivers/BSP/Components directory into our project. 
  We had to reconfigure the stm32l4xx_hal_conf.h to work with BSP. 
