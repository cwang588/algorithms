#include<bits/stdc++.h>
using namespace std;
struct edge{
	int from,to,nxt;
}e[400005];
int Head[200005],cnt;
void add(int x,int y){
	++cnt;
	e[cnt].from=x;	
	e[cnt].to=y;	
	e[cnt].nxt=Head[x];	
	Head[x]=cnt;
}
int sz[500005],col[500005],dfn[200005],dep[200005],dfncnt,fa[200005][25];
int pointnum;
vector<int>v[200005];
void dfs1(int now,int pre){
	fa[now][0]=pre;
	sz[now]=1;
	for(int i=1;i<=20;++i)fa[now][i]=fa[fa[now][i-1]][i-1];
	dfn[now]=++dfncnt;
	dep[now]=dep[pre]+1;
	v[col[now]].push_back(now);
	bool ky=false;
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(to==pre)continue;
		dfs1(to,now);
		ky=true;
		sz[now]+=sz[to];
	}
	if(!ky){
		++pointnum;
		dfn[pointnum]=++dfncnt;
		dep[pointnum]=dep[now]+1;
		fa[pointnum][0]=now;
		for(int i=1;i<=20;++i)fa[pointnum][i]=fa[fa[pointnum][i-1]][i-1]; 
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=20;i>=0;--i)if(dep[fa[x][i]]>=dep[y])x=fa[x][i];
	if(x==y)return x;
	for(int i=20;i>=0;--i){
		if(fa[x][i]!=fa[y][i]){
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	return fa[x][0];
}
bool cmp(int x,int y){
	return dfn[x]<dfn[y];
}
int nowcol;
long long ans;
long long calc(long long x){
	return x*(x-1)/2;
} 
struct graph{
	vector<int>to[200005];
	int dp[200005];
	void dfs(int now,int pre){
		if(col[now]==nowcol)dp[now]=0;
		else dp[now]=1;
		bool ky=false;
		for(auto x:to[now]){
			if(x==pre)continue;
			dfs(x,now);
			ky=true;
			if(col[now]==nowcol)ans-=calc(dp[x]+dep[x]-dep[now]-1);
			else dp[now]+=dp[x]+dep[x]-dep[now]-1;
		}
		if(!ky){
			for(int i=Head[now];i;i=e[i].nxt){
				int to=e[i].to;
				if(to==fa[now][0])continue;
				ans-=calc(sz[to]);
			}
		}
		v[now].clear();
	}
}bkx;
int main(){
	int n;
	while(cin>>n){
		memset(fa,0,sizeof(fa));
		cnt=dfncnt=0;
		for(int i=1;i<=n;++i)Head[i]=0;
		for(int i=1;i<=n;++i)cin>>col[i];
		for(int i=1;i<n;++i){
			int x,y;
			cin>>x>>y;
			add(x,y);
			add(y,x);
		}
		dfs1(1,0);
		for(int i=1;i<=n;++i){
			if(!v[i].size())continue;
			nowcol=i;
			ans+=calc(n);
			stack<int>s;
			s.push(0);
			sort(v[i].begin(),v[i].end(),cmp);
			s.push(v[i][0]);
			for(auto x:v[i]){
				int now1=s.top();
				s.pop();
				int now2=s.top();
				int lc=lca(x,now1);
				if(lc==now1){
					s.push(now1);
					s.push(x);
				}
				else if(dep[lc]<dep[now2]){
					bkx.to[lc].push_back(now1);
				//	bkx.usd[lc]=bkx.usd[now1]=true;
					s.push(lc);
					s.push(x);
				}
				else if(lc==now2){
					bkx.to[lc].push_back(now1);
				//	bkx.usd[lc]=bkx.usd[now1]=true;
					s.push(x);
				}
				else{
					while(lc>dep[now2]){
						bkx.to[now2].push_back(now1);
					//	bkx.usd[now2]=bkx.usd[now1]=true;
						s.pop();
						now1=now2;
						now2=s.top();
						lc=lca(x,now1);
					}
					if(dep[lc]<dep[now2]){
						bkx.to[lc].push_back(now1);
					//	bkx.usd[lc]=bkx.usd[now1]=true;
						s.push(lc);
						s.push(x);
					}
					else{
						bkx.to[lc].push_back(now1);
					//	bkx.usd[lc]=bkx.usd[now1]=true;
						s.push(x);
					}
				}
			}
			while(!s.empty()){
				if(s.top()==0)break;
				int now1=s.top();
				s.pop();
				int now2=s.top();
				if(now2){
					bkx.to[now2].push_back(now1);
				//	bkx.usd[now2]=bkx.usd[now1]=true;
				}
			}
			bkx.dfs(1,0);
		}
		cout<<ans<<endl;
	}
	return 0;
}
