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
	for(int i=0;i<n;i++){
	//	cout<<"enter priority,  arrival and brust time of process "<<i+1<<" :  ";
		cin>>p[i].pri>>p[i].at>>p[i].bt;
		p[i].ps=0;
	}
	int k=0, t=0, ct=0;
		
	while(k<n){
		int ind = findprocess(p, n, t);
		if(ind!=-1){
			p[ind].ct=ct+p[ind].bt;
			t=p[ind].ct;
			ct=t;
			p[ind].ps=1;
			k++;
		}
		else{
			t++;
			ct++;
		}
	}
		
	for(int i=0;i<n;i++){
		 cout<<p[i].ct<<" ";
	}
	//2 0 4 4 1 2 6 2 3 3 3 5 8 4 1 7 5 4
	
}

