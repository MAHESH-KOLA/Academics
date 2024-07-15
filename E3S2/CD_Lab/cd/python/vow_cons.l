%{
   int vc=0;
   int cc=0;
%}

%%
[aeiouAEIOU] {vc++;}
[^aeiouAEIOU] {cc++;}
%%

int yywrap(){}

int main()
{
   printf("Enter the string: ");
   yylex();
   printf("No.of vowels: %d\nNo.of consonants: %d\n",vc,cc);
   return 0;
}
