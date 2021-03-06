/***************************************************************
	 Name:Eric Duhon		     Assignment #7 part1
	 SS#: 453-97-8531		     Filename: prog7pt1.c
	 COSC 1410			     Due Date: 6 APR 99
	 Section: 07007			     Turned in: 6 APR 99
****************************************************************/
/*program outputs the minimum and maximum values of the basic data
  types on this computer*/
#include<stdio.h>
#include<math.h>
#include<limits.h>
#include<float.h>

void main()
{
 clrscr();
 printf("\nThe smallest int on this comuter is %d",INT_MIN);
 printf("\nThe largest int on this comuter is %d",INT_MAX);
 printf("\nThe smallest long int on this comuter is %ld",LONG_MIN);
 printf("\nThe largest long int on this comuter is %ld",LONG_MAX);
 printf("\nThe largest unsigned long int on this comuter is %lu",ULONG_MAX);
 printf("\nThe largest float on this comuter is %e",FLT_MAX);
 printf("\nThe largest double on this comuter is %e",DBL_MAX);
 printf("\nThe largest long double on this comuter is %Le",LDBL_MAX);

 /*exit code*/
 printf("\n\nPress any key to exit program.");
 while(!kbhit())
  {
  }

}
