#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#define SIZE 3
typedef struct{
    
    float buff[SIZE];
   volatile uint8_t head;
   volatile uint8_t tail;
    uint8_t count;
    float SUM;
    float avg;
}RingBuffer;


RingBuffer myRing = {0};


float PushandAverage(float value)
{  
    if(myRing.count == SIZE)
    {
        //buffer is full begin overwrite
        myRing.SUM -=myRing.buff[myRing.tail];
        myRing.tail = (myRing.tail + 1) % SIZE;
        
    }
    myRing.SUM +=  value;
    if(myRing.count != SIZE)
    {
       myRing.count++; 
    }
    myRing.buff[myRing.head] = value;
    myRing.head = (myRing.head + 1) % SIZE;
    
    return (myRing.SUM / myRing.count);
}
int main(void)
{
    
    
    printf("%f this is the RingBuffers avg rn\n",myRing.avg);
    printf("average is :%f\n",PushandAverage(1.0));
    printf("average is %f\n",PushandAverage(2.0));
    printf("average is %f\n",PushandAverage(3.0));
    printf("average is %f\n",PushandAverage(4.0));
    printf("average is %f\n",PushandAverage(5.0));
    //PushandAverage(6.0);
    for(int x= 0; x<3; x++)
    {
        printf("[%f]",myRing.buff[x]);
    }

    
    
}


