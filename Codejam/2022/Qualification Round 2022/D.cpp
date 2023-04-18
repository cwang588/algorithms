#include<bits/stdc++.h>
using namespace std;
long long a[100005];
struct edge{
	int from,to,nxt;
}e[200005];
int Head[100005],cnt;
void add(int x,int y){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
long long sum[100005];
long long dfs(int now){
	sum[now]=0;
	long long Min1=1e18;
	for(int i=Head[now];i;i=e[i].nxt){
		long long tmp=dfs(e[i].to);
		sum[now]+=sum[e[i].to];
		if(tmp<=Min1){
			Min1=tmp;
		}
	}
	if(Min1==1e18){
		sum[now]=a[now];
		return a[now];
	}
	sum[now]+=max(0ll,a[now]-Min1);
	Min1=max(Min1,a[now]);
	return Min1;
}
int main(){
	int t;
	cin>>t;
	for(int Case=1;Case<=t;++Case){
		cnt=0;
		int n;
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i],Head[i]=0;
		vector<int>start;
		for(int i=1;i<=n;++i){
			int fa;
			cin>>fa;
			if(fa==0)start.push_back(i);
			else add(fa,i);
		}
		long long ans=0;
		for(const auto &s:start)dfs(s),ans+=sum[s];
		cout<<"Case #"<<Case<<": "<<ans<<"\n";
	}
	
	return 0;
}