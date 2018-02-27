#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	FILE *fptr;
	fptr=fopen("test.txt","r");

	char c;
	char keyword[2][20]={"scalar","foreach"};
	int ctr=0;
	for(c=fgetc(fptr);c!=EOF;c=fgetc(fptr)){
		if(c=='#'){
			c=fgetc(fptr);
			if(c=='!'){
				printf("<");
				while(c!='\n'){
					printf("%c",c);
					c=fgetc(fptr);
				}
				printf(",directive>\n");
			}
			else{
				while(c!='\n')
					c=fgetc(fptr);
				continue;
			}
		}
		else if(c=='$'){
			printf("LOLOLO\n");
			printf("<$");
			while(c!='=' || c!=' '){
				printf("%c",c );

					c=fgetc(fptr);
			}
			printf(",%d>",ctr++ );
			printf("<%c>",c );
			continue;
			// c=fgetc(fptr);

		}
		else {

			char buff[20];
			while(c!=' ' || c!='=' || c!=';')
			{
				buff[strlen(buff)]=c;
			}
			// printf("%s\n", );
			buff[strlen(buff)]='\0';
			if(strcmp(buff,keyword[0])==0 || strcmp(buff,keyword[1])==0){
				printf("<%s,",buff );
				printf(",>");
			}
		}
	}

}
