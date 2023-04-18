#include<bits/stdc++.h>
using namespace std;
struct edge{
	int from,to,nxt,value;
}e[2000005];
int Head[200005],cnt;
void add(int x,int y,int z){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].value=z;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
int col[200005],fa[200005],tot,num[200005],tmpcnt[200005];
bool ky;
void dfs(int now){
	++num[fa[now]];
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(!col[to]){
			if(col[now]==1)col[to]=col[now]+e[i].value;
			else col[to]=col[now]-e[i].value;
			fa[to]=fa[now];
			dfs(to);
		}
		else{
			if(abs(col[to]-col[now])!=e[i].value){
				ky=false;
				return;
			}
		}
		
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		ky=true;
		for(int i=1;i<=n;++i)col[i]=Head[i]=fa[i]=num[i]=tmpcnt[i]=0;cnt=tot=0;
		for(int i=1;i<=m;++i){
			int x,y;
			string s;
			cin>>x>>y>>s;
			if(s=="imposter"){
				add(x,y,1);
				add(y,x,1);
			}
			else{
				add(x,y,0);
				add(y,x,0);
			}
		}
		for(int i=1;i<=n;++i){
			if(!col[i]){
				fa[i]=++tot;
				col[i]=1;
				dfs(i);
			}
		}
		if(!ky){
			cout<<"-1\n";
			continue;
		}
		for(int i=1;i<=n;++i)if(col[i]==1)++tmpcnt[fa[i]];
		int ans=0;
		for(int i=1;i<=tot;++i)ans+=max(tmpcnt[i],num[i]-tmpcnt[i]);
		cout<<ans<<"\n";
	}
	return 0;
}