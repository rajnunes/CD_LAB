#include "stdio.h"
#include "stdlib.h"

int main()
{
	FILE *fptr1;
	char c,ans='c';

	fptr1 = fopen("test.txt", "r");

	if (fptr1 == NULL){
		// printf("Cannot open file %s \n", filename);
		exit(0);
	}
	printf("Enter q or c: \n");
	scanf("%c",&ans);
	getchar();
	
	if(ans=='q'){
		fclose(fptr1);
		exit(0);
	}
	
	c = fgetc(fptr1);
	int lines=0,n_char=0,sp=0,ctr=0;
// Read contents from file
	while (c != EOF){
		if (c=='\n'){
			lines++;
			ctr=0;
		}	
		else{
			n_char++;
			if(c==' ')
				sp++;
		}
		printf("%c",c );

		if((lines)%5==0 && ctr==0 && lines!=0){
			ctr=1;
			printf("Enter q or c: \n");
			scanf("%c",&ans);
			getchar();
			printf("%c Ans val\n",ans );
		}
		if(ans=='q'){
			fclose(fptr1);
			exit(0);
		}

		c = fgetc(fptr1);
	}

	fclose(fptr1);
	
}