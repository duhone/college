#include <stdio.h>
#include "queue.h"   /*to declare Queue type and prototypes for queue operations*/

int main()
{  int i;  Queue q = NewQueue();   /*q has been created as a new empty queue*/
   Enqueue(1, q);  Enqueue(2, q);  Enqueue(3, q);  /*q  now contains 1, 2, 3*/
   while (!IsEmptyQueue(q)) 
   {  i = Dequeue(q);  printf("%d\n", i);   /*prints 1, 2, 3*/
   }
   DeleteQueue(q);   /*deletes all dynamic storage used for the queue*/
   return 0;
}
