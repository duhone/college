/*graph.c*/
/*
  implements the functions necessary to input the vertices of a graph
  (getgraph), print out the graph vertices(printgraph), and do a topological
  sort on the graph and print out the result(printtopsprtorder)
*/
/*
  Name        Eric Duhon
  Social      453-97-8531
  cosc 2320 Data Structures
*/



#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "queue.h"
#include "error.h"
#include "graph.h"

struct edge
 {
  int vertex;
  ptrtoedge next;
 };

struct graph
 {
   int numvertices;
   ptrtoedge *array;
 };

FILE *fileopen(char* name,char*opt)
 {
  /*opens file name with access options opt*/
  FILE *temp;
  if((temp = fopen(name,opt)) == NULL)
   {
    FatalError("\nFile could not be opened");
   }
  return temp;
 }

graph getgraph(void)
 {
  /*inputs a set of vertices from a file specified by the user.
    the vertices are put into a graph structure and returned
  */
  FILE *userfile;
  graph tempgraph;
  ptrtoedge tempedge,tempedge2;
  int tempint,tempint2,count;
  char filename[50];
  /*open the file*/
  printf("\nEnter the name of the file to analyze ");
  gets(filename);
  userfile = fileopen(filename,"r");
  tempgraph = malloc(sizeof(struct graph));
  if(tempgraph == NULL)
   FatalError("out of memory");
  /*input the number of vertices*/
  fscanf(userfile,"%d",&tempint);
  tempgraph->numvertices = tempint;
  /*initialize the array of vertices*/
  tempgraph->array = malloc(sizeof(ptrtoedge) * tempint);
  if(tempgraph->array == NULL)
   FatalError("out of memory");
  for(count = 0;count < tempint;count++)
   {
    tempgraph->array[count] = NULL;
  }
  /*input the vertices from the file*/
  while(fscanf(userfile," %d",&tempint) != EOF)
   {
    fscanf(userfile," %d",&tempint2);
    tempedge = malloc(sizeof(struct edge));
    if(tempedge == NULL)
     FatalError("\nout of memory");
    tempedge->next = NULL;
    tempedge->vertex = tempint2;
    tempedge2 = tempgraph->array[tempint];
    if(tempedge2 == NULL)
     {
      tempgraph->array[tempint] = tempedge;
     }
    else
     {
     while(tempedge2->next != NULL)
      {
       tempedge2 = tempedge2->next;
      }
     tempedge2->next = tempedge;
     }
   }

  fclose(userfile);
  return tempgraph;

 }

void printgraph(graph g)
 {
  int count;
  ptrtoedge tempedge;
  /*print the number of vertices to the screen*/
  printf("\n%d",g->numvertices);
  /*print the vertices*/
  for(count = 0;count<g->numvertices;count++)
   {
    tempedge = g->array[count];
    while(tempedge != NULL)
     {
      printf("\n%d %d",count,tempedge->vertex);
      tempedge = tempedge->next;

     }
   }
 }

void printtopsortorder(graph g)
 {
  Queue q;
  ptrtoedge tempedge;
  int *degree;
  int count,count2,tempint;
  q = NewQueue();
  printf("\n");
  /*set up the degree array*/
  degree = malloc(sizeof(int)*g->numvertices);
  if(degree == NULL)
   FatalError("\nout of memory");
  for(count=0;count<g->numvertices;count++)
   degree[count] = 0;
  for(count = 0;count<g->numvertices;count++)
   {
    tempedge = g->array[count];
    while(tempedge != NULL)
     {
      degree[tempedge->vertex]++;
      tempedge = tempedge->next;
     }
   }
  /*sort and print out the sorted vertices*/
  count2 = g->numvertices;
  while(count2 != 0)
  {
  /*get vertices to print out this time around*/
  for(count=0;count<g->numvertices;count++)
   {
    if(degree[count] == 0)
     {
      Enqueue(count,q);
     }
   }
  /*in case of a cycle exit wiht error*/
  if(IsEmptyQueue(q))
   FatalError("There is a cycle involving the remaining vertices.");
  /*adjust degree for the removed vertices and print out the vertex*/
  while(!IsEmptyQueue(q))
   {
    count2--;
    tempint = Dequeue(q);
    printf("%d ",tempint);
    degree[tempint] = -1;
    tempedge = g->array[tempint];
    while(tempedge != NULL)
     {
      degree[tempedge->vertex] -= 1;
      tempedge = tempedge->next;
     }

   }

  }
  DeleteQueue(q);
 }

