#include<stdio.h>
#include<string.h>
struct pp{
char left[10];
char right[10];
};
int main()
{
	int i,j,k,stacklen,sublen,n,stacktop;
	char stack[20],temp[20],ch[2],input[20],*t1,*t2,*substring;
	struct pp rules[20];
	stack[0]='\0';
	printf("N=?");
	scanf("%d",&n);
	printf("grammer=?");
	for(i=0;i<n;i++)
{
	scanf("%s",temp);
	t1=strtok(temp,"->");
	t2=strtok(NULL,"->");
	strcpy(rules[i].left,t1);
	strcpy(rules[i].right,t2);
}
printf("input:?");
scanf("%s",input);
i=0;
while(1)
{
	if(i<strlen(input))
	{
		ch[0]=input[i];
		ch[1]='\0';
		i++;
		strcat(stack,ch);
		printf("%s\t",stack);
		for(k=i;k<strlen(input);k++)
		{
			printf("%c",input[k]);
		}
		printf("\tshift %s\n",ch);
	}
	for(j=0;j<n;j++)
	{
		substring=strstr(stack,rules[j].right);
		if(substring!=NULL)
		{
			stacklen=strlen(stack);
			sublen=strlen(substring);
			stacktop=stacklen-sublen;
			stack[stacktop]='\0';
			strcat(stack,rules[j].left);
		printf("%s\t",stack);
		for(k=i;k<strlen(input);k++)
		{
			printf("%c",input[k]);
		}
		printf("\treduce %s->%s\n",rules[j].left,rules[j].right);
		j=-1;
		}
	}
	if(strcmp(stack,rules[0].left)==0 && i==strlen(input))
	{
		printf("\naccepted");
		break;
	}
	if(i==strlen(input))
	{
		printf("\nnot accepted");
		break;
	}
}
}
	
