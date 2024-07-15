%{
#include<stdio.h>
int n,s,i;
%}

%%
[0-9]+ {n=atoi(yytext);
	s=0;
	for(i=1;i<n;i++)
	{
	   if(n%i==0)
	     s=s+i;
	}
	if(s==n)
	{
	    printf("%d is Perfect Number",n);
	}
	else
	{
	    printf("%d is not a Perfect Number",n);
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