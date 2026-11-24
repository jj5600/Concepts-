Lesson 9 Task notification:

Read:

Mastering the FreeRTOS Real Time Kernel
Chapter 9. Task Notifications
9.1 Chapter Intro and Scope
9.2 Task Notifications: Benefits and Limitations
9.3 Using Task Notifications


https://www.youtube.com/watch?v=IdFmnouVs88


LOw Power steps:

Low-Power Steps
Here are some steps to follow related to achieving low-power in your FreeRTOS design.

Step 1. Choose a low-power microcontroller. For example the STM32L4 that we have been using in this course is a low-power device.

Step 2.  Study the low-power options of your chosen microcontroller. For example most microcontrollers have different modes of operation such as full power (run), medium power (standby), very low power (stop), etc.

Step 3. For external peripherals, you may want to power them up only when needed. For example, you may have a radio, but only power up the radio when you transmit, which, for example, could be once every 5 minutes, etc.

Step 4. Enable FreeRTOS for tickless idle mode:

#define configUSE_TICKLESS_IDLE                 1
#define configEXPECTED_IDLE_TIME_BEFORE_SLEEP  3
#define configTICK_RATE_HZ                      1000
Step 5. Use event driven tasks. That is, do not do polling but rather have events notify your code. That way the code only runs when an event fires (e.g. a button pressed).

Step 6. You may be able to decrease the FreeRTOS tick rate from the default 1K per second to a lower-value. For example maybe all you need is 100 ticks per second.

Step 7. If you transfer lots of data, using DMA (Direct Memory Access) may save power compared to using CPU driven data transfers

Step 8. Do live testing and measure the power usage of your hardware. Try different algorithms (e.g. normal FreeRTOS vs tickless mode) and see the difference in power usage.

The above steps are a good start to reaching low-power in your design!


FINAL:"

his is your final programming assignment. It has four required parts, plus two optional parts.


You have THREE Options for the Final Assignment:

Option #1. Do the assignment listed below. The advantage of this assignment is that it reviews and combines all the previous assignments into a final assignment. This is the option most students select. You will submit a detailed PDF with screen shots (just like you have done all semester) for grading.

Option #2. Coffee Maker Project. This project is more "open ended" in that you use your Embedded RTOS Skills and the STM32 Discovery Board to write code to control a Coffee Maker. You will submit a detailed PDF with screen shots (just like you have done all semester) for grading.

Option #3. Custom Project. If you have a custom project you want to use for your final project, please do so. Same requirement as the other two:  submit a detailed PDF with screen shots (just like you have done all semester) for grading. 

Here are the requirements for OPTION 1:

A key goal of the Final Embedded RTOS Assignment is for you to write code that runs on the STM board that demonstrates all the key RTOS Skills you have learned. With this in mind, you'll be focus on "RTOS Meets LEDs'" for the final project.

NOTE: You'll need some extra LEDs that you will connect to the STM board. In addition to using the on-board LEDs on the STM board, will use external LEDs to show results as our code runs.

Each LED will be controlled by using a different RTOS related skill. Here are the require parts of the final project:

=== REQUIRED FEATURES ===

1. TaskLED - LED2_Pin
RTOS Skills: tasks
Description: This LED will be controlled by a free running "LED Task" that will flash the LED at a given rate.

2. PeriodicTimerLED - ARD_D5_Pin
RTOS Skills: periodic timer
Description: This LED will flash at a rate controlled by a periodic timer. 

3. OneShotTimerLED - ARD_D8_Pin
RTOS Skills: Interrupt Handling, one shot timers
Description: This LED will be triggered by the press of the blue button on the STM board. It will cause a one-shot timer to flash the LED on, then off.

4. QueueLEDs (Two LEDs required) - ARD_D9_Pin and ARD_D10_Pin
RTOS Skills: Tasks, Queues
Description: Here you will create two tasks that "ping pong" back and forth, via a queue, to turn their respective LEDs on/off. Using a queue, the "ping" task will send a command to the "pong" task to flash it's LEDs. In return, the "pong" task will send, via another queue, a command back to the "ping" task to flash it's LED.

== OPTIONAL FEATURES - These are not required but will gain you bonus points ====

5. ResourceLED.
RTOS Skills: Tasks, Resource Management
Description: Here you will create several tasks, each competing to use a single LED. The tasks must share the LED using RTOS resource management skills.

6. EventGroupLED.
RTOS Skills: Tasks, Event Groups
Description: Here you will create several tasks, each in charge of a given event bit. Another task will be watching the event bits, then turn on an LED once all the event bits are set. The cycle repeats at a given rate.

In summary, in addition to the two user-mode LED 1 on the STM board, you'll need about four additional LEDs that you will connect to the STM external connector, i.e., the Arduino compatible connector. See the attached PDF to see the pins you'll need to use for the required parts of the final assignment.

NOTE: For the optional parts of the assignment, you can add additional LEDs to other Arduino pins as needed.

To certify that you have completed the above skills, you should create a PDF document. The PDF document should include screen shots from your system and also clearly state your name. You should show all major parts of your code in the screenshots.

NOTE: Please name your PDF using this naming convention: UCSD-Embedded-RTOS-Final-Assignment-FirstName-LastName.pdf and then submit for grading.
 
