#include<bits/stdc++.h>
using namespace std;
struct edge{
	int from,to,nxt;
}e[500005];
int Head[200005],cnt;
void add(int x,int y){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt; 
}
int scnt[200005],num[200005],fa[200005];
bool yz[200005],bud[200005];
void dfs(int now,int pre){
	fa[now]=pre;
	num[now]=scnt[now]=yz[now]=0;
	bud[now]=true;
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(to==pre)continue;
		++scnt[now];
		dfs(to,now);
		bud[now]&=yz[to];
		if(!yz[to])++num[now];
	}
	if(!scnt[now])bud[now]=false,yz[now]=true;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cnt=0;
		for(int i=1;i<=n;++i)Head[i]=0;
		for(int i=1;i<n;++i){
			int x,y;
			cin>>x>>y;
			add(x,y);
			add(y,x);
		}
		dfs(1,0);
		vector<int>v;
		int live=0,ans=0;
		for(int i=2;i<=n;++i){
			if(yz[i])++ans;
			if(bud[i])v.push_back(i);
			else{
				if(yz[i]&&!bud[fa[i]])++live;
			}
		}
		for(auto x:v){
			if(!live)live+=scnt[x];
			else{
				if(scnt[fa[x]]>1)--ans;
				--scnt[fa[x]];
				--num[fa[x]];
				live+=scnt[x]-1;
				if(scnt[fa[x]]==0)++live;
				x=fa[x];
				while(x!=1&&!num[x]){
					if(scnt[x]){
						if(scnt[fa[x]]>1)--ans;
						--scnt[fa[x]];
						--num[fa[x]];
						live+=scnt[x]-1;
						if(scnt[fa[x]]==0)++live;
					}
					x=fa[x];
				}
			}
		}
		cout<<ans<<endl;
	}	
	return 0;
}
