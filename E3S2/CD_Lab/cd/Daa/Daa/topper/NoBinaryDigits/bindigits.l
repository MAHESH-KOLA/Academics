%{
#include<stdio.h>
#include "bindigits.tab.h"
%}

%%
[0] {yylval=0; return zero;}
[1] {yylval=1; return one;}
. {return 0;}
%%

int yywrap(){return 1;}