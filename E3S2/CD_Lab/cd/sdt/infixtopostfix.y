%{
#include<stdio.h>
int flag=0;
%}
%token id
%left '+' '-'
%left '/' '*' '%'
%left '(' ')'
%%
a:e{printf("\nresult = %d\n",$$);}
;
e:e'+'e{$$=$1+$3;printf("+");}
e:e'-'e{$$=$1-$3;printf("-");}
e:e'*'e{$$=$1*$3;printf("*");}
e:e'/'e{$$=$1/$3;printf("/");}
e:e'%'e{$$=$1%$3;printf("%");}
e:'('e')' {$$=$2;}
e:id {$$=$1;printf("%d",$1);}
;
%%
void main()
{
	printf("enter expression:");
	yyparse();
	if(flag==0)
	{
	printf("valid");
	}
}
void yyerror(char *s)
{
printf("invalid");
flag=1;
}


