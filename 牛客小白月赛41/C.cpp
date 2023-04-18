#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	long long k;
	cin>>n>>k;
	int ans=0;
	priority_queue<long long>q;
	for(int i=1;i<=n;++i){
		long long t;
		cin>>t;
		q.push(-t);
	}
	long long tot=0;
	while(true){
		long long now=q.top();
		q.pop();
		if(tot-now<=k){
			++ans;
			tot+=-now;
			q.push(now*2);
		}
		else break;
	}
	cout<<ans;
	return 0;
}