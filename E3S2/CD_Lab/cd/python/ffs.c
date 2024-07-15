//FIRST:

// #include <stdio.h>
// #include <stdlib.h>
// #include<ctype.h>
// #include <string.h>
// #include <string.h>

// char prod[10][10],result[20];
// int n;

// void addToResult(char c)
// {
// 	int i;
// 	for(i=0;result[i]!='\0';i++)
// 		if(result[i]==c) return;
// 	result[i]=c;
// }

// int first(char c)
// {
// 	if(c=='$')
// 	{
// 		addToResult(c);
// 		return 1;
// 	}

// 	if(c=='(' || c==')' || c=='*' || c=='+' || islower(c))
// 	{
// 		addToResult(c);
// 		return 0;
// 	}

// 	int x;
// 	for(int i=0;i<n;i++)
// 	{
// 		if(prod[i][0]==c)
// 		{
// 			for(int j=2;prod[i][j]!='\0';j++)
// 			{
// 				x=first(prod[i][j]);
// 				if(!x) break;
// 			}
// 		}
// 	}
// 	return x;
// }

// int main()
// {
// 	printf("Enter no.of prod's: ");
// 	scanf("%d",&n);

// 	printf("Enter prod's:\n");
// 	for(int i=0;i<n;i++) scanf(" %s",prod[i]);

// 	int choice;
//     do
//     {
//     	for(int i=0;i<20;i++) result[i]='\0';
    		
//     	char c;
//     	printf("First of ? : ");scanf(" %c",&c);
//     	int x=first(c);

//     	printf(" { ");
//     	for(int i=0;result[i]!='\0';i++) printf("%c, ",result[i]);
//     	printf(" }");

//         printf("Continue?(0/1) : ");scanf("%d",&choice);
//     }while(choice);
// }


//FOLLOW:
// #include<stdio.h>
// #include<stdlib.h>
// #include<ctype.h>
// #include<string.h>


// int n;
// char prod[10][10],result[20];

// void addToResult(char c)
// {
// 	int i;
// 	for(i=0;result[i]!='\0';i++)
// 		if(result[i]==c) return;
// 	result[i]=c;
// }

// int first(char c)
// {

// 	if(c=='$') {
// 		addToResult(c);
// 		return 1;
// 	}

// 	if(c=='(' || c==')' || c=='*' || c=='+' || islower(c))
// 	{
// 		addToResult(c);
// 		return 0;
// 	}

// 	int x;
// 	for(int i=0;i<n;i++)
// 	{
// 		if(prod[i][0]==c)
// 		{
// 			for(int j=2;prod[i][j]!='\0';j++)
// 			{
// 				x=first(prod[i][j]);
// 				if(!x) break;
// 			}
// 		}
// 	}
// 	return x;
// }

// void follow(char c)
// {
// 	if(prod[0][0]==c) {
// 		addToResult('$');
// 	}

// 	for(int i=0;i<n;i++)
// 	{
// 		for(int j=2;prod[i][j]!='\0';j++)
// 		{
// 			if(prod[i][j]==c)
// 			{
// 				int k;
// 				for(k=j+1;prod[i][k]!='\0';k++)
// 				{
// 					int x=first(prod[i][k]);
// 					if(!x) break;
// 				}
// 				if(prod[i][k]=='\0' && c!=prod[i][0]) follow(prod[i][0]);
// 			}
// 		}
// 	}
// }

// int main()
// {
// 	printf("Enter no.of prod's: ");scanf("%d",&n);

// 	printf("Enter prod's :\n");
// 	for(int i=0;i<n;i++)
// 		scanf(" %s",prod[i]);

// 	int choice;
// 	do
// 	{
// 		for(int i=0;i<20;i++) result[i]='\0';

// 		char c;
// 	    printf("\nFollow of ?: ");scanf(" %c",&c);
// 	    follow(c);

// 	    printf(" { ");
// 	    for(int i=0;result[i]!='\0';i++) printf("%c ,",result[i]);
// 	    printf(" }");

// 	    printf("\nContinue (0/1) :");scanf("%d",&choice);
// 	}while(choice);
// }



//SHIFT_REDUCE:
// #include<stdio.h>
// #include<string.h>
// #include<ctype.h>

// char prod[10][10],input[10];
// char stack[50];int top=-1,n;

// int checkForReduce()
// {
// 	if(top==-1) return 0;

// 	for(int i=0;i<n;i++)
// 	{
// 		int j=0;
// 		while(prod[i][j]!='\0') j++;
// 		j--;
// 		int k=top;
// 		while(k>=0 && prod[i][j]==stack[k])
// 		{
// 			j--;
// 			k--;
// 		}

// 		if(j==1)
// 		{
// 			top=k;
// 			k++;
// 			while(k<50) stack[k++]='\0';
// 			stack[++top]=prod[i][0];
// 			return 1;
// 		}
		
// 	}
// 	return 0;
// }

// int main()
// {
// 	printf("Enter no.of prod's: ");
// 	scanf("%d",&n);

// 	printf("Enter prod's :\n");
// 	for(int  i=0;i<n;i++) scanf("%s",prod[i]);

// 	printf("Enter the i/p string : ");
//     scanf("%s",&input);
    
//     int i=0;
//     while(input[i]!='\0')
//     {
//     	if(checkForReduce())
//     	{
//     		printf("Reduce Operation  ->    ");
//     		for(int i=0;i<=top;i++) printf("%c ",stack[i]);
//     		printf("\n");
//     	    continue;
//     	}

//     	stack[++top]=input[i];
//     	printf("Shift Operation  ->    ");
//     	for(int i=0;i<=top;i++) printf("%c ",stack[i]);
//     	printf("\n");
//         i++;
//     }
//     while(checkForReduce());
//     for(int i=0;i<=top;i++) printf("%c ",stack[i]);
//     printf("\n");

//     if(top==0 && stack[top]==prod[0][0])
//     	printf("Accepted!");
//     else printf("Rejected!!");
// }

/*GRAMMAR is -
E=2E2 
E=3E3 
E=4

stack      input      action
$    32423$    SHIFT
$3     2423$    SHIFT
$32      423$    SHIFT
$324       23$    REDUCE TO E -> 4
$32E       23$    SHIFT
$32E2        3$    REDUCE TO E -> 2E2
$3E        3$    SHIFT
$3E3         $    REDUCE TO E -> 3E3
$E         $    Accept
*/


