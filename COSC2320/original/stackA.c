/*A stack s is implemented using a dynamically allocated array. s->arraySize 
is the size of this array. If the array size turns out to be too small then 
the array is reallocated with double the size. s->top is the subscript of 
the top element. s->array is the dynamically allocated array.*/

#include "stack.h"
#include "error.h"
#include <stdlib.h>
#define INITIAL_ARRAY_SIZE 25

struct StackInfo
{  int arraySize;  int top;  StackElementType *array;
};

Stack NewStack(void)
{  Stack s = malloc(sizeof(struct StackInfo));
   if (s == 0) FatalError("Out of space!!! Cannot create new stack.");
   s->array = malloc(INITIAL_ARRAY_SIZE*sizeof(StackElementType));
   if (s->array == NULL) FatalError("Out of space!!! Cannot create new stack.");
   s->arraySize = INITIAL_ARRAY_SIZE;  s->top = -1;
   return s;
}

void Push(StackElementType x, Stack s)
{  if (s->top == s->arraySize -1)
   {  StackElementType *oldArray = s->array;  int i, oldArraySize = s->arraySize;
      s->arraySize *= 2;  s->array = malloc(s->arraySize*sizeof(StackElementType));
      if (s->array == NULL) FatalError("Out of Space!!! Cannot push element on stack");
      for (i = 0; i < oldArraySize; i++)
         s->array[i] = oldArray[i];
      free(oldArray);
   }
   s->array[++s->top] = x;
}

StackElementType Pop(Stack s)
{  if (s->top == -1) FatalError("Stack empty. Cannot pop element off stack.");
   return (s->array[s->top--]);
}

int IsEmptyStack(Stack s)
{  return (s->top == -1);
}

void DeleteStack(Stack s)
{  free(s->array);  free(s);
}

