/*wordhash.c*/

/*reads in a text file, counts the accourences of the words in the file, and then
  sorts the words according to how many times they accur in the file, then finaly
  outputs the words in sorted order*/
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
#include "d:\cosc2320\error.h"

long int numbcomp;

typedef struct Node *PtrToNode;
struct Node { char *word; int count; PtrToNode next; };
typedef struct HTInfo *HT;
struct HTInfo
{ long int arraySize; /*current array size. if re-hashing occurs this will change*/
  long int num;       /*number of words (nodes in linked lists) in table*/
  PtrToNode *array;   /*dynamically allocated array of pointers that point to linked
			lists containing the words/counts*/
};

long int hash(char s[], long int arraySize);

/*************************************************************************************************
The function NextPrime returns the smallest prime number greater than or equal to n form the
following list of primes: 31, 61, 127, 251,  509, 1021, 2039, 4093, 8191, 16381, 32749, 65521,
131071, 262139, 524287, 1048573. These are the largest primes less than 2**n for 5 <= n <= 20.
*************************************************************************************************/
long int NextPrime(long int n)
 {
  long int number;
  int isprime = 0,a;
  number = n-1;
  if(number < 31) number = 31;
  while(!isprime)
   {
    number++;
    if(number >= 1048573)
     {
      number = 1048573;
      break;
     }
    /*test if prime*/
    for(a=number-1;a>=2;a--)
     {
      if((number % a) == 0)
       {
	isprime = 1;
       }
     }
   }
  return number;
 }



/*************************************************************************************************
The function NewHT creates a new empty hash table of given size and returns it.
*************************************************************************************************/
HT NewHT(long int size)
{  long int i; HT ht = malloc(sizeof(struct HTInfo));
   if (ht == NULL) FatalError("Out of storage!!! Cannot create new hash table");
   ht->arraySize = NextPrime(size);
   ht->array = malloc(ht->arraySize * sizeof(PtrToNode));
   if (ht->array == NULL) FatalError("Out of storage!!! Cannot create hash table array");
   for (i = 0; i < ht->arraySize; i++)
      ht->array[i] = NULL;
   ht->num = 0;
   return ht;
}

/*************************************************************************************************
The function FindHT finds the node containing w and returns a pointer to it or NULL if not found.
*************************************************************************************************/
PtrToNode FindHT(char *w, HT ht,int *numprob)
 {
  long int position;
  PtrToNode node;
  position = hash(w,ht->arraySize);
  node = ht->array[position];
  (*numprob)++;
  while((strcmp(w,node->word)!=0) && (node != NULL))
   {
    (*numprob)++;
    node = node->next;
   }
  return node;
}
/*************************************************************************************************
The function InsertHT inserts a node containing w and count 0 in the front of the correct list.
If (ht->num > 2*ht->arraySize) then it re-hashes by allocating an array of size the next largest
prime as determined by NextPrime and re-inserting each node into the correct list for the larger
array and freeing the old array. This function assumes that FindHT has already determined that w
is not in the hash table.
*************************************************************************************************/
void InsertHT(char *w, HT ht)
 {
  PtrToNode node,newnode,tempnode;
  long int position,a;
  long int newsize;
  PtrToNode *newarray,*temparray;
  position = hash(w,ht->arraySize);
  node = malloc(sizeof(struct Node));
  if(node == NULL) FatalError("Out of storage!!!");
  node->word = w;
  node->count = 1;
  node->next = ht->array[position];
  ht->array[position] = node;
  ht->num++;
  if(ht->num > 2*ht->arraySize)
   {
    newsize = NextPrime(ht->arraySize+1);
    newarray = malloc(sizeof(struct Node) * newsize);
    for(a=0;a<ht->arraySize;a++)
     {
      node = ht->array[a];
      while(node != NULL)
       {
	position = hash(node->word,newsize);
	newnode = malloc(sizeof(struct Node));
	if(newnode == NULL) FatalError("Out of storage!!!");
	newnode->word = node->word;
	newnode->count = node->count;
	newnode->next = newarray[position];
	newarray[position] = newnode;
	tempnode = node;
	node = node->next;
	free(tempnode);
       }
     }
    temparray = ht->array;
    ht->array = newarray;
    free(temparray);
   }
 }
/*************************************************************************************************
The function hash computes an integer between 0 and tableSize - 1. It does this by adding together
all the integer character codes in s, left shifting each sum by 2 bits so that the order of
characters matters, and then getting the remainder when divided by arraySize. s[0] is added in
last to assure that the last and first character codes are not left shifted out of the sum since
these characters are often the most important in distinguishing 2 similar strings.
*************************************************************************************************/
long int hash(char s[], long int arraySize)
{  int i; unsigned long int sum = 0;
   if (s[0] == '\0') return 0;
   for (i = 1; s[i] != '\0'; i++)
      sum = (sum + s[i]) << 2;
   sum = sum + s[0];
   return sum % arraySize;
}

/*************************************************************************************************
 The function cmp compares node p to q. count feilds are comaperd first, and if they are equal
 thye words are compared. function returns -1,0,1 if p is less than,euqal to, or greater than q
 respectivly.
*************************************************************************************************/
int cmp(PtrToNode p,PtrToNode q)
 {
  int returnv;
  if(p->count > q->count)
   {
    returnv = 1;
   }
   else
    {
     returnv = -1;
    }
  if(p->count == q->count)
   {
    returnv = -strcmp(p->word,q->word);
   }
  return returnv;
 }

/*************************************************************************************************
 The function partition splits the array a into two parts. the left side is
 all less than the original middle value while the right side is all greater.
 function returns the pivot point of the array of the array.
*************************************************************************************************/
int Partition(PtrToNode a[], int left, int right)
{  int i, j, mid;
   PtrToNode pivot, hold; /*these should be the type of the array*/
   mid = (left + right)/2;  pivot = a[mid];
   hold = a[mid];  a[mid] = a[right];  a[right] = hold;
   i = left;  j = right - 1;
   for ( ; ; )
   {  numbcomp++;
      while (cmp(a[i],pivot) > 0)
       {
	 i++;
	 numbcomp++;
       }
      numbcomp++;
      while ((i < j) && (cmp(a[j],pivot) < 0))
	{
	 j--;
	 numbcomp++;
	}
      if (i < j)
      {  hold = a[i];  a[i] = a[j];  a[j] = hold;
	 i++;  j--;
      }
      else
	 break;
   }
   hold = a[i];  a[i] = a[right];  a[right] = hold;
   return i;
}

/*************************************************************************************************
 The function qsort sorts part of the array a inside the left and right points.
 Qsort does this by using partition tto split the array and then calling on itself
 to sort the two smaller arrays.
*************************************************************************************************/

void Qsort(PtrToNode a[], int left, int right)
{  int i;
   if (left >= right)
      ;/*do nothing*/
   else
   {  i = Partition(a, left, right);
      Qsort(a, left, i - 1);
      Qsort(a, i + 1, right);
   }
}


/*************************************************************************************************
The function QuickSort sorts the pointers in the array so that they point to nodes in the order
of descending counts. For nodes with counts that are equal the nodes are in descending
alphabetical order of the words. The function works by calling on Qsort which is recursive.
*************************************************************************************************/
void QuickSort(PtrToNode a[ ], int n)
{
 Qsort(a, 0, n-1);
}

/*************************************************************************************************
 The function fileopen opens the file name with read options opt.
 The function returns a file pointer to the opened file.
*************************************************************************************************/
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

/*************************************************************************************************
 The function movehash moves pointers of all the nodes in the hast table to
 an array.
*************************************************************************************************/
void movhash(HT ht,PtrToNode array[])
 {
  long int a;
  long int b=0;
  PtrToNode temp;
  for(a=0;a<ht->arraySize;a++)
   {
    temp = ht->array[a];
    while(temp != NULL)
     {
      array[b] = temp;
      temp = temp->next;
      b++;
     }
   }
 }

/*************************************************************************************************
 The function printarray prints out all the words and counts int the array
*************************************************************************************************/
void printarray(PtrToNode *array,long int num)
 {
  long int a;
  printf("\nWord               Frequency");
  for(a=0;a<num;a++)
   {
    printf("\n%-18s%6d",array[a]->word,array[a]->count);
   }
 }

void main()
 {

  PtrToNode foundnode;
  PtrToNode *sortarray;
  FILE * userfile;
  char filename[50];
  char word[50];
  char *wordp;
  char outertemp,innertemp,count;
  int numprob,numsear;
  HT hasht;
  hasht = NewHT(500);
  numbcomp = 0;
  numprob = 0;
  numsear = 0;
  /*get file name and open it*/
  printf("\nEnter the name of the file to analyze ");
  gets(filename);
  userfile = fileopen(filename,"r");
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
      /*put word in hash table
	to insert new entry*/
      numsear++;
      if((foundnode = FindHT(word,hasht,&numprob))!= NULL)
       {
	/*update old entry in hash table*/
	foundnode->count++;
       }
       else
	{
	 /*enter a new entry in tree*/
	 wordp = malloc(strlen(word)+1);
	 strcpy(wordp,word);
	 InsertHT(wordp,hasht);
	}

     }

   }
  /*initialize array to keep sorted nodes*/
  sortarray = malloc(sizeof(PtrToNode) * hasht->num);
  if(sortarray == NULL)
   {
    FatalError("Out of memory");
   }
  /*move all the values into the sortarray unsorted*/
  movhash(hasht,sortarray);
  /*sort the array*/
  QuickSort(sortarray,hasht->num);
  /*print the array*/
  printarray(sortarray,hasht->num);
  printf("\n\nThe number of probes divided by the number of searches is %f",((float)numprob/numsear));
  printf("\n\nQsort performed %d comparisons",numbcomp);
  printf("\nIdeally it should have performed %.0f comparisons(nlogn)",floor(hasht->num*log(hasht->num)/log(2)));
  fclose(userfile);
 }


