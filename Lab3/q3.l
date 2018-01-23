%{
	int pInt,nInt,pFloat,nFloat;	
%}


%%

\+?[0-9]*[E]?[0-9]* {
	pInt++;
}

\+?[0-9]*\.[0-9]*[E]?[0-9]* {
	pFloat++;
}




-[0-9]*[E]?[0-9]* {
	nInt++;
}

-[0-9]*\.[0-9]*[E]?[0-9]* {
	nFloat++;
}
%%

int main(){
	yylex();
	printf("pInt %d \n pFloat %d \n nInt %d \n nFloat %d",pInt,pFloat,nInt,nFloat);
	return 0;
}

int yywrap(){
	return 1;
}