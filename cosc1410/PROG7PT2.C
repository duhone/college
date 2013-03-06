/***************************************************************
	 Name:Eric Duhon		                Assignment #7 part2
	 SS#: 453-97-8531		                Filename: prog7pt2.c
	 COSC 1410			                   Due Date: 6 APR 99
	 Section: 07007			             Turned in: 6 APR 99
****************************************************************/
/*program outputs the number of bytes used by the basic data types
  on this computer*/
#include<stdio.h>
#include<math.h>
#include<limits.h>
#include<float.h>

void main()
{
 clrscr();
 printf("\nThe number of bytes used by int on this comuter is %d",sizeof(int));
 printf("\nThe number of bytes used by long int on this comuter is %d",sizeof(long));
 printf("\nThe number of bytes used by float on this comuter is %d",sizeof(float));
 printf("\nThe number of bytes used by double on this comuter is %d",sizeof(double));
 printf("\nThe number of bytes used by long double on this comuter is %d",sizeof(long double));

 /*exit code*/
 printf("\n\nPress any key to exit program.");
 while(!kbhit())
  {
  }

}
