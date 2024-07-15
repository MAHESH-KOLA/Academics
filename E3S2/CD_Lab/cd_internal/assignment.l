%{
	#include<stdio.h>
%}
%%
">"|"<"|"<="|">="|"=="|"!=" {printf("relational operater: %s\n", yytext);}
%%

int yywrap(){
	return 0;
}
int main(){
	yylex();
	return 0;
}
