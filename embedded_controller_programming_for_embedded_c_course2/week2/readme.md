week2:
Week2 Overview:
We continue building our Embedded Controller Programming with Embedded C with a look at the LL (Low-Layer) interface. This layer of C coding puts you very close to the hardware --- you deal directly with pointers to registers, pointer offsets to registers, and low-level bit patterns.  The good news of this layer is you have total and complete access to the hardware. The bad news is that code written at this layer is very much "hard coded" for a given machine.  

Accessing Memory, I/O, Registers
LL Embedded C Data Types
LL Embedded C Data Functions and Macros

Reading Assignment: Description of STM32L4/L4+ HAL and low-layer driver Chapter 4: Overview of low layer drivers
https://www.st.com/content/ccc/resource/technical/document/user_manual/63/a8/8f/e3/ca/a1/4c/84/DM00173145.pdf/files/DM00173145.pdf/jcr:content/translations/en.DM00173145.pdf

Video 1:
https://www.youtube.com/watch?v=fSKR8mUz1OE
Video 2:
https://www.youtube.com/watch?v=r2QnmPw_oPs
Video 3:
https://www.youtube.com/watch?v=WSdqqVzg4Ew
Video 4:
https://www.youtube.com/watch?v=_WRkEsupuGw

Assignment 2:
Complete this Assignment after you have (1) watched all videos; (2) reviewed all slides; (3) completed reading assignments.

This Assignment will certify your Embedded C skills related to the following:

Your skills for using the LL driver to read the status of the Blue button on the STM32 Discovery Board
Your skills for using the LL driver to turn an LED on/off
Your skills for using STM32CubeIDE tool to generate code that include LL drivers.
Here are the requirements for this assignment:

=1= Use STM32CubeIDE to generate the default code for the STM32 Discovery Board, being sure to include the LL option for GPIO when generating the code.
=2= Use STM32CubeIDE to edit, build, run, and debug the code that uses the LL API to (1) get the Flash size, LL_GetFlashSize(); (2) get the device unique ID, LL_GetUID_Wordn(). Just read these values into variables, e.g. you do not have to display them anywhere.

=3= Use the LL to read the status of the Blue Button. If the Blue Button is pressed, then turn on LED2 using the LL. If the Blue Button is not pressed, the turn off LED2.

NOTE! If you have not yet received your STM32 Discovery board, you do not have to run the code. Rather, just build the code and you can run the code later once you receive your STM32 Discovery Board.

To certify that you have completed the above skills, you should create a PDF document similar to the one attached to this assignment. The PDF document should include screen shots from your system and also clearly state your name. Use the attached PDF as a template or guide, but you should replace the screen shots with your specific screen shots and your name.

NOTE: Please name your PDF using this naming convention: UCSD-Embedded-C-Assignment-2-LL-FirstName-LastName.pdf and then submit for grading.

Quiz 2:
orrect answer
Question 1
1 / 1 pts
This Lesson covered LL and Embedded C. What is LL?
  Longest Level 
  Logical Layer 
  Low Layer 
  Looping Layer 
 
Correct answer
Question 2
1 / 1 pts
Which answer below is FALSE as it relates to LL and Embedded C?
  LL is closer to the hardware than the HAL 
  Use of LL does not require deep knowledge of MPU and peripherals. 
  Only a subset of peripherals are implemented in LL 
  LL is implemented in strict ANSI C 
 
Correct answer
Question 3
1 / 1 pts
Which peripheral function below is NOT a standard LL function?
  LL_PPP_DeInit() 
  LL_PPP_Init() 
  LL_PPP_StructInit() 
  LL_PPP() 
 
Correct answer
Question 4
1 / 1 pts
Suppose you are using STM32CubeMX to generate LL code. Where in the STM32CubeMX tool do you select LL?
  Pinout & Configuration, LL Configuration
  Project Manager, Code Generator, LL Config 
  Project Manager, Advanced Settings, Driver Selector 
  It is not possible to generate LL code using the STM32CubeMX tool. 
 
Correct answer
Question 5
1 / 1 pts
You have a project open in TrueStudio and you want to look at the LL file that defines the interface to GPIO. What file do you select?
  Drivers/stm32l4xx_ll_gpio.h
  Drivers/STM32L4xx_LL_Driver/Inc/stm32l4xx_ll_gpio.h
  Drivers/Inc/stm32l4xx_ll_gpio.h
  Drivers/STM32L4xx_HAL_Driver/Inc/stm32l4xx_ll_gpio.h 
