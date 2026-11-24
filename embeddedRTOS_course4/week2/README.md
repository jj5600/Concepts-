Lesson 2 Overview:
In this Lesson, you will learn about these key topics:

- Memory Management
- STM32CubeMX GUI Tool
- TrueSTUDIO
- TrueSTUDIO Running Blinky Demo

Starting with FreeRTOS V9.0.0, your code can use 100% static memory allocation, removing the need for memory management. You can also use the Heap Memory Manager to dynamically allocate and release memory.

 Reading Assignment: 
 Mastering the FreeRTOS Real Time Kernel
Chapter 2. Heap Memory Management
2.1 Chapter Intro and Scope
2.2 Example Memory Allocation Schemes
2.3 Heap Related Utility Functions

Preview of Activity 2:
Think about the small size of the memory footprint on the typical embedded RTOS device. For example, on the STM32L Discovery Kit, the total RAM is 128Kbytes - not MB but KB! Clearly memory management is a key focus of your FreeRTOS development.

Should you use static memory allocation? That is, should you know exactly how much memory will be allocated when you build your app, never needing to allocate or free additional memory? Or should you use dynamic memory allocation, allocating and freeing memory as needed?

Video: 
https://www.youtube.com/watch?v=q-kuYnJLP5Q

https://www.youtube.com/watch?v=V7_HifkYwSc

https://www.youtube.com/watch?v=X1NBitVKXjQ

https://www.youtube.com/watch?v=gfuxivt4CQY

https://www.youtube.com/watch?v=FN4dz5Q1c2o

https://youtu.be/tPIxKgyuKXQ
Assignment 2: 

This Assignment will certify your RTOS skills related to both Lesson 1 and Lesson 2. While the focus of Lesson 2 is on RTOS Memory Allocation, you will use the skills from Lesson 1 to blink and LED in the default task and blink the Wifi/BLE LEDs from the vApplicationMallocFailedHook() when you have a memory error.

Here are the requirements for this coding assignment:

Create a new STM32CubeIDE Project. (Do NOT use the same project from Lesson 1).
Begin by configuring the project the same as in Lesson 1 (e.g. use all the defaults) but then make the changes required for memory allocation as described below..
Configure FreeRTOS  for a HEAP memory size of 6000.
Keep the default dynamic/static allocation along with the default memory 4 allocation option.
In your default task, blink the LED2 every second and also use pvPortMalloc() to allocate 500 bytes every time you blink the LED2. The goal here is to "leak memory" as your loop runs until you run out of memory.
Add the vApplicationMallocFailedHook() to your code so that when you run out of memory (remember you have a memory leak from in the default task as described in the previous bullet). The code in the vApplication MallocFailedHook() should be a "while (1) { }" that blinks the Wifi/BLE LED at a 0.5 second (1/2 second) rate. What do you observe? Does the LED2 continue to blink while the vApplicationMallocFailedHook() runs?
To certify that you have completed the above skills, you should create a PDF document similar to like you did for Lesson 1. The PDF document should include screen shots from your system and also clearly state your name. Show your steps and also your code in the PDF document. You do not have to submit your code, but rather only screen shots of your code inserted in the PDF document.

NOTE: Please name your PDF using this naming convention: UCSD-Embedded-RTOS-Assignment-2-FirstName-LastName.pdf and then submit for grading.

Attachments (Sample PDF - Your PDF should follow this same type of format)
UCSD-Embedded-RTOS-Assignment-2-Norman-McEntire.pdf


QUIZ:

Question 1
1 / 1 pts
Starting with this version of FreeRTOS, applications can statically allocate memory, removing the need for a heap memory manager.
  Answer not given because FreeRTOS does not support static memory allocation. 
  V9.0.0 
  V1.0.0 (static memory allocation has always been a feature of FreeRTOS) 
  V10.0.0 
 
Correct answer
Question 2
1 / 1 pts
Of the answers given, select the one that is NOT a kernel object that is dynamically allocated.
  Task Kernel Object 
  Queue Kernel Object 
  Semaphore Kernel Object 
  Configuration Kernel Object 
 
Correct answer
Question 3
1 / 1 pts
Select the answer below that is FALSE as it related to FreeRTOS dynamic memory allocation.
  You can use malloc() and free() as needed because they are fully supported by FreeRTOS. 
  Both pvPortMalloc() and vPortFree() are public functions and can be called from FreeRTOS code. 
  FreeRTOS comes with multiple implementations of pvPortMalloc() and vPortFree(), you can also write your own implementation if desired.
  FreeRTOS comes with multiple implementations of pvPortMalloc() and vPortFree(). 
 
Correct answer
Question 4
1 / 1 pts
Suppose you are writing FreeRTOS code and you need to allocate memory. What function should you use?
  malloc() 
  MALLOC() 
  pvPortMalloc() 
  FreeRTOS_Malloc() 
 
Correct answer
Question 5
1 / 1 pts
When editing FreeRTOSConfig.h, set this #define to specify the total heap size.
  total_heap_size 
  TOTAL_HEAP_SIZE 
  FreeRTOS_TOTAL_HEAP_SIZE 
  configTOTAL_HEAP_SIZE 


