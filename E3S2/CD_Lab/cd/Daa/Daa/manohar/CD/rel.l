%{
#include <stdio.h>
%}

%%
[<>=!]=?    { printf("Relational operator: %s\n", yytext); }
.*      { printf("entered wrong"); }
%%
int yywrap(){
}
int main() {
    printf("Enter an operator: ");
    yylex();
    return 0;
}

