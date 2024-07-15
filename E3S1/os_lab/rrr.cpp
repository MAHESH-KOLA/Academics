#include<bits/stdc++.h>
using namespace std;
struct process{
	int at, bt, ct, tat, wt, ps;
};

int push_process(process p[], int n){
	int mini=INT_MAX, ind=-1;
	for(int i=0;i<n;i++){
		if(p[i].at<mini and p[i].ps==0){
			mini=p[i].at;
			ind=i;
		}
	}
	return ind;
}

void completeTime(process p[], int n, int time){
	int remainingTime[n];
	for(int i=0;i<n;i++) remainingTime[i]=p[i].bt;
	int complete_time=0;
	bool isComplete=false;
	queue<int> q;
	while(!isComplete){
		isComplete=true;
		int ind=push_process(p,n,q,complete_time);
		for(int i=0;i<n;i++){
			if(remainingTime[i]>0){
			 isComplete=false;
			if(remainingTime[i]>time){
				complete_time+=time;
				remainingTime[i]-=time;
			}
			else{
				complete_time+=remainingTime[i];
				p[i].ct=complete_time;
				remainingTime[i]=0;
				p[i].ps=1;
			}
		}
		}
	}
}
int main(){
	int n;
	cout<<"enter no. of processes: ";
	cin>>n;
	process p[n];
	for(int i=0;i<n;i++){
		//cout<<"enter arrival and brust time of process "<<i+1<<" :  ";
		cin>>p[i].at>>p[i].bt;
		p[i].ps=0;
	}
	int  timeQuantum;
	cout<<"enter time limit: ";
	cin>>timeQuantum;
	
	completeTime(p, n, timeQuantum);
	

		for(int i=0;i<n;i++) cout<<p[i].ct<<" ";
	}
	//0 4 1 5 2 6 3 3 4 1 5 4




