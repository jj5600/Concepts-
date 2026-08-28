lesson 2 Micro Controller and Registers:
1.) Read slides
2.) read You should read chapter 1 and 4.1 from book. 
https://developer.arm.com/ip-products/processors/cortex-m/cortex-m4#:~:text=The%20Arm%20Cortex%2DM4%20processor,control%20and%20signal%20processing%20capabilitiesLinks to an external site.. 

https://www.techspot.com/community/topics/qualcomms-decision-to-remove-integrated-modem-from-snapdragon-865-soc-is-puzzling.259087Links to an external site.

https://semiengineering.com/von-neumann-is-struggling/Links to an external site.

3.) Assn2 Overview:
Follow these steps to complete this assignment.

Note: I have attached the assignment overview and Demo video for your reference. 

Use STM32CubeIDE to generate code without UART interrupt
This exercise is to use UART in polling mode.
Write additional code in C language to do the followings.
Implement logMsg() method to display the string on terminal with default UART timeout 100 ms - 1 Point
Implement logGetMsg () method to receive character from terminal with default UART timeout 100 ms - 1 Point
Write the logic to process character from terminal  in main()   - 3 Points
If you enter char ‘g’ on the terminal   
Print the received char
And toggle green LED. If LED was on then it will turn off and vice-versa.
Add delay of 1 sec to make sure LED stays on/off for 1 sec.
If you enter char ‘b’ on the terminal  
Print the received char
And toggle blue LED. If LED was on then it will turn off and vice-versa.
Add delay of 1sec to make sure LED stays on/off for 1 sec.
If you enter char ‘t’ on the terminal  
Print the received char
And change UART timeout from 100 ms  in ( #3.1/#3.2 )to 1 ms
For any other character, print “unknown character received”
Find below the  code template for your reference only. Feel free to use the methods parameter differently but keep the method name same.  We will be using the same name for future assignments.
// logMsg method

void logMsg(UART_HandleTypeDef *huart, char _out[])

{

                // fill in code here

                // Use HAL_UART_Transmit()

}

// logGetMsg method

uint8_t logGetMsg(UART_HandleTypeDef *huart )

{

  // fill in here

}

Void main()

{

/* USER CODE BEGIN 2 */

    logMsg(&huart1, "welcome to Embedded controller programming \r\n");

    logMsg(&huart1, "Enter g for toggling Green LED \r\n");

    logMsg(&huart1, "Enter b for toggling Blue LED \r\n");

    logMsg(&huart1, "Enter t to change timeout value to 1 ms \r\n");

 

// Rest of the code goes here

  /* USER CODE END 2 */

}

 

Test the software after pressing key b, g and other keys multiple times (but not t) slowly first. Then, press b or g few times quickly and watch what you notice and see on the screen. Write your observation/comments here or in the code - 1/2 point
 

Enter t to change the UART timeout to 1 ms and repeat step 4. Watch what you notice and see on the screen. Write your observation/comments here or in the code - 1/2 point
 

Repeat step 4 but reduce the led delay to 10 ms (It was set to 1 sec in 3.3 and 3.4 above). Watch what you notice and see on the screen. Write your observation/comments here or in the code - 1/2 point
  

Submit the followings - 1/2 Point
Main.c and any other modified files (only)
Attach the terminal output
