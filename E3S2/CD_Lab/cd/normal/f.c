#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
int i=0,j=0,n,k=0,m=0;
char a[10][10],f[10];
void first(char c);
void follow(char c);
int main()
{
	int z;
	char c,ch;
	printf("enter no of productions");
	scanf("%d",&n);
	printf("enter productions");
	for(i=0;i<n;i++)
	scanf("%s%c",a[i],&ch);
	do{
	m=0;
	printf("enter input character");
	scanf("%c",&c);
	follow(c);
	printf("Follow(%c)={",c);
	for(i=0;i<m;i++)
	printf("%c",f[i]);
	printf("}");
	
	printf("continue(0/1)?");
	scanf("%d%c",&z,&ch);
	}while(z==1);
return 0;
}
void first(char c)
{
	int k;
	if(!isupper(c))
	f[m++]=c;
	for(k=0;k<n;k++)
	{
		if(a[k][0]==c)
		{
			if(a[k][2]=='$')
			//f[m++]='$';
			follow(a[k][0]);
			else if(islower(a[k][2]))
			f[m++]=a[k][2];
			else
			first(a[k][2]);
		}
	}
}
void follow(char c)
{
	if(a[0][0]==c)
	f[m++]='$';
	for(i=0;i<n;i++)
	{
		for(j=2;j<strlen(a[i]);j++)
		{
			if(a[i][j]==c)
			{
				if(a[i][j+1]!='\0')
				first(a[i][j+1]);
				 if(a[i][j+1]=='\0' && c!=a[i][0])
				follow(a[i][0]);
			}
		}
	}
}
	
	
