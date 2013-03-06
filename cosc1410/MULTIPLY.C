/***************************************************************
	 Name:Eric Duhon			    Assignment #4
	 SS#: 453-97-8531		    	 Filename: multiply.c
	 COSC 1410			    	    Due Date: 4 MAR 99
	 Section: 07007			    Turned in: 4 MAR 99
****************************************************************/

/* Program asks a user defined number and type of multiplication
	problems which the user then answers. Program keeps track of
	how well the student is doing and reports the results at the
	end of the program. */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define numbques 10


int Pow10(int);

unsigned int randomint(unsigned int);

void printresponsetoright(void);

void printresponsetowrong(int,unsigned long);

void printsummary(int,int,int);

void main()
{
 /*declerations, and seed the random number generator*/
 int numbdig,domore,numright,numwrong,counter,counter2;
 unsigned int maxnumb,firnum,secnum;
 unsigned long rightans,userans;
 srand(time(NULL));
 do
  {
	/*repeats program for every set of practice problems*/
	clrscr();
	numright = 0;
	numwrong = 0;
	do
	 {
	  /*gets number of digits to use insuring no more than 4 digits which would be to large
	  for the long int answer*/
	  printf("\nEnter the maximum number of digits to use in this set of practice problems: ");
	  scanf("%d",&numbdig);
	  if(numbdig <= 0 || numbdig >4)
		printf("You must enter a digit between 1 and 4. Please try again");
	 }while(numbdig <= 0 || numbdig >4);
	/*calculate largest number to use based on max digits*/
	maxnumb = Pow10(numbdig) - 1;
	for(counter = 1;counter <= numbques;counter++)
	 {
	  /*calculate a random problem, then prints it out. loop excecutes a
		 predetermined number of times*/
	  firnum = randomint(maxnumb);
	  secnum = randomint(maxnumb);
	  rightans = firnum * (unsigned long)secnum;
	  printf("\n\nProblem %d\n",counter);
	  counter2 = 0;
	  do
		{
		 /*keep reasking problem until user gets it right or have asked 3 times*/
		 printf("  %d x %d = ",firnum,secnum);
		 scanf("%U",&userans);
		 counter2++;
		 if(userans == rightans)
		  {
			numright += 1;
			printresponsetoright();
		  }
		 else
		  {
			numwrong += 1;
			printresponsetowrong(counter2,rightans);
		  }
		}while((counter2 < 3) && (userans != rightans));
	 }
	printsummary(numright,numwrong,numbdig);
	printf("\n\nDo you want to do %d more problems, yes or no? Enter Y or N: ",numbques);
	domore = getche();
  }while(domore == 'y' || domore == 'Y');
 /*exit code*/
 printf("\n\nPress any key to exit program.");
 while(!kbhit())
  {
  }
}

int Pow10(int m)
 /*calculates 10 raised to the n power*/
 {
  int a,power;
  power = 1;
  for(a = 0;a < m;a++)
	{
	 power *= 10;
	}
  return power;
 }

unsigned int randomint(unsigned int n)
 /*calculates a random number between 1 and n*/
 {
  int numb;
  numb = (rand() % n) + 1;
  return numb;
 }

void printresponsetoright(void)
 {
  /*prints one of 4 random positive responses to a correct answer*/
  unsigned int response;
  response = randomint(4);
  switch(response)
	{
	 case 1:
	  printf("  VERY GOOD!");
	  break;
	 case 2:
	  printf("  EXCELLENT!");
	  break;
	 case 3:
	  printf("  NICE WORK!");
	  break;
	 case 4:
	  printf("  KEEP UP THE GOOD WORK!");
	  break;
	}
 }

void printresponsetowrong(int count,unsigned long right)
 {
  /*prints one of 4 negative response to a wrong ansewr, unless user
	 has used all there gueses(count == 3) in which case funciton prints out the
	 correct answer (right)*/
  unsigned int response;
  response = randomint(4);
  if(count == 3) response = 5;
  switch(response)
	{
	 case 1:
	  printf("  No. Please try again.\n");
	  break;
	 case 2:
	  printf("  Wrong. Try once more.\n");
	  break;
	 case 3:
	  printf("  Don't give up!\n");
	  break;
	 case 4:
	  printf("  No. Keep trying.\n");
	  break;
	 case 5:
	  printf("  No. The correct answer is %lu. Ask your teacher to help you on this problem\n",right);
	  break;
	}
 }

void printsummary(int numright,int numwrong,int maxdig)
 {
  /*prints summary of how well student did on one group of questions
	 based on the number they got right(numright) and the number they
	 got wrong(numwrong)*/
  float average;
  if((numright + numwrong) != 0)
	average = 100.0 * numright / (float)(numright + numwrong);
  else average = 0.0;
  printf("\n%.1f%%  of your answers were correct on these problems.",average);
  if(average >= 90.0)
	{
	 printf("\nEXCELLENT! Try proplems with %d digits next time.",(maxdig+1));
	}
  else if(average >= 60.0)
	{
	 printf("\nGOOD, but keep practicing problems with %d digits until you get at least 90%% \ncorrect.",maxdig);
	}
  else
	{
	 printf("\nDont't be discouraged, but ask your teacher for extra help.");
	}
 }