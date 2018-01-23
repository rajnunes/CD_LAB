%{
	int w,c,blanks,lines,sp_c;	
%}


%%
\n lines++;

[a-zA-Z][ ] {
	blanks++;
	w++;
	c++;
}

[a-zA-Z]\n {
	blanks++;
	w++;
	lines++;
	c++;
}

[a-zA-Z] {
	c++;
}

[ ] {
	blanks++;
}

. sp_c++;
%%

int main(){
	yylex();
	printf("words %d \n chracters %d \n blanks %d \n lines %d ",w,c,blanks,lines);

	return 0;
}

int yywrap(){
	return 1;
}
