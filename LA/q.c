#include "stdio.h"
#include "stdlib.h"
#include "string.h"

enum type{FUNC,ID,INT,CHAR,FLOAT,DOUBLE};

char dataTypes[10][10]={"func",
						"id",
						"int",
						"char",
						"float",
						"double"};

typedef struct node{
	char lexeme[20];
	int size;
	char scope;
	int type;
	struct node *next;
}LexemeNode;

typedef struct basicNode{
	LexemeNode *next;
	LexemeNode *last;
}BasicNode;


int hashValue(char name[]){
	int sum=0;
	for(int i=0;i<strlen(name);i++)
		sum+=(int)name[i];
	return sum%20;
}

int isAlpha(char c){
	if('a'<=c && c<='z')
		return 1;
	else if('A'<=c && c<='Z')
		return 1;
	return 0;

}

int isDigit(char c){
	if(0<=c || c<=9)
		return 1;
	return 0;
} 

int getNextToken(){
	FILE *fptr;
	fptr=fopen("test.c","r");


	if(fptr==NULL){
		perror("Error");
		exit(0);
	}
	char c;
	char lexemeName[20];

	for(c=fgetc(fptr);c!=EOF;c=fgetc(fptr)){
		if(c==' ' || c=='\t' || c=='\n'){
			printf("%c",c );
			continue;
		}
		if(isAlpha(c) )
	}

	fclose(fptr);	
	return 1;
}


// GLOBAL VARIABLES
BasicNode hashTable[20];

int main(){


	// getNextToken();

	return 1;
}
