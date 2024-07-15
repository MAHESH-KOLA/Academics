%{
#include <stdio.h>
void yyerror(char *s);
int flag = 0;
%}
%token '(' ')' '\n'
%%
N : L '\n' {printf("Valid\n");flag = 1;return 0;}
;
L : L '(' L ')' {}
|  {}
;
%%
void main()
{
   printf("Enter the string : ");
   yyparse();
   if(flag == 0) printf("Invalid");
}
void yyerror(char *s)
{

}
