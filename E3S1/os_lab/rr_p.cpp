#include<bits/stdc++.h>
using namespace std;

struct process{
	int pid, pri, at, bt, ct, tat, wt, ps;
};
void sort(struct process p[], int n){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(p[i].at>p[j].at){
				int t=p[i].pid;
				p[i].pid=p[j].pid;
				p[j].pid=t;
				
				t=p[i].at;
				p[i].at=p[j].at;
				p[j].at=t;
				
				t=p[i].bt;
				p[i].bt=p[j].bt;
				p[j].bt=t;
				
			}
		}
	}
}
int findprocess(struct process p[], int n, int t, queue<int> &q){
	int ind=-1, mini=t;
	for(int i=0;i<n;i++){
		if(p[i].at<=mini and p[i].ps==0){
				ind=i;
				mini=p[i].at;
			}
		}
	 for(int i=ind; i<n;i++){
	 	if(p[i].at<t and p[i].ps==0 ) q.push(i);
	 	else break;
	 }
	return ind;
}
int main(){
	int n, tq;
	cout<<"enter no. of processes: ";
	cin>>n;
	cout<<"enter time quantum: ";
	cin>>tq;
	process p[n];
	int bt[n];
	for(int i=0;i<n;i++){
	//	cout<<"enter priority,  arrival and brust time of process "<<i+1<<" :  ";
		cin>>p[i].pid>>p[i].at>>p[i].bt;
		bt[i]=p[i].bt;
		p[i].ps=0;
	}
	int k=0,t=0;
	sort(p, n);
	queue<int> q;
	while(k<n){
		int ind = findprocess(p, n, t, q);
		if(ind!=-1){
			//cout<<"P"<<ind<<" ";
			if(p[ind].bt<=tq){
				p[ind].ct=t+p[ind].bt;
				t=p[ind].ct;
				p[ind].ps=1;
				k++;
				q.pop();
			}
			else{
				p[ind].bt=p[ind].bt-tq;
				t=t+tq;
				q.pop();
				q.push(ind);
			}
		}
		else{
			t++;
		}
	}
		
	for(int i=0;i<n;i++){
		 cout<<p[i].ct<<" ";
	}
	//0 3 2 5 3 2 5 4
	
}

