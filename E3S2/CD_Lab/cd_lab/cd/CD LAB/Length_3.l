%{
#include<stdio.h>
int length;
int fun(int);
%}

%%
[a-zA-Z0-9]+ {length=yyleng;fun(length);}

%%
int fun(int length)
{
    if(yytext[0]=='A'||yytext[0]=='a')
    {
       if(length==3)
         printf("%s is a word starts with A and length 3",yytext);
    }
    return 0;
}
main()
{
    printf("Enter any String:");
    yylex();
}
int yywrap()
{
    return 1;
}