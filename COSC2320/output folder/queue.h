#ifndef _queue_h
#define _queue_h
typedef int QueueElementType;  /*this needs to be changed if elements 
                                 are not ints*/
typedef struct QueueInfo *Queue;
Queue NewQueue(void);
void Enqueue(QueueElementType x, Queue q);
QueueElementType Dequeue(Queue q);
int IsEmptyQueue(Queue q);
void DeleteQueue(Queue q);
#endif
