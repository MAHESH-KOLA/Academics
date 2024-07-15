%{
#include<stdio.h>
#include "bd.tab.h"
%}

%%
1	{yylval=1; return one;}
0	{yylval=0; return zero;}
[\n]	{return 0;}
.	{return 0;}
%%
int yywrap(){}