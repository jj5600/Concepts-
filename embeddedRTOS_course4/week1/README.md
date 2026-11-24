Lesson 1 Overview (Introduction to Embedded RTOS)

Welcome to the amazing world of Embedded RTOS, the technology foundation for the ever growing number of embedded devices --- including the fast growing IoT devices!

In this lesson, you are going to accomplish three major goals:

Goal #1. An introduction to FreeRTOS (Preface and Chapter 1 in textbook)
Goal #2. An introduction to the FreeRTOS on STM32CubeIDE
Goal #3. Blink and LED using FreeRTOS
At the end of this lesson you will have used STM32CubeIDE to create a FreeRTOS project that blinks and LED at a 1 second rate.

Reading Assignments: 
Mastering the FreeRTOS Real Time Kernel
Preface
Chapter 1. Introduction

Preview Activity 1: 

In this lesson we will see how to use FreeRTOS on the STM32L4 Discovery Kit IoT Node.

If you have already received your STM32 Discovery Kit IoT Node, take a look at the STM32L476 MCU that is on the board. Notice all the many pins on the chip. And imagine that each of the pins can be configured different ways: GPIO Input, GPIO Output (with or without pull-up resistor), Serial I/O, ADC, and more.

Think about how hard and it would be to configure the chip, and create the C initialization code, without the proper tools.

What type of GUI-based tools can you imagine would be useful to help configure the I/O pins, and also generate C code? And what type of IDE to use once the code is generated?

 Video Lectures:
 https://www.youtube.com/watch?v=PUWfJBC2-qw
 https://www.youtube.com/watch?v=MmeeSfvhGPs
 https://www.youtube.com/watch?v=X1NBitVKXjQ
 https://www.youtube.com/watch?v=P8ZlESyk9cM


 L1 Coding Assignment:
 This Assignment will certify your RTOS skills related to the following:

Your skills for downloading and installing the STM32CubeIDE
Your skills for configuring an STM32CubeIDE Project to use FreeRTOS
Your skills for modifying the generated code the blink LED2 on the Discovery Board at a 1 second rate.
To certify that you have completed the above skills, 
you should create a PDF document similar to one used with the video in this lesson that covered using the STM32CubeIDE.
The PDF document should include screen shots from your system and also clearly state your name. 

NOTE: Please name your PDF using this naming convention: UCSD-Embedded-RTOS-Assignment-1-FirstName-LastName.pdf and then submit for grading.

Quiz:
FreeRTOS uses the concept of a ____ to organize your embedded solution into independently executing functions.
  thread 
  task 
  process 
  job 
 
Correct answer
Question 2
1 / 1 pts
Of the FreeRTOS Kernel Features listed below, which one is NOT a feature offered by the standard FreeRTOS kernel?
  Tasks 
  Flash File System 
  Software Timers 
  Queues 
 
Correct answer
Question 3
1 / 1 pts
Select the answer below that is FALSE related to FreeRTOS.
  FreeRTOS is built for a large number of different compilers (20 or more) 
  FreeRTOS offers both Static and Dynamic Memory Allocation 
  FreeRTOS is built for a large number of architectures (30 or more) 
  FreeRTOS is proprietary software 
 
Correct answer
Question 4
1 / 1 pts
This type of real-time requirement states that a time deadline is required, but breaching the time dead-line does not render the system useless.
  Determinate Real-Time Requirement 
  Soft Real-Time Requirement 
  Hardware Real-time Requirement 
  Solid Real-Time Requirment 
 
Correct answer
Question 5
1 / 1 pts
This type of real-time requirement states that a time deadline is required, and breaching the time dead-line renders the system useless.
  Hard Real-Time Requirement 
  Determinted Real-Time Requirement 
  Soft Real-Time Requirement 
  Solid Real-Time Requirement 
