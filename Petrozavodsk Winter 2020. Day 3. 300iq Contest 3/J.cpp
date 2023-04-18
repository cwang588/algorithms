#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
struct edge{
	int from,to,nxt;
}e[600005];
int Head[200005],cnt;
void add(int x,int y){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
int col[200005],num;
bool ky;
void dfs(int now){
	++num;
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(col[to]){
			if(col[to]+col[now])ky=false;
		}else{
			col[to]=-col[now];
			dfs(to);
		}
	}
}
long long qpow(long long a,long long b){
	long long re=1,now=a;
	while(b){
		if(b&1)re=re*now%mod;
		now=now*now%mod;
		b>>=1;
	}
	return re;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cnt=0;
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;++i)Head[i]=col[i]=0;
		for(int i=1;i<=m;++i){
			int x,y;
			cin>>x>>y;
			add(x,y);
			add(y,x);
		}
		int tot=0;
		for(int i=1;i<=n;++i){
			if(!col[i]){
				num=0;
				ky=true;
				col[i]=1;
				dfs(i);	
				if(ky)tot+=num-1;
				else tot+=num;
			}
		}
		cout<<qpow(5,m-tot)<<"\n";
	}
	return 0;
}