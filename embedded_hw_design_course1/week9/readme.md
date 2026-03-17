Instructions
1. Run BLE use case (heartRate), and modify certain values (10 points)
A primary Bluetooth Low Energy (BLE) example for the B-L475E-IOT01A1 Discovery kit is the HeartRate application, found in the STM32Cube_FW_L4_V1.x.x/Projects/B-L475E-IOT01A/Applications/BLE/HeartRate/ directory of the STM32Cube firmware package. This application demonstrates using the on-board SPBTLE-RF module to simulate heart rate data. 
I am attaching the zipped directory for the STM32Cube_FW_L4_V1.18.2, where you can find the HeartRate application.


Default Installation Path

If you have installed the STM32CubeL4 package via STM32CubeIDE or STM32CubeMX, the project is located at:

C:\Users\username\STM32Cube\Repository\STM32Cube_FW_L4_Vx.xx.x\Projects\B-L475E-IOT01A\Applications\BLE\HeartRate\ 
Or you can use the zip file Download zip fileI attached for the STM32Cube_FW_L4_V1.18.2, where you can find the HeartRate application.

 

How to Open the Project

Open STM32CubeIDE.
Navigate to File > Import...
Select General > Existing Projects into Workspace.
Browse to the folder mentioned above, then select the folder corresponding to STM32CubeIDE
You should see the HeartRate project in your IDE, looking like this HeartRate Project snapshot.png
 

Dowload the nRF-Connect App from NordicSemi on your phone to connect to  the HeartRate application running on the STM32.
Here is the link to download the App either for Apple or Android phones.
https://www.nordicsemi.com/Products/Development-tools/nRF-Connect-for-mobileLinks to an external site.

You will need to build and run the HeartRate code on the STM32 and then
open the nRF-Connect App-> Scroll to find "HR_L475_IoT" -> Hit Connect-> Select (.--) Advertised Services icon from the top menu -> Hit the down arrow on the "Heart Rate Measurement(UUID:2A37)", here you should see the Heart Rate value in bpm displayed, this is being 
sent in the Advertising BLE packet connection.
I am attaching a short video here to show the above steps.
A) As part of the assignment, provide a screenshot that shows the heart rate value in the Heart rate Measurement.

B) Modify the code to display for the following values in the BLE advertising code, and provide a screenshot and the zipped up project with the modified code.

Modify Heart rate for the following values:

In the Heart rate Measurement(UUID:2A37) value, put a fixed value of 75 to display. (Hit the down arrow to display)
In the Body Sensor Location(UUID:2A38), change the value from “Hand” to “Wrist”. (Hit the down arrow to display)
Manufacture Name string(UUID: 2A29) change the Value from “STM” to “STM_UCSD”. (Hit the down arrow to display)

Hint: Look at the uuid.h file and search for the above-mentioned UUID 

2.  Create a hardware schematic a thermostat design based on the following component using KiCad. (5 points)
Use the STM32 Discovery schematic Download STM32 Discovery schematicas reference to see how to connect these components.
Use the STM32L475 as the SoC, attach the components needed for creating a thermostat

Including HST221 sensor, User Push button, the BLE module SPBTLE-RF and LED.

3. Create a software flow diagram that will perform the following behavior for the thermostat. (5 points)
On boot up read the temperature sensor data, this will be the current temperature value,
The default desired temperature on boot up should be 60°F.
If the push button is pressed, the desired value should increase by 1°F. If the desired value exceeds 80.0°F, wrap back to 60°F.
If the current temperature <= (desired temperature - 0.5 °F)  , then turn on the LED(Heating ON).
If current temperature >= (desired temperature + 0.5 °F), then turn OFF the LED(Heating OFF).
Also transmit the desired value on the BLE module. 
