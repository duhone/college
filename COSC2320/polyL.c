/*A polynomial p is implemented using a linked list with a header node.*/
/*
  Name     Eric Duhon
  Social   453-97-8531
  cosc 2320 Data Structres


*/
#include <stdio.h>
#include <stdlib.h>
#include "d:\cosc2320\poly.h"
#include "d:\cosc2320\error.h"

typedef struct PolyNode *PtrToPolyNode;

struct PolyNode
{
 float coef;
 int exp;
 PtrToPolyNode next;
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
{
 PtrToPolyNode tempp = malloc(sizeof(struct PolyNode));
 if(tempp == NULL) FatalError("\nOut of memory");
 tempp->coef = coef;
 tempp->exp = exp;
 tempp->next = NULL;
 last->next = tempp;

}

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

/*Deallocates memory for a poly*/
void DeletePoly(Poly p)
 {
  PtrToPolyNode temp;
  PtrToPolyNode temp2;

  temp = p;
  temp2 = p;
  while(temp->next != NULL)
   {
    temp = temp2->next;
    free(temp2);
    temp2 = temp;
   }
 }

/*Read in a poly*/
Poly ReadPoly(void)
 {
  float coef;
  int exp;
  Poly p = NewPolyNode();
  PtrToPolyNode current;
  current = p;
  printf("\nEnter a new polynomial in decending order of exponents");
  printf("\nEnter the coefficient of the current term(enter 0.0 to quit)");
  scanf("%f",&coef);
  printf("\nEnter the exponent of the current term(enter 0 to quit)");
  scanf("%d",&exp);
  while(coef != 0.0 || exp != 0)
   {
    InsertTerm(coef,exp,current);
    current = current->next;
    printf("\nEnter the coefficient of the current term(enter 0.0 to quit)");
    scanf("%f",&coef);
    printf("\nEnter the exponent of the current term(enter 0 to quit)");
    scanf("%d",&exp);

   }
  return p;
 }

/*print out a poly*/
void PrintPoly(Poly p)
 {
  PtrToPolyNode temp;
  if(p->next != NULL)
   temp = p->next;
  else
   {
    printf("\n0.0");
    return;
   }
  printf("\n");
  while(temp != NULL)
   {
    if(temp->coef >= 0.0)
     {
      printf(" + %f",temp->coef);
     }
    else
     {
      printf(" - %f",(-temp->coef));
     }
    if(temp->exp > 0)
     {
      printf("X^%d",temp->exp);
     }
    temp = temp->next;
   }
 }

/*subtract poly 2 from poly 1*/
Poly SubPoly(Poly p1,Poly p2)
 {
  Poly result,temp;
  PtrToPolyNode tempc;
  temp = NewPolyNode();
  tempc = temp;
  while(p2->next != NULL)
   {
    p2 = p2->next;
    InsertTerm(-p2->coef,p2->exp,tempc);
    tempc = tempc->next;
   }
  result = AddPoly(temp,p1);
  DeletePoly(temp);
  return result;
 }

/*find the derivative of poly p*/
Poly DifPoly(Poly p)
 {
  Poly result;
  PtrToPolyNode temp;
  result = NewPolyNode();
  temp = result;
  while(p->next != NULL)
   {
    p = p->next;
    if(p->exp > 0)
     InsertTerm((p->coef*p->exp),(p->exp-1),temp);
    temp = temp->next;
   }
  return result;
 }

/*multiply poly p by singel term*/
static Poly submul(float coef,int exp,Poly p)
 {
  Poly answer;
  PtrToPolyNode temp;
  answer = NewPolyNode();
  temp = answer;
  while(p->next != NULL)
   {
    p = p->next;
    InsertTerm((coef*p->coef),(exp+p->exp),temp);
    temp = temp->next;
   }
  return answer;
 }

/*copy one poly to another*/
static Poly cpyply(Poly p2)
 {
  PtrToPolyNode temp;
  Poly result;
  result = NewPolyNode();
  temp = result;
  while(p2->next != NULL)
   {
    p2 = p2->next;
    InsertTerm(p2->coef,p2->exp,temp);
    temp = temp->next;
   }
  return result;
 }


/*multiply poly 1 and 2*/
Poly MulPoly(Poly p1,Poly p2)
 {
  Poly sum,result,temp;
  PtrToPolyNode tempc;
  result = NewPolyNode();

  while(p1->next != NULL)
   {
    p1 = p1->next;
    sum = NewPolyNode();
    temp = NewPolyNode();
    temp = submul(p1->coef,p1->exp,p2);
    sum = AddPoly(result,temp);
    DeletePoly(result);
    result = cpyply(sum);
    DeletePoly(sum);
    DeletePoly(temp);
   }
  return result;
 }

