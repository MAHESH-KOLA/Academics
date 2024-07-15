%{
#include<stdio.h>
void yyerror(char *s);
int flag=0;
%}
%token id
%left '+' '-'
%left '/' '*'
%left '(' ')'
%%
e1:e{printf("valid");flag=1;printf("%d",$$);}
;
e:e'+'e {$$=$1+$3;}
e:e'-'e{$$=$1-$3;}
e:e'*'e {$$=$1*$3;}
e:e'/'e {$$=$1/$3;}
e:'('e')' {$$=$2;}
e:id {$$=$1;}
;
%%
int main()
{
	yyparse();
	//if(flag==1)
	//printf("valid");
}
void yyerror(char *s)
{
printf("invalid");
}
