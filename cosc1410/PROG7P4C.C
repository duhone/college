/***************************************************************
	 Name:Eric Duhon		                Assignment #7 part4 C
	 SS#: 453-97-8531		                Filename: prog7t4c.c
	 COSC 1410			                   Due Date: 6 APR 99
	 Section: 07007			             Turned in: 6 APR 99
****************************************************************/
/*program uses pointer arithmatic to reverse the values of array a[]*/
#include<stdio.h>
#include<math.h>
#include<limits.h>
#include<float.h>

void reverse(int *,int);

void main()
{
 int i = 1,a[5] = {10,20,30,40,50},count;
 int* p;
 clrscr();
  printf("\nThe address of a is %p",a);

 for(count = 0;count < 5;count++)
  printf("\nA[%d] is set to %d",count,a[count]);
 reverse(a,5);
 printf("\n\nAfter reversing");
 for(count = 0;count < 5;count++)
  printf("\nA[%d] is set to %d",count,a[count]);


 /*exit code*/
 printf("\n\nPress any key to exit program.");
 while(!kbhit())
  {
  }

}

void reverse(int *b,int n)
 {
  /*reverses the values in the array b*/
  int *frontp, *rearp;
  int hold;
  printf("\nThe array b starts at address %p\n",b);
  frontp = b;
  rearp = b+n-1;
  while(frontp < rearp)
	{
	 hold = *frontp;
	 *frontp = *rearp;
	 *rearp = hold;
	 frontp++;
	 rearp--;

	}

 }