#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#define RING_BUFFER_SIZE 16
typedef struct
{
    uint8_t data[RING_BUFFER_SIZE];
    volatile uint8_t head;
    volatile uint8_t tail;
}RingBuffer;
// I want to avoid dynamic allocaiton in embedded
// statically allocated
// global memory or BSS area

volatile RingBuffer myBuffer = {0};

void RingBuffpush(uint8_t byte)
{
    uint8_t nextPosition = (myBuffer.head + 1) % RING_BUFFER_SIZE;
    if(nextPosition == myBuffer.tail)
    {
        myBuffer.tail = (myBuffer.tail +1)% RING_BUFFER_SIZE;
    }
    myBuffer.data[myBuffer.head] = byte;
    myBuffer.head = nextPosition;
}

int RingBufferpop(uint8_t *byte)
{
    if(myBuffer.head == myBuffer.tail)
    {
        return 0;
    }
    *byte = myBuffer.data[myBuffer.tail];
    myBuffer.tail = (myBuffer.tail +1) % RING_BUFFER_SIZE;
    return 1;
}
int main(void)
{
    for(uint8_t x = 1; x < RING_BUFFER_SIZE + 5; x++)
    {
        RingBuffpush(x);
    }
    printf("myBuffer.head is %u\n",myBuffer.head);
    printf("sizeof myBuffer is : %x\n",sizeof(myBuffer));
    printf("Done !\n");
    
}
