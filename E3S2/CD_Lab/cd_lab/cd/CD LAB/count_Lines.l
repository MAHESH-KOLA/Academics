%{
#include<stdio.h>
int ch=0,word=0,line=0,space=0,tab=0;
%}

%%
[\n] {line++; ch++;}
[\t] {tab++; ch++;}
([ ]) {space++; ch++;}
[a-zA-Z0-9]+ {word++; ch=ch+yyleng;}

%%
int main()
{
   printf("Enter any string:");
   yylex();
   printf("\nTotal Lines:%d",line);
   printf("\nTotal Tab Spaces:%d",tab);
   printf("\nTotal Spaces:%d",space);
   printf("\nTotal Words:%d",word);
   printf("\nTotal Characters:%d",ch);
}
int yywrap()
{
   return 1;
}