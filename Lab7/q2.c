#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void E();
void E_();
void T();
void T_();
void F();

char *charPtr;

void E(){
	// printf("E -- ");
	T();
	// printf("E -- ");
	E_();
}

void E_(){
	// printf("E' -- ");
	if(*charPtr == '+'){
		// printf("+ -- ");
		charPtr++;
		T();
		// printf("E -- ");
		E_();
	}
	return;
}

void T(){
	// printf("T -- ");
	F();
	// printf("T -- ");
	T_();
}

void T_(){
	// printf("T' -- ");
	if(*charPtr == '*'){
		// printf("* -- ");
		charPtr++;
		F();
		// printf("T' -- ");
		T_();
	}
	return;
}

void F(){
	// printf("F -- ");
	if(*charPtr == '('){
		// printf("( -- ");
		charPtr++;
		E();
		// printf("F -- ");
		if(*charPtr == ')'){
			// printf(") -- ");
			charPtr++;
			return;
		}
	}
	else if(*charPtr == 'i'){
		charPtr++;	
		if(*charPtr == 'd'){
			// printf("id -- ");
			charPtr++;
			return;
		}
	}
	printf("\nCannot Parse.\n");
	exit(1);
}

int main(int argc, char const *argv[])
{
	char buf[256];
	read(0, buf, sizeof(buf));
	charPtr = buf;
	E();
	// // printf("%d\n", (int)(charPtr-buf) + 1);
	// // printf("%d\n", (int)strlen(buf));
	if((int)(charPtr-buf) + 1 == (int)strlen(buf))
		printf("\nParsed\n");
	else
		printf("\nCannot Parse\n");
	return 0;
}
