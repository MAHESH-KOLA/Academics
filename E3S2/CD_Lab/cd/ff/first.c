#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>

char productionSet[10][10];
int size;
void first(char *,char);
void addToresultSet(char *,char);

void first(char *result,char c){
	
	result[0] = '\0';
	char subresult[10];
	subresult[0] = '\0';
	
	if(!(isupper(c))){
		addToresultSet(result,c);
		return;
	}	
	
	int i = 0;
	
	for(i = 0; i < size; i++){
		
		if(productionSet[i][0] == c){
		
			if(productionSet[i][2] == '$'){
				addToresultSet(result,'$');
				return;
			} else{
				
				int j = 2;
				
				while(productionSet[i][j] != '\0'){
					
					first(subresult,productionSet[i][j]);
					
					int k;
					for(k = 0; subresult[k] != '\0'; k++){
						addToresultSet(result,subresult[k]);
					}		
					
					bool foundepsilon = false;
					
					for(k = 0; subresult[k] != '\0'; k ++){
						
						if(subresult[k] == '$'){
							foundepsilon = true;
							break;
						}	
							
					}
					
					if(!foundepsilon){
						break;
					}
						
					j ++;
				}
				
			}
			
		} 	
		
	}
	
	return;
	
}

void addToresultSet(char result[],char ch){
	
	int k;
	
	for(k = 0; result[k] != '\0'; k++){
		
		if(result[k] == ch){
			return;
		}	
		
	}	
	
	result[k] = ch;
	result[k + 1] = '\0';
}

void main(){
	
	printf("Enter the number of productions: ");
	scanf("%d",&size);
	
	int i;
	for(i = 0; i < size; i++){
		printf("Enter the production %d: ",i + 1);
		scanf("%s",productionSet[i]);	
	}
	
	char choice,c;
	char result[20];
	
	do{
	
		printf("First of: ");
		
		while(getchar() != '\n');
		
		scanf("%c",&c);
		
		first(result,c);
		
		printf("First (%c) { ",c);
		int k = 0;
		
		for(k = 0; result[k] != '\0'; k++){
			printf("%c ",result[k]);
		}
		
		printf("}\n");
		
		printf("Do you want to continue Y/N ?");
		
		while(getchar() != '\n');
		
		scanf("%c",&choice);
		
	} while(choice == 'y' || choice == 'Y');
	
	

}
	
