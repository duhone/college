/*A polynomial p is implemented using a linked list with a header node.*/

#include <stdio.h>
#include <stdlib.h>
#include "poly.h"
#include "error.h"


typedef struct PolyNode *PtrToPolyNode;
struct PolyNode
{  float coef;  int exp;  PtrToPolyNode next;
};

/* NewPolyNode is a local function only used in this file - thus it is declared as staic*/
static PtrToPolyNode NewPolyNode(void)
{  PtrToPolyNode p = malloc(sizeof(struct PolyNode));
   if (p == NULL) FatalError("Out of space!!! Cannot create new polynomial");
   p->next = NULL;
   return p;
}

/* InsertTerm gets a new PolyNode, sets the coef, exp fields of this node to coef and exp*/
/* and then inserts it as the last  node in a list whose current last node is pointed to by last.*/
static void InsertTerm(float coef, int exp, PtrToPolyNode last)
  /*write the body of this function*/

Poly AddPoly(Poly p1, Poly p2)
{  float sum;
   Poly p3 = NewPolyNode(); /*Initialized so p3 starts with a header node*/
   PtrToPolyNode q1 = p1->next,  q2 = p2->next,  q3 = p3;
   while (q1 != NULL && q2 != NULL)
      if (q1->exp == q2->exp)
      {  sum = q1->coef + q2->coef;
         if (sum != 0)
         {   InsertTerm(sum, q1->exp, q3);  q3 = q3->next;
         }
         q1 = q1->next;  q2 = q2->next;
      }
      else if (q1->exp > q2->exp)
      {  InsertTerm(q1->coef, q1->exp, q3);  q3 = q3->next;  q1 = q1->next;
      }
      else
      {  InsertTerm(q2->coef, q2->exp, q3);  q3 = q3->next;  q2 = q2->next;
      }
   while (q1 != NULL)
   {  InsertTerm(q1->coef, q1->exp, q3);  q3 = q3->next;  q1 = q1->next;
   }
   while (q2 != NULL)
   {  InsertTerm(q2->coef, q2->exp, q3);  q3 = q3->next;  q2 = q2->next;
   }
   return p3;
}
