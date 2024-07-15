%{
%}
%%
manu {printf("bye");}
.* { printf("wrong");} 
%%
int yywrap(){

}
int main(){
    printf("enter the message");
    yylex();  
}
