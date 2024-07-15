%{
#include<stdio.h>
int yyerror(char *c);
%}

%token Num
%left '+' '-'
%left '*' '/' '%'
%left '(' ')'

%%
A : E	{printf("%d",$$);}
E : E '+' E {$$=$1+$3;}
E : E '-' E {$$=$1-$3;}
E : E '*' E {$$=$1*$3;}
E : E '/' E {$$=$1/$3;}
E : E '%' E {$$=$1%$3;}
E : Num	{$$=$1;}
%%

int main()
{
printf("Enter Expression");
yyparse();
}



int yyerror(char *c)
{
printf("%s",c);
}