%{
	int num_lines=0;
	int num_words=0;
	int num_chars=0;
%}

%%
\n {num_lines++;num_chars+=yyleng;}
[\t\n ] {num_words++;num_chars+=yyleng;}
[^\t\n ] {num_chars++;}
%%

int yywrap(){}

int main()
{
	yylex();
	printf("lines count is %d\n",num_lines);
	printf("characters count is %d\n",num_chars);
	printf("words count is %d\n",num_words);
}