/***************************************************************
	 Name:Eric Duhon		    Assignment #9
	 SS#: 453-97-8531		    Filename: phone.c
	 COSC 1410			       Due Date: 29 APR 99
	 Section: 07007			 Turned in: 29 APR 99
****************************************************************/
/*program manages a phone book*/
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<dos.h>
#include<conio.h>

#define TEL_BOOK_SIZE 75
#define NAME_SIZE 22
#define TEL_NUM_SIZE 14

struct tel_book_element
 {
   char name[NAME_SIZE];
   char tel_num[TEL_NUM_SIZE];
 };

typedef struct tel_book_element Tel_Book_Element;

struct tel_book
 {
  Tel_Book_Element entry[TEL_BOOK_SIZE];
  int n;
 };

typedef struct tel_book Tel_Book;

char getselect();

void printmenu();

int openfile(const char *, Tel_Book *);

void outputfile(const char *,Tel_Book *);

void upstring(char *);

void lookup(Tel_Book *);

int binarysearch(const Tel_Book *, const char *,int *);

void waitforkey(void);

void inputnew(Tel_Book *);

void deletentry(Tel_Book *);

void gensearch(Tel_Book *);

void openbook(char *,Tel_Book *);

void createfile(char *,Tel_Book *);

void upbook(Tel_Book *);

void sortbook(Tel_Book *);

void swapentry(Tel_Book_Element *,Tel_Book_Element *);

void main()
 {
  char select;
  Tel_Book tb;
  char filename[14];
  clrscr();
  /*set default filename to tbfile.txt*/
  strcpy(filename,"tbfile.txt");
  if(openfile(filename,&tb) == 0)
	{
	/*in case of error opening file*/
	printf("There was an error opening the file tbfile.txt");
	printf("\npress any key to exit");
	waitforkey();
	exit(0);
	}
  select = 0;
  while(select != 'f')
	{
	/*print menu and get user selection*/
	select = getselect();
	/*run apropriate function according to user selection*/
	switch(select)
	 {
	  case 'a':
		lookup(&tb);
		break;
	  case 'b':
		gensearch(&tb);
		break;
	  case 'c':
		inputnew(&tb);
		break;
	  case 'd':
		deletentry(&tb);
		break;
	  case 'e':
		openbook(filename,&tb);
		break;

	 }
	}
  /*save user changes to disk*/
  outputfile(filename,&tb);
 }

char getselect()
 {
  /*function gets users selection. returns letter coresponding to user's
	 menu choice*/
  char select;
  char str[20];
  clrscr();
  printmenu();
  fgets(str,20,stdin);
  select = str[0];
  select = tolower(select);
  while(!(select >= 'a' && select <= 'f'))
	{
	 printf("\nYOUR SELECTION WAS INVALID. PLEASE TRY AGAIN");

	delay(2500);
	clrscr();
	printmenu();
	fgets(str,20,stdin);
    select = str[0];
    select = tolower(select);
   }
  return select;
 }

void printmenu()
 {
  /*function prints main menu*/
  printf("\nMenu of Operations for Automated Telephone Book");
  printf("\n   a) Look-up Name");
  printf("\n   b) List Names Starting with Given String");
  printf("\n   c) Insert New or Modified Entry");
  printf("\n   d) Delete Entry");
  printf("\n   e) Input New Telephone Book");
  printf("\n   f) Quit");
  printf("\nEnter Your Selection(a-f) > ");
 }

int openfile(const char filename[],Tel_Book *tbp)
 {
  /*function opens file named in variable filename. returns 1 if sucesful or 0
	 if not*/
  char temp[22];
  FILE * fp;
  int m = 0;
  fp = fopen(filename,"r");
  if(fp == NULL)
	{
	return 0;
	}
  while(fgets(temp,22,fp) != NULL)
	{
	temp[strlen(temp)-1] = 0;
	strcpy(tbp->entry[m].name,temp);
	fgets(temp,22,fp);
	temp[strlen(temp)-1] = 0;
	strcpy(tbp->entry[m].tel_num,temp);
	m++;

	}
  tbp->n = m;
  fclose(fp);
  return 1;
 }


void upstring(char *str)
 {
  /*function converts string to uppercase*/
  int a;
  for(a=0;a<strlen(str);a++)
   {
	str[a] = toupper(str[a]);
   }
 }

void lookup(Tel_Book *tbp)
 {
  /*function searches through telephone book looking for the person specified
	 by the user*/
  int position;
  char lookname[22];
  clrscr();
  printf("Enter the name of the person you are looking for ");
  gets(lookname);
  upstring(lookname);
  if(binarysearch(tbp,lookname,&position) == 1)
   {
	printf("\n%s's telphone number is %s",tbp->entry[position].name,tbp->entry[position].tel_num);
	printf("\npress any key to continue");
	waitforkey();
   }
	else
	{
	 printf("\nThe name you selected was not found");
	 printf("\nPress any key to continue");
	 waitforkey();
	}
 }

int binarysearch(const Tel_Book *tbp, const char *searchname,int *ip)
 {
  /*function searches tbp for the structure designated by searchname*/
  int low,high,middle;
  low = 0;
  high = tbp->n-1;
  while(low<=high)
   {
	middle = (low + high)/2;
	if(strcmp(searchname,tbp->entry[middle].name) == 0)
	 {
	  *ip = middle;
	  return 1;
	 }
	else if(strcmp(searchname, tbp->entry[middle].name) < 0)
	 {
	  high = middle - 1;
	 }
	 else
	  {
	   low = middle + 1;
	  }
   }
  *ip = low;
  return 0;
 }

void waitforkey(void)
 {
  /*functions pauses program until user presses a key*/
  char temp;
  while(kbhit() == 0)
   {
   }
  temp = getch();
  temp++;
 }

void inputnew(Tel_Book * tbp)
 {
  /*function modifies or inputs a new entry in the phonebook*/
  int position,a;
  char temp[22];
  clrscr();
  printf("Enter the name of the person to add or modify ");
  gets(temp);
  upstring(temp);
  if(binarysearch(tbp,temp,&position) == 1)
   {
	printf("\nEnter the the new phone number for %s\n",tbp->entry[position].name);
	gets(temp);
	strcpy(tbp->entry[position].tel_num,temp);
	printf("\n%s's phone number has been updated. Press any key to continue",tbp->entry[position].name);
	waitforkey();
	}
  else
   {
	if(tbp->n < 75)
	 {
	  for(a = tbp->n;a > position;a--)
	   {
		strcpy(tbp->entry[a].name,tbp->entry[a-1].name);
		strcpy(tbp->entry[a].tel_num,tbp->entry[a-1].tel_num);
	   }
	  strcpy(tbp->entry[position].name,temp);
	  printf("Enter the phone number for %s\n",temp);
	  gets(temp);
	  strcpy(tbp->entry[position].tel_num,temp);
	  tbp->n += 1;
	  printf("\n%s's phone number has been added. Press any key to continue",tbp->entry[position].name);
	  waitforkey();

	 }
	 else
	  {
	   printf("\nYou have exceded the maximum number of phone book entries");
	   printf("\nIf you need more entries please buy the upgrade for only $200");
	   printf("\nOr remove some entries from the phone book");
	   printf("\nPress any key to continue");
		waitforkey();
	  }
   }

 }

void outputfile(const char *filename,Tel_Book *tbp)
 {
  /*function outputs file named by string filename*/
  char temp[22];
  FILE * fp;
  int m,length;
  fp = fopen(filename,"w");
  for(m=0;m<tbp->n;m++)
	{
	strcpy(temp,tbp->entry[m].name);
	length = strlen(temp);
	temp[length] = '\n';
	temp[length+1] = 0;
	fputs(temp,fp);
	strcpy(temp,tbp->entry[m].tel_num);
	length = strlen(temp);
	temp[length] = '\n';
	temp[length+1] = 0;
	fputs(temp,fp);
   }
/*  fputc(EOF,fp);*/
  fclose(fp);
 }

void deletentry(Tel_Book *tbp)
 {
  /*function deletes an entry specified by the user*/
  char temp[22];
  int position,a;
  clrscr();
  printf("Enter the name of the person to delete ");
  gets(temp);
  upstring(temp);
  if(binarysearch(tbp,temp,&position) == 1)
	{
    for(a=position;a<(tbp->n-1);a++)
     {
		tbp->entry[a] = tbp->entry[a+1];

	  }
    printf("\nPerson deleted. Press any key to continue");
    waitforkey();
    tbp->n -= 1;
   }
   else
    {
     printf("\nName not found - No entry deleted");
	  printf("\nPress any key to continue");
     waitforkey();
    }
 }

void gensearch(Tel_Book *tbp)
 {
  /*function searches and prints a list of people whose names begin with
	 user specified string*/
  char temp[22];
  int a;
  clrscr();
  printf("Enter a partial name to look up. ");
  gets(temp);
  upstring(temp);
  printf("\n\nList of Names begining with %s",temp);
  for(a=0;a<tbp->n;a++)
   {
    if(tbp->entry[a].name == strstr(tbp->entry[a].name,temp))
	  {
		printf("\n%s",tbp->entry[a].name);
	  }
	}
  printf("\nFinished creating list. Press any key to continue");
  waitforkey();
 }

void openbook(char *filename,Tel_Book *tbp)
 {
  /*function opens or creates a new telephone book for use in the program. it assigns the
	 name of the new file to filename*/
  char temp[14];
  char ch;
  clrscr();
  printf("Enter the name of the file open ");
  gets(temp);
  if(openfile(temp,tbp) == 0)
	{
	 printf("\nFile does not exist. Do you want to create it?(press y or n) ");
	 ch = getchar();
	 ch = toupper(ch);
	 if(ch == 'Y')
	  {
		createfile(temp,tbp);
		strcpy(filename,temp);
		printf("\nFile created. Press any key to continue");
		waitforkey();
	  }
	  else
		{
		 printf("\nFile not opened. Press any key to continue");
		 waitforkey();
		}
	 ch = getchar();
	}
	else
	 {
	  strcpy(filename,temp);
	  upbook(tbp);
	  sortbook(tbp);
	 }

 }

void createfile(char *filename,Tel_Book *tbp)
 {
  /*creates new file named by filename with one test entry*/
  tbp->n = 1;
  strcpy(tbp->entry[0].name,"test");
  strcpy(tbp->entry[0].tel_num,"123-456-7890");
  outputfile(filename,tbp);
 }

void upbook(Tel_Book *tbp)
 {
  /*converts entire phone book to upper case*/
  int a;
  for(a=0;a<tbp->n;a++)
	{
	 upstring(tbp->entry[a].name);
	}
 }

void sortbook(Tel_Book *tbp)
 {
  /*sorts tbp into alphabetical order according to name field*/
  int a,b;
  for(a=0;a<tbp->n-1;a++)
	{
	 for(b=0;b<tbp->n-1-a;b++)
	  {
		if(strcmp(tbp->entry[b].name,tbp->entry[b+1].name) > 0)
		 swapentry(&(tbp->entry[b]),&(tbp->entry[b+1]));
	  }
	}
 }

void swapentry(Tel_Book_Element *elp1,Tel_Book_Element *elp2)
 {
  /*swaps two entrys*/
  Tel_Book_Element temp;
  strcpy(temp.name,elp1->name);
  strcpy(temp.tel_num,elp1->tel_num);
  strcpy(elp1->name,elp2->name);
  strcpy(elp1->tel_num,elp2->tel_num);
  strcpy(elp2->name,temp.name);
  strcpy(elp2->tel_num,temp.tel_num);

 }