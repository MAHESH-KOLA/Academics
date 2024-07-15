%{
#include<stdio.h>
int yyerror(char *c);
int cnt=0;
%}

%token lp rp

%%
A : E	{printf("%d",$$);return 0;}
E : lp E rp E {cnt++;$$=cnt;}
E :	{$$=0;}
%%

int main()
{
printf("Enter Expression:");
yyparse();
return 0;
}

int yyerror(char *c)
{
printf("%s",c);

}
