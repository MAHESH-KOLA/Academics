%{
#include<stdio.h>
%}
%%
int|float|printf|for	{printf("%s is Keyword\n",yytext);}
[+\-/*%^=]	{printf("%s is operator\n",yytext);}
[<>\[\]{}();,]	{printf("%s is special character\n",yytext);}
[0-9]*"."[0-9]+	{printf("%s is constant\n",yytext);}
[0-9]+		{printf("%s is constant\n",yytext);}
[a-zA-Z_][a-zA-Z0-9]*	{printf("%s identifier\n",yytext);}
[\t\n]	{}
.	{printf("%s is unidentified character\n",yytext);}
%%

int yywrap(){}

int main()
{
yylex();
}