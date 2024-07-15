%{
	#include<stdio.h>	
	int n;
%}
%%
[+-]?[0-9]+ {n=atoi(yytext); 
		if(n<0) printf("Negative");
		 else printf("Positive");}
.* {printf("Invalid input");}
%%
int yywrap(){
	return 1;
}
int main(){
	yylex();
	return 1;
}