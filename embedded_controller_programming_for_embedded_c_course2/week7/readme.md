Bonus Video: https://www.youtube.com/watch?v=3u6Ml7K8bvc

Lesson 7 Uart:
We continue building our Embedded Controller Programming with Embedded C skills by focusing on UARTs, probably second only to GPIO in how often this is used in embedded designs. Here you will learn how to program UARTs with all kinds of options!

UART Concepts
UART Data Structures
UART Functions and Macros

Additional tool;Here is an example of a USB to Serial Cable useful for this lesson. (And will be useful throughout your embedded systems career!)

https://www.adafruit.com/product/954Links to an external site.

Video 1:
https://www.youtube.com/watch?v=xQwoqnPzo8Y

Video 2:
https://www.youtube.com/watch?v=fRMb8x7qRRU

Reading assignment:
UM1884 User ManualLinks to an external site.

Description of STM32L4/L4+ HAL and low-layer drivers

Chapter 68: HAL UART Generic Driver

Bonus Material for use with Bonus Videos.

ASF4 API Reference ManualLinks to an external site.

Description of ASF4 USART API

Chapter 37: USART Drivers
Bonus: https://www.youtube.com/watch?v=E50nrVlYsf0
Bonsu 2: https://www.youtube.com/watch?v=VAzrXneqgLg
Bonus 3: https://www.youtube.com/watch?v=cY8qPAhlUVY
Bonus 4: https://www.youtube.com/watch?v=ZN3wV2xOKjY
Bonus 5: https://www.youtube.com/watch?v=n1ZddAKZMsQ

Assignment 7: 
Complete this Assignment after you have (1) watched all videos; (2) reviewed all slides; (3) completed reading assignments.

 

This Assignment will certify your Embedded C skills related to the following:

Your skills for using the HAL Generic UART driver to send messages out the ST-LINK Virtual COMP Port, or UART1, and display the messages on your host computer. Display the message "UART1: 0, UART1: 1, ...UART1: n", where N is a count that increments every 5 seconds.
Your skills for using the HAL Generic UART driver to send messages out the Arduino TX/RX Port, or UART4, and display the messages on your host computer. Display the message "UART4: 0, UART4: 1, ...UART4: n", where N is a count that increments every 10 seconds.
Use a program such as PuTTY (PC) or minicom (Linux) or screen (Mac) to display the output on the virtual serial console.
Your skills for using STM32CubeIDE tool to generate code for this project.
To certify that you have completed the above skills, you should create a PDF document similar to the one attached to this assignment. The PDF document should include screen shots from your system and also clearly state your name. Use the attached PDF as a template or guide, but you should replace the screen shots with your specific screen shots and your name.

NOTE: Please name your PDF using this naming convention: UCSD-Embedded-C-Assignment-7-UART-FirstName-LastName.pdf and then submit for grading.

 

Attachments
UCSD-Embedded-C-Assignment-7-Norman-McEntire.pdf

Quiz 7:
Submitted May 18 at 3:11pm
This attempt took 8 minutes.
 
Question 1
1 / 1 pts
On the STM32 Discovery Board used in this course, which UART provides a virtual console via the USB Port used with ST-Link?
  UART1 
  UART2 
  UART3 
  UART4 
 
Incorrect
Question 2
0 / 1 pts
On the STM Discovery Board we are using in this course, select the UART that that is used on D0/D1 on the Arduino shield.
  UART4 
  UART1 
  UART2 
  UART3 
 
Question 3
1 / 1 pts
Select the UART data structure that includes fields to initialize the Baud Rate, Word Length, and StopBits.
  UART_InitTypeDef 
  UART_AdvFeatureInitTypeDef 
  HAL_UART_StateTypeDef 
  UART_ClockSourceTypeDef 
 
Question 4
1 / 1 pts
Related to UART transmit functions, which function below is NOT a valid HAL UART function?
  HAL_UART_Transmit_Polled() 
  HAL_UART_Transmit() 
  HAL_UART_Transmit_IT() 
  HAL_UART_Transmit_DMA() 
 
Question 5
1 / 1 pts
This key HAL UART Data Type contains the base address, initialization info, pointers to tx/rx buffers, and more.
  UART_HandleTypeDef 
  USART_TypeDef 
  UART_InitTypeDef 
  UART_AdvFeatureInitTypeDef 
