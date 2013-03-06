  /*implements huffman trees*/
/*
   name     Eric Duhon
   Social   453-97-8531
   Cosc 2320 Data Structures

*/

#include "hufftree.h"
#include "error.h"
#include <stdlib.h>
#include <string.h>


/********************
 Creates a new huffman tree with ch in its character field
 and freq in its frequency field. Function return the tree.
********************/
HuffTree  NewHuffTree(char ch,int freq)
 {
  HuffTree newtree;
  newtree = malloc(sizeof(struct hufftree));
  if(newtree == NULL) FatalError("Out of memory");
  newtree->ch = ch;
  newtree->freq = freq;
  newtree->left = NULL;
  newtree->right = NULL;
  return newtree;
 }

/**************
 Joins huffman trees t1 and t2 putting the character field to
 null and making the frequency field equal to the sum of the
 frequency fields of t1 and t2. the joined tree is returned.
**************/

HuffTree JoinHuffTrees(HuffTree t1,HuffTree t2)
 {
  HuffTree newtree;
  newtree = malloc(sizeof(struct hufftree));
  if(newtree == NULL) FatalError("out of memory");
  newtree->ch = NULL;
  newtree->freq = t1->freq + t2->freq;
  newtree->left = t1;
  newtree->right = t2;
  return newtree;
 }

/*****************
 function recursivly outputes the huffman codes idetified
 by hufftree t. the code is paseed from call to call in
 variable code and its length in len.
*****************/
void recoutput(HuffTree t,char *code,int len)
 {
  if(t->ch != NULL)
   {
    printf("\n");
    if(t->ch == '\n')
     {
      printf("nl  %s",code);

     }
     else if(t->ch == ' ')
      {
       printf("sp  %s",code);
      }
      else
       {
	printf("%c   %s",t->ch,code);
       }
    code[len-1] = NULL;
    len--;
   }
   else
    {
     code[len] = '0';
     code[len+1] = NULL;
     recoutput(t->left,code,len+1);
     code[len] = '1';
     code[len+1] = NULL;
     recoutput(t->right,code,len+1);
    }
 }

/**************
 sets up the call to the recursive output function.
**************/
void OutputHuffCodes(HuffTree t)
 {
  char code[128];
  int len;
  code[0] = NULL;
  len = 0;
  recoutput(t,code,len);
 }