%{
#include<stdio.h>
%}

%%
">"|"<"|">="|"<="|"=="|"!=" {printf("Relational operators is %s",yytext);}

.* {printf("%s is Not a relational operator",yytext);}
%%

main()
{
    printf("Enter any input:");
    yylex();
}
int yywrap()
{
    return 1;
}