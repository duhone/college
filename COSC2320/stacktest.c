#include <stdio.h>
#include "stack.h"

int main()
{  int i;  Stack s = NewStack();  /*creates new empty stack s*/
   Push(1, s);  Push(2, s);  Push(3, s);  /*s now contains 1, 2, 3*/
   while (!IsEmptyStack(s))  /*loop pops 3, 2, 1 off s and prints them*/
   {  i = Pop(s);  printf("%d\n", i);
   }
   DeleteStack(s);  /*deletes dynamic storage for s*/
   return 0;
}
