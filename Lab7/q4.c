#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
char *ptr;

void lexp();
void aterm();
void list();
void ls();
void ls1();

int isDigit(char c) {
    if(c >= 48 && c <= 57)
        return 1;
    return 0;

}

int isAlpha(char c){
    if(c >= 97 && c <= 122)
        return 1;
    return 0;
}

void lexp()
{
	if(*ptr == '1' || *ptr == 'a')
	{
		aterm();
		return;
	}
	else if(*ptr == '(')
	{
		list();
		return;
	}
	printf("Cannot parse\n");
	printf("lexp\n");
	exit(0);
}
void aterm()
{
	if(*ptr == '1')
	{
		ptr++;
		return;
	}
	else if(*ptr == 'a')
	{
		ptr++;
		return;
	}
	printf("Cannot parse\n");
	printf("aterm\n");
	exit(0);

}
void list()
{
	if(*ptr == '(')
	{
		ptr++;
		ls();
		if(*ptr == ')')
		{
			ptr++;
			return;
		}
	}
	printf("Cannot parse\n");
	printf("list\n");
	exit(0);
}
void ls()
{
	lexp();
	ls1();
}
void ls1()
{
	if(*ptr == '1' || *ptr == 'a' || *ptr == '(')
	{
		lexp();
		ls1();
	}
	return;
}


int main()
{
  char buf[20];
  printf("Enter input string: ");
  scanf("%s",buf);
  buf[strlen(buf)]='$';
  ptr = buf;
  lexp();
  if(*ptr == '$')
  		printf("Success\n");
  else
  		printf("Failure\n");
}