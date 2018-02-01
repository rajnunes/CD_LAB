#include "stdio.h"
#include "stdlib.h"
// #include "bits/stdc++.h"
// #include <iostream>

struct lexeme{
	int index;
	unsigned int row,col;
	char type[100];
	char lexemename[100];
};

int main(){
	/*FILE *fptr;
	fptr=fopen("test","r");



	if(fptr==NULL){
		perror("Error");
		exit(0);
	}

	char c;
	c=fgetc(fptr);

	while(c!=EOF){
		
		c=fgetc(fptr);		
	}

	fclose(fptr);
	*/
	ifstream file;
	file.open ("test.txt");
	return 0;
}