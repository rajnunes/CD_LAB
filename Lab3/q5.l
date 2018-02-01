%{
	int y;	
%}


%%
[ ]*and[a-zA-Z] ;

[ ]*and {
	y++;
}

[a-zA-Z]and[ ]* ;

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
