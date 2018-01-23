#include "stdio.h"
#include "stdlib.h"

int main()
{
	FILE *fptr1;
	char filename[100], c;
	printf("Enter the filename to open for reading: \n");
	scanf("%s", filename);
	getchar();
	// filename="test.txt";
	fptr1 = fopen(filename, "r");

	int ctr=0;
	while (fptr1 == NULL){
		printf("Cannot open file %s \n", filename);
		ctr++;
		printf("%d\n",ctr );
		if(ctr==3){
			printf("You have exceeded 3 tries . Die\n");
			exit(0);
		}
			
		printf("Enter the filename to open for reading: \n");
		scanf("%s", filename);
		fptr1 = fopen(filename, "r");
	}

	c = fgetc(fptr1);
	int lines=0,n_char=0,sp=0;
// Read contents from file
	while (c != EOF){
		if (c=='\n'){
			lines++;
		}	
		else{
			n_char++;
			if(c==' ')
				sp++;
		}
		c = fgetc(fptr1);
	}

	printf("characters (w spaces): %d , lines: %d ,spaces: %d\n",n_char,lines,sp );

	fseek(fptr1,0,SEEK_END);
	int end=ftell(fptr1);

	printf("VALUE : %d\n",(end) );
	fclose(fptr1);
}
