#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#ifndef HASHLEN
#define HASHLEN 20
#endif

enum type{FUNC,ID,INT,CHAR,FLOAT,DOUBLE};

char dataTypes[10][10]={"func","id","int","char","float","double"};

char buf[10],sizebuf[10];
char key [20][20]={"char","int","long","double","float","if","else","switch","case","for","while","break","return","FILE","struct","NULL","typedef","EOF"};
char typesize[20][20]={"1","4","16","8","8","","","","","","","","","",""};
int id[100],previd=-1;
int usedcur=0,usednumcur=0;

typedef struct node{
	char lexemeName[100];
	char size[100];
	char scope;
	int id;
	char type[100];
	int hashValue;
	struct node *next;
}LexemeNode;

typedef struct basicNode{
	LexemeNode *next;
	LexemeNode *last;
}BasicNode;

BasicNode hashList[HASHLEN];

int resetHashList(){
	for (int i = 0; i < HASHLEN; ++i){
		hashList[i].next=hashList[i].last=NULL;
	}
	return 1;
}
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
int searchToken(LexemeNode *node){
	LexemeNode *temp=hashList[node->hashValue].next;
	while(temp!=NULL){
		if(strcmp(temp->lexemeName,node->lexemeName)==0){
			return 1;
		}
	}
	return 0;
}

int insertToken(LexemeNode* node){
	if(node==NULL){
		printf("TMPTEMPTEMP\n");
		return 0;
	}
	if(searchToken(node))
		return 1;
	LexemeNode *tempNode;
	strcpy(tempNode->lexemeName,node->lexemeName);
	strcpy(tempNode->size,node->size);
	strcpy(tempNode->type,node->type);
	tempNode->scope=node->scope;
	tempNode->id=node->id;
	tempNode->hashValue=node->hashValue;
	tempNode->next=NULL;

	LexemeNode *last=hashList[tempNode->hashValue].last;
	last->next=tempNode;
	hashList[tempNode->hashValue].last=tempNode;
	return 1;
}



int getNextToken(FILE *fp1){
	// FILE * fp2;

	if(fp1==NULL){
		perror("Error");
		exit(0);
	}
	char c=fgetc(fp1);

	while(c!=EOF){
		int i=0,func=0,arr=0;
		buf[0]='\0';

		LexemeNode *tempNode;

		if(c==' '||c=='\t') 
			c=getc(fp1);
		else if(c=='#'){
			while(c!='\n')
				c=getc(fp1);
			c=getc(fp1);
		}
		else if(c=='\''){
			c=getc(fp1);
			while(c!='\'')
				c=getc(fp1);
			c=getc(fp1);
		}
		else if(c=='\"'){
			c=getc(fp1);
			while(c!='\"')
				c=getc(fp1);
			c=getc(fp1);
		}
		else if(c=='\n'){
			// fprintf(fp2, "\n");
			c=getc(fp1);
		}		
		else if(c=='='){
			buf[i++]=c;
			c=fgetc(fp1);
			if(c=='='){
				buf[i++]=c;
				buf[i]='\0';
				// fprintf(fp2, "<%s> ", buf);
				c=fgetc(fp1);
			}
			else{
				buf[i]='\0';
				// fprintf(fp2, "<%s> ", buf);
			}
		}
		else if(c=='+'){
			buf[i++]=c;
			c=fgetc(fp1);
			if(c=='+'){
				buf[i++]=c;
				buf[i]='\0';
				// fprintf(fp2, "<%s> ", buf);
				c=fgetc(fp1);
			}
			else{
				buf[i]='\0';
				// fprintf(fp2, "<%s> ", buf);
			}
		}
		else if(c=='<'||c=='>'){
			buf[i++]=c;
			c=fgetc(fp1);
			if(c=='='){
				buf[i++]=c;
				buf[i]='\0';
				// fprintf(fp2, "<%s> ", buf);
			}
			else{
				buf[i]='\0';
				// fprintf(fp2, "<%s> ", buf);
			}
		}
		else if(c=='!'){
			buf[i++]=c;
			c=fgetc(fp1);
			if(c=='='){
				buf[i++]=c;
				buf[i]='\0';
				// fprintf(fp2, "<%s> ", buf);
				c=fgetc(fp1);
			}
			else{
				buf[i]='\0';
				// fprintf(fp2, "<%s> ", buf);
			}
		}
		else if(c>='A'&&c<='Z'||c>='a'&&c<='z'){
			buf[i++]=c;
			c=fgetc(fp1);
			while(c>='A'&&c<='Z'||c>='a'&&c<='z'||c>='0'&&c<='9'){
				buf[i++]=c;
				c=fgetc(fp1);
			}
			if(c=='(')
				func=1;
			else if(c=='[')
			{
				// fprintf(fp2, "<%c> ", c);
				int s=0;
				arr=1;
				c=fgetc(fp1);
				while(c!=']')
				{
					sizebuf[s++]=c;
					c=fgetc(fp1);
				}
				sizebuf[s]='\0';
			}
			buf[i]='\0';
			int keyflag=0;
			for(int k=0;k<18;k++)
				if(strcmp(buf, key[k])==0)
				{
					keyflag=1;
					previd=k;
					break;
				}
			if(keyflag==1){
				// fprintf(fp2, "<%s> ", buf);
			}
			else
			{
				int usedflag=0;int pos=0;
				// Add logic for hash map
				int hashVal=hashValue(buf);
				strcpy(tempNode->lexemeName,buf);
				tempNode->hashValue=hashVal;


				//replace with searchToken() 
				/*for(int k=0;k<usedcur;k++){
					if(strcmp(buf, used[k])==0)
					{
						usedflag=1;
						pos=k;
						break;
					}
				}*/
				usedflag=searchToken(tempNode);
					
				if(usedflag==1){
					// fprintf(fp2, "<id,%d>", pos+1);
				}
				else
				{
					// strcpy(used[usedcur], buf);
					// strcpy(s[usedcur].name,buf);
					if( func==0 && arr==0 )
					{
						strcpy(tempNode->type,key[previd]);
						// strcpy(s[usedcur].type,key[previd]);
						strcpy(tempNode->size,typesize[previd]);
					}
					else if( func==1 && arr==0 )
					{
						strcpy(tempNode->type,"FUNC");
						// strcpy(s[usedcur].type,"FUNC");
						strcpy(tempNode->size,"");
					}
					else if( arr==1 && func==0 )
					{
						char temp[100];
						strcpy(temp,key[previd]);
						strcat(temp," array");
						int sz=atoi(sizebuf);
						int ts=atoi(typesize[previd]);
						sz=sz*ts;
						sprintf(sizebuf,"%d",sz);
						strcpy(tempNode->type,temp);
						strcpy(tempNode->size,sizebuf);
					}
					tempNode->id=usedcur;
					usedcur++;
					// fprintf(fp2, "<id,%d> ", usedcur);
				}
			}
		}
		else if(c>='0'&&c<='9'){
			buf[i++]=c;
			c=fgetc(fp1);
			while(c>='0'&&c<='9')
			{
				buf[i++]=c;
				c=fgetc(fp1);
			}
			buf[i]='\0';
			
			
			int usedflag=0;int pos=0;
			/*for(int k=0;k<usedcur;k++){
				if(strcmp(buf, usednum[k])==0){
					usedflag=1;
					pos=k;
					break;
				}
			}		*/
			usedflag=searchToken(tempNode);
			if(usedflag==1){
				// fprintf(fp2, "<%s,%d>",buf, pos+1);
			}
			else{
				printf("%s\n",buf);
				strcpy(tempNode->lexemeName,buf);
				// strcpy(usednum[usednumcur++], buf);
				// fprintf(fp2, "<%s,%d> ",buf, usednumcur);
			}
		}
				
		else
		{	
			// fprintf(fp2, "<%c> ", c);
			c=fgetc(fp1);
		}
		printf("YOLO'Z %s\n", );
		if(insertToken(tempNode))
			 printf("success fuly inserted\n");
		else
			printf("insertion fail\n");
		// while loop end
		/*char *token;
		token=(char*)malloc(sizeof(char)*strlen(tempNode->lexemeName));
		strcpy(token,tempNode->lexemeName);
		return token;
*/
	}
}
/*int getNextToken(){
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
*/

// GLOBAL VARIABLES
// BasicNode hashTable[HASHLEN];

int main(){

	FILE *fp1;
	char file[100];
	// printf("\nEnter Input File : ");
	// scanf("%s",file);
	strcpy(file,"eval.txt");
	fp1 = fopen(file, "r");
	getNextToken(fp1);
	// char *temp=getNextToken(fp1);
	// printf("%s",temp);
	// getNextToken();
	// printf("LOl\n");
	return 1;
}
