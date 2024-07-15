%{
int length;
%}

%%
[a-zA-Z0-9]+ { 
    length = yyleng; 
    if (yytext[0] == 'a' && length == 3) {
        printf("%s\n", yytext);
    }
}
.           ;
%%

int yywrap(){

}
int main(){
    yylex();
    return 0;
}

