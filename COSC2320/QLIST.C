/*implements a qlist fifo*/
/*
  Name     Eric Duhon
  Social   453-97-8531
  cosc 2320 Data Structres


*/

#include <stdio.h>
#include <stdlib.h>
#include "qlist.h"
#include "error.h"

typedef struct queitem *qitem;

struct queitem
 /*holds one element in the que*/
 {
  int n;
  qitem next;
 };

struct quelist
 /*holds the que*/
 {
  qitem front;
  qitem rear;
 };

Qlist newqlist(int n)
 /*creates a new que with one element n*/
 {
  Qlist temp;
  qitem temp2;
  temp = malloc(sizeof(struct quelist));
  temp2 = malloc(sizeof(struct queitem));
  temp2->n = n;
  temp2->next = NULL;
  temp->front = temp2;
  temp->rear = temp2;
  return temp;
 }

void insertqlist(int n,Qlist q)
 /*inserts a new element n into q*/
 {
  qitem temp;
  temp = malloc(sizeof(struct queitem));
  temp->n = n;
  temp->next = NULL;
  q->rear->next = temp;
  q->rear = temp;
 }

void outputqlist(Qlist q)
 /*outputs all elements in q from front to rear*/
 {
  qitem temp;
  int count = 0;
  temp = q->front;
  while(temp != NULL)
   {
    if(count == 12)
     {
      printf("\n");
      count = 0;
     }
    printf("%5d",temp->n);
    count++;
    temp = temp->next;
   }
 }