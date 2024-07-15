#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cout<<"enter no. of processes: ";
	cin>>n;
	vector< pair<int, int> > t;
	for(int i=0;i<n;i++){
		cout<<"enter arrival and brust time of process "<<i+1<<" : "<<endl;
		int a,b; cin>>a>>b;
		t.push_back({a,b});
	}
	vector<int> ct(n);
	int prev=0;
	for(int i=0;i<n;i++){
		ct[i]=prev+t[i].second;
		prev=ct[i];
	}
	for(int i=0;i<n;i++){
		cout<<ct[i]<<" ";
	}
	vector<int>  tat(n);
	int sum1=0;
	for(int i=0;i<n;i++){
		tat[i]=ct[i]-t[i].first;
		sum1+=tat[i];
	}
	double avg_tat=(double)sum1/n;
	vector<int>  wt(n);
	sum1=0;
	for(int i=0;i<n;i++){
		wt[i]=tat[i]-t[i].second;
		sum1+=wt[i];
	}
	double avg_wt=(double)sum1/n;
	cout<<endl;
	cout<<"process id"<<"	"<<"arrival time"<<"	"<<"burst time"<<"	"<<"complete time"<<"	"<<"turn around time"<<"	"<<"waiting time"<<endl;
	for(int i=0;i<n;i++){
		cout<<i+1<<"		"<<t[i].first<<" 			"<<t[i].second<<"		"<<ct[i]<<"			"<<tat[i]<<"		"<<wt[i]<<endl;
	}	
	cout<<"average turn around time: "<<avg_tat<<endl;
	cout<<"average waiting time: "<<avg_wt<<endl;
	return 0;
}


