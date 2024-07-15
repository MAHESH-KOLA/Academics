#include<stdio.h>
#include<ctype.h>

void FIRST(char[], char);
void addToResultSet(char[],char);
int n;
char productionSet[10][10];
int main(){
	int i;
	char choice;
	char c;
	char result[20];
	printf("enter no. of productions: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		print("enter production n.: " i+1);
		scanf("%s", productionSet[i]);
	}
	do{
		printf("\n finf the First of :");
		scanf("%c",&c);
		FIRST(result,c);
		printf("\n FIRST(%c) = {", c);
		scanf
	}
	return 0;
}
