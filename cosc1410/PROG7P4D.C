/***************************************************************
	 Name:Eric Duhon		                Assignment #7 part4 D
	 SS#: 453-97-8531		                Filename: prog7t4d.c
	 COSC 1410			                   Due Date: 6 APR 99
	 Section: 07007			             Turned in: 6 APR 99
****************************************************************/
/*program dynamicly creates an array and adds the user inputed
  values of the array together*/
#include<stdio.h>
#include<stdlib.h>


void main()
{
 int n,count;
 float *x,sum;
 clrscr();
 printf("Enter the number of elements to add. ");
 scanf("%d",&n);
 x = malloc(n*sizeof(float));
 sum = 0;
 for(count = 0;count < n;count++)
  {
	printf("Enter a float number ");
	scanf("%f",x+count);
  }
 for(count = 0;count < n;count++)
  {
	sum += x[count];
  }
 printf("\nThe sum of the numbers you enterd is %.2 f",sum);
 free(x);

 /*exit code*/
 printf("\n\nPress any key to exit program.");
 while(!kbhit())
  {
  }

}

