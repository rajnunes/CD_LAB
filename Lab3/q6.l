%{
	int v,c;	
%}


%%
[aeiouAEIOU] {
	v++;
}


[a-z A-Z] {
	c++;
}

%%

int main(){
	yylex();
	printf("vowels %d \n consonants %d \n",v,c);
	return 0;
}

int yywrap(){
	return 1;
}