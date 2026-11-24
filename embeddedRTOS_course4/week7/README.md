Lesson 7 Resource Management: 
In this lesson, you will learn how to manage resources using critical sections, mutexes, and semaphores. You will learn how to use these objects to protect shared resources.

Reading: 
Mastering the FreeRTOS Real Time Kernel
Chapter 7. Resource Management
7.1 Chapter Intro and Scope
7.2 Critical Sections and Suspending the Scheduler
7.3 Mutexes (and Binary Semaphores)
7.4 Gatekeeper Tasks

https://www.youtube.com/watch?v=peSVWPkuyT0
https://www.youtube.com/watch?v=v1py4rCNClo
https://www.youtube.com/watch?v=-3PfRTbcmsk
https://youtu.be/vvIplK1FHoALinks to an external site.

Coding Assn:

This Assignment will certify your RTOS skills related to resource management using critical sections and a mutex. You will need to use the STM board for this assignment, because you will need to generate interrupts with the Blue Button. You will also need to create two tasks that read a value incremented from the pushing the Blue button, and then flash the LED the appropriate number of times.

The requirements are:

Create a counter that is protected by a critical section
Create a mutex that will be used by each LED task to flash the LED. Each LED task must obtain the mutex before flashing the LED
Create a count with initial value of 0.
When you press the Blue button, the ISR should enter a critical section, increment the count, then exit the critical section. (Remember you are inside an ISR, so call the ISR version of function). Every press of the button will enter the critical section, increment the count, then exit the critical section.
Create two LED blinker tasks. One of the LED tasks will flash at 500msec rate and the other will flash at 1000 msec rate.
Each LED blinker task should sleep for 5 seconds, then enter a critical section to read the value of the count. The value of the count should be stored inside the thread to be the count of the number of times the LED should toggle. Then the count should be set to 0 before exiting the critical section.
Using the value just read from the counter, the task should grab the LED mutex, then flash the LED the number of times given by the count, then release the LED mutex.
If the count value was zero, then instead of flashing the LED the task should sleep for 5 seconds again.
To certify that you have completed the above skills, you should create a PDF document similar to the one attached to this assignment. The PDF document should include screen shots from your system and also clearly state your name. Use the attached PDF as a template or guide, but you should replace the screen shots with your specific screen shots and your name.

NOTE: You do not need to provide as many steps as shown in the attached PDF unless you want to. Rather, the key screen shots you should show is of your RTOS code.

NOTE: Please name your PDF using this naming convention: UCSD-Embedded-RTOS-Assignment-7-FirstName-LastName.pdf and then submit for grading.

Quiz: 

Question 1
1 / 1 pts
A higher priority task being delayed by a lower priority task is called what?
  Priority Inversion 
  Priority Jitter 
  Deadlock 
  Priority Inheritance 
 
Question 2
1 / 1 pts
This ensures that only a single task at a time can access a shared resource.
  ISRs 
  mutual exclusion 
  priority inversion 
  task priorites 
 
Question 3
1 / 1 pts
You are making sure that all your functions are reentrant. What answer below would NOT be used in a reentrant function?
  num4++ 
  return num3 
  static uint32_t num1; 
  uint32_t num2 
 
Question 4
1 / 1 pts
Select the answer below that is NOT an example of a race condition.
  Incrementing a shared variable from several tasks 
  Writing to an LCD screen from several tasks 
  Processing of a linked-list data structure from several tasks 
  A reentrant function that is called from several tasks 
 
Question 5
1 / 1 pts
Select the BEST code segment below that shows changing a bit in a variable that is shared by multiple tasks
  taskENTER_CRITICAL_FROM_ISR();
PORTA |= 0x01;
taskEXIT_CRITICAL_FROM_ISR();
  xSemaphoreCreateMutexFromISR();
PORTA |= 0x01;
xSemaphoreDeleteMutexFromISR();
  taskENTER_CRITICAL();
PORTA |= 0x01;
taskEXIT_CRITICAL();
  xSemaphoreCreateMutex();
PORTA |= 0x01;
xSemaphoreDeleteMutex();
 
