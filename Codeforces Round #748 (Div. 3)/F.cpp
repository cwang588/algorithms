#include<bits/stdc++.h>
using namespace std;
int degree[400005];
vector<int>to[400005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		if(n==1){
			cout<<"0\n";
			continue;
		}
		for(int i=1;i<=n;++i)to[i].clear(),degree[i]=0;
		for(int i=1;i<n;++i){
			int x,y;
			cin>>x>>y;
			++degree[x],++degree[y];
			to[x].push_back(y);
			to[y].push_back(x);
		}
		queue<pair<int,int> >q;
		for(int i=1;i<=n;++i)if(degree[i]==1)q.push(make_pair(i,1));
		int cnt=0;
		while(!q.empty()){
			auto now=q.front();
			q.pop();
			++cnt;
			if(now.second==k)continue;
			for(auto x:to[now.first]){
				--degree[x];
				if(degree[x]==1)q.push(make_pair(x,now.second+1));
			}
		}
		cout<<n-cnt<<"\n";
	}
	
	return 0;
}