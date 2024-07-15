%{
	int i=0,f=0;
%}
%%
[0-9]+"."[0-9]+ {f++;}
[0-9]+ {i++;}
\n return 0;
%%
int yywrap()
{return 1;}
int main(){
yylex();
printf("Float :%d \n Int : %d",f,i);
return 0;
}
