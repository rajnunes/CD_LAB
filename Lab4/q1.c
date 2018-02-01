#include "stdio.h"
#include "stdlib.h"
// #include "bits/stdc++.h"
// #include <iostream.h>

struct lexeme{
	int index;
	unsigned int row,col;
	char type[100];
	char lexemename[100];
};

int main(){
	FILE *fptr;
	fptr=fopen("test.c","r");



	if(fptr==NULL){
		perror("Error");
		exit(0);
	}

	char c,t;
	c=fgetc(fptr);
	int q_ctr=0;
	int bracket=0;
	while(c!=EOF){
		if(c==' ' || c=='\t' || c=='\n'){
			printf("%c",c );
			c=fgetc(fptr);
		}

		if(c=='"' && q_ctr==0){
			q_ctr++;
			printf("<\"");
			while(q_ctr==1){
				if(c=='"'){
					printf("\">");
					q_ctr--;
				}
				else
					printf("%c",c );
				c=fgetc(fptr);
			}
		}

		else if(bracket==0 && ((65<=c && c<=90) || (97<=c && c<=122))){
			bracket++;
			printf("<%c",c );
			c=fgetc(fptr);
			while(bracket==1){
				if(bracket==1 && ((65<=c && c<=90) || (97<=c && c<=122))){
					printf("%c",c );
				}
				else{
					bracket--;
					printf(">%c",c );
				}
				c=fgetc(fptr);

			}
		}
		
		else{
			switch(c){
				case '&':
				case '<':
				case '>':
				case '=':
				case '+':
				case '-':
						t=fgetc(fptr);
						switch(t){
							case '&':
							case '<':
							case '>':
							case '=':
							case '+':
							case '-':
								printf("<%c%c>",c,t );
								break;
							default:
								printf("<%c>",c );
								fseek(fptr,-1,SEEK_CUR);
						}
						break;

				case '{':
				case '}':
				case '[':
				case ']':
				case '(':
				case ')':
					if(bracket==1){
						printf("><%c>",c );
						bracket--;
					}
					else
						printf("<%c>",c );
					break;
				default:
					break;

			}
		}

		c=fgetc(fptr);		
	}

	fclose(fptr);	
	return 0;
}