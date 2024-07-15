%{
#include<stdio.h>
int yylex();
int yyerror(char *c);
%}



%token zero one

%%
start : N {printf("The Result : %d", $1);}
N:N D {$$=$1+$2;}
N : D {$$=$1;}
D : zero {$$=1;}
D : one {$$=1;}
;
%%

int main()
{
printf("Enter the binay Number::");
yyparse();
return 0;
}


int yyerror(char *c)
{
printf("Invalid inputs");
printf("%s", c);
return 0;
}
