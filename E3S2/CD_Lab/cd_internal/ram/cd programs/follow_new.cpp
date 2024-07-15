#include<stdio.h>
#include<string.h>
#include<ctype.h>

void first(char c);
void follow(char c);
void addtoresult(char);
int result[20];
char prodset[20][20];
int noofprod;
int m;

int main(){
	int i,j;
	char choice,c;
	printf("enter no of productions:");
	scanf("%d",&noofprod);
	//scanf("%d",&noofprod);
	
	for(i=0;i<noofprod;i++){
	  printf("enter production rule %d",i+1);
	  scanf("%s",prodset[i]);
	}
	
	do{
		m=0;
		printf("find follow of : ");
		scanf("%c",&c);
		scanf("%c",&c);
		follow(c);
		printf("follow(%c) {",c);
		for(i=0;i<m;i++){
			printf("%c ",result[i]);
		}	
		printf("}\n");
		printf("do you want to continue?(y or n)");
		scanf("%c",&choice);
		scanf("%c",&choice);
	}while(choice == 'y' || choice == 'Y');
}


void follow(char c){
	int k,i;
	if(prodset[0][0] == c) addtoresult('$');
	for(i=0;i<noofprod;i++){
		for(k=2;k<strlen(prodset[i]);k++){
		 if(prodset[i][k] == c){
			if(prodset[i][k+1] == '\0') follow(prodset[i][0]);
			if(prodset[i][k+1] != '\0') first(prodset[i][k+1]);
		 }
	   }
	}
}

void first(char c){
	int k;
	if(!(isupper(c))) addtoresult(c);
	for(k=0;k<noofprod;k++){
		if(prodset[k][0] == c){
		  	if(prodset[k][2] == '$') follow(prodset[k][0]);
			else if(islower(prodset[k][2])) addtoresult(prodset[k][2]);
			else first(prodset[k][2]);
		}
	}
}

void addtoresult(char c){
	int k;
	for(k=0;k<=m;k++)
	if(result[k]==c)
	return;
	result[m++] = c;
}
