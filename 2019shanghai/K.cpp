#include<bits/stdc++.h>
using namespace std;
struct edge{
	int x,y;
}e[155];
int col[25],n,m,ans;
void dfs(int now){
	if(now==n+1){
		int cnt=0;
		for(int i=1;i<=m;++i){
			if(col[e[i].x]!=col[e[i].y])++cnt;
		}
		ans=max(ans,cnt);
		return;
	}
	col[now]=1;
	dfs(now+1);
	col[now]=0;
	dfs(now+1);
}
int main(){
	int t;
	cin>>t;
	for(int Case=1;Case<=t;++Case){
		cin>>n>>m;
		ans=0;
		for(int i=1;i<=m;++i){
			int x,y;
			cin>>x>>y;
			e[i]={x,y};
		}
		dfs(1);
		cout<<"Case #"<<Case<<": "<<ans<<"\n";
	}
	
	return 0;
}