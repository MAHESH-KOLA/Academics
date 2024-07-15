%{
#include <stdio.h>
%}

%%
[A][A-Za-z][A-Za-z][ ]    { printf("%s\n", yytext); }
. ;
%%

int yywrap(){return 1;}

int main() {
    yylex();
    return 0;
}
