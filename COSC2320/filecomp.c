 /*implements a file compression table using minheapes and huffman
   trees
 */
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
#include <stdio.h>

FILE *fileopen(char* name,char *opt)
 {
  /*opens file name with acess options opt*/
  FILE *temp;
  if((temp = fopen(name,opt)) == NULL)
   {
    printf("\nFile could not be opened");
   }
  return temp;
 }

void main()
 {
  FILE * userfile;
  char filename[50];
  char input;
  int inputarray[128];
  int count;
  minheap heap;
  HuffTree temp,temp2,temp3;
  for(count = 0;count < 128;count++)
   {
    inputarray[count] = 0;
   }
  /*get file name and open it*/
  printf("\nEnter the name of the file to analyze ");
  gets(filename);
  userfile = fileopen(filename,"r");
  /*repeat until end of file to get words*/
  while((input = fgetc(userfile)) != EOF)
   {
    inputarray[input]++;
   }
  for(count = 0;count < 128;count++)
   {
    if(inputarray[count] > 0)
     {
      printf("%c  %d",count,inputarray[count]);
     }
   }
  printf("\n\n");
  heap = NewMinHeap();
  /*creat huffman trees for all the characters*/
  for(count = 0; count<128;count++)
   {
    if(inputarray[count] > 0)
     {
      temp = NewHuffTree(count,inputarray[count]);
      InsertMinHeap(temp,heap);
     }

   }
  printf("\n\n");
  /*create the final huffman tree*/
  while(SizeMinHeap(heap) > 1)
   {
    temp = DeleteMinHeap(heap);
    temp2 = DeleteMinHeap(heap);
    temp3 = JoinHuffTrees(temp,temp2);
    InsertMinHeap(temp3,heap);
   }
  /*output the huffman codes*/
  temp3 = DeleteMinHeap(heap);
  OutputHuffCodes(temp3);
  fclose(userfile);
 }