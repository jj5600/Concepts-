#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
typedef struct{
    float *buffer;
    volatile uint8_t head;
    volatile uint8_t tail;
    float average;
    float runningSum;
    volatile uint8_t count;
    volatile uint8_t BUF_SIZE;
}RingBuffer;

RingBuffer* init_DynamicRingBuffer(uint8_t size)
{
    RingBuffer *ptr = malloc(sizeof(RingBuffer));
    if(ptr == NULL)
    {
        printf("Malloc Failed\n");
        return NULL;
    }
    ptr->buffer = malloc(sizeof(float) * size);
    if(ptr->buffer == NULL)
    {
        printf("Malloc failed\n");
        return NULL;
    }
    ptr->head = 0;
    ptr->tail = 0;
    ptr->average = 0.0;
    ptr->count = 0;
    ptr->runningSum = 0.0;
    ptr->BUF_SIZE = size;
    printf("Success\n");
    return ptr;
}

float pushToRing(RingBuffer *ptr,float value)
{
    uint8_t next = (ptr->head + 1) % ptr->BUF_SIZE;
   if(next == ptr->tail && ptr->count == ptr->BUF_SIZE)
    {
    // Buffer full - don't increment count
        ptr->runningSum -= ptr->buffer[ptr->tail];
        ptr->tail = (ptr->tail + 1) % ptr->BUF_SIZE;
    }
    else
    {
    ptr->count++;  // Only increment if not full
    }
    ptr->buffer[ptr->head] = value;
    ptr->runningSum +=value;
    ptr->average = (ptr->runningSum) / ptr->count;
    ptr->head = next;
    return ptr->average;
}

int main()
{
    RingBuffer *myRing = init_DynamicRingBuffer(3);
    printf("%f\n",pushToRing(myRing,1.0));
    printf("%f\n",pushToRing(myRing,5.0));
    printf("%f\n",pushToRing(myRing,0.0));
    
    printf("Hello World!");
    
    return 0;
}
