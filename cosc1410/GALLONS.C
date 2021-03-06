/***************************************************************
	 Name:Eric Duhon		    Assignment #2
	 SS#: 453-97-8531		    Filename: gallons.c
	 COSC 1410			    Due Date: 9 FEB 99
	 Section: 07007			    Turned in: 9 FEB 99
****************************************************************/

/* Program calculates various statics about automobile fuel consuption,
	including miles per gallon and cost per mile. */

#include<stdio.h>

void main()
{
 /*declarations*/
 char exit;
 int miles=0,tmiles=0;
 float gall=0,tgall=0,cospgal=0,mpg=0,cospmil=0,tmpg=0;
 clrscr();
 /*calculate individual costs*/
  printf("Enter gallons used(enter -1 to exit): ");
  scanf("%f", &gall);

 while((gall != -1))
 {
  /* get input*/
  printf("Enter miles driven: ");
  scanf("%d",&miles);
  printf("Enter cost per gallon in dollars: ");
  scanf("%f",&cospgal);
  /*calculate and display individual output*/
  mpg = miles / gall;
  cospmil = ((cospgal*gall)/miles)*100;
  tmiles += miles;
  tgall += gall;
  printf("\nThe miles / gallon for this tank was %.2f.",mpg);
  printf("\nThe cost / mile for this tank was %.1f cents per mile.",cospmil);
  delay(3000);
  printf("\n\nEnter gallons used(enter -1 to exit): ");
  scanf("%f", &gall);

 }
 /*calculate average miles per gallon*/
 tmpg = tmiles/tgall;
 printf("\n\nThe overall average miles / gallon was %.2f.",tmpg);
 if(tmpg < 20) printf("\nThat is poor mileage.");
 else if((tmpg >=20) && (tmpg <=32)) printf("\nThat is good mileage.");
 else if(tmpg > 32) printf("\nThat is excellent mileage.");

 /*exit code*/
 printf("\n\nPress any key to exit program");
 exit = getch();
}