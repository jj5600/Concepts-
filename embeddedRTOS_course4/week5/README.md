Lesson 5 Queues: 

In this lesson, you will learn about Queues. You will use queues to provide communication several ways:

Task to Task Communication
Task to Interrupt Communication
Interrupt to Task Communication
In this lesson you will learn how to create, manage, and delete queues.

Mastering the FreeRTOS Real Time Kernel
Chapter 4. Queue Management
4.1 Chapter Intro and Scope
4.2 Characteristics of a Queue
4.3 Using a Queue
4.4 Receiving Data from Multiple Sources
4.5 Working with Large or Variable Sized Data
4.6 Receiving from Multiple Queues
4.7 Using a Queue to Create a Mailbox

https://www.youtube.com/watch?v=0kp3TGl9O2w
https://www.youtube.com/watch?v=xUS1aZ7LqDs
https://www.youtube.com/watch?v=Yse1GRlCIQY

Lesson 5:

This Assignment will certify your RTOS skills related to the following:

Create "Queue1" that is length of five to hold up to five uint32_t values.
Create "Task 1" that will run every 2 seconds, increment a count, then send the count to the queue. Use a value of portMAX_DELAY when writing to the queue.
Create "Task 2" that will receive from the queue, then display the count received from the queue. Use a value of portMAX_DELAY when reading from the queue.
Run this on the STM32CubeIDE (with IoT Discovery Board or equivalent) and observe the result.
 

 

To certify that you have completed the above skills, you should create a PDF document similar to the one attached to this assignment. The PDF document should include screen shots from your system and also clearly state your name. Use the attached PDF as a template or guide, but you should replace the screen shots with your specific screen shots and your name.

NOTE: Please name your PDF using this naming convention: UCSD-Embedded-RTOS-Assignment-5-FirstName-LastName.pdf and then submit for grading.


L5 Quiz:

Question 1
1 / 1 pts
Select the answer below that is FALSE as it related to queues.
  A queue holds a finite number of items 
  Each item in a queue is of a fixed size 
  Queues are used for Task to Task communication 
  A queue has a priority 
 
Correct answer
Question 2
1 / 1 pts
Select the answer below that is FALSE as it relates to queues.
  Any number of tasks can write to a queue. 
  Any number of tasks can read from a queue 
  Queues can only have a single reader and a single writer 
  Queue are kernel objects 
 
Correct answer
Question 3
1 / 1 pts
What answer below is NOT a parameter passed to the xQueueSend() API?
  The item to queue 
  The Queue Handle 
  The callback to use when item is placed in the queue 
  Time timeout to wait for queue to become available 
 
Correct answer
Question 4
1 / 1 pts
Select the answer below that is NOT a FreeRTOS Queue API
  xQueueSend() 
  xQueueReceive() 
  xQueueWrite() 
  xQueueSendToBack() 
 
Correct answer
Question 5
1 / 1 pts
As related to calling xQueueReceive() from a queue that is empty, select the answer below that is FALSE.
  An exception will be thrown and your queue empty hook routine must take appropriate action 
  If the xTicksToWait parameter is 0, then the function will return immediately with a result of err QUEUE_EMPTY 
  If the xTicksToWait parameter is portMAX_DELAY, then the function will wait "forever" until a value sent to the queue
  If the xTicksToWait parameter is pdMS_TO_TICKS(2000), then the function will wait for up to 2 seconds on the empty queue, and then return errQUEUE_EMPTY 


 
