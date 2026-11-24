Lesson 3 Tasks:

In this lesson, you will learn how to use tasks. Tasks are C functions that return void and accept a single void pointer parameter. A typical FreeRTOS solution has a number of tasks, and each task runs independently. Since FreeRTOS applications are organized as tasks, this is one of the most important lessons in the course.

In addition to learning about the concept of a task, you will also learn how to create, manage, and delete tasks.

Mastering the FreeRTOS Real Time Kernel
Chapter 3. Task Management
3.1 Chapter Intro and Scope
3.2 Task Functions
3.3 Top-Level Task States
3.4 Creating Tasks
3.5 Task Priorities
3.6 Time Measurement and the Tick Interrupt
3.7 Expanding the Not Running State
3.8 The Idle Task and Idle Task Hook
3.9 Changing the Priority of a Task
3.10 Deleting a Task


https://www.youtube.com/watch?v=VrB49qhTT7k
https://www.youtube.com/watch?v=TCn5MKyCsWQ
https://www.youtube.com/watch?v=SrOgidseLlM
https://www.youtube.com/watch?v=pDXgfi8Rl1A
https://www.youtube.com/watch?v=FBAQLRRxSaY
https://www.youtube.com/watch?v=xTL_71pn8l4

L3 Coding tasks:

This Assignment will certify your RTOS skills related to the following:

Create "Task 1" that blinks the LED2 (Green LED) every 250 msec
Create "Task 2" that blinks LED3_WIFI_LED4_BLE every 1000 msec
Create "Task 3" that displays a counter (e.g. "count = 1", "count = 2", etc.) on the STM32 Virtual Console
To certify that you have completed the above skills, you should create a PDF document similar to the one attached to this assignment. The PDF document should include screen shots from your system and also clearly state your name. Use the attached PDF as a template or guide, but you should replace the screen shots with your specific screen shots and your name.

NOTE: Please name your PDF using this naming convention: UCSD-Embedded-RTOS-Assignment-3-FirstName-LastName.pdf and then submit for grading.

Attachments (template only - content out of date)

Question 1
1 / 1 pts
Related to a FreeRTOS Task Function, select the answer that is FALSE.
  A Task Function is a special function that is not a standard C function 
  A Task Function should never "just end", but rather call vTaskDelete() before ending.
  A Task Function accepts a single parameter that is a pointer to a void. (void *) 
  A Task Function returns void. (void) 
 
Correct answer
Question 2
1 / 1 pts
You want to hook a function into the FreeRTOS Idle Task. What must you name the function?
  You can name the function anything you would like.  
  MyIdleHook() 
  vApplicationIdleHook() 
  configApplicationIdleHook() 
 
Correct answer
Question 3
1 / 1 pts
Select the best answer that demonstrates using the FreeRTOS API to delay your task for 1 second.
  vTaskDelay(pdMS_TO_TICKS(1000)) 
  vTaskDelay(1000)
  wait(1000) 
  sleep(1000) 
 
Correct answer
Question 4
1 / 1 pts
Select the answer below that is NOT one of the sub-states of the "Not Running" state.
  Ready 
  Suspended 
  Blocked 
  Paused 
 
Correct answer
Question 5
1 / 1 pts
You are using the vTaskCreate() function in your FreeRTOS code. Select the answer below that is NOT one of the parameters passed into the xTaskCreate() function.
  The Task Function 
  The Task Stack Depth 
  The Task Priority 
  The Task Timeout 
