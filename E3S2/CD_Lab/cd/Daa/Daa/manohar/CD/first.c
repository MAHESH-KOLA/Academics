#include<stdio.h>
#include<ctype.h>
int n;
char productionset[10][10];
void first(char *result,char c)
{
	int i,j,k;
	char subresult[20];
	int foundepsi;
	subresult[0]='\0';
	result[0]='\0';
	if(!(isupper(c)))
	{
		addToResultSet(result,c);
		return;
	}
	for(i=0;i<n;i++)
	{
		if(productionset[i][0]==c)
		{
			if(productionset[i][2]=='$')
			addToResultSet(result,'$');
			else
			{
				j=2;
				while(productionset[i][j]!='\0')
				{
					foundepsi=0;
					first(subresult,productionset[i][j]);
					for(k=0;subresult[k]!='\0';k++)
					addToResultSet(result,subresult[k]);
					for(k=0;subresult[k]!='\0';k++)
					if(subresult[k]=='$')
					{
						foundepsi=1;
						break;
					}
					if(!foundepsi)
					break;
					j++;
				}
			}
		}
	}		
		return ;
}						

void addToResultSet(char result[],char val)
{
	int k;
	for(k=0;result[k]!='\0';k++)
	if(result[k]==val)
	return;
	result[k]=val;
	result[k+1]='\0';
}
	



int main()
{
	int i;
	char choice,c;
	char result[20];
	printf("How many no.of productions? ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter productions num %d :",i+1);
		scanf(" %s",productionset[i]);
	}
	do
	{
		printf("\n First of :");
		scanf(" %c",&c);
		first(result,c);
		printf("\n First(%c)= { ",c);
		for(i=0;result[i]!='\0';i++)
		printf(" %c ",result[i]);
		printf("}\n");
		printf("press y to continue :");
		scanf(" %c",&choice);
	}
	while(choice=='y' || choice=='Y');
}			
