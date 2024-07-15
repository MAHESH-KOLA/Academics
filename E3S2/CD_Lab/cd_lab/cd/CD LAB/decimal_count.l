%{
#include<stdio.h>
int floatc=0,intc=0;
%}

%%
[0-9]+"."[0-9]+ {ECHO; printf("Decimal Number"); floatc++;}
[0-9]+ {ECHO; printf("Integer");intc++;}
%%
int main()
{
    printf("Enter any number:");
    yylex();
    printf("Decimal count=%d\nInteger count=%d",floatc,intc);
    return 0;
}
int yywrap()
{
    return 1;
}