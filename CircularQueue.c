#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 5

// define a type struct with appropriate elements
typedef struct{
    
    int *value;
    int front;
    int back;
    int available_slots;
} Ring;
//dynamically allocate array in Ring and return pointer to that struct
Ring * CreateRing(Ring *rptr)
{
    rptr->value = malloc(sizeof(int) * SIZE);
    if(rptr->value == NULL)
    {
        printf("malloc failure");
        return 0;
    }
    rptr->available_slots = SIZE;
    rptr->front = 0;
    rptr->back = 0;
    printf("SUCCESS creating Ring\n");
    return rptr;
    
}
// free array dynamically allocated by ring
void destroyRing(Ring * rptr)
{
    free(rptr->value);
}
// print the current status (values) of elements in the Ring Struct
void printRingStatus(Ring *rptr)
{
    printf("STATUS ************************\n");
    printf("Available Slots : %d\n",rptr->available_slots);
    printf("Front is : %d\n",rptr->front);
    printf("Back is : %d\n",rptr->back);
    printf("END OF STATUS ***********************\n");
}
// check is the Ring is empty
bool isEmpty(Ring * rptr)
{
    return((rptr->available_slots) == SIZE ? true : false);
}
//check if the Ring is full
bool isFull(Ring * rptr)
{
    return((rptr->available_slots) == 0 ? true : false);
}

void enqueue(Ring * rptr, int value)
{
    if(rptr->available_slots != 0 )
    {
        rptr->value[rptr->back] = value;
        rptr->available_slots--;
        rptr->back = (rptr->back + 1 ) % (SIZE) ;
        printf("rptr->back is : %d ",rptr->back);
        printf("rptr->available slots are: %d\n",rptr->available_slots);
    }
    else
    {
        
        printf("QUEUE IS FULL\n");
        return;
    }
}

int dequeue(Ring *rptr)
{
    int temp;
    if(isEmpty(rptr))
    {
        printf("** ERROR QUEUE is empty");
        return 99;
    }
    temp = rptr->value[rptr->front];
    rptr->available_slots++;
    rptr->front = (rptr->front +1 ) % SIZE; // %SIZE is used to ensure the rptr->front ptr doesnt "walk off" the array
    printf("rptr->front is : %d ",rptr->back);
    printf("rptr->available slots are: %d\n",rptr->available_slots);
    return temp;
}
int main(void)
{
    Ring ring;
    Ring *rptr = &ring;
    rptr = CreateRing(rptr);
    printRingStatus(rptr);
    enqueue(rptr,0);
    enqueue(rptr,1);
    enqueue(rptr,2);
    enqueue(rptr,3);
    enqueue(rptr,4);
    
    printf("Dequeued value: %d\n",dequeue(rptr));
    printf("Dequeued value: %d\n",dequeue(rptr));
    printf("Dequeued value: %d\n",dequeue(rptr));
    printf("Dequeued value: %d\n",dequeue(rptr));
    printf("Dequeued value: %d\n",dequeue(rptr));
    enqueue(rptr,56);
    printf("Dequeued value: %d\n",dequeue(rptr));
    
    destroyRing(rptr);
    return 0;
}
