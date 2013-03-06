/*graphtop.c*/
/*inputs a set of vertices for a graph from a file.
  then sorts them and prints out the vertices in topological
  sorted order
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
#include <queue.h>
#include <graph.h>

void main()
 {
  char exitint;
  graph maingraph;
  maingraph = getgraph();
  printgraph(maingraph);
  printtopsortorder(maingraph);
  printf("\npress the enter key to quit");
  scanf("%c",&exitint);
 }