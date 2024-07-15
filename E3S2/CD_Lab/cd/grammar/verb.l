%{
	#include<stdio.h>
	#include<string.h>
	int v=0, n=0,f=0,i;
%}
%%
[a-zA-Z0-9]+ {fun(yytext);}
%%
fun(char* s){
	char* verbs[2];
	verbs[0]="coming";
	verbs[1]="going";
	printf("%s ",s);
	for(i=0;i<2;i++){
		n=strcmp(verbs[i],s);
		if(n==0){
			f=1;
			break;
		}
	}
	if(f==1) printf("verb\n");
	else printf("not verb\n");
}
int yywrap(){
	return 1;
}
int main(){
	yylex();
	return 1;
}
