Lesson 4: Introduction to Assembly language

1.) read slides
2.) read Chapter 5 & 6
3.) JULY 19 QUIZ: Score for this quiz: 7 out of 7
Submitted Jul 19 at 11:46pm
This attempt took 152 minutes.

---

QUESTION 1 (2/2 pts)
Find out what the following assembly code calculates. What is the final value in r0 (in decimal)?

AREA my code, CODE

EXPORT __main

ALIGN

ENTRY

__main PROC

MOVS  r0,#0
MOVS  r1,#15  
MOVS  r2,#0  

loop
CMP   r2,r1
BGT   stop
MLA   r0,r2,r2,r0  
ADDS  r2,r2,#1
B     loop

; The final result is saved in register r0

stop
ENDP
END

ANSWER: 1240

---

QUESTION 2 (2/2 pts)
Translate the following C program into an assembly program. The C program finds the minimal value of three signed integers. Assume a, b, and c are stored in register r0, r1, and r2, respectively. The result min is saved in register r3.

C CODE:
if (a < b && a < c) {
     min = a;
} else if (b < a && b < c) {
     min = b;
} else {
     min = c;
}

ASSEMBLY ANSWER:
; r0 = a, r1 = b, r2 = c

CMP r0,r1       ; a < b
BGE elseif      ; if anything but a < b go to elseif

CMP r0, r2      ; a < c
BGE elseif      ; if anything but a < c go to elseif

MOV r3, r0      ; min = a
B end

elseif
     CMP r1, r0 ; b < a
     BGE else   ; if anything but b < a go to else

    CMP r1, r2  ; b < c
    BGE else    ; if anything but b < c go to else

    MOV r3, r1  ; min = b 
    B end

else
    MOV r3, r2  ; min = c
    B end

end

---

QUESTION 3 (1/1 pts)
Suppose r0 = 0x20008000. From which address will r7 be stored in the following instructions? What is the value of r0 after executing each instruction? Assume each instruction is being executed separately, i.e., they are not part of a program.
Please enter the result in Hex format starting with 0x.

STMIA r0!, {r3, r9, r7, r1, r2}
Hint: value of r2 = 0x20008004

r0 = 0x20008014
r7 = 0x2000800C

STMIB r0!, {r3, r9, r7, r1, r2}
r0 = 0x20008014
r7 = 0x20008010

ANSWERS:
Answer 1: 0x20008014
Answer 2: 0x2000800C
Answer 3: 0x20008014
Answer 4: 0x20008010

---

QUESTION 4 (2/2 pts)
Write an assembly program that converts a 32-bit integer stored in the memory from little endian to big endian, without using the REV instruction. Make sure the result is saved back to the memory.

Example:
If, Little-endian: 0x01020304
Then, Big-endian: 0x04030201

ASSEMBLY ANSWER:
; suppose r4 is 0x8200_0004

LDR r0, [r4]        ; load in value from reg
LDR r1, =0xFF       ; masking each byte
LDR r2, =0x0        ; starting value for output
MOV r3, #4          ; 4 bytes to swap 

loop
AND r5, r0, r1      ; mask lower byte and store in r5
LSR r0, #8          ; shift r0 by 8 bits 
LSL r2, #8          ; shift r2 left by 8 bits
ORR r2, r2, r5      ; insert extracted bit to output
SUB r3, r3, #1      ; decrement counter
CMP r3, #0          ; compare
BNE loop             ; loop again if != equal

end
STR r2, [r4]        ; save solution to memory

---

TOTAL SCORE: 7/7 ✓
