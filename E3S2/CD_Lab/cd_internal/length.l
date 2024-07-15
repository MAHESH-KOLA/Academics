%{
	#include<stdio.h>
	int l;
%}

%%
[a-zA-Z0-9 ]+ {l=yyleng; printf("%d\n",l);}
%%

int yywrap(){
	return 1;
}
int main(){
	yylex();
	return 1;
}
