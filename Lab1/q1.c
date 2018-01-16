#include "stdio.h"
#include "stdlib.h"

int main()
{
	FILE *fptr1;
	char filename[100], c;
	// printf("Enter the filename to open for reading: \n");
	// scanf("%s", filename);
	// filename="test.txt";
	fptr1 = fopen("test.txt", "r");

	if (fptr1 == NULL){
		// printf("Cannot open file %s \n", filename);
		exit(0);
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

	fclose(fptr1);
}