%{
	#include<stdio.h>
	int lc=0, sc=0, wc=0, cc=0;
%}

%%
[\n] {lc++; cc+=yyleng;}
[ \t] {sc++; cc+=yyleng;}
[$] {return 1;}
[^\t\n ]+ {wc++; cc+=yyleng;}
%%

int yywrap(){}
int main(){
	yylex();
	printf("%d %d %d %d", lc,sc,wc,cc);
	return 1;
}

