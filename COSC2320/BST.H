#ifndef _bst_h
#define _bst_h
#include "qlist.h"
typedef struct BSTNode *PtrToBSTNode;
typedef struct BSTInfo *BST;
BST NewBST(void);
int FindBST(char *w, BST t, PtrToBSTNode *foundNodep);
void InsertBST(char *w, int lineNum, BST t, PtrToBSTNode foundNode);
void IncBSTNode(int lineNum, PtrToBSTNode foundNode);
void PrintBST(BST t);
int HeightBST (BST t);
int SizeBST(BST t);
Qlist LineqBSTNode(PtrToBSTNode foundNode);
#endif
