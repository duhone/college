typedef struct Node *PtrToNode;
struct Node { char *word; int count; PtrToNode next; };
typedef struct HTInfo *HT;
struct HTInfo
{ long int arraySize; /*current array size. if re-hashing occurs this will change*/ 
  long int num;       /*number of words (nodes in linked lists) in table*/ 
  PtrToNode *array;   /*dynamically allocated array of pointers that point to linked 
                        lists containing the words/counts*/
};

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
PtrToNode FindHT(char *w, HT ht)

/*************************************************************************************************
The function InsertHT inserts a node containing w and count 0 in the front of the correct list. 
If (ht->num > 2*ht->arraySize) then it re-hashes by allocating an array of size the next largest 
prime as determined by NextPrime and re-inserting each node into the correct list for the larger 
array and freeing the old array. This function assumes that FindHT has already determined that w 
is not in the hash table.  
*************************************************************************************************/
void InsertHT(char *w, HT ht)

/*************************************************************************************************
The function NextPrime returns the smallest prime number greater than or equal to n form the 
following list of primes: 31, 61, 127, 251,  509, 1021, 2039, 4093, 8191, 16381, 32749, 65521, 
131071, 262139, 524287, 1048573. These are the largest primes less than 2**n for 5 <= n <= 20.
*************************************************************************************************/
long int NextPrime(long int n)

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
The function QuickSort sorts the pointers in the array so that they point to nodes in the order 
of descending counts. For nodes with counts that are equal the nodes are in descending 
alphabetical order of the words. The function works by calling on Qsort which is recursive.
*************************************************************************************************/
void QuickSort(PtrToNode a[ ], int n)
{ Qsort(a, 0, n-1);
}
