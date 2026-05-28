Week 8:
We continue building our Embedded Controller Programming with Embedded C skills by focusing on I2C, sometimes referred to as a 2-wire interface. This interface is widely used due to its low pin count and low cost. Here you learn how to program I2C devices using Embedded C!

I2C Concepts
I2C Data Structures
I2C Functions and Macros

 Video 1: https://www.youtube.com/watch?v=eI9YfOdDn4I
 Video 2: https://www.youtube.com/watch?v=T9elz_wsqhQ
 Video 3: https://www.youtube.com/watch?v=lvBdm_fm67Y
 Video 4: https://www.youtube.com/watch?v=ufQPlWoCxD4
 Bonus : https://www.youtube.com/watch?v=wRAJvi3qAP0
 Reading:
 Reading Assignment Banner
UM1884 User ManualLinks to an external site.

Description of STM32L4/L4+ HAL and low-layer drivers

Chapter 33: HAL I2C Generic Driver

Bonus Material for use with Bonus Videos.

ASF4 API Reference ManualLinks to an external site.

Description of ASF4 API

Chapter 25: I2C Drivers
Assignment:
Complete this Assignment after you have (1) watched all videos; (2) reviewed all slides; (3) completed reading assignments.

This Assignment will certify your Embedded C skills related to the following:

Your skills for using HAL I2C APIs to read  the I2C sensor of your choice on the STM32 Discovery Board. There are several I2C sensors on the STM32 Discovery Board --- pick one that is of interest to you, and then read data using the I2C HAL APIs.
Display your data from your sensor on the UART1 console.
Use either the STM32CubeIDE or the STM32CubeMX/TrueStudo.
Here are the requirements for this assignment:

=1= Use either STM32CubeIDE or STM32CubeMX to generate I2C code so that you can access the I2C device of your choice. Clearly document the I2C device you decide to read from. You can choose any I2C device on the board (or even an external I2C device if you want to connect to the Arduino connector. NOTE: Although you can choose to use the HTS221, it was used in a previous assignment, so you may want to select another I2C device for this assignment.

=2= Add the HAL I2C code needed to support reading from the I2C device of your choice. NOTE: You may need to look at the BSP code to get idea of how to use I2C HAL code to read from the I2C device. This is why it's OK to use the HTS221 if you want to (since you used the BSP API to read from the HTS221 in the earlier exercise, here you will use the HAL API for I2C.)

=3= Read your sensor at a rate that makes sense for the sensor, displaying the value on the UART1 console.


To certify that you have completed the above skills, you should create a PDF document similar the PDF documents we have used for previous assignments. The PDF document should include screen shots from your system and also clearly state your name. If possible, include a photo for the I2C sensor value being displayed on a PuTTY (or equivalent) serial terminal emulator.

NOTE: Name your PDF using this naming convention: UCSD-Embedded-C-Assignment-8-I2C-FirstName-LastName.pdf and then submit for grading.


 Quiz:
 Question 1
1 / 1 pts
Select the answer below that is FALSE as it relates to I2C.
  The I2C Master generates the clock and initiates communication. 
  The I2C reference design has a 7-bit address (bits 7-1), while bit 0 is used to indicate Read/Write. 
  I2C clock stretching allows a I2C Slave device to hold SCL low after receiving (or sending) indicating that it is not yet ready. 
  I2C uses two bidirectional push-pull lines, one for serial data and another for serial clock 
 
Question 2
1 / 1 pts
This is the key I2C data structure that is used as an input for function such as HAL_I2C_Init().
  I2C_HandleTypeDef 
  struct I2C 
  HAL_HandleIc2Init 
  HAL_I2C 
 
Question 3
1 / 1 pts
When using STM32CubeMX to configure I2C2, which answer below is NOT valid.
  I2C Turbo Mode 
  SMBus-two-wire-interface Mode 
  SMBus-Alert Mode 
  I2C Mode 
 
Question 4
1 / 1 pts
What is NOT a feature of the HTS221 used in this lesson?
  UART Interface 
  Data Ready Output Signal 
  SPI Interface 
  I2C Interface 
 
Question 5
1 / 1 pts
Several functions were used in the TrueStudio code demo in this lesson, reading from the HTS221. Select the answer below that does NOT have a function that was used in this lesson.
  HAL_Delay(5000) 
  BSP_HSENSOR_ReadHumidity() 
  BSP_TSENSOR_Init() 
  HAL_ReadTemperature() 
  
