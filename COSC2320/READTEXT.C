/*readtext.c*/
/*reads in a text file counts the accourences of the words in the file, and then
  allows the user to search for particular words and outputs the number of occurences
  for that particular word*/
/*
  Name     Eric Duhon
  Social   453-97-8531

  cosc 2320 Data Structres


*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include "qlist.h"
#include "error.h"
#include "bst.h"

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

  BST tree;
  PtrToBSTNode foundnode;
  FILE * userfile;
  char filename[50];
  char word[50];
  char *wordp;
  char outertemp,innertemp,count;
  int linenum = 1;
  int size,height,iheight;
  /*get file name and open it*/
  printf("\nEnter the name of the file to analyze ");
  gets(filename);
  userfile = fileopen(filename,"r");
  tree = NewBST();
  /*repeat until end of file to get words*/
  while((outertemp = fgetc(userfile)) != EOF)
   {
    /*if character is a letter start new word*/
    if(isalpha(outertemp))
     {
      count = 1;
      word[count-1] = tolower(outertemp);
      /*get rest of word*/
      while(isalnum(innertemp = fgetc(userfile)))
       {
	count++;
	word[count-1] = tolower(innertemp);
       }
      count++;
      word[count-1] = 0;
      /*find current entry of word in tree or find were
	to insert new entry*/
      if(FindBST(word,tree,&foundnode))
       {
	/*update old entry in tree*/
	IncBSTNode(linenum,foundnode);
       }
       else
	{
	 /*enter a new entry in tree*/
	 wordp = malloc(strlen(word)+1);
	 strcpy(wordp,word);
	 InsertBST(wordp,linenum,tree,foundnode);
	}
      if(innertemp == '\n') linenum++;
     }
    if(outertemp == '\n') linenum++;
   }
  PrintBST(tree);
  /*look up words and output there  lists*/
  printf("\nAt each prompt enter a word or # to quit.");
  printf("\nEnter a word: ");
  gets(word);
  while(word[0] != '#')
   {
    printf("\n");
    if(FindBST(word,tree,&foundnode))
     {
      outputqlist(LineqBSTNode(foundnode));
     }
     else
      {
       printf("This word does not occur in the file");
      }
    printf("\nEnter a word: ");
    gets(word);
   }
  /*compare this tree to ideal situation*/
  size = SizeBST(tree);
  height = HeightBST(tree);
  iheight = floor(log(size)/log(2));
  printf("\nThe size of the tree is %d",size);
  printf("\nThe height of the tree is %d",height);
  printf("\nThe height of a perfectly balanced tree would be %d",iheight);
  printf("\nThe ratio between the actual height to the ideal height is %f",((float)height/(float)iheight));

  fclose(userfile);
 }