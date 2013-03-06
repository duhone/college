/*A stack s is implemented using a linked list. s->top points to the top node*/

#include "stack.h"
#include "error.h"
#include <stdlib.h>

typedef struct StackNode *PtrToStackNode;
struct StackNode
{  StackElementType element;  PtrToStackNode next;
};
struct StackInfo
{  PtrToStackNode top;
};

Stack NewStack(void)
{  Stack s = malloc(sizeof(struct StackInfo));
   if (s == NULL) FatalError("Out of space!!! Cannot create new stack.");
   s->top = NULL;
   return s;
}

void Push(StackElementType x, Stack s)
{  PtrToStackNode p = malloc(sizeof(struct StackNode));
   if (p == NULL) FatalError("Out of space!!! Cannot push element on stack.");
   p->element = x;  p->next = s->top;  s->top = p;
}

StackElementType Pop(Stack s)
{  StackElementType x;  PtrToStackNode p = s->top;
   if (p == NULL) FatalError("Stack empty. Cannot pop element off stack.");
   x = p->element;  s->top = p->next;  free(p);
   return x;
}

int IsEmptyStack(Stack s)
{  return (s->top == NULL);
}

void DeleteStack(Stack s)
{  PtrToStackNode p, q = s->top;
   while (q != NULL)
   {  p = q;  q = q->next;  free(p);
   }
   free(s);
}
