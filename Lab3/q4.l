%{
	int sf,pf;	
%}


%%
scanf {
	sf++;
	fprintf(yyout,"write");
}

printf {
	pf++;
	fprintf(yyout,"read");
}
%%

int main(){

	yyin=fopen("ac","r");
	
	yyout=fopen("bc","w");

	yylex();
	printf("sf %d \n pf %d \n",sf,pf);
	return 0;
}

int yywrap(){
	return 1;
}