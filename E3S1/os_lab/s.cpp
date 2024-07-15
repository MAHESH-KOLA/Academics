#include<bits/stdc++.h>
using namespace std;

struct process{
	int at, bt, ct, st;
};
int findprocess(process p[], int n, int time){
	int mini=INT_MAX, ind=-1;
	for(int i=0;i<n;i++){
		if(p[i].at<=time and p[i].st==0){
			if(p[i].bt<mini){
				mini=p[i].bt;
				ind=i;
			}
		}
	}
	return ind;
}
int main(){
	int n;
	cin>>n;
	process p[n];
	for(int i=0;i<n;i++){
		cin>>p[i].at>>p[i].bt;
		p[i].st=0;
	}
	int ct=0, t=0, k=0;
	while(k<n){
		int index=findprocess(p, n, t);
		if(index!=-1){
			p[index].ct=ct+p[index].bt;
			ct=p[index].ct;
			t=ct;
			p[index].st=1;
			k++;
		}
		else{
			t=t+1;
			ct=ct+1;
		}
	}
		for(int i=0;i<n;i++){
		cout<<p[i].ct<<" ";
	}
	
	return 0;
}
