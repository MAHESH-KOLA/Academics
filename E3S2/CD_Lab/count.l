%{
	int lc=0,sc=0,tc=0,ch=0,c=0,wc=0;
%}
%%
($) return 0;
\n {lc++;}
([ ])+ {sc++;}
\t {tc++;}
. {ch++;c++;}
[a-zA-Z0-9]+ {wc++;c=c+yyleng;}
%%
int yywrap(){}
int main()
{
	yylex();
	printf("lines count is %d\n", lc);
	printf("spaces count is %d\n", sc);
	printf("tabs count is %d\n", tc);
	printf("characters count is %d\n", c);
	printf("words count is %d\n", (wc+ch));
}
