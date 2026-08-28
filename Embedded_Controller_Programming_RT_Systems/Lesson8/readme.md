Lesson 8 DMA/RTC and Power modes:
1.) slides
2.) read chapter 16.5 and 17
Final Exam:

Note: Follow these steps to complete this assignment. Feel free to explore and try different ways to implement. It is just a software and there is more than one way to write the code. Do share with me if you come across any surprises.

Prerequisite:

You will use same logMsg() and logGetMsg() from mid-term
Enable Timer 2 and Timer 3  interrupts
Enable  IWDG Watchdog
Final:

  Note: comment out MX_IWDG_Init(), MX_RTC_Init()  in the beginning to test #1- #4.  You will uncomment when you will test this out in #5 - #6.

// Here is menu list for your reference

Void main()

{

/* USER CODE BEGIN 2 */

    logMsg(&huart1, "welcome to Embedded controller programming \r\n");

    logMsg(&huart1, "Enter g for toggling Green LED \r\n");

    logMsg(&huart1, "Enter b for toggling Blue LED \r\n");

    logMsg(&huart1, "Enter s to generate SW interrupt  \r\n");

    logMsg(&huart1, "Enter t to start timer 3 \r\n");

    logMsg(&huart1, "Enter w to trigger watchdog reset\r\n");

// Rest of the code goes here

  /* USER CODE END 2 */

}

1 Create a software interrupt and use one of the non-used IRQ – 5 points
You will write your own IRQHandler, callback method and will enable interrupt.
You could any unused IRQ but let’s use 48 for this assignment.
FMC_IRQn                    = 48,     /*!< FMC global Interrupt */
Enable the FMC_IRQn in MX_GPIO_Init()
Create another menu with character ‘s’, which will generate the software interrupt and you should print the message “ SW Interrupt detected”.  Here are steps involved.
When the key is pressed, you should enable STIR using FMC_IRQn
This will trigger the interrupt and callback method will be called from ISR
Set a flag or do something else in callback to detect interrupt
Print the message “ SW  Interrupt detected”. 
Strongly recommend to define IRQHandler for  FMC_IRQn   in stm32l4xx_it.c file as it has other handlers too.                 
2 Create a method myDelay1() using timer2, which will take input in Millisecond – 5 Points
Replace the existing HAL_Delay() with myDelay1() for Blue LED
Program timer 2 registers to implement the delay.
// Here is the method signature and feel free to implement the way you want to

void myDelay1(uint32_t val)  {            

}

3 Create a method myDelay2() using SysTick, which will take input in Millisecond – 5 Points
Replace the existing HAL_Delay() with myDelay2() for Green LED
Program SysTick registers to implement the delay
// Here is the method signature and feel free to implement the way you want to

void myDelay2(uint32_t val) {            

}

4 Use Timer 3 to count events – 5 points
Program the timer3 in MX_TIM3_Init() with values , which will expire every second.
Create a menu with character ‘t’ to start the timer3
You will need to implement HAL_TIM_PeriodElapsedCallback() method to know when 1 sec has lapsed.
Count for 10 (equivalent to 10 sec) in main loop and stop the timer3 when count reaches 10.
Print the log message - "Total counted timer3 event = %d\r\n"
5 Uncomment MX_IWDG_Init() code to test the watchdog – 5 Points
Program the prescaler, window and reload value for timeout of 0.5 sec.
Pet the watchdog in main () code – to avoid board reset
Make sure you don’t have any unconditional delay in main() code.
There should be no reset and software should be working properly.
Now simulate a failure by introducing a delay more than 0.5 sec to miss the watchdog pet.
Create a menu with character ‘w’ and delay of 1 sec. Since 1 sec is more that 0.5 sec, SW will miss the pet and unit will reset.
You could myDelay1() or myDelay2() for 1 sec delay.
6 Uncomment MX_RTC_Init() to test RTC Alarm – 4 Points
Set the alarm for hour 0, minute 1
Use RTC callback  to detect the alarm
One minute after start of the board , alarm should be set.
Print the log Message  "RTC alarm A detected .... \r\n"
7 Submit the followings - 1 Point
New or modified files only - e,g main.c, stm32l4xx_it.c
Terminal output
Any other comments you could write in-line when you submit the assignment
