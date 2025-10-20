#include <stdio.h>
#include <stdbool.h>
#define SIZE 3
typedef struct {
    float *buffer;
    int head;
    int tail;
    int count;
    int capacity;
} RingBuffer;
bool isEmpty(RingBuffer *rb)
{
    if(rb->count == 0)
        return true;
    else
        return false;
}
void ring_buffer_init(RingBuffer *rb, float *data_array, int capacity)
{
    rb->buffer = data_array;
    rb->head = 0;
    rb->tail = 0;
    rb->count = 0;
    rb->capacity = 3;
    
}
void ring_buffer_write(RingBuffer *rb, float value)
{
    // if buffer coutn is less than SIZE
    if(rb->count < SIZE)
    {
        rb->buffer[rb->tail] = value;
        rb->tail = (rb->tail + 1) % SIZE;
        rb->count++;
    }
    // if buffer is full overwrite oldest value
    else if(rb->count == rb->capacity)
    {
        rb->buffer[rb->head] = value;
        rb->head = (rb->head + 1) % SIZE;
        rb->tail = (rb->tail + 1) % SIZE;
    }
}
int  ring_buffer_read(RingBuffer *rb, float *out_value)
{
    if(isEmpty(rb))
    {
        printf("Empty Ring Buffer\n");
        *out_value = 111;
        return 0xFF;
    }
    else{
        int temp = (int)rb->buffer[rb->head];
        rb->buffer[rb->head] = 0.0;
        rb->head = (rb->head + 1) % SIZE;
        rb->count--;
        return temp;
    }
}
int  ring_buffer_count(RingBuffer *rb)
{
    return rb->count;
}

int main(void)
{

    RingBuffer RB1;
    float error_code = 0.0;
    static float dataArr[3] = {0};
    ring_buffer_init(&RB1, dataArr, SIZE);
    ring_buffer_write(&RB1,33.99);
    ring_buffer_write(&RB1, 68.2);
    ring_buffer_write(&RB1, 11.2);
    ring_buffer_write(&RB1, 2.1);
    
    printf("this is the value read back: %d\n",ring_buffer_read(&RB1,&error_code));
    printf("This is the size: %d\n",ring_buffer_count(&RB1));
    return 0;
}
