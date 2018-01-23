%{
	int y;	
%}


%%
[ ]*and[a-zA-z] ;

[ ]*and {
	y++;
}

[a-zA-z]and[ ]* ;

and[ ] {
	y++;
}

%%

int main(){
	yylex();
	if(y>0)
		printf("coumpound %d",y);
	else
		printf("Nawt");
	return 0;
}

int yywrap(){
	return 1;
}