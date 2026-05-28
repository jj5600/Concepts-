Overview:
The last but not least lesson in the course! 

SPI Concepts
SPI Data Structures
SPI Functions and Macros

Video 1: https://www.youtube.com/watch?v=4k8IVqqrR-o
Video 2: https://www.youtube.com/watch?v=qfQXLGatRBQ
Video 3: https://www.youtube.com/watch?v=Ci7cmsvg2xk
Video 4: https://www.youtube.com/watch?v=ivsCwFH7Jqo
Bonus : https://www.youtube.com/watch?v=PTaylV1uYOY

Reading: UM1884 User ManualLinks to an external site.

Description of STM32L4/L4+ HAL and low-layer drivers

Chapter 62: HAL SPI Generic Driver

Bonus Material for use with Bonus Videos.

ASF4 API Reference ManualLinks to an external site.

Description of ASF4 API

Chapter 33: SPI Drivers
Virtual console: https://www.youtube.com/watch?v=TRqc8nQM0QQ

Final Assignment:
This Assignment will certify that you have mastered all Embedded C skills that we covered in the lessons of this course.

You have THREE Options for the Final Assignment:

Option #1. Do the assignment listed below. The advantage of this assignment is that it reviews and combines all the previous assignments into a final assignment. This is the option most students select. You will submit a detailed PDF with screen shots (just like you have done all semester) for grading.

Option #2. Coffee Maker Project. This project is more "open ended" in that you use your Embedded Skills and the STM32 Discovery Board to write code to control a Coffee Maker. You will submit a detailed PDF with screen shots (just like you have done all semester) for grading.

Option #3. Custom Project. If you have a custom project you want to use for your final project, please do so. Same requirement as the other two:  submit a detailed PDF with screen shots (just like you have done all semester) for grading.

Here are the requirements for OPTION 1:

=1= Use STM32CubeMX/STM32CubeIDE to generate the initial code for this final assignment. 

=2= You will use the UART that is connected to the Arduino connector to display output from this assignment onto PuTTy (or similar) terminal emulator. (Similar to how you displayed output on the UART from a previous assignment.)

=3= You will use the Blue Button on the STM board to cycle through different demos. Each time you press the Blue button, the title of the demo will be sent to the UART and displayed on PuTTY. Importantly, pressing the Blue Button should generate an interrupt and change a "demo count" so that your main looping code changes to the next demo on every button press. When you power up "Demo 1" will auto start. When you press the Blue Button "Demo 1" ends and "Demo 2" starts. This continues until you reach the last demo, then you cycle back to Demo 1. Stated differently, pressing the Blue Button lets you cycle through the demos as many times as you like.

=4= The list of demos you should include are:

= "Demo 1: LL APIs".  Use the following APIs during demo 1: (a) get flash size  LL_GetFlashSize(); (b) get the device unique ID, LL_GetUID_Wordn(); c3) toggle the LED, LL_GPIO_TogglePin() at a 1 second rate. Display the Flash Size and GUID only when demo begins, but keep flashing the LED every 1 second until the Blue Button is pressed to advance to next demo.

= "Demo 2: HAL APIs". Use the following HAL APIs during demo 2: (a) get the device ID, HAL_GetDEVID(), (b) read the device unique ID, HAL_GetUIDwn(), and  (c)toggle the LED, HAL_GPIO_TogglePin() at a 2 second rate, using HAL_Delay() to sleep for the 2 seconds. Display the Dev ID info only when demo 2 begins, but keep flashing the LED every 2 second until the Blue Button is pressed to advance to next demo.

= "Demo 3: BSP APIs". Use the following BSP APIs during demo 3: (a) read the temperature, BSP_TSENSOR_ReadTemp() (b) turn the LED on every 3 seconds with BSP_LED_On() (c)  turn LED off, every 3 seconds with BSP_LED_Off(). In other words the LED should blink on/off at a 3-second rate (3 seconds on, 3 seconds off). Continue this until the Blue Button pressed to advance to the next demo.

= "Demo 4: BONUS!" This is optional. Use this demo to demonstrate an optional I/O device that is on the STM board. Or, connect additional I/O devices to the Arduio connectors. Some examples: (1) connect a push-button switch to one of the GPIO input pins on the Arduino connector, then read the status of the on-off push button; (2) connect an LED to one of the GPIO output pins, and toggle the LED at a 4 second cycle (4 seconds on, 4 seconds off). (3) Connect an ADC device to one of the ADC Arduino pins, and read the value. (4) connect an I2C or SPI device to the Arduino pins, and read the info from those devices.

NOTE: Demo 1, 2, and 3 are required. However Demo 4 is optional for extra credit.

To certify that you have completed the above skills, you should create a PDF document similar the PDF documents we have used for previous assignments. The PDF document should include screen shots from your system and also clearly state your name. Include a photo for the output being displayed on a PuTTY (or equivalent) serial terminal emulator.

NOTE: Name your PDF using this naming convention: UCSD-Embedded-C-Final-Assignment-FirstName-LastName.pdf and then submit for grading.
