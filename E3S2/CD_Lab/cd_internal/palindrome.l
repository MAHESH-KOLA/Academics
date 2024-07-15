%{
	#include<stdio.h>
	int i,j, f;
%}

%%
[a-zA-Z0-9]* {i=0; j=yyleng-1,f=1;
				while(i<=j){
				printf("%c ", yytext[i]);
					if(yytext[i]!=yytext[j]){
						f=0;
						break;
					}
					i++; j--;
				}
				if(f==1){printf("Plindrome"); }
				else{ printf("Not palindrome"); }
			}
%%
int yywrap(){
	return 1;
}
int main(){
	yylex();
	return 1;
}
