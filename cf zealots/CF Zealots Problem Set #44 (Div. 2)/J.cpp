#include<bits/stdc++.h>
using namespace std;
int to[100005];
bool usd[100005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;++i)to[i]=0,usd[i]=false;
		for(int i=1;i<=m;++i){
			int x,y;
			cin>>x>>y;
			to[x]=y;
		}
		int ans=m;
		for(int i=1;i<=n;++i){
			if(!to[i])continue;
			if(to[i]==i){
				--ans;
				continue;
			}
			usd[i]=true;
			int now=to[i];
			while(now&&!usd[now]){
				usd[now]=true;
				now=to[now];
			}
			if(now==i)++ans;
		}	
		cout<<ans<<"\n";
	}
	
	return 0;
}