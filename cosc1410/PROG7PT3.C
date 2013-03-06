/***************************************************************
	 Name:Eric Duhon		                Assignment #7 part3
	 SS#: 453-97-8531		                Filename: prog7pt3.c
	 COSC 1410			                   Due Date: 6 APR 99
	 Section: 07007			             Turned in: 6 APR 99
****************************************************************/
/*program outputs the result of adding one to the maximum integer
  value, and multiplying the maximum float by 10 on this comupter*/
#include<stdio.h>
#include<math.h>
#include<limits.h>
#include<float.h>

void main()
{
 int integer;
 float floating;
 clrscr();
 integer = INT_MAX + 1;
 printf("\nThe value of an int after adding 1 to its maximum value is %d",integer);
 printf("\n");
 floating = 10 * FLT_MAX;

 printf("\nThe value of an float after multiplying its maximum value by 10 is %f",floating);

 /*exit code*/
 printf("\n\nPress any key to exit program.");
 while(!kbhit())
  {
  }

}
