%option noyywrap
%{
#include<stdio.h>
#include "iop.tab.h"
%}

%%
[0-9]+	{yylval=atoi(yytext); return Num;}
[\t]	{}
[\n]	{return 0;}
.	{return yytext[0];}
%%
