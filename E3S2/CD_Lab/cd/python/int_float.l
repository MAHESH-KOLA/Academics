%{
	int num_int=0;
	int num_float=0;
%}

%%
[0-9]+ {printf("Integer\n");num_int++;}
[0-9]+"."[0-9]+ {printf("Decimal Num\n");num_float++;}
%%

int yywrap(){return 1;}

int main()
{
	yylex();
	printf("no.of Integers: %d\nno.of Floating: %d",num_int,num_float);
	return 0;
}