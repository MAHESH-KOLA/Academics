#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>
#include<string.h>
int size;
int m;
char result[20];
char productionSet[10][10];

void follow(char ch){
	
	if(productionSet[0][0] == ch){
		addToresultSet('$');
	}	
	
	int i,j;
	
	for(i = 0; i < size; i++){
		
		for(j = 2; productionSet[i][j] != '\0'; j++){
			
			if(productionSet[i][j] == ch){
				
				if(productionSet[i][j + 1] != '\0'){
					first(productionSet[i][j + 1]);
				} else {
					
					if(productionSet[i][0] != ch){
						follow(productionSet[i][0]);
					}
				}
					
			}	
			
		}	
		
	}
	
}

void first(char ch){
	
	if(!(isupper(ch))){
		addToresultSet(ch);
	}	
	
	int i,j;
	
	for(i = 0; i < size; i++){
		
		if(productionSet[i][0] == ch){
			
			if(productionSet[i][2] == '#'){
				follow(productionSet[i][0]);
			} else {
				first(productionSet[i][2]);
			}
			
		}	
		
	}
	
}

void addToresultSet(char ch){
	
	int k = 0;
	
	for(k = 0; k < m; k++){
		if(result[k] == ch) return;
	}
	
	result[m ++] = ch;
	
}

void main(){
	
	printf("Enter the number of productions: ");
	scanf("%d",&size);
	
	int i;
	
	for(i = 0; i < size; i++){
		printf("Enter the production %d: ", i + 1);
		scanf("%s",productionSet[i]);
	}
	
	
	char choice,c;
	
	do{
		m = 0;
		printf("Follow of : ");
		
		while(getchar() != '\n');
		
		scanf("%c",&c);
		
		follow(c);
		
		printf("Follow (%c) : { ",c);
		
		for(i = 0; i < m; i++){
			printf("%c ",result[i]);
		}
		printf(" }\n");
		
		printf("Do you want to continue Y/N? ");
		
		while(getchar() != '\n');
		
		scanf("%c",&choice);
		
			
		
	} while(choice == 'y'|| choice == 'Y');
	
	
}
