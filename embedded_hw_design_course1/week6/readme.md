Required Reading
 These are the required reading texts for this module. You can expect this content to appear in assignments or exams.

Read section 8.2(IoT System Applications),8.3(IoT System Architectures),8.4(Network for IoT),9.2(Vehicular use cases),9.3(Network controlled systems in cars and airplanes),9.4(Vehicular Networks)  from textbook

 Overview
1. The quiz is covering your understanding of your knowledge of IoT Embedded Systems and IoT in Automotives
2. The Lab assignment is to give you exposure to using sensors in IoT devices

Student Learning Outcomes
Do you have questions about this assignment?
Post your questions in the Ask the Instructor Forum, located towards the top of the Modules area of this course.

Instructions
(10 points)

Quiz #5

(10 points)

Create a Interrupt-Driven Thermostat, you can use parts from the previous 2 assignments.
Week 5:"Temp Sensor" and Week 4:User button with Interrupt.
For this assignment, you will be using: Peripherals: Temperature sensor (I2C), User button (EXTI interrupt), UART (printf), LED (status output)

System Behavior Requirements
You will implement a “thermostat” controller:

A) Temperature sampling
Read temperature once per second.

Print to UART:

Current temperature (°F)

Setpoint (°C). On power up, the default Setpoint temperature to 60°F

State: HEATING ON/OFF

B) Button interrupt → change setpoint
User button is handled via interrupt (EXTI) (no polling).

Each button press increases setpoint by 1°F.

If setpoint exceeds 80.0°C, wrap back to 60°F.

C) Control logic
Implement hysteresis to avoid rapid toggling:

If temp <= setpoint - 0.5°F → “HEATING ON”

If temp >= setpoint + 0.5°F → “HEATING OFF”

Indicate heating state with an LED:

LED ON = Heating ON

LED OFF = Heating OFF
