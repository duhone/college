/*A queue q is implemented using a dynamically allocated array.
  q->arraySize is the size of this array. If the array size turns out
    to be too small then the array is reallocated with double the size. 
  q->front/q->rear  are the subscripts of the front/rear element.  
  q->size is the number of elements currently in the queue. 
  q->array is the dynamically allocated array.*/
#include <stdlib.h>
#include "queue.h"
#include "error.h"
#define INITIAL_ARRAY_SIZE 25

struct QueueInfo
{  int arraySize;  int front;  int rear;  int size;  QueueElementType *array;
};

Queue NewQueue(void)
{  Queue q = malloc(sizeof(struct QueueInfo));
   if (q == NULL) FatalError("Out of space!!! Cannot create new queue.");
   q->array = malloc(sizeof(QueueElementType)*INITIAL_ARRAY_SIZE);
   if (q->array == NULL) FatalError("Out of space!!! Cannot create new queue.");
   q->arraySize = INITIAL_ARRAY_SIZE;  q->front = 0;  q->rear = -1;  q->size = 0;
   return q;
}

QueueElementType Dequeue(Queue q)
{ QueueElementType x;
   if (q->size == 0) FatalError("Queue empty. Cannot pop element off queue.");
   q->size--;  x = q->array[q->front];  q->front = (q->front + 1) %  q->arraySize;
   return x;
}

void Enqueue(QueueElementType x, Queue q)
{  if (q->size == q->arraySize)
   {  QueueElementType *oldArray = q->array;  int j, k, oldArraySize = q->arraySize;
      q->arraySize *= 2; q->array = malloc(sizeof(QueueElementType)*q->arraySize);
      if (q->array == NULL) FatalError("Out of Space!!! Cannot push element on queue");
      j = q->front;
      for (k = 0; k < oldArraySize; k++)
      {  q->array[k] = oldArray[j];  j = (j + 1) % oldArraySize;
      }
      q->front = 0;  q->rear = k - 1;
      free(oldArray);
   }
   q->size++;  q->rear = (q->rear + 1) % q->arraySize;  q->array[q->rear] = x;
}

int IsEmptyQueue(Queue q)
{  return (q->size == 0);
}

void DeleteQueue(Queue q)
{  free(q->array);  free(q);
}
