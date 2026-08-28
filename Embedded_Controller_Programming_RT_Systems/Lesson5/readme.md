Lesson 5 Introduction to Interrupts:
1.) read slides;
2.)read chapter 11
3.) Midterm:

Note: Follow these steps to complete this assignment. Feel free to explore and try different ways to implement. It is just a software and there is more than one way to write the code. Do share with me if you come across any surprises.

Prerequisite:

This exercise is to use UART in Interrupt mode.
Use STM32CubeIDE to generate code with UART interrupt
Enable GPIO PIN 13 interrupt, used for blue user switch and handler is
                            EXTI15_10_IRQHandler ()

 Mid-term:

1 Implement methods below (same name as assignment #2) using interrupt -  2 Points
Implement logMsg() method to display the string on terminal using interrupt
Implement logGetMsg () method to receive character from terminal using interrupt
If you enter char ‘g’ on the terminal
Print the received char
And toggle green LED (if it was ON then will change to OFF)
If you enter char ‘b’ on the terminal
Print the received char
And toggle blue LED   (if it was ON then will change to OFF)
For any other character, print “unknown character received”
Test the software after pressing key b, g and other keys multiple times. Press b or/and g few times quickly and see what happens. Explain the results compared with Assignment #2 with use of interrupt now.
// Main starts here

Void main()

{

/* USER CODE BEGIN 2 */

    logMsg(&huart1, "welcome to Embedded controller programming \r\n");

    logMsg(&huart1, "Enter g for toggling Green LED \r\n");

    logMsg(&huart1, "Enter b for toggling Blue LED \r\n");

    logMsg(&huart1, "Enter v to find the sum of squares of a number  \r\n");

    logMsg(&huart1, "Enter n to find number of 1’s  \r\n");

    logMsg(&huart1, "Enter d to disable a interrupt \r\n");

    logMsg(&huart1, "Enter e to enable the interrupt \r\n");

    logMsg(&huart1, "Enter a to disable all interrupts \r\n");

 

// Rest of the code goes here

}

2 Create mySquareSum.s file. This file will implement a routine which will take integer value and return integer. 3 Points
For a given integer take the square upto this integer and add it - Capture-2.JPG  
So, for 3, it would be 3^2 + 2^2+1^2 = 14
Create another menu with character v, and pass fixed value, say 3
      // Call assembly routine with value 3 and print the value of sum (should be 14)

      //  Might use sprintf() to print values of decimal as shown below.

       char buffer[50];

                           sprintf(buffer, "my value %d\r\n",  12));

                          logMsg(&huart1, buffer);

3 Create a method, numOnes(),   in main.c and implement in assembly. 3 Points
This method takes one integer argument and return number of 1’s.
Create another menu n, pass fixed value, say 7, to this method
uint32_t numOnes(uint32_t a)

{

// Add assembly code here

}

// So, if we pass 7, it should return 3 as 7 has 3 1's (0x111)

4 Implement the callback method for HAL_GPIO_EXTI_IRQHandler() – 2 Points
Print “Blue button pressed” on serial console if blue button is pressed.
//Remember to check the PIN number 13 in the call back method as same interrupt is used for PIN 10 – PIN 15.

5 Implement enable and disable interrupt using interrupt registers (No HAL or CMSIS methods) for a given interrupt - 2 points
Add another menu with char “d” to disable the interrupt and “e” to enable interrupt.
Press the blue switch few times and observe “Blue button pressed” message on the console.
Press d key to disable the blue switch interrupt. Now press the switch and should see no “Blue button pressed” message on console.  But other key should work.
I suggest to use blue switch interrupt to disable interrupt to keep displaying the character on serial console   
Now press e key to enable the blue switch interrupt. Press the switch and should see "Blue button pressed” message on console. This means our enable and disable interrupt method is working.                 
USART1_IRQn                 = 37,     *!< USART1 global Interrupt *                                         

EXTI15_10_IRQn              = 40,     /*!< External Line[15:10] Interrupts

          Void myDisableIntr(uint32_t IRQn)

         {

                 // Write code here using registers

         }

           Void myEnableIntr(uint32_t IRQn)

         {

           // Write code here

         }

6 Implement method myDisableAllIntr() to disable all interrupts. 2 Points
Create another menu with character ‘a’ to invoke myDisableAllIntr().
Press key a and it should disable all interrupts.
Now press any key or  the blue switch and notice that nothing is shown on the screen, because all interrupts are disabled.
Reset the board and everything should be back to normal.
Void myDisableAllIntr()

{

            // Write code here

            // You could use FAULTMASK Register or cpsid instruction or CMSIS function

}

 

7 Submit the followings - 1 Point
Explanation for #1.6
Upload only the modified files separately and not zipped file.
Attach the terminal output
