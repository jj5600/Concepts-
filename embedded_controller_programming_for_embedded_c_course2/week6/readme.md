Lesson 6 Overview:
We continue building our Embedded Controller Programming with Embedded C skills by focusing on the ADC, that is, Analog-to-Digital Conversion. It is very common for embedded controllers to read ADC values from various sensors. For example, light sensors, temperature sensors, and pressure sensors are just of few of the many types of devices that connect to the MCU via ADC. Here you will learn how to use Embedded C to read ADC values..

ADC Concepts
ADC Data Structures
ADC Functions and Macros

Video 1: https://www.youtube.com/watch?v=WIr_xaO4rx8
Video 2: https://www.youtube.com/watch?v=-I7kWPUSmH0
Video 3: https://www.youtube.com/watch?v=B3EuajK306M
Video 4: https://www.youtube.com/watch?v=_VAZlqoEl6E
Video 5: https://www.youtube.com/watch?v=hGKQ3DOku4I
Bonus: https://www.youtube.com/watch?v=vvIplK1FHoA
Reading assignment: UM1884 User ManualLinks to an external site.

Description of STM32L4/L4+ HAL and low-layer driver

Chapter 6: HAL ADC Generic Driver

Bonus Material for use with Bonus Videos.

ASF4 API Reference ManualLinks to an external site.

Description of ASF4 API

Chapter 5: ADC Drivers

Assignment:
This Assignment will certify your Embedded C skills related to the following:

Your skills for using the HAL ADC driver to read the ADC value of a battery
Your skills for using STM32CubeMX tool to generate code for this project.
Your skills for using TrueStudio to build and run code for this project.
Here are the requirements for this assignment:

=1= Use STM32CubeMX to generate ADC1-IN14 code so that you can access the Arduino shield pin A0 on the STM32 Discovery IoT Board.
=2= Use TrueStudio to include edit main.c to read the ARD_A0 value every 1 second. 
=3= Use TrueStudio to edit, build, run, and debug the code, using a breakpoint to display the value read from the ARD_A0 pin.
=4= Try reading these three values from ARD_A0: (1) Floating (nothing connected to the pin); (2) GND (the ARD_A0 pin connected to ground); (3) 1.5 VDC battery connected to ARD_A0 (be sure to connect the GND of the battery to GND on the Arduino shield.


To certify that you have completed the above skills, you should create a PDF document similar to the one attached to this assignment. The PDF document should include screen shots from your system and also clearly state your name. Use the attached PDF as a template or guide, but you should replace the screen shots with your specific screen shots and your name.

NOTE: Please name your PDF using this naming convention: UCSD-Embedded-C-Assignment-6-ADC-FirstName-LastName.pdf and then submit for grading.

Quiz;
Question 1
1 / 1 pts
The STM Discovery board used in this course has several ADC resolutions. Select the answer below that is NOT a valid ADC resolution for the STM Discovery Board.
  10-bit 
  16-bit 
  8-bit 
  12-bit 
 
Question 2
1 / 1 pts
Select the answer below that is NOT a valid ADC data type.
  HAL_ADC_TypeDef 
  ADC_ChannelConfTypeDef 
  ADC_HandleTypeDef 
  ADC_TypeDef 
 
Question 3
1 / 1 pts
You need to retrieve the value of an ADC conversion when using either polled or interrupt driven operation. What function do you use?
  HAL_ADC_ReadADCValue() 
  HAL_ADC_GetValue(uint_t Pinx)
  HAL_ADC_GetValue()
  HAL_ADC_GetValue(ADC_HandleTypeDef *hadc) 
 
Question 4
1 / 1 pts
The STM Discovery Board used in this course has an Arduino shield connector, with ARD_A0 on one of the signals. Which ADC and channel does ARD_A0 connect to on the STM Discovery Board?
  PC5 - ADC1_IN14 
  PC2 - ADC1_IN3 
  PC3 - ADC1_IN4 
  PC4 - ADC1_IN13 
 
Question 5
1 / 1 pts
Given the code segment below, select the answer that fills in the missing function:

HAL_ADC_Start(&hadc1);
[missing line]
adc1Result = HAL_ADC_GetValue(&hadc1);

  HAL_ADC_Prime(&hadc)
  HAL_ADC_PollForConversion(&hadc,100)
  HAL_ADC_Pulse(&adc1)
  HAL_ADC_Stop(&hadc,100)
