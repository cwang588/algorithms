#include<bits/stdc++.h>
using namespace std;
struct edge{
	int from,to,nxt;
}e[600005];
int Head[300005],cnt;
void add(int x,int y){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
int w[300005],s[300005],t[300005];
int fa[300005][25],depth[300005];
void dfs(int now,int pre){
	depth[now]=depth[pre]+1;
	fa[now][0]=pre;
	for(int i=1;i<=20;++i)fa[now][i]=fa[fa[now][i-1]][i-1];
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(to==pre)continue;
		dfs(to,now);
	}
}
int lca(int x,int y){
	if(depth[x]<depth[y])swap(x,y);
	for(int i=20;i>=0;--i)if(depth[fa[x][i]]>=depth[y])x=fa[x][i];
	if(x==y)return x;
	for(int i=20;i>=0;--i){
		if(fa[x][i]!=fa[y][i]){
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	return fa[x][0];
}
struct athlete{
	int s,t,Btime;	
}a1[300005],a2[300005];
int num1,num2,ans[300005];
vector<int>s1[300005],t1[300005],s2[300005],t2[300005];
unordered_map<int,int>tong1,tong2;
void dfss(int now,int pre){
		int tmp1=tong1[w[now]+depth[now]],tmp2=tong2[w[now]-depth[now]];
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(to==pre)continue;
		dfss(to,now);
	}
	for(auto ath:s1[now])++tong1[depth[a1[ath].s]];
	for(auto ath:t2[now])++tong2[a2[ath].Btime-depth[a2[ath].s]];
	ans[now]=tong1[w[now]+depth[now]]+tong2[w[now]-depth[now]]-tmp1-tmp2;
	for(auto ath:t1[now])--tong1[depth[a1[ath].s]];
	for(auto ath:s2[now])--tong2[a2[ath].Btime-depth[a2[ath].s]];
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<n;++i){
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	for(int i=1;i<=n;++i)cin>>w[i];
	for(int i=1;i<=m;++i)cin>>s[i]>>t[i];
	dfs(1,0);
	for(int i=1;i<=m;++i){
		int nowlca=lca(s[i],t[i]);
		if(nowlca==t[i]){
			++num1;
			a1[num1]=athlete{s[i],t[i],0};
			s1[s[i]].push_back(num1);
			t1[t[i]].push_back(num1);
		}
		else if(nowlca==s[i]){
			++num2;
			a2[num2]=athlete{s[i],t[i],0};
			s2[s[i]].push_back(num2);
			t2[t[i]].push_back(num2);
		}
		else{
			++num1;
			a1[num1]=athlete{s[i],nowlca,0};
			s1[s[i]].push_back(num1);
			t1[nowlca].push_back(num1);
			int now=t[i];
			for(int j=20;j>=0;--j)if(depth[fa[now][j]]>depth[nowlca])now=fa[now][j];
			++num2;
			a2[num2]=athlete{now,t[i],depth[s[i]]-depth[nowlca]+1};
			s2[now].push_back(num2);
			t2[t[i]].push_back(num2);
		}
	}
	dfss(1,0);
	for(int i=1;i<=n;++i)cout<<ans[i]<<" ";
	cout<<"\n";
	return 0;
}