/***************************************************************
	 Name:Eric Duhon			    Assignment #6
	 SS#: 453-97-8531		    	 Filename: scores.c
	 COSC 1410			    	    Due Date: 25 MAR 99
	 Section: 07007			    Turned in: 25 MAR 99
****************************************************************/
/*program inputs a answer key and then inputs scores of several students
  stored in a file. The program then grades the scores and then sorts
  them in descending order and finally outputs the results.*/
#include<stdio.h>
#include<math.h>

void printresults(int [],int [], float, int);

void inputarray(int [],int);

int scoretest(int [],int [],int n);

float average(int [],int n);

void sortscores(int [],int [],int);

void main()
{
 int key[20];
 int id[50];
 int scores[50];
 int ans[20];
 float avg;
 int nq,ns,oid;
 clrscr();
 ns = 0;
 /*input number of questions on test*/
 scanf("%d",&nq);
 /*input answer key*/
 inputarray(key,nq);
 while(scanf("%d",&oid) != EOF)
  {
	/*input individual students scores*/
	inputarray(ans,nq);
	/*store id number aquired earlier in scanf in id[]*/
	id[ns] = oid;
	/*score individual students test*/
	scores[ns] = scoretest(key,ans,nq);
	ns++;

  }
 /*calculate average score for entire class*/
 avg = average(scores,ns);
 /*sort class scores in descending order*/
 sortscores(scores,id,ns);
 /*output results to screen*/
 printresults(id,scores,avg,ns);
}

void printresults(int id[],int scores[], float avg,int n)
 {
  /*outputs id, scores and class average to screen*/
  int a;
  printf("SCORE  ID");
  for(a=0;a<n;a++)
	{
	 printf("\n%3d    %2d",scores[a],id[a]);
	}
  printf("\nAVG=%.2f",avg);

 }

void inputarray(int a[],int n)
 {
  /*inputs an array and stores it in a[]*/
  int count;
  for(count=0;count<n;count++)
	{
	 scanf("%d",&a[count]);
	}
 }

int scoretest(int key[],int ans[],int n)
 {
  /*scores test stored in ans[] according to correct
	 answers stored in key[]*/
  int a,score;
  score = 0;
  for(a=0;a<n;a++)
	{
	 if(key[a] == ans[a]) score++;
	}
	return score;
 }

float average(int score[],int n)
 {
  /*calculates average of all values in score[]*/
  int a;
  float avg;
  avg = 0;
  for(a=0;a<n;a++)
	{
	 avg += score[a];
	}
  avg /= n;
  return avg;
 }

void sortscores(int score[],int id[],int n)
 {
  /*sort values in score[] and id[] in descending order
	 according to the values in score[]*/
  int a,b,temp;
  for(b=0;b<n-1;b++)
	for(a=0;a<n-1-b;a++)
	 {
	  /*reverses id and score if they are out of order*/
	  if(score[a] < score[a+1])
		{
		 temp = score[a];
		 score[a] = score[a+1];
		 score[a+1] = temp;
		 temp = id[a];
		 id[a] = id[a+1];
		 id[a+1] = temp;
		}
	 }

 }