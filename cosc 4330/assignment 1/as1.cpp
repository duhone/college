// Name:   Eric Duhon
// SSN:	   453-97-8531
//COSC 4330 Assignment 1

//Implements a simple shell



#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<list>
#include<string>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>

using namespace std;

list<char*> history_list; //hold history

int findspace(char* arg)
/*find the first space character in arg and return its position or return -1 if no 
	space found
*/
{
	unsigned int count;
	for(count = 0;count < strlen(arg);count++)
	{
		if(arg[count] == ' ')
		{
			return count;
		}
	}
	return -1;
}

int findnonspace(char* arg)
/*find the first non-space character in arg and return its position or return -1 if no 
	non-space characters found
*/
{
	unsigned int count;
	for(count = 0;count < strlen(arg);count++)
	{
		if(arg[count] != ' ')
		{
			return count;
		}
	}
	return -1;
}

int findpipe(char* arg)
/*find the first pipe (|) character in arg and return its position or return -1 if no 
	pipe found
*/
{
	unsigned int count;
	for(count = 0;count < strlen(arg);count++)
	{
		if(arg[count] == '|')
		{
			return count;
		}
	}
	return -1;
}

int breaks(char **input,char** output)
/*break input string input into 2 strings. Function cuts the string
at the first space character found. First word is returned in output and 
remaining string is returned in input. returns -1 if there was no white space
*/
{
	int pos;
//find break point
	pos = findspace(*input);
	if(pos == -1) return -1;
	*output = new char[pos+1];
//copy first word to output
	memcpy(*output,*input,pos);
	(*output)[pos] = 0;
	char *temp;
	temp = new char[strlen(*input) - pos + 1];
//copy left overs into input getting rid of the original string
	strcpy(temp,(*input)+pos+1);
	delete[] *input;
	*input = new char[strlen(temp) + 1];
	strcpy(*input,temp);
	
	return 1;
}

int breakpipe(char **input,char** output)
/*break input string input into 2 strings. Function cuts the string
at the first pipe character found. First word is returned in output and 
remaining string is returned in input. returns -1 if there was no white space
*/
{
	int pos;
	int spaceskip;
//find break point
	pos = findpipe(*input);
//find leading space characters to delete from second word
	spaceskip = findnonspace((*input)+pos+1);
	if(pos == -1) return -1;
	*output = new char[pos+1];
//copy first word to output
	memcpy(*output,*input,pos);
	(*output)[pos] = 0;
	char *temp;
	temp = new char[strlen(*input) - pos + 1];
//copy left overs into input getting rid of the original string
	strcpy(temp,(*input)+pos+1+spaceskip);
	delete[] *input;
	*input = new char[strlen(temp) + 1];
	strcpy(*input,temp);
	
	return 1;
}
void addToHistory(char* arg)
/*Add arg to history list. Only 200 max entrys are held in the list. if there are
already 200 entries the oldest entry is deleted from the list
*/
{
	char* temp;
	temp = new char[strlen(arg)+1];
	strcpy(temp,arg);

	history_list.push_back(temp);

//if more than 200 entries delete oldest
	if(history_list.size() >= 200)
	{
		temp = history_list.front();
		delete[] temp;
		history_list.pop_front();
	}


}


int main(int argc, char* argv[])
{
	int count;
	char *cline;	//hold current command line from shell
	bool repeat = false;	//hold if this is a repeat command or not
	for(;;)
	{
//if not repeating create a new command line string
	if(!repeat) cline = new char[250];
//print prompt
	printf("\n##");

//if repeating print repeated comand to screen
	if(repeat) printf("%s",cline);

//if not repeating get a new command from user
	if(!repeat) gets(cline);
//if repeating make sure we dont repeat next time too
	else repeat = false;
	
//add current command to history list
	addToHistory(cline);
	
	if(strchr(cline,'|') == 0)
	{
//not a pipe command
		char* comnd;
		if(breaks(&cline,&comnd) == -1)
		{
//there is only one command with no args
			if(strcmp(cline,"repeat") == 0)
			{
//this was a repeat request. get the last command 
//from the history list and repeat it
				repeat = true;
				delete[] cline;
				cline = new char[250];
				list<char*>::reverse_iterator listit = history_list.rbegin();
				listit++;
				strcpy(cline,*listit);
			}
			else if(strcmp(cline,"exit") == 0)
			{
//this was an exit request. close down everything and
//exit
				kill(0,SIGKILL);
				exit(0);
			}
			else
			{
//this was an unrecognized request
//fork and pass to unix.
				int pid;
				pid = fork();
				if(pid == 0)
				{
					execlp(cline,cline,NULL);
					printf("error could not find file");
					_exit(1);
				}
				else 
				{
//pause shell until unix command completes
					waitpid(pid,0,0);
				}
		}
		}
		else
		{
//this command has args
			if(strcmp(comnd,"background") == 0)
			{
//this was a background request
				delete[] comnd;
				if(breaks(&cline,&comnd) == -1)
				{
//fork, close stdin,stdout, and stderror and run program in silence with no args
					int pid;
					pid = fork();
					if(pid == 0)
					{
						close(0);
						close(1);
						close(2);
						execlp(cline,cline,NULL);
						printf("error could not find file");
						_exit(1);
					}
//do not wait for background app to complete
				}
				else
				{
//fork, close stdin,stdout, and stderror and run program in silence with args
					int pid;
					pid = fork();
					if(pid == 0)
					{
						close(0);
						close(1);
						close(2);
						execlp(comnd,comnd,cline,NULL);
						printf("error could not find file");
						_exit(1);
					}
//do not wait for background app to complete
		
				}
			}
			else if(strcmp(comnd,"history") == 0)
			{
//history request
				int repcount;
//get size user requested for history list
				sscanf(cline,"%d",&repcount);
//if requested size is to large, truncate to current
//size
				if(repcount >= history_list.size())
					repcount = history_list.size()-1;
//skip first entry's to make list right size in history 
//list and the print out the requested list
				int skipcount = history_list.size() - repcount - 1;
				list<char*>::iterator listit = history_list.begin();
				for(count = 0;count < skipcount;count++)
				{
					listit++;
				}
				for(count = 0;count < repcount;count++)
				{
					char* tempstr = *listit;
					printf("\n%d.  %s",count+1,tempstr);
					listit++;

				}
	
			}
			else
			{
//this was an unrecognized request
//fork and pass to unix, with args.
			int pid;
				pid = fork();
				if(pid == 0)
				{
					execlp(comnd,comnd,cline,NULL);
					printf("error could not find file");
					_exit(1);
				}
//wait for command to finish
				else waitpid(pid,0,0);
			}
		}

	}
	else
	{
//this was a pipe request
		char* comnd;
//breaqk into tokens
		breakpipe(&cline,&comnd);
		printf("\n");
		int pid;
		pid = fork();
		if(pid == 0)
		{
//create pipe and set up stdin and stdout
			int pd[2];
			pipe(pd);
			pid = fork();
			if(pid == 0)
			{
//producer
				close(pd[0]);
				dup2(pd[1],1);
				close(pd[1]);
				if(breaks(&comnd,&cline) == -1)
				{
//has no args
					execlp(comnd,comnd,NULL);

				}
				else
				{
//has args
					execlp(cline,cline,comnd,NULL);
				}
			}
			else
			{
//consumer			
				close(pd[1]);
				dup2(pd[0],0);
				close(pd[0]);
				if(breaks(&cline,&comnd) == -1)
				{
//has no args
					execlp(cline,cline,NULL);

				}
				else
				{
//has args
					execlp(comnd,comnd,cline,NULL);
				}
	

			}
		}
//wait until pipe operation is done
		else waitpid(pid,0,0);
		
	}


	if(!repeat) delete[] cline;
	}
	return 0;
}
