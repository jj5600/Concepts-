Lesson 3: Micro controller Instruction sets

1.) read Slides
2.) read chapter 3 and 4 from textbook
3.) Assn 3# Quiz Results

**Score:** 8 out of 8  
**Submitted:** Jul 13 at 12:11am  
**Duration:** 127 minutes

---

## Question 1 (1/1 pts)

**Topic:** Flag calculations for ARM instructions

**Given:**
- r0 = 0xFFFFFFFF
- r1 = 0x00000001
- r2 = 0x00000000
- Initial flags: N=0, Z=0, C=0, V=0

**Example (solved):**
```
SUBS r3, r0, r0
r3 = 0x00000000, NZCV = 0110
```

**Answers:**

1. ADDS r3, r0, r2
   - r3 = 0xFFFFFFFF
   - NZCV = 1000

2. LSRS r3, r1, #1
   - r3 = 0x00000000
   - NZCV = 0110

---

## Question 2 (2/2 pts)

**Topic:** Bitwise operations

**Given:**
- r0 = 0x0F0F0F0F
- r1 = 0xFEDCBA98

**Example (solved):**
```
EOR r3, r1, r0
r3 = 0xF1D3B597
```

**Answers:**

1. ORR r3, r1, r0
   - r3 = 0xFFDFBF9F

2. BIC r3, r1, r0
   - r3 = 0xF0D0B090

3. MVN r3, r0 / ADD r3, r1, r3
   - r3 = 0xEFCDAB88

---

## Question 3 (2/2 pts)

**Topic:** Assembly program for polynomial calculation

**Polynomial:** y = 3x³ - 7x² + 12x - 11

**Solution:**
```assembly
; r0 = x, r1 = y
; factor ((3x-7)x + 12)x -11

MOV r3, #3           ; r3 = 3
MUL r2, r0, r3       ; r2 = 3 * x
SUB r2, r2, #7       ; r2 = 3x - 7
MUL r2, r2, r0       ; r2 = (3x - 7) * x
ADD r2, r2, #12      ; r2 = (3x - 7)x + 12
MUL r2, r2, r0       ; r2 = ((3x - 7)x + 12) * x
SUB r1, r2, #11      ; r1 = ((3x - 7)x + 12)x - 11
```

---

## Question 4 (1/1 pts)

**Topic:** Bit manipulation in assembly

**Assumption:** LSB is odd bit (bit 0 is odd, bit 1 is even, etc.)

**Task 1: Set all odd bits to one, keep even bits unchanged**
```assembly
; LSB is odd bit: 0(odd), 1(even), 2(odd)...
; 0101 -> 0x5 -> load 0x5 across 32 bits

LDR r1, =0x55555555  ; load mask
ORR r0, r0, r1       ; enable odd bits and leave even
```

**Task 2: Toggle all odd bits, keep even bits unchanged**
```assembly
LDR r1, =0x55555555  ; load mask
EOR r0, r0, r1       ; toggle odd bits and leave even
```

---

## Question 5 (2/2 pts)

**Topic:** Using LSL for fast multiplication

**Example (solved):**
```
x = 31*x
Ans: x = 31x = 32x - x
RSB r0, r0, r0, LSL 5
```

**Answer 1: x = 38*x**
```assembly
; 38 = 32 + 4 + 2

LSL r1, r0, 5        ; r1 = 32x
ADD r1, r1, r0, LSL #2  ; r1 = 32x + 4x
ADD r0, r1, r0, LSL #1  ; r0 = 32x + 4x + 2x = 38x
```

**Answer 2: x = 17*x**
```assembly
; 17 = 16 + 1

ADD r0, r0, r0, LSL #4  ; r0 = x + 16x = 17x
```

---

**Total Score: 8/8 ✓**
