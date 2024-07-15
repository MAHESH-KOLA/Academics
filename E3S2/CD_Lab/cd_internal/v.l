%{
  int v=0;
  int c=0;
%}
%%
[aeiouAEIOU] {v++;}
[a-z A-Z] {c++;}
\n return 0;
%%
int yywrap(){}
int main()
{
	printf("enter he string of vowels and consonents");
	yylex();
	printf("no. of vowels=%d \n no of consonents=%d",v,c);
	return 0;
}

