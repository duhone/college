  /*implements a minimum heap*/
/*
   name     Eric Duhon
   Social   453-97-8531
   Cosc 2320 Data Structures

*/

#include "hufftree.h"
#include "minheap.h"
#include "error.h"
#include <stdlib.h>
#include <string.h>


struct minheap
 {
  HuffTree heap[128];
  int size;
 };

/***********
 compares hufftree t1 and t2 and returns -1,0,1 if
 the freq field of t1 is less than, equal to, or
 greater than t2 respectivly.
***********/
int cmp(HuffTree t1, HuffTree t2)
 {
  int result;
  if(t1->freq < t2->freq) result = -1;
  if(t1->freq == t2->freq) result = 0;
  if(t1->freq > t2->freq) result = 1;
  return result;
 }

/***********
 creates a new minheap of size 128
***********/
minheap NewMinHeap()
 {
  minheap newheap;
  int a;
  newheap = malloc(sizeof(struct minheap));
  if(newheap == NULL) FatalError("out of memory");
  newheap->size = 0;
  for(a=0;a<128;a++)
   newheap->heap[a] = NULL;
  return newheap;
 }

/*********
 returns the size of the minheap
*********/
int SizeMinHeap(minheap heap)
 {
  return heap->size;
 }

/*************
 function returns and deletes the smallest value from
 the min heap, and then rearanges the heap to keep it
 a min heap.
*************/
HuffTree DeleteMinHeap(minheap mheap)
 {
  HuffTree deletedtree;
  HuffTree temp;
  int parent,child;
  deletedtree = mheap->heap[1];
  temp = mheap->heap[mheap->size];
  mheap->size--;
  parent = 1;
  child = 1;
  while(child <= ((mheap->size)/2))
   {
    child *= 2;
    if((child != mheap->size)&&(cmp(mheap->heap[child],mheap->heap[child+1]) > 0))
     {
      child++;
     }
    if(cmp(temp,mheap->heap[child]) > 0)
     {
      mheap->heap[parent] = mheap->heap[child];
     }
     else break;
    parent = child;
   }
  mheap->heap[parent] = temp;
  return deletedtree;
 }


/************
 inserts the hufftree tree into the minheap mheap
************/
void InsertMinHeap(HuffTree tree,minheap mheap)
 {
  int parent;
  int child;
  mheap->size++;
  parent = mheap->size;
  child = parent;
  while(child > 1)
   {
    parent /= 2;
    if(cmp(tree,mheap->heap[parent]) < 0)
     {
      mheap->heap[child] = mheap->heap[parent];
     }
     else break;
    child = parent;
   }
  mheap->heap[child] = tree;
 }

