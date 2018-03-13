#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "p1.c"

char *ptr;

void err(int i)
{

	printf("\nError parsing input string %d\n",i);
	exit(0);
}

void success()
{
	printf("\nSuccess parsing input string\n");
	exit(0);
}


void program();
void declarations();
void assign_stat();
void data_type();
void identifier_list();

void statement_list();

void mulop();
void addop();
void relop();
void factor();
void tprime();
void expn();


void mulop(){
	ptr=getNextToken();
	printf("%s\n",ptr);
	if(strcmp(ptr,"*")==0 || strcmp(ptr,"/")==0 || strcmp(ptr,'%')==0){

	}
	else{
		err(100);
	}
}

void relop(){
	ptr=getNextToken();
	if(){

	}
	else{
		printf("%s\n",ptr);
		if(strcmp(ptr,"==")==0 || strcmp(ptr,"!=")==0 || strcmp(ptr,"<=")==0 || strcmp(ptr,">=")==0 || strcmp(ptr,">")==0 || strcmp(ptr,"<")==0){
		}
		else{
			err(101);
		}
	}
}

void addop(){
	ptr=getNextToken();
	printf("%s\n",ptr);
	if(strcmp(ptr,"+")==0 || strcmp(ptr,"-")==0){

	}	
	else
		err(102);
}

void factor(){
	ptr=getNextToken();
	printf("%s\n",ptr);
	if(strcmp(ptr,"id")==0 || strcmp(ptr,"num")==0){

	}	
	else
		err(103);

}

void tprime(){
	ptr=getNextToken();
	printf("%s\n",ptr);


}

void expn(){
	simple_expn();
	eprime();
}

void eprime(){

	relop();
	simple_expn()
}

void statement_list(){
	ptr=getNextToken();
	printf("%s\n",ptr );
	if()
}

void program()
{
	ptr=getNextToken();
	printf("%s\n",ptr);
	if(strcmp(ptr,"main")==0)
	{
		ptr=getNextToken();printf("%s\n",ptr);
		if(strcmp(ptr,"(")==0)
		{
			ptr=getNextToken();printf("%s\n",ptr);
			if(strcmp(ptr,")")==0)
			{
				ptr=getNextToken();printf("%s\n",ptr);
				if(strcmp(ptr,"{")==0)
				{
					declarations();

					assign_stat();
					ptr=getNextToken();printf("%s\n",ptr);
					if(strcmp(ptr,"}")==0)
					{
						ptr=getNextToken();
					}
					else
						err(5);
				}
				else
					err(4);
			}
			else
				err(3);
		}
		else
			err(2);
	}
	else
		err(1);

	printf("Last token <%s> \n", ptr);
	if(strcmp(ptr,"")==0)
		success();
	else
		err(6);
}

void declarations()
{
	ptr=getNextToken();
	
	printf("%s\n",ptr);
	
	if(strcmp(ptr,"id")==0)
	{
		currIndex -= strlen(ptr);	
	}	
	else
	{
		data_type();	

		identifier_list();

		if(strcmp(ptr,";")==0)
		{
			declarations();
		}
		else{
			//insert code
			err(7);
		}
	}
}

void data_type()
{
	if(strcmp(ptr,"int")==0||strcmp(ptr,"char")==0)
	{
	}
	else
		err(12);
}

void identifier1()
{
	ptr=getNextToken();printf("%s\n",ptr);
	if(strcmp(ptr,";")==0)
	{
	}
	else if(strcmp(ptr,",")==0)
	{
		identifier_list();
	}
}

void identifier_list()
{
	ptr=getNextToken();printf("%s\n",ptr);
	if(strcmp(ptr,"id")==0)
	{
		identifier1();
	}
	else
		err(13);
}

void assign_stat()
{
	ptr=getNextToken();printf("%s\n",ptr);
	if(strcmp(ptr,"id")==0)
	{
		ptr=getNextToken();printf("%s\n",ptr);
		if(strcmp(ptr,"=")==0)
		{
			expn();
		}
		else
			err(9);
	}
	else
		err(8);
}


int main()
{
	start();
	program();
	return 0;
}