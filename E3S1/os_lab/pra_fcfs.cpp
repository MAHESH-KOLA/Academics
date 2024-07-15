#include<bits/stdc++.h>
using namespace std;
struct process
{
	int at,bt,ct,tat,wt,c;
};

int findprocess(process* p,int n,int t)
{
	int min=99999,index=-1;
	for(int i=0;i<n;i++)
	{
		if(p[i].at<=t && p[i].c==0)
		{
			if(p[i].at<min)
			{
				min=p[i].at;
				index=i;
			}
		}
	}
	return index;
}
	
main()
{
	int n,t=0,ct=0,k=0, index;
	printf("enter nuber of precosses");
	cin>>n;
	process *p;
	p=(struct process*)malloc(n*sizeof(struct process));
	printf("enter processes detailes ");
	for(int i=0;i<n;i++)
	{
		cin>>p[i].at>>p[i].bt;
		p[i].c=0;
	}
	
	while(k<n)
	{
		index=findprocess(p,n,t);
		if(index!=-1)
		{
			p[index].c=1;
			p[index].ct=ct+p[index].bt;
		//	p[index].tat=p[index].ct-p[index].at;
		//	p[index].wt=p[index].tat-p[index].bt;
			t=p[index].ct;
			ct=t;
			k=k+1;
		}
		else
		{
			t=t+1;
			ct=ct+1;
		}
	}
	
	for(int i=0;i<n;i++)
	{
		cout<<p[i].at<<"		"<<p[i].bt<<"		"<<p[i].ct<<"		"<<p[i].tat<<"		"<<p[i].wt<<endl;;
	}
}
	
	
	
	
