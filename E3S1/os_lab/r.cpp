#include<bits/stdc++.h>
using namespace std;
struct process{
	int at, bt, ct, tat, wt, ps;
};

int findmin(process p[], int n){
	int mini=INT_MAX, ind=-1;
	for(int i=0;i<n;i++){
		if(p[i].at<mini and p[i].ps==0){
			mini=p[i].at;
			ind=i;
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
		cout<<"enter arrival and brust time of process "<<i+1<<" :  ";
		cin>>p[i].at>>p[i].bt;
		p[i].ps=0;
	}
	int  time_limit;
	cout<<"enter time limit: ";
	cin>>time_limit;
	
	int ct=0;
	int ind=findmin(p, n);
	queue<int> q;
	q.push(ind);
	ct=ct+p[ind].at;
	
	while(!q.empty()){
		int top=q.front();
		if(p[top].bt==0 and p[top].ps==0){
			if(p[top].bt>=time_limit){
			ct=ct+time_limit;
			p[top].bt=p[top].bt-time_limit;
			if(p[top].bt==0){
				p[top].ct=ct;
				p[top].ps=1;
			}
		}
		else{
			ct=ct+p[top].bt;
			p[top].bt=0;
				p[top].ct=ct;
				p[top].ps=1; 
		}
		}   //?
		q.pop();
			int ind=findmin(p, n);
			if(ind!=-1){
			q.push(ind);
		}
			if(p[top].bt!=0){
				q.push(top);
			}
			
		}
		
		for(int i=0;i<n;i++) cout<<p[i].ct<<" ";
	}


