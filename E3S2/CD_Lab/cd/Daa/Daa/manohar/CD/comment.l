%{
#include<stdio.h>
%}

%%
\/\/.* {}
\/\*(.*\n)*.*\*\/ {}
%%

int yywrap(){

}
int main(){
	yyin = fopen("inp.txt","r");
	yyout = fopen("out.txt","w");
	yylex();
	return 0;
}
