#include <stdio.h>
#include "stackclass.h"   //to declare Stack class

int main()
{  int i;  Stack s ;   //stack constructor function automatically called
   s.Push(1);  s.Push(2);  s.Push(3);   //s now contains 1, 2, 3
   while (!s.IsEmptyStack())  //loop pops 3, 2, 1 off s and prints them
   {  i = s.Pop();  printf("%d\n", i);
   }
   return 0;
   //stack destructor is called implicitly whenever stack goes out of scope
}
