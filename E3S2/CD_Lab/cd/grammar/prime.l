%{
	#include<stdio.h>
	int n,f=0,i;
%}

%%
[0-9]+ {n=atoi(yytext);
		for(i=2;i*i<=n;i++){
		if(n%i==0){
		f=1;
		break;
		}
		}
		}
\n {return 0;}
.* {printf("invalid"); return 1;}
%%

int yywrap(){
	return 1;
}

int main(){
	yylex();
	if(f==0){
	printf("prime");
	}
	else{
	printf("not prime");
	}
	return 0;
}