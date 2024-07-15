%{
	#include<stdio.h>
	int n;
%}
%%
[0-9]+ {n=atoi(yytext);
if(n%2==0) { 
printf("even");
}
else{
	printf("Odd");
}
}
.* { printf("invalid number");}
%%
int yywrap(){
	return 1;
}
int main(){
	yylex();
}
