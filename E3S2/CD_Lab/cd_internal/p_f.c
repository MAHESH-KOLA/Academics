#include<stdio.h>
#include<ctype.h>
void FIRST(char[], char);
void addToResultSet(char[], char);
int n;
char productions[20][20];
int main() {
	int i;
	char c, choice;
	char result[20];
	printf("enter no. of productions: ");
	scanf(" %d", &n);
	for(i=0;i<n;i++){
		scanf(" %s", &productions[i]);
	}
	do{
		printf("enter non terminal to find first: ");
		scanf(" %c",&c);
		FIRST(result, c);
		for(i=0;result[i]!='\0';i++){
			printf(" %c ", result[i]);
		}
		printf("\n");
		printf("enter y/Y to continue... ");
		scanf(" %c",&choice);
	}while(choice=='Y' || choice=='y');
}

void FIRST(char result[20], char c){
	int i, j, k;
	int foundEpsilon=0;
	char subresult[20];
	result[0]="\0";
	subresult[0]="\0";
	if(!(isupper(c))){
		addToResultSet(result, c);
		return;
	}
	
	for(i=0;i<n;i++){
		if(productions[i][0]==c){
			if(productions[i][2]=='$')
			  addToResultSet(result, '$');
			else{
				j=2;
				while(productions[i][j]!='\0'){
					foundEpsilon=0;
					FIRST(subresult, productions[i][j]);
					for(k=0;subresult[k]!='\0';k++){
						addToResultSet(result, subresult[k]);
					}
					for(k=0;subresult[k]!='\0';k++){
						if(subresult[k]=='$'){
							foundEpsilon=1;
							break;
						}
					}
						if(foundEpsilon==0) break;
						j++;
					}
				}
			}
		}
		return;
}

void addToResultSet(char result[20], char c){
	int k;
	for(k=0;result[k]!='\0'; k++){
		if(result[k]==c)
		 break;
	}
	result[k]=c;
	result[k+1]='\0';
}
