#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void S();
void T();
void T_();

char *charPtr;

void S(){
	if(*charPtr == 'a'){
		charPtr++;
		return;
	}
	else if(*charPtr == '-'){
		charPtr++;
		if(*charPtr == '>'){
			charPtr++;
			return;
		}
	}
	else if(*charPtr == '('){
		charPtr++;
		T();
		if(*charPtr == ')'){
			charPtr++;
			return;	
		}
	}
	printf("Cannot parse.\n");
	exit(-1);
}

void T(){
	S();
	T_();
}

void T_(){
	if(*charPtr == ','){
		charPtr++;
		S();
		T_();
	}
	return;
}

int main(int argc, char const *argv[])
{
	char buf[256];
	read(0, buf, sizeof(buf));	
	charPtr = buf;
	S();
	if((int)(charPtr-buf) + 1 == (int)strlen(buf))
		printf("Parsed\n");
	else
		printf("Cannot Parse\n");
	return 0;
}