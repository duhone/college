#include <stdio.h>
#include <string.h>  /*for prototype of strcpy - needed in NextWord*/
#include <ctype.h>   /*for prototypyes of isalnum, tolower - needed in NextWord*/
#include <stdlib.h>
#include "error.h"

char *NextWord(int *ip, char line[ ]);

/****************************************************************************
main tests the function nexword. To use it you must have a text file named
testfile.txt.
****************************************************************************/
int main()
{  char line[120]; char *w; int i; FILE *fp = fopen("testfile.txt", "r");
   if (fp == NULL) FatalError("File did not open");
   while (fgets(line, 120, fp) != NULL)
   {  i = 0;
      while ((w = NextWord(&i, line)) != NULL)
         puts(w);
   }
   fclose(fp);
   return 0;
}

/****************************************************************************
The function NextWord extracts the next word from line starting from  
subscript *ip. It make each letter in the word lower case. It stores the
word in dynamically allocated storage of the right length for the word and
returns a pointer to the dynamic storage. If no word is extracted before
the end of the line is reached then the function returns NULL. *ip is
changed to the subscript of the character just past the extracted word.
****************************************************************************/
char *NextWord(int *ip, char line[ ])
{  int j = *ip, k, l;  char *wp;
   while ((line[j] != '\0') && !isalpha(line[j])) /*ignore this character*/
      j++;
   if (line[j] == '\0') return NULL;
   k = j;
   while (isalnum(line[k]))
      k++;
   wp = malloc(k - j + 1);
   if (wp == NULL) FatalError("Out of storage!!! Cannot store word.");
   l = 0;
   while (j < k)
      wp[l++] = tolower(line[j++]);
   wp[l] = '\0';
   *ip = k;
   return wp;
}
