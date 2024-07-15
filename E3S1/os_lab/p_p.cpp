#include<bits/stdc++.h>
using namespace std;
struct process{
	int pri, at, bt, ct, tat, wt, ps;
};

int findprocess(struct process p[], int n, int t){
	int ind=-1, pri=100;
	for(int i=0;i<n;i++){
		if(p[i].at<=t and p[i].ps==0){
			if(p[i].pri<pri){
				ind=i;
				pri=p[i].pri;
			}
		}
	}
	return ind;
}
int main(){
	int n;
	cout<<"enter no. of processes: ";
	cin>>n;
	process p[n];
	int bt[n];
	for(int i=0;i<n;i++){
	//	cout<<"enter priority,  arrival and brust time of process "<<i+1<<" :  ";
		cin>>p[i].pri>>p[i].at>>p[i].bt;
		bt[i]=p[i].bt;
		p[i].ps=0;
	}
	int k=0,t=0;
		
	while(k<n){
		int ind = findprocess(p, n, t);
		if(ind!=-1){
			cout<<"P"<<" ";
			p[ind].bt=p[ind].bt-1;
			if(p[ind].bt==0){
			t++;
			p[ind].ct=t;
			t=p[ind].ct;
			p[ind].ps=1;
			k++;
		
			}
			else{
			t++;	
			}
		}
		else{
			t++;
		}
	}
		
	for(int i=0;i<n;i++){
		 cout<<p[i].ct<<" ";
	}
	//2 0 4 4 1 2 6 2 3 1 3 5 8 4 1 3 5 4 2 11 6
	
}

