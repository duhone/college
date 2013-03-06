#ifndef _stack_h
#define _stack_h
typedef int StackElementType;  /*this needs to be changed if the stack elements are not ints*/
typedef struct StackInfo *Stack;
Stack NewStack(void);
void Push(StackElementType x, Stack s);
StackElementType Pop(Stack s);
int IsEmptyStack(Stack s);
void DeleteStack(Stack s);
#endif
