%{
#include<stdio.h>
int yyerror(char *c);
%}

%token Num
%left '+' '-'
%left '*' '/' '%'
%left '(' ')'

%%
A : E	{printf("valid");}
E : E '+' E	{}
E : E '-' E	{}
E : E '*' E	{}
E : E '/' E	{}
E : E '%' E	{}
E : '(' E ')'	{}
E : Num	{}
%%

int main()
{
printf("Enter Expression");
yyparse();
return 0;
}

int yyerror(char *c)
{
printf("%s",c);
}
