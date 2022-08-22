#include "queue.h"
#include<stdlib.h>
#include<stdio.h>

QUEUE_t* createQueue(int8_t i8Size){
    QUEUE_t* pInstance=(QUEUE_t *)malloc(sizeof(QUEUE_t));
    pInstance->i8Size=i8Size;
    pInstance->i8EmptySpace=i8Size;
    pInstance->i8OccupiedElements=0;
    pInstance->i8Front=-1;
    pInstance->i8Rear=-1;
    pInstance->pi16Array=(int16_t *)malloc(sizeof(int16_t)*i8Size);
    for(int8_t i=0;i<i8Size;i++){
        pInstance->pi16Array[i]=INT16_MIN;
    }
    return pInstance;
}

void EnqueueElements(QUEUE_t* pQueue,int16_t* pElements,int8_t i8InputSize)
{
    if(pQueue->i8EmptySpace<i8InputSize)
    {
        printf("Insufficient space in array");
        return;
    }
    int8_t i=0;
    while(i<i8InputSize)
    {
        if(pQueue->i8Front==-1)
        {
            pQueue->i8Front=0;
            pQueue->i8Rear=0;
            pQueue->pi16Array[pQueue->i8Rear]=pElements[i];
        }
        else if(pQueue->i8Rear==pQueue->i8Size-1&&pQueue->i8Front!=0)
        {
            pQueue->i8Rear=0;
            pQueue->pi16Array[pQueue->i8Rear]=pElements[i];
        }
        else
        {
            pQueue->i8Rear=pQueue->i8Rear+1;
            pQueue->pi16Array[pQueue->i8Rear]=pElements[i];
        }
        pQueue->i8OccupiedElements=pQueue->i8OccupiedElements+1;
        pQueue->i8EmptySpace=pQueue->i8EmptySpace-1;
        i++;
    }
    printf("Enqueue success!");
}

int16_t* DequeueElements(QUEUE_t* pQueue,int8_t i8DequeueSize)
{
    if(i8DequeueSize>pQueue->i8OccupiedElements)
    {
        printf("Not enough elements in queue");
        int16_t* pInsufficientElements=(int16_t *)malloc(sizeof(int16_t)*1);
        pInsufficientElements[0]=INT16_MIN;
        return pInsufficientElements;
    }
    int16_t* pRemovedElements=(int16_t *)malloc(sizeof(int16_t)*i8DequeueSize);
    int8_t i=0;
    while(i8DequeueSize--)
    {
        pRemovedElements[i]=pQueue->pi16Array[pQueue->i8Front];
        pQueue->pi16Array[pQueue->i8Front]=INT16_MIN;
        pQueue->i8OccupiedElements=pQueue->i8OccupiedElements-1;
        pQueue->i8EmptySpace=pQueue->i8EmptySpace+1;
        if(pQueue->i8Front==pQueue->i8Size-1)
        {
            pQueue->i8Front=0;
        }
        else
        {
            pQueue->i8Front=pQueue->i8Front+1;
        }
        i++;
    }
    return pRemovedElements;
}

int8_t EmptySpace(QUEUE_t* pQueue)
{
    return pQueue->i8EmptySpace;
}
