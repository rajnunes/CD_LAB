#include "stdio.h"
#include "stdlib.h"
#include "string.h"
// using namespace std;


int main()
{
	FILE *fptr1,*fptr2;
	char c1,sp=' ';
	fptr1 = fopen("test.txt", "r");
	fptr2 = fopen("output3.c","w");

	char keyword[10][10]={"if","else","int","char","while"};

	char KEYWORDS[10][10]={"IF","ELSE","INT","CHAR","WHILE"};
	char buff[100];

	// printf("%d\n",(int)strlen(keyword[0]) );
	if (fptr1 == NULL)
		exit(0);
	
	if (fptr2 == NULL)
		exit(0);

	c1 = fgetc(fptr1);
	int ctr=0,i=0;

	while(c1!=EOF){

		printf("LOL\n");
		if(c1==' ' || c1=='\t'){
			fputc(c1,fptr2);
			c1=fgetc(fptr1);
		}
		else{
			i=0;
			while(c1!=' ' || c1!='('){
				buff[i]=c1;
				c1=fgetc(fptr1);
				i++;
			}
			buff[i]='\0';
			for(int i=0;i<5;i++){
				if(strcmp(buff,keyword[i])==0){
					ctr=i+1;
					break;
				}

			}
			if(ctr!=0){
				for (int i = 0; i < strlen(KEYWORDS[ctr-1]); ++i){
					fputc(KEYWORDS[ctr-1][i],fptr2);
					printf("%c\n", KEYWORDS[ctr-1][i]);
				}
			}
			else{
				for(int i=0;i<strlen(buff);i++){
					fputc(buff[i],fptr2);

					printf("%c\n", buff[i]);
				}
			}
			fputc(c1,fptr2);

		}

		c1 = fgetc(fptr1);

		printf("LOLWUT\n");
	}


	fclose(fptr1);
	fclose(fptr2);

}	