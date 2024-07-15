%{
#include<stdio.h>
int flag=0,c=0;
%}
%token '(' ')'
%%
e: s {}
    ;
s :  '(' s ')' {c+=1}
s :  ;
%%
void main()
{
yyparse();
printf("%d\n",c);
}
void yyerror(char *s)
{ 
}

