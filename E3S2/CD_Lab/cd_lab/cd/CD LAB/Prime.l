%{
#include<stdio.h>
int n,c,i;
%}

%%
[0-9]+ {n=atoi(yytext);
	c=0;
	for(i=1;i<=n;i++)
	{
	    if(n%i==0)
	      c++;
	}
	if(c==2)
	{
	    printf("%d is Prime Number",n);
	}
	else
	{
	    printf("%d is not a Prime",n);
	}
	}
%%
main()
{
    printf("Enter any number:");
    yylex();
}
int yywrap()
{
    return 1;
}