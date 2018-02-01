%{
	int kw,symbol,relop,dec,inc,m_com,s_com,id,sp;	
%}

%%

[?] symbol++;

[ ] sp++;



[/][/][ ]*[a-zA-Z]+ s_com++;

[/][*][ ]*[a-zA-Z]*[ ]*[a-zA-Z]*[ ]*[*][/] m_com++;

if {
	kw++;
	printf("%s keyword %d\n",yytext,kw);
}

[<>=+{}:] {
	symbol++;
}

[a-zA-Z]+ {
	id++;

	printf("%s id %d\n",yytext,id);
} 

[()] {
	symbol++;
	printf("%s symbol %d\n",yytext,symbol);
}

[[]] {
	symbol++;
	printf("%s symbol %d\n",yytext,symbol);
}
[=][=] {
	relop++;
	printf("%s relop %d\n",yytext,relop);

}

[&][&] {
	relop++;
	printf("%s relop %d\n",yytext,relop);

}

[<][=] {
	relop++;
}

[+][+] inc++;


%%

int main(){
	yyin=fopen("test.c","r");

	yylex();

	printf("symbol %d,\nkw %d,\nid %d,\ninc %d,\nm_com %d,\ns_com %d,\nrelop %d",symbol,kw,id,inc,m_com,s_com,relop);
	return 0;
}

int yywrap(){
	return 1;
}