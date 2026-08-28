1.) Read slides
2.) chapter 7 and 20
3.) AUG 27 QUIZ: Score for this quiz: 9.33 out of 10
Submitted Aug 27 at 11:50am
This attempt took 62 minutes.

---

QUESTION 1 (0.5/0.5 pts)
According to the procedure call standard for ARM architecture, the arguments are passed in core registers (R0-R3) and on the stack. When calling a function sum(1, 2, 3, 4), what is the value of the register R2? Assuming each integer has 32 bits.

ANSWER: 3

---

QUESTION 2 (0.5/0.5 pts)
The procedure can also take arguments larger than 32 bits. For example, a double-word variable, such as 64-bit long long type variable in C, is passed in two consecutive registers (e.g. R0 and R1, or R2 and R3). A 128-bit variable is passed in four consecutive registers.

int64_t add_64(int64_t a, int64_t b)

Select all registers used to store the variable a.

ANSWERS: R0, R1

---

QUESTION 3 (0.5/0.5 pts)
If the physical memory address has 32 bits, the maximum amount of memory it can access is:

ANSWER: 4GB

---

QUESTION 4 (0.5/0.5 pts)
Memory Address | Memory Data
0x20008003    | 0xA7
0x20008002    | 0x90
0x20008001    | 0x8C
0x20008000    | 0xEE

Please enter using 0x format - e.g 0x12345678

If Big Endian, the word stored at address 0x20008000 is:
ANSWER: 0xEE8C90A7

If Little Endian, the word stored at address 0x20008000 is:
ANSWER: 0xA7908CEE

---

QUESTION 5 (0.5/0.5 pts)
Select all instructions which will update all N, Z, C and V flags according to the result.

ANSWERS: ADDS, MULS, SUBS

---

QUESTION 6 (0.38/0.5 pts)
Select all possible answers for communication between Interrupt and Threads.

ANSWERS: shared memory, global variable, Queue, Callback method

---

QUESTION 7 (0.5/0.5 pts)
What is the highest priority exception (value) and name of the exception?

ANSWER 1: -3
ANSWER 2: Reset

---

QUESTION 8 (0.5/0.5 pts)
What are the name of the registers to enable and disable interrupts?

Please enter the short four letter name - e.g ICPR, IABR

ANSWER 1: ISER
ANSWER 2: ICER

---

QUESTION 9 (0.5/0.5 pts)
Which register is used to disable all exceptions with configurable priority?

Please enter all capital or small letter of the register in short form - e.g BASEPRI/basepri

ANSWER: PRIMASK

---

QUESTION 10 (0.5/0.5 pts)
Select all exceptions with fixed priority.

ANSWERS: NMI, RESET, HardFault

---

QUESTION 11 (0.25/0.5 pts)
Select all SysTick timer registers.

ANSWERS: Calibration Register, Reload value Register

---

QUESTION 12 (0.5/0.5 pts)
What is the name of module/controller which is used for tamper detection on the controller?

Please use the short form in upper or lower case - e.g DMA/dma

ANSWER: RTC

---

QUESTION 13 (0.5/0.5 pts)
What is IRQ number and exception number for SysTick interrupt?

Please enter integer number.

ANSWER 1: -1
ANSWER 2: 15

---

QUESTION 14 (0.38/0.5 pts)
Select all possible power modes for the processor.

ANSWERS: sleep, Run, Stop 1, Standby

---

QUESTION 15 (0.5/0.5 pts)
Select all possible bus interface for the processor.

ANSWERS: I2C, AHB, APB

---

QUESTION 16 (0.33/0.5 pts)
What is use of DMA controller? Select all possible answers.

ANSWERS: Peripheral to peripheral, Peripheral to memory, Memory to peripheral

---

QUESTION 17 (0.5/0.5 pts)
Select all the valid exception/interrupt state.

ANSWERS: Inactive, Active, Active Pending, Pending

---

QUESTION 18 (0.5/0.5 pts)
Select everything you need to implement interrupts?

ANSWERS: Thread, Synchronization, ISR, Interrupt number, Priority

---

QUESTION 19 (0.5/0.5 pts)
What should the Link Register (r14) store when a caller is calling a subroutine?

ANSWER: Return address of the subroutine

---

QUESTION 20 (0.5/0.5 pts)
Select all the applicable instructions used for power management.

ANSWERS: SEV, WFI, WFE

---

TOTAL SCORE: 9.33/10 ✓
