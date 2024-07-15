%{
int charCount = 0;
int wordCount = 0;
int spaceCount = 0;
int tabCount = 0;
int lineCount = 0;
%}

%%
[a-zA-Z]+    { charCount += yyleng; wordCount++; }
" "          { spaceCount++; }
\t           { tabCount++; }
\n           { lineCount++; }
%%

int yywrap(){

}
int main() {
    yylex();
    printf("Character Count: %d\nWord Count: %d\nSpace Count: %d\nTab Count: %d\nLine Count: %d\n",
           charCount, wordCount, spaceCount, tabCount, lineCount);
    return 0;
}

