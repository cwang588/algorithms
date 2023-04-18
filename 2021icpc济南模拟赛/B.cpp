#include<bits/stdc++.h>
using namespace std;
struct edge{
	int from,to,nxt,value;
}e[2000005];
int Head[1005],cnt;
void add(int x,int y,int z){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].value=z;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
int dfn[1005],low[1005],dfncnt;
vector<int>ans;
bool usd[2000005],vis[1005];
void tarjan(int now,int fa){
	vis[now]=true;
	dfn[now]=low[now]=++dfncnt;
	for(int i=Head[now];i;i=e[i].nxt){
		if(usd[i])continue;
		int to=e[i].to;
		if(!dfn[to]){
			usd[i]=usd[i^1]=true;
			tarjan(to,now);
			low[now]=min(low[now],low[to]);
			if(low[to]>dfn[now])ans.push_back(i);
		}
		else low[now]=min(low[now],dfn[to]);
	}
}
int main(){
	cin.tie(0)->sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	while(n){
		ans.clear();
		memset(vis,0,sizeof(vis));
		memset(usd,0,sizeof(usd));
		memset(dfn,0,sizeof(dfn));
		memset(low,0,sizeof(low));
		memset(Head,0,sizeof(Head));
		cnt=1;
		dfncnt=0;
		for(int i=1;i<=m;++i){
			int x,y,z;
			cin>>x>>y>>z;
			add(x,y,z);
			add(y,x,z);
		}
		tarjan(1,0);
		bool ky=true;
		for(int i=1;i<=n;++i){
			if(!vis[i]){
				ky=false;
				break;
			}
		}
		int Min=2147483647;
		for(auto x:ans)Min=min(Min,e[x].value);
		if(Min == 0) Min = 1;
		if(!ky)cout<<"0";
		else{
			if(ans.size())cout<<Min;
			else cout<<"-1";
		}
		cin>>n>>m;
		if(n)cout<<"\n";
	}
	
	return 0;
}