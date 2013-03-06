#include "stackclass.h"
#include "error.h"

const int INITIAL_ARRAY_SIZE = 25;

Stack::Stack()
{  array = new StackElementType[INITIAL_ARRAY_SIZE];
   if (array == 0) FatalError("Out of space!!! Cannot create new array");
   arraySize = INITIAL_ARRAY_SIZE;  top = -1;
}

void Stack::Push(StackElementType x)
{  if (top == arraySize -1)
   {  StackElementType *oldArray = array;  int i, oldArraySize = arraySize;
      arraySize *= 2;  array = new StackElementType[arraySize];
      if (array == 0) FatalError("Out of Space!!! Cannot push element on stack");
      for (i = 0; i < oldArraySize; i++)
         array[i] = oldArray[i];
      delete [ ] oldArray;
   }
   array[++top] = x;
}

StackElementType Stack::Pop()
{  if (top == -1) FatalError("Stack empty. Cannot pop element off stack.");
   return (array[top--]);
}

int Stack::IsEmptyStack()
{  return (top == -1);
}

Stack::~Stack()
{  delete [ ] array;
}
