Lesson 8 Overview:Event Groups

In this lesson, you will learn about Event Groups and Task Notifications.

Event Groups allow events to be communicated to tasks. But unlike queues and semaphores, event groups allow a task to wait in the blocked state for a combination of one or more events to occur.

Task Notifications provide yet another way for tasks to communicate, using a very light mechanism.

Reading:

Mastering the FreeRTOS Real Time Kernel
Chapter 8. Event Groups
8.1 Chapter Intro and Scope
8.2 Characteristics of an Event Group
8.3 Event Management Using Event Groups
8.4 Task Synchronization Using an Event Group
Chapter 9. Task Notifications
9.1 Chapter Intro and Scope
9.2 Task Notifications: Benefits and Limitations
9.3 Using Task Notifications

Videos:
[
](https://www.youtube.com/watch?v=P8cwcfE_aYM)
https://www.youtube.com/watch?v=ewWLiKy8JdI


Assignment:

This Assignment will certify your RTOS skills related to Event Groups by using an ISR and two tasks. The ISR will fire by pressing the Blue button on the STM board. This will set one of the three bits in an event group.

One of the tasks will wait on this event from the ISR, then delay for 1 second, set another event group bit, wait another 1 second, then set another event group bit.

The second task will be waiting on an event group of three bits --- one bit from the ISR and the other two bits from the other task. Once all three events are set, this task will turn on the LED on the STM board for 1 second, then turn the LED off for 1 second, then repeat again, waiting for the 3 bits in the event group to be set again. (This second task should be sure to clear all three event bits when calling the xEventGroupWaitBits() function.)

To certify that you have completed the above skills, you should create a PDF document similar to the one attached to this assignment. The PDF document should include screen shots from your system and also clearly state your name. Use the attached PDF as a template or guide, but you should replace the screen shots with your specific screen shots and your name.

NOTE: You do not need to provide as many steps as shown in the attached PDF unless you want to. Rather, the key screen shots you should show is of your RTOS code.

NOTE: Please name your PDF using this naming convention: UCSD-Embedded-RTOS-Assignment-8-FirstName-LastName.pdf and then submit for grading.


Quiz:

Question 1
1 / 1 pts
Event Groups are different from Semaphores and Queues in all but ONE of the following ways:
  Event groups allow a task to wait in the blocked state for a combination of one or more events to occur 
  Event groups unblock all the tasks that were waiting for the same event 
  Event groups are useful for synchronizing multiple tasks - they can broadcast 
  Event groups can be accessed by tasks but not by ISRs 
 
Question 2
1 / 1 pts
When using FreeRTOS+TCP, a TCP socket must respond to multiple events:
- accept events
- bind events
- read events
- close events
What is the best kernel object to use to sync on these multiple events.
  Counting Semaphore 
  Binary Semaphore 
  Mutex 
  Event Group 
 
Question 3
1 / 1 pts
Task A receives an event and then delegates work to tasks B, C, and D. However task A cannot continue until task B, C, and D complete their work. What synchronization objects should be used?
  Binary Semaphore 
  Event Group 
  Semaphore Group 
  Mutext Group 
 
Question 4
1 / 1 pts
Given the following:
----
Existing Event Group Value: 0000
uxBitsToWaitFor: 0101
xWatiForAllBits: pdFALSE
----
then what answer below is FALSE?
  Calling task will leave the blocked state when bit 3 is set
  Calling task will leave the blocked state when bit 0 is set 
  Calling task will enter the Blocked state 
  Calling task will leave the blocked state when bit 2 is set
 
Question 5
1 / 1 pts
Select the correct function prototype for xEventGroupSync.
  EventBits_t
xEventGroupSync(
    const EventBits_t uxBitsToSet,
    const EventBits_t uxBitsToWaitFor,
    TickType_t xTicksToWait)
  EventBits_t
xEventGroupSync(
    EventGroupHandle_t xEventGroup,
    const EventBits_t uxBitsToSet,
    TickType_t xTicksToWait)
  EventBits_t
xEventGroupSync(
    EventGroupHandle_t xEventGroup,
    const EventBits_t uxBitsToSet,
    const EventBits_t uxBitsToWaitFor,
    TickType_t xTicksToWait)
  EventBits_t
xEventGroupSync(
    EventGroupHandle_t xEventGroup,
    const EventBits_t uxBitsToWaitFor,
    TickType_t xTicksToWait)
 
