#include<stdint.h>
typedef struct{
    int16_t* pi16Array;
    int8_t i8Size;
    int8_t i8OccupiedElements;
    int8_t i8EmptySpace;
    int8_t i8Front;
    int8_t i8Rear;
} QUEUE_t;

QUEUE_t* createQueue(int8_t i8Size);
void EnqueueElements(QUEUE_t* pQueue,int16_t* pElements,int8_t i8InputSize);
int16_t* DequeueElements(QUEUE_t* pQueue,int8_t i8DequeueSize);
int8_t EmptySpace(QUEUE_t* pQueue);

