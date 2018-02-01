#include "stdio.h"
#include "stdlib.h"

// using namespace std;

int main()
{
	FILE *fptr1,*fptr2;
	char c1,sp=' ';
	fptr1 = fopen("test.txt", "r");
	fptr2 = fopen("output.c","w");

	if (fptr1 == NULL)
		exit(0);
	
	if (fptr2 == NULL)
		exit(0);

	c1 = fgetc(fptr1);
	int ctr=0;
	while(c1!=EOF){
		ctr=0;
		while (c1==' '  || c1=='\t'){
			ctr=1;
			c1=fgetc(fptr1);
		}
		if(ctr==1){
			fputc(sp,fptr2);
			ctr=0;
		}
		fputc(c1,fptr2);
		c1=fgetc(fptr1);
	}
	fputc(EOF,fptr2);

	fclose(fptr1);
	fclose(fptr2);
}
