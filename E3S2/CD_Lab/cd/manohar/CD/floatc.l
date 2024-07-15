
%{
#include<stdio.h>
	int ic=0;
	int fc=0;
%}
%%
[0-9]+ {printf("Interger");ic++;}
[0-9]+"."[0-9]+ {printf("Float");fc++;}
%%
	int yywrap(){
	return 1;}
	int main()
	{
		printf("Enter the numbers");
		yylex();
		printf("Count of intergers=%d\n",ic);
		printf("Count of float numbers=%d\n",fc);
		return 0;
	}	
