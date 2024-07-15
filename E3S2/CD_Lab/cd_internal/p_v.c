%{
	#include<stdio.h>
	int vc=0, cc=0;
%}
%%
[aeiouAEIOU] {vc++;}
. {cc++;}
%%
yywrap(){return 1;}
int main(){
	printf("enter string: ");
	yylex();
	return 1;
}
