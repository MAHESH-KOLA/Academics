%{
	#include<stdio.h>
 	int vc=0, cc=0;
%}
%%
[aeiouAEIOU] {vc++;}
[a-zA-Z] {cc++;}
\n return 0;
%%
int yywrap(){return 1;}
int main(){
	printf("enter string: ");
	yylex();
	printf("%d %d", vc, cc);
	return 1;
}
