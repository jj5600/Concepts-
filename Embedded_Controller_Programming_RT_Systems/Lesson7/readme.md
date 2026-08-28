Lesson 7 Timers

1.) read slides
2.)Read chapter 16 from text book. 

About IWDG:

https://youtu.be/dcLS2GSfdN8Links to an external site.

3.) assignment: 
AUG 9 QUIZ: Score for this quiz: 6 out of 6
Submitted Aug 9 at 11:18pm
This attempt took 76 minutes.

---

QUESTION 1 (2/2 pts)
Suppose the HSE (high-speed external clock) of 16 MHz is selected as the clock of the timer. In order to generate a 1Hz square wave with duty cycle of 50%, how would you set up the timer? Show the value of ARR, CCR, and PSC registers.

Hint: The solution is not unique. So, assume ARR = 999, Mode 1, up-counting, Polarity 1

Please enter the decimal value.

CCR = 500
PSC = 15999

ANSWERS:
Answer 1: 500
Answer 2: 15999

---

QUESTION 2 (2/2 pts)
If the MSI 4.094 MHz clock is used as the system clock and the SysTick selects it as the clock.

Please enter decimal value and rounded to an integer value.

What should the SysTick_LOAD register be in order to generate a SysTick interrupt every microsecond?
Answer: 3

What is the SysTick_LOAD value in order to generate a SysTick interrupt every millisecond?
Answer: 4093

ANSWERS:
Answer 1: 3
Answer 2: 4093

---

QUESTION 3 (1/1 pts)
Suppose the default MSI (2.097 MHz) is used to drive the system timer (SysTick).

Can you use this MSI to generate a SysTick interrupt every minute?

ANSWER: True

---

QUESTION 4 (1/1 pts)
What is the max interrupt period generated (In Sec) by default MSI (2.097 MHz) which is used to drive the system timer (SysTick)?

ANSWER: 8

---

TOTAL SCORE: 6/6 ✓
