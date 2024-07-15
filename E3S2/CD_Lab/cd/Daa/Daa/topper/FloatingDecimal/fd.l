%{
#include<stdio.h>
int f=0,d=0;
%}


%%
[0-9]+"."[0-9]+	{printf("FloatingNumber\n");f++;}
[0-9]+	{printf("Decimal\n");d++;}
%%
int main()
{
printf("Enter numbers:");
yylex();
printf("Float:%d,Decimal:%d",f,d);
return 0;
}
int yywrap(){}