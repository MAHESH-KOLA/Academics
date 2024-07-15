%{
#include<stdio.h>
#include "validpar.tab.h"
%}

%%
[\(]	{return lp;}
[\)]	{return rp;}
[\n]	{return 0;}
%%

int yywrap(){}