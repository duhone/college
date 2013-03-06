#ifndef _stackclass_h
#define _stackclass_h
typedef int StackElementType;  //change if elements are not ints or use templates
class Stack
{  public:
      Stack();    //constructor
      void Push(StackElementType x);
      StackElementType Pop();
      int IsEmptyStack();
      ~Stack();  //destructor
   private:
      int arraySize;  int top;  StackElementType *array;
};
#endif
