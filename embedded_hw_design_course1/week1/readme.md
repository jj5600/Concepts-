week 1 assignment: 
Reading: 
These are the required reading texts for this module. You can expect this content to appear in assignments or exams.
Read  "Complex Systems and Microprocessors"  section 1.2 from the textbook
 Student Learning Outcomes
This assignment is connected to the following student learning outcomes from the syllabus.
Install STM32CubeIDE and CubeMX
Run LED blink + UART print on the STM board
Create a block diagram for the chosen embedded system
Do you have questions about this assignment?
Post your questions in the Ask the Instructor Forum, located towards the top of the Modules area of this course.

Instructions
For all lab assignments, use the following file naming format to upload your work: W#_First Name_Last Name.zip
Please zip up your complete project for grading.
A: To create a project for the B-L475E-IOT01A board on STM32CubeIDE version 2.0  for development and STM32CubeMX for project configuration. 
Prerequisites
Install the standalone version of STM32CubeIDE v2.0
Links to an external site.
.
Install the standalone version of STM32CubeMX
Links to an external site.
.
Install a console emulator such as TeraTerm for Windows or iTerm for Mac. This is used to display the output from the UART.
Ensure the relevant STM32L4 MCU firmware package is installed via the STM32CubeMX updater. 
Step-by-Step Guide
Part 1: Project Setup and Code Generation (using STM32CubeMX) 
Open STM32CubeMX and start a new project.
In the Board Selector tab, type and select the board part number: B-L475E-IOT01A.
Click Start Project.
A pop-up will ask if you want to initialize all peripherals to their default mode for the selected board; click Yes. This configures the basic pins and clocks for the board's features.
(Optional) The Pinout & Configuration tab will open. You can further customize peripheral settings (e.g., enable specific sensors, configure Wi-Fi module interfaces, etc.).
Go to Project -> Generate Code (or click the generate code icon).
In the Project Manager settings:
Specify a Project Name and Project Location.
Select STM32CubeIDE as your Target IDE from the dropdown menu.
Ensure the Firmware Package is the correct STM32CubeL4 series version.
Configure any code generation options as needed, then click Generate Code. This creates a .ioc file and the initial C code files. 
Part 2: Project Import and Development (using STM32CubeIDE)
Open STM32CubeIDE and choose your workspace.
From the top menu, navigate to File -> Open Projects from File System.
In the Import Source screen, select Directory and browse to the location where you saved the project using STM32CubeMX. Select the project folder.
The project should appear in the "Projects" list. Click Finish to import it into your workspace.
The project should now appear in the Project Explorer view.
Build the project by clicking the Build icon (hammer symbol) in the toolbar. This compiles the generated code.
Write your application logic, typically starting in the main.c file.
Look at the following link
Links to an external site.
 , section 6,for writing the Blink LED example, 
The code that you will need to add to main is: 

HAL_GPIO_TogglePin (GPIOA, GPIO_PIN_5);
HAL_Delay (100);   /* Insert delay 100 ms */
Look at the following link,
Links to an external site.
 section 2 for writing, building and debug the Hello World Print to the UART
Note the UART console emulator should be set for baud rate: 115200, Data:8 bits, Parity: None, Stop bits:1, Flow Control: None

uint8_t Test[] = "Hello World !!!\r\n"; //Data to send
HAL_UART_Transmit(&huart2,Test,sizeof(Test),10);// Sending in normal mode
HAL_Delay(1000);
Make sure you had connected your B-L475E-IOT01A board to your PC via USB before building and debugging in step 7 above.
You can also flash the code, by right-clicking on the project name in the Project Explorer and selecting Run As -> STM32 Cortex-M C/C++ Application. 
You have now successfully created and built a project for your B-L475E-IOT01A board in STM32CubeIDE version 2.0. 
 
B: Your assignment is to construct a block diagram for a real-world embedded system.
You can choose any device you like; it could be 
a thermostat, a drone sensor node, a wearable device, or something unique to your industry.
Your block diagram should identify:
the microcontroller, sensors, outputs, memory components, power subsystem,
and communication interfaces.
Expectations
The expectations from this assignment are to ensure that you can successfully set up the STM board, write, compile, download, and execute a simple "Hello World" code, and also blink the LED.
Supplemental Resources
This article explains the workflow for creating B-L475E-IOT01A projects in STM32CubeIDE version 2.0.0 using standalone STM32CubeMX:

https://wiki.st.com/stm32mcu/wiki/STM32StepByStep:Step3_Introduction_to_the_UART
Links to an external site.



