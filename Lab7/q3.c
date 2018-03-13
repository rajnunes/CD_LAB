#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void S();
void A();
void A_();
void B();

char *charPtr;

void S(){
	// printf("S -- ");
	if(*charPtr == 'a'){
		//printf("a -- ");
		charPtr++;
		A();
		//printf("S -- ");
		
		if(*charPtr == 'c'){
		//	printf("c -- ");
			charPtr++;
			B();
		//	printf("S -- ");
			
			if(*charPtr == 'e'){
		//		printf("e -- ");
				charPtr++;
				return;
			}
		}
	}
	printf("Cannot Parse\n");
	exit(1);
}

void A(){
//	printf("A -- ");
	if(*charPtr == 'b'){
//		printf("b -- ");
		charPtr++;
		A_();
	}
}

void A_(){
//	printf("A' -- ");
	if(*charPtr == 'b'){
//		printf("b -- ");
		charPtr++;
		A_();
	}
	return;
}

void B(){
//	printf("B -- ");
	if(*charPtr == 'd'){
//		printf("d -- ");
		charPtr++;
		return;
	}
}

int main(int argc, char const *argv[]){
	char buf[256];
	read(0, buf, sizeof(buf));
	charPtr = buf;
	S();
	// printf("%d\n", (int)(charPtr-buf) + 1);
	// printf("%d\n", (int)strlen(buf));
	if((int)(charPtr-buf) + 1 == (int)strlen(buf))
		printf("\nParsed\n");
	else
		printf("\nCannot Parse\n");
	return 0;
}
