/*implements a binary search tree*/
/*
   name     Eric Duhon
   Social   453-97-8531
   Cosc 2320 Data Structures

*/

#include "bst.h"
#include "qlist.h"
#include "error.h"
#include <stdlib.h>
#include <string.h>

struct BSTNode
{  char *word;  Qlist lineq;  int count;  PtrToBSTNode left, right;
};
struct BSTInfo
{  PtrToBSTNode root;  int size;
};

static void PrintBSTRec(PtrToBSTNode p);   /*private function prototype*/

/******************************************************************************
The function NewBST creates a new empty binary search tree and returns it as
its value.
******************************************************************************/
BST NewBST(void)
{  BST t = malloc(sizeof(struct BSTInfo));
   if (t == NULL) FatalError("Out of space!!! Cannot create new binary search tree.");
   t->root = NULL;  t->size = 0;
   return t;
}
/******************************************************************************
The function FindBST searches for w in the binary search tree t and returns
1(TRUE) if found and 0(FALSE) if not found. It also sets the output parameter
*foundNodep as follows: If w is found then *foundNodep is set to point to
the node containing w. If not found then *foundNodep is set to point to the
node such that a node containg w could be inserted directly below *foundNodep.
If w is not found and the tree is empty then *foundNodep is set to NULL.
******************************************************************************/
int  FindBST(char *w, BST t, PtrToBSTNode *foundNodep)
{  PtrToBSTNode p = t->root, q = NULL;
   while (p != NULL)
   {  if (strcmp(w, p->word) == 0)
      {  *foundNodep = p;  return 1;
      }
      else if (strcmp(w, p->word) < 0)
      {  q = p;  p = p->left;
      }
      else
      {  q = p;  p = p->right;
      }
   }
   *foundNodep = q;  return 0;
}
/*****************************************************************************
The function InsertBST constructs a new node containing w. It gets a new Qlist
containing only lineNum and assigns it to the lineq field of the new node. It
sets the count field of the new node to 1. The left and right fields of new
node are set to NULL. It then inserts new node into the binary search tree t
immediately below the node pointed to by foundNode or if foundNode is NULL
it inserts the new node as the root node of the tree.
******************************************************************************/
void InsertBST(char *w, int lineNum, BST t, PtrToBSTNode foundNode)
{  PtrToBSTNode newNode = malloc(sizeof(struct BSTNode));
   if (newNode == NULL) FatalError("Out of space!!! Cannot insert in tree");
      /*Set the word, lineq, count, left, right fields of this node.*/
   newNode->word = w;
   newNode->lineq = newqlist(lineNum);
   newNode->count = 1;
   newNode->left = NULL;
   newNode->right = NULL;
   /*insert newNode as the root node of the tree if tree is empty*/
   if (foundNode == NULL)
      t->root = newNode;
   /*insert newNode to the left of node pointed to by foundNode*/
   else if (strcmp(w, foundNode->word) < 0)
      foundNode->left = newNode;
   /*insert newNode to the right of node pointed to by foundNode*/
   else
      foundNode->right = newNode;
   t->size++;
}
/****************************************************************************
The function IncBSTNode inserts the lineNum in the lineq and increments the
count field of the node pointed to by foundNode.
****************************************************************************/
void IncBSTNode(int lineNum, PtrToBSTNode foundNode)
 {
  foundNode->count++;
  insertqlist(lineNum,foundNode->lineq);
 }
/****************************************************************************
The function PrintBST outputs the word and count fields of the binary
search tree in alphabetical order of the words. This function works by
calling on a recursive version of the same function. The recursive version
needs a slightly different parameter.
****************************************************************************/
void PrintBST(BST t)
{  PrintBSTRec(t->root);
}
/****************************************************************************
The function PrintBSTRec is essentially an inorder traversal where each time
a node is visited we output the word and count field. It is only used
in this file and is not directly used by the client code. There is no
function prototype for it in bst.h. It is declared static to make it
private to this file.
****************************************************************************/
static void PrintBSTRec(PtrToBSTNode p)
 {
  if(p == NULL)
   /*do nothing*/;
  else
   {
    PrintBSTRec(p->left);
    printf("\n%-15s%5d",p->word,p->count);
    PrintBSTRec(p->right);
   }
 }
/****************************************************************************
The function HeightBST computes the height of the tree.
****************************************************************************/
int HeightBST(BST t)
 {
  return heightbstrec(t->root);
 }

/******************************************************************
Recursive function to compute the height of the tree
******************************************************************/
static int heightbstrec(PtrToBSTNode p)
 {
  int temp1,temp2;
  if(p == NULL) return -1;
  temp1 = heightbstrec(p->left);
  temp2 = heightbstrec(p->right);
  if(temp1 > temp2) return ++temp1;
  else return ++temp2;
 }
/****************************************************************************
The function SizeBST returns the size of the binary search tree.
****************************************************************************/
int SizeBST(BST t)
{  return t->size;
}
/****************************************************************************
The function LineqBSTNode returns the lineq field of the of the node
pointed to by foundNode. foundNode must not have the value NULL.
****************************************************************************/
Qlist LineqBSTNode(PtrToBSTNode foundNode)
{  return foundNode->lineq;
}

