#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[15];
int b[10005];
char s[15][10005];
long long ans;
vector<pair<int,int> >tmp;
long long bkx[10005];
void dfs(int now,long long tot){
	if(now==n+1){
		tmp.clear();
		for(int i=1;i<=m;++i)tmp.push_back(make_pair(b[i],i));
		sort(tmp.begin(),tmp.end());
		long long nowans=tot;
		for(int i=0;i<m;++i)nowans+=1ll*(i+1)*tmp[i].first;
		if(ans<nowans){
			ans=nowans;
			for(int i=0;i<m;++i)bkx[tmp[i].second]=i+1;
		}
		return;
	}
	for(int i=1;i<=m;++i)if(s[now][i]=='1')++b[i];
	dfs(now+1,tot-a[now]);
	for(int i=1;i<=m;++i)if(s[now][i]=='1')b[i]-=2;
	dfs(now+1,tot+a[now]);
	for(int i=1;i<=m;++i)if(s[now][i]=='1')++b[i];
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		ans=-1;
		for(int i=1;i<=m;++i)b[i]=0;
		for(int i=1;i<=n;++i)cin>>a[i];
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j)cin>>s[i][j];
		}
		dfs(1,0);
		for(int i=1;i<=m;++i)cout<<bkx[i]<<" ";
		cout<<"\n";
	}
	
	return 0;
}