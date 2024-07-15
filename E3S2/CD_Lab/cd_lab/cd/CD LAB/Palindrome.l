%{
#include<stdio.h>
int n,r,s,temp;
%}

%%
[0-9]+ {n=atoi(yytext);
	temp=n;
	s=0;
	r=0;
	while(n>0)
	{
	   r=n%10;
	   s=(s*10)+r;
	   n=n/10;
	}
	if(s==temp)
	{
	   printf("Palindrome");
	}
	else
	{
	   printf("Not a palidrome");
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