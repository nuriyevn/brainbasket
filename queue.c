#include <stdlib.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>

#define QUEUE_MAX 3

struct Queue {
    int data [QUEUE_MAX];
    int size ; 
    int start;
    int end;
    
} ;
typedef struct Queue queue ;
void Queue_Init(queue *q);
void Queue_Add(queue *q, int value);
void Queue_Print(queue *q);
void Queue_Remove(queue *q);
bool Queue_Full(queue *q);
bool Queue_Empty(queue *q);
int main (void)
{
    char op;
    queue myqueue;
    Queue_Init(&myqueue);
    while((op = GetChar()))
    {
        switch (op)
        {
        case 'u' : 
            Queue_Add(&myqueue,GetInt());
            break;
        case 'o' :
            Queue_Remove(&myqueue);
            break;
        case 'p' :
            Queue_Print(&myqueue);
            break;
        }
           
    }
   
    
    
}


void Queue_Init(queue *q)
{
    q->size = 0 ;
    q->start = 0;
    q->end = -1;
}
void Queue_Add(queue *q, int value)
{
    
    if(!Queue_Full(q))
    {
        if(q->end == QUEUE_MAX - 1)
        {
           q->end = -1;
        } 
        q->end++;
        q->data[q->end] = value;
        q->size++;
        
        Queue_Print(q);
        
    }
    
    else 
    {
        printf("Queue is full");
    }

    
}
void Queue_Print(queue *q)
{
    int s = q->size;
    printf("size=%d ,start=%d, end =%d; ",q->size,q->start,q->end);
    for (int i = q->start; s ; s--)
    {
        printf("data = %d; ",q->data[i]);
        if(i == QUEUE_MAX-1)
        {
            i = 0;
        }
    
        else
        {
            i++;
        }
    }
}

void Queue_Remove (queue *q)
{
       
        if (!Queue_Empty(q))
        {
            if(q->start == QUEUE_MAX)
            {
                q->start=-1;
            }
            q->start++;
            q->size--;
            Queue_Print(q);
            
        }
        else
        {
            printf("Queue is empty\n");
        }
            
}

bool Queue_Empty(queue *q)
{
    return q->size == 0;
}
bool Queue_Full(queue *q)
{
    return q->size == QUEUE_MAX;
}

