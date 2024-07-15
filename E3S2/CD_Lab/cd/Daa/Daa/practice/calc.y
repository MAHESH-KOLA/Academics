%{
#include <stdio.h>
int yylex();
int yyerror();
int temp=0;
%}

%token Number
%left '+''-'
%left '*''/''%'
%left '('')'

%%
A : E {printf("result:%d",$$);};
E : E '+' E {$$=$1+$3;};
|E '-' E {$$=$1-$3;};
|E '*' E {$$=$1*$3;};
|E '/' E {$$=$1/$3;};
|E '%' E {$$=$1%$3;};
|'('E')' {$$=$2;};
|Number{$$=$1;};
%%

int main()
{
printf("enter the expression:");
yyparse();
if(temp==0)
{
printf("valid expression");
}
}

int yyerror()
{
printf("invalid");
temp=1;
}