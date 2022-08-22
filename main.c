#include<stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include "queue.h"

void main()
{
    int8_t i8QueueSize;
    printf("====== CIRCULAR QUEUE ======\n");
    printf("Enter circular queue size: ");
    scanf("%" SCNd8,&i8QueueSize);
    QUEUE_t* pQueue=createQueue(i8QueueSize);
    printf("===> Creating circular queue of size %" PRId8,i8QueueSize);
    while(1)
    {
        printf("\n(1) Enqueue n elements\n");
        printf("(2) Dequeue n elements\n");
        printf("(3) See available space\n");
        int iUserChoice;
        scanf("%d",&iUserChoice);
        if(iUserChoice==1)
        {
            int8_t i8EnqueueSize;
            printf("Enter enqueue buffer size: ");
            scanf("%" SCNd8,&i8EnqueueSize);
            int16_t pElements[i8EnqueueSize];
            printf("Enter enqueue elements: \n");
            for(uint8_t i=0;i<i8EnqueueSize;i++){
                scanf("%" SCNd16,&pElements[i]);
            }
            EnqueueElements(pQueue,pElements,i8EnqueueSize);
        }
        if(iUserChoice==2)
        {
            int8_t i8DequeSize;
            printf("Enter dequeue size: ");
            scanf("%" SCNd8,&i8DequeSize);
            int16_t* pRemovedElements=DequeueElements(pQueue,i8DequeSize);
            if(pRemovedElements[0]!=INT16_MIN)
            {
                for(uint8_t i=0;i<i8DequeSize;i++){
                    printf("%" PRId16,pRemovedElements[i]);
                    printf(" ");
                }
                printf("\n");
            }
        }
        if(iUserChoice==3)
        {
            printf("The empty space in queue is: %" PRId8,pQueue->i8EmptySpace);
        }
    }
}