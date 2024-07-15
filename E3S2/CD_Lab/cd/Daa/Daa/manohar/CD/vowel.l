
%{
#include<stdio.h>
	int vc=0;
	int cc=0;
%}
%%
[aeiouAEIOU] {vc++;}
[a-zA-z] {cc++;}
%%
	int yywrap(){
	return 1;}
	int main()
	{
		printf("Enter the string of vowels and consonants ");
		yylex();
		printf("No.of vowels=%d\n",vc);
		printf("No.of consonants=%d\n",cc);
		return 0;
	}	
