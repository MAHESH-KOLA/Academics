%{
#include<stdio.h>
int flag=0,c1=0;
%}
%token '(' ')'
%%
N : L '\n' {printf("valid");flag=1;return 0;}
    ;
L : L '(' L ')' {}
  | {}
   ;
%%
void main()
{
yyparse();
//printf("%d",c1);
}
void yyerror(char *s)
{printf("invalid");}


