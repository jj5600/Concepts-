🧠 Problem: Implement a Fixed-Size Ring Buffer
Background
You are implementing a data logging system for a drone that stores sensor readings (floating-point values). Because memory is limited, you must use a fixed-size circular buffer to store the most recent readings.
When the buffer becomes full, new writes must overwrite the oldest entries.

Requirements
Implement a ring buffer that supports the following operations:
Initialization


Takes a pointer to a statically allocated array and its capacity.


Initializes internal indices (head, tail, count).


Write Operation


Writes a new value into the buffer.


If the buffer is full, it overwrites the oldest element.


Updates internal pointers correctly.


Read Operation


Reads the oldest value and removes it from the buffer.


Returns an error code if the buffer is empty.


Utility


Function to return the current number of elements stored in the buffer.



Function Prototypes
typedef struct {
    float *buffer;
    int head;
    int tail;
    int count;
    int capacity;
} RingBuffer;

void ring_buffer_init(RingBuffer *rb, float *data_array, int capacity);
void ring_buffer_write(RingBuffer *rb, float value);
int  ring_buffer_read(RingBuffer *rb, float *out_value);
int  ring_buffer_count(RingBuffer *rb);


Behavior Example
Assume capacity = 3:
Operation
Buffer (head→tail)
Output
Count
write(1.0)
[1]
-
1
write(2.0)
[1,2]
-
2
write(3.0)
[1,2,3]
-
3
write(4.0)
[4,2,3] (overwrites oldest)
-
3
read()
returns 2.0
2.0
2
write(5.0)
[4,5,3]
-
3
read()
returns 3.0
3.0
2


Constraints
Capacity is fixed and known at initialization.

No dynamic memory allocation (malloc or free not allowed).

All functions must run in O(1) time.

Maximum capacity = 256.



Input/Output format (for HackerRank testing)
You’ll be given commands as input:
INIT 3
WRITE 1.0
WRITE 2.0
WRITE 3.0
WRITE 4.0
READ
WRITE 5.0
READ
COUNT

Expected output:
2.00
3.00
2

Scoring
Correct ring buffer logic: 40%
Overwrite on full buffer: 20%
Proper wraparound behavior: 20%
Accurate count tracking and error handling: 20%

Notes
This problem tests stateful logic, pointer arithmetic, and buffer wraparound, which are common in embedded firmware systems.


Your solution must compile cleanly in C99 without external libraries.



