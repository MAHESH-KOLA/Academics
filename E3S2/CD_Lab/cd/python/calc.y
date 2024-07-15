%{
	#include<stdio.h>
	int flag=1;
%}

%token NUMBER
%left '+''-'
%left '*''/''%'
%left '('')'

%%
ArithmeticExpression:E{printf("\nResult=%d\n",$$);return 0;}

E:E'+'E{$$=$1+$3;}
|E'-'E{$$=$1-$3;}
|E'*'E{$$=$1*$3;}
|E'/'E{$$=$1/$3;}
|E'%'E{$$=$1%$3;}
|'('E')'{$$=$2;}
|NUMBER{$$=$1;}
;
%%

void main()
{
	printf("\nEnter Expression: ");
	yyparse();
	if(flag==1){
	printf("Valid\n");
	}
}

void yyerror()
{
	printf("Invalid\n");
	flag=0;
}
