Lesson 5:
We continue building our Embedded Controller Programming with Embedded C skills by focusing on the programming GPIO, or General Purpose Input/Output. A typical Microcontroller has many GPIOs, and each can be configured many different ways: input, output, with or without pullup or pull downs, interupt inputs, and more.

GPIO Concepts
GPIO Data Structures
GPIO Functions and Macros
Reading: (Google these)
UM1884 User ManualLinks to an external site.

Description of STM32L4/L4+ HAL and low-layer driver

Chapter 31: HAL GPIO Generic Driver

Bonus Material for use with Bonus Videos.

ASF4 API Reference ManualLinks to an external site.

Description of ASF4 API

Video 1: https://www.youtube.com/watch?v=QLUTj7brdyo
Video 2: https://www.youtube.com/watch?v=YQEoBc4kpZE
Video 3: https://www.youtube.com/watch?v=HUuBGtdVTs0
Video 4: https://www.youtube.com/watch?v=lyRWCcXvutE
Video 5: https://www.youtube.com/watch?v=3-fJeZh8S_U
Video 6: https://www.youtube.com/watch?v=6tRDU9Od0Qs

Final Project Preview:
Preview of Final Project: Coffee Maker
This is an early look at the final project, called Coffee Maker! Even though we have more lessons to cover in the course, we have covered enough so that you can at least get started on the project.

Check out both the video and the attached presentation.

ALSO: I have setup a Discussion Group to discuss any questions/issues related to Coffee Maker project.

The "big picture" is that you will use your embedded skills to write code to control a Coffee Maker:

== User Buttons + LEDs ===
=> On/Off Button + LED (solid or blinking, depending on mode)
=>Strong Brew Button + LED
=> 12oz Size Button + LED (Travel Mug)
=> 10oz Size Button + LED (Large Mug)
=> 8oz Size Button + LED (Small Mug)
=> 6oz Size Button + LED (Small Cup)

== Internal Sensors ===
=> Water Level Sensor
=> Water Temperature Sensor

== internal control ==
=> Brew Water Relay Opened/Closed 
Video of final proj: https://www.youtube.com/watch?v=muVvwa8XLbI

Lesson 5 Assignment:
This Assignment will certify your Embedded C skills related to the following:

Your skills for using the HAL GPIO driver to configure the Blue button to generate an interrupt
Your skills for using the HAL GPIO driver to toggle an LED on/off from a interrupt service routine. Press the Blue button to turn the LED on. Then press again to turn the LED off. 
Here are the requirements for this assignment:

=1= Use STM32CubeIDE (or the older STM32CubeMX) to generate the default code for the STM32 Discovery Board.
=2= Edit, build, run, and debug the code that uses uses the HAL_GPIO API to toggle the LED2 On/Off when the blue button is pressed. The on/off toggle should happen in an interrupt service routine that runs when the blue button pressed. 
=3= The STM32 IOT Discovery board has an Arduino Connector. On that connector, connect pin D8 to the +(positive ) side of an LED (the longer LED pin), then connect the - (negative) of the LED (the short LED pin) to a small (say 330 ohm) resistor, and then connect the resistor to the Arduino GND pin. Write code to blink the LED connected to D8 at a 1 second rate. 

At the end of this demo, you will have the LED connected to the Arduino D8 flashing at 1 second rate, while at the same time be able to toggle the on-board LED on/off by pressing the Blue Push Button.

To certify that you have completed the above skills, you should create a PDF document similar to the one attached to this assignment. The PDF document should include screen shots from your system and also clearly state your name. Use the attached PDF as a template or guide, but you should replace the screen shots with your specific screen shots and your name.

NOTE: Please include a photo of your board and LED connected to the Arduino connector.

NOTE: If you are using a board other than the IoT Discovery Board, then find an available pin that you can connect an LED and flash it similar to how is done on the Arduino connector.

NOTE: Please name your PDF using this naming convention: UCSD-Embedded-C-Assignment-5-GPIO-FirstName-LastName.pdf and then submit for grading.

Lesson 5 Quiz
Question 1
1 / 1 pts
Select the answer below that is NOT a HAL GPIO data structurre.
  GPIO_InitTypeDef 
  LL_GPIOType 
  GPIO_PinState 
  GPIO_TypeDef 
 
Correct answer
Question 2
1 / 1 pts
You need to read the value of a GPIO pin. What function below do you use?
  HAL_GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint16_t GPIO_PIN) 
  HAL_GPIO_ReadPin(GPIO_TypeDef *GPIOx)
  HAL_GPIO_ReadPin()
  HAL_GPIO_Read(GPIO_TypeDef *GPIOx)
 
Correct answer
Question 3
1 / 1 pts
You need to set the value of a GPIO pin. Select the function you would use.
  HAL_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState) 
  HAL_GPIO_WritePin(GPIO_TypeDef *GPIOx)
  HAL_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
  HAL_GPIO_WritePin(uint16_t GPIO_Pin, GPIO_PinState PinState)
 
Correct answer
Question 4
1 / 1 pts
You need to toggle the value of a GPIO pin. What function do you use?
  HAL_GPIO_TogglePin()
  HAL_GPIO_TogglePin(GPIO_TypeDef *GPIOx)
  HAL_GPIO_TogglePin(uint16_t GPIO_Pin)
  HAL_GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin) 
 
Correct answer
Question 5
1 / 1 pts
When configuring GPIO pins as inputs and outputs, select the answer below that is NOT valid.
  #define GPIO_MODE_OUTPUT_PP 
  #define GPIO_MODE_INPUT_OUTPUT 
  #define GPIO_MODE_OUTPUT_OD 
  #define GPIO_MODE_INPUT 
