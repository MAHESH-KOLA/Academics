%{
#include <stdio.h>
int yylex();
int yyerror();
int temp=0;
%}

%token Number
%left '+' '-'
%left '*' '/' '%'
%left '(' ')'
%%
A : E {printf("result:%d",$$);};
E : E '+' E {$$=$1+$3;}
|E '-' E {$$=$1-$3;}
|E '*' E {$$=$1*$3;}
|E '%' E {$$=$1%$3;}
|E '/' E {$$=$1/$3;}
|'('E')' {$$=$2;}
|Number {$$=$1;};
%%
int main()
{
printf("enter expression:");
yyparse();
if(temp==0)
{
printf("valid expresion");
}
}

int yyerror()
{
printf("it is not valid");
temp=1;
}