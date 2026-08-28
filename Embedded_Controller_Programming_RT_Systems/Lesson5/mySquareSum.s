.syntax unified
.cpu cortex-m4
.thumb

.global mySquareSum
.type mySquareSum, %function


mySquareSum:

	MOVS r2 , #0 //; this will hold the squared instance
	MOVS r3, #0 //; this will hold the added result

	loop:
		cmp r0, #0  // ; compare if value is equal to 0
		BEQ stop    //; if it is add 1 and return final
		MUL r2, r0, r0 //; square and store in r2
		SUBS r0, r0, #1 // ; decrement input value
		ADDS r3, r3, r2 // ; add to existing count
	B loop

	stop:
		MOVS r0, r3// ; move r3 to output r1
		bx lr
