#include "stdio.h"
#include "stdlib.h"

int main()
{
	FILE *fptr1,*fptr2;
	char filename[100], c1,c2;
	// printf("Enter the filename to open for reading: \n");
	// scanf("%s", filename);
	// getchar();
	// filename="test.txt";
	fptr1 = fopen("test.txt", "r");
	if (fptr1 == NULL){
		// printf("Cannot open file %s \n", filename);
		exit(0);
	}

	fptr2 = fopen("test1.txt", "r");
	if (fptr2 == NULL){
		// printf("Cannot open file %s \n", filename);
		exit(0);
	}

	c1 = fgetc(fptr1);

	c2 = fgetc(fptr2);
	int lines=0,n_char=0,sp=0;
// Read contents from file
	int ctr=0;
	while (c1 != EOF && c2 != EOF){
		if(c1!=c2){
			ctr=1;
			printf("Different Files\n");
			break;
		}
		c1 = fgetc(fptr1);
		c2 = fgetc(fptr2);		
	}
	if(ctr==0)
		printf("Same Files\n");
	fclose(fptr1);
	fclose(fptr2);


}
