#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#ifndef HASHLEN
#define HASHLEN 20
#endif

enum type{FUNC,ID,INT,CHAR,FLOAT,DOUBLE};

char dataTypes[10][10]={"func","id","int","char","float","double"};

typedef struct node{
	char lexemeName[20];
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
	return sum%HASHLEN;
}


// 1 is TRUE 0 is FALSE
int isAlpha(char c){
	if('a'<=c && c<='z')
		return 1;
	else if('A'<=c && c<='Z')
		return 1;
	return 0;

}

int isSpace(char c){
	if(c==' ' || c=='\t' || c=='\n')
		return 1;
	return 0;
}

int isDigit(char c){
	if(0<=c || c<=9)
		return 1;
	return 0;
} 

int isAlphaOrDigit(char c){
	return isAlpha(c)|isDigit(c);
}

int insertToken(LexemeNode node){
	int hash_value=hashValue(node.lexemeName);

	return 1;
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
		else if(c=='#'){
			while(c!='\n')
				c=fgetc(fptr);
			continue;
		}
		else if(c=='/'){
			c=fgetc(fptr);
			if(c=='/'){
				while(c!='\n')
					c=fgetc(fptr);
				continue;
			}
			else if(c=='*'){
				int multiComm=0;
				char t=fgetc(fptr);
				while(t!='/'){
					if(t=='*'){
						multiComm=1;
						t=fgetc(fptr);	
						if(t=='/' && multiComm==1){
							c=fgetc(fptr);
							break;
						}
					}
					t=fgetc(fptr);
				}

			}
		}
		else if(isAlpha(c)){
			lexemeName[strlen(lexemeName)]=c;
			char t=fgetc(fptr);
			while(isSpace(t)!=1){
				lexemeName[strlen(lexemeName)]=t;
				t=fgetc(fptr);
			}
			c=fgetc(fptr);


		}
	}

	fclose(fptr);	
	return 1;
}


// GLOBAL VARIABLES
BasicNode hashTable[HASHLEN];

int main(){

	for(int i=0;i<HASHLEN;i++)
		hashTable[i].next=hashTable[i].last=NULL;
	

	// getNextToken();
	printf("LOl\n");
	return 1;
}
