#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cout<<"enter no. of processes: ";
	cin>>n;
	vector<pair<pair<int, int>, int>> t;
	for(int i=0;i<n;i++){
		cout<<"enter arrival and brust time of process "<<i+1<<" : "<<endl;
		int a,b; cin>>a>>b;
		t.push_back({{a,b},i});
	}
	sort(t.begin(),t.end());
	queue<pair<int,int>> q;
	vector<int> ct(n,0);
	int time=0,p=0;
	vector<int< vis(n,0);
	for(auto lt: t){
		if(lt==t.begin()){
		int arrival= lt.first.first;
		int brust= lt.first.second;
		int process_id= it.second;
		ct[p]=brust - arrival +arrival;
		time=ct[p];
		vis[p]=1;
	}
	else{
		
		
	}
		for(int i=1; i<n; i++){
			if(time >= v[i].first.first){
				q.push({v[i].first.second,i});
			}
		}
		
	}
	
	return 0;
}
