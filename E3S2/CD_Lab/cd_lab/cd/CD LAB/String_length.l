%{
#include<stdio.h>
int length;
int fun(int);
%}

%%
[A]+[a-zA-Z0-9]+ {length=yyleng;
		   fun(length);}
%%
main()
{
    printf("Enter any string:");
    yylex();
}
fun(int length)
{
    if(length==3)
      printf("\nString of length 3 is: %s",yytext);
    else
      printf("\nStrinf of length greater than 3 is: %s",yytext);
    return 0;
}
int yywrap()
{
   return 1;
}