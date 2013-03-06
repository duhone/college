/*
 * Here we have an incrediblly ugly test routine - but it works.
 *
 *        w colquitt
 *        Fall 1999
 */
#include <stdio.h>
#include <string.h>


int Bin2ASCII(char*, int, unsigned int);
int ClrScrn(int, int);
int PlzWait(unsigned int);

int
main()
   {
    char Answer[7];
    int i;
    char Buffer[7];

      Buffer[6] = (char) 0;

      ClrScrn(0, 10);

      Answer[6] = (char) 0;
      printf("\n");
      
        /*   Test for a zero pointer  */
      i = Bin2ASCII(0, 0, 0);    /* Better error off ASAP - NULL pointer! */
      if ( i != -1 ) printf("\nProgram can't handle NULL pointer case!");

        /* This group tests  for bad radix values  */
      strcpy(Answer, "******\0");
      if ( Bin2ASCII(Answer, -11, 12) != -1 ) printf("\nBad return value");
      printf("\nAnswer should be BadRdx %s\n", Answer);
      PlzWait(1000);

      printf("\n");

   /* ***** Now a series of tests for signed conversions ****** */
      strcpy(Answer, "******\0");
      i = Bin2ASCII(Answer, -10,  (unsigned) -32768);
      printf("\nConverted %2d chars - Answer should be 5",i);
      printf("\nAnswer should be -32768 %s\n", Answer);
      PlzWait(1000);
      
     
      
      strcpy(Answer, "******\0");
      i = Bin2ASCII(Answer, -10, 32767);
      printf("\nConverted %2d chars - Answer should be 5",i);
      printf("\nAnswer should be +32767 %s\n", Answer);
      PlzWait(1000);

      strcpy(Answer, "******\0");
      i = Bin2ASCII(Answer, -10, 123);
      printf("\nConverted %2d chars - Answer should be 3",i);
      printf("\nAnswer should be   +123 %s\n", Answer);
      PlzWait(1000);

      strcpy(Answer, "******\0");
      i = Bin2ASCII(Answer, -10, 0);
      printf("\nConverted %2d chars - Answer should be 1",i);
      printf("\nAnswer should be     +0 %s\n", Answer);
      PlzWait(1000);

      printf("\n");

   /* ***** Now a series of tests for hex conversions ****** */
     strcpy(Answer, "******\0");
      i = Bin2ASCII(Answer, 16,  (unsigned) -1);
      printf("\nConverted %2d chars - Answer should be 4",i);
      printf("\nAnswer should be 0FFFFh %s\n", Answer);
      PlzWait(1000);

      strcpy(Answer, "******\0");
      i = Bin2ASCII(Answer, 16, 32767);
      printf("\nConverted %2d chars - Answer should be 4",i);
      printf("\nAnswer should be 07FFFh %s\n", Answer);
      PlzWait(1000);

      strcpy(Answer, "******\0");
      i = Bin2ASCII(Answer, 16, 0);
      printf("\nConverted %2d chars - Answer should be 4",i);
      printf("\nAnswer should be 00000h %s\n", Answer);
      PlzWait(1000);

      printf("\n");

   /* ***** Now a series of tests for unsigned conversions ****** */
      strcpy(Answer, "******\0");
      i = Bin2ASCII(Answer, 10,  (unsigned) -1);
      printf("\nConverted %2d chars - Answer should be 5",i);
      printf("\nAnswer should be  65535 %s\n", Answer);
      PlzWait(1000);

      strcpy(Answer, "******\0");
      i = Bin2ASCII(Answer, 10, (unsigned) 32768);
      printf("\nConverted %2d chars - Answer should be 5",i);
      printf("\nAnswer should be  32768 %s\n", Answer);
      PlzWait(1000);

      strcpy(Answer, "******\0");
      i = Bin2ASCII(Answer, 10, 0);
      printf("\nConverted %2d chars - Answer should be 1",i);
      printf("\nAnswer should be      0 %s\n", Answer);

      printf("\n");


     /*   Now that its tested let's use it for real from C:     */
       i = 0x9876;
       Bin2ASCII(Buffer, -10, i);
       printf("\nVariable i currently has: %s in it (as signed)", Buffer);
       Bin2ASCII(Buffer, 10, i);
       printf("\nVariable i currently has: %s in it (as unsigned)", Buffer);
       Bin2ASCII(Buffer, 16, i);
       printf("\nVariable i currently has: %s in it (as hex)", Buffer);
   
      return 0;
   }
