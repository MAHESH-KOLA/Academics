%{
  int m;
%}
%%  
[0-9]+ {
  m=atoi (yytext);
    if(m%2==0){
       printf("even number");
    }
    else{
       printf("odd number");
    }
}
.* { printf("invalid number");}
%%
int yywrap(){

}
int main(){
   printf("enter the number ");
   yylex();
return 0;
}
