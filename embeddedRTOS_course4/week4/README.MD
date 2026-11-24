Lesson 4 Software Timers:

In this lesson, you will learn about Software Timers. You can use software timers two ways:

Option 1. To execute a function at a set time in the future. For example, execute a given function 60 seconds in the future.
Option 2. To execute a function periodically with a fixed frequency. For example, to execute a function every 60 seconds.

Software Timers are implemented by and are under the control of FreeRTOS - they do not require use of hardware timers.

Importantly, software timers do not use any processing time unless the timer callback function is executing.

  Reading Assn:
Mastering the FreeRTOS Real Time Kernel
Chapter 5. Timer Management
5.1 Chapter Intro and Scope
5.2 Software Timer Callback Functions
5.3 Attributes and States of a Software Timer
5.4 The Context of a Software Timer
5.5 Creating and Starting a Software Timer
5.6 The Timer ID
5.7 Changing the Period of a Timer
5.8 Resetting a Software Timer

https://www.youtube.com/watch?v=jpHNBbSFa4A  
https://www.youtube.com/watch?v=DL0wtvn6lGE
https://www.youtube.com/watch?v=yVMMedYoZLg
https://www.youtube.com/watch?v=S5shzrlEQ74
https://www.youtube.com/watch?v=3rH617xfqhU


This Assignment will certify your RTOS skills related to the following: 

Create "Task 1" that blinks the LED2 at a rate of 1 second
Create "Task 2" that blinks the "Wifi/BLE" LED at a rate of 2 seconds
Create "Timer 1" that is a One-Shot timer function named prvMyTimerOneShot(). The timer should fire 15 seconds after startup and display a message "prvMyTimerOneShot" on the console.
Create "Timer 2" that is an auto-reload timer function named prvMyTimerAutoReload(). The timer should fire every 5 seconds  and display a count and a message on the console, for example, "prvMyTimerAutoReload: 1".
NOTE: Use code similar to this to send a message out of the console.

int count = 42;
char buf[100];
snprintf(buf, sizeof(buf), "Message goes here: count: %d\r\n", count);
HAL_UART_Transmit(&huart1, (uint8_t  *)buf, strlen(buf), 1000);

To certify that you have completed the above skills, you should create a PDF document similar to the one attached to this assignment. The PDF document should include screen shots from your system and also clearly state your name. Use the attached PDF as a template or guide, but you should replace the screen shots with your specific screen shots and your name.

NOTE: Please name your PDF using this naming convention: UCSD-Embedded-RTOS-Assignment-4-FirstName-LastName.pdf and then submit for grading.


FreeRTOS provides both Tasks and Software Timers. What is the key difference between the two?
  Tasks can call Blocking APIs, but Software Timers cannot call Blocking APIs. 
  Tasks use dynamic memory allocation but software timers use static memory  allocation 
  Software Timers can call Blocking APIs, but Tasks cannot call Blocking APIs.
  Tasks use static memory allocation but tasks static memory  allocation
 
Correct answer
Question 2
1 / 1 pts
Select the answer below that is FALSE as it relates to a software timer.
  A software timer can be implemented as an Auto Load Timer 
  A software timer can be implemented as a One-Shot Timer 
  A software timer executes in the context of the Free RTOS daemon task 
  A software timer executes in the context of the Idle Task 
 
Correct answer
Question 3
1 / 1 pts
Select the function below that could be used as a software timer callback.
  void *pvMyTimer() 
  BaseType_t  vMyTimer(void * pvParams)
  void vMyTimer(void * pvParams)
  void vMyTimer(TimerHandle_t xTimer) 
 
Correct answer
Question 4
1 / 1 pts
Select the item below that is FALSE as it relates to software timers.
  The software timer API functions send commands from the calling task to the daemon task on a queue. 
  xTimerStart() must be called to start the timer 
  Software timers are created with a priority; the higher priority timers run before the lower priority timers 
  xTimerCreate() creates the software timer but does not start the timer 
 
Correct answer
Question 5
1 / 1 pts
Select the answer below that is FALSE as it relates to software timers.
  Each software timer includes an ID 
  The software timer ID is of type TimerHandle_t 
  The pvTimerGetTimerID() function can be use to get the timer ID 
  The vTimerSetTimerID() function can be used to set the timer ID 
 
