#include<bits/stdc++.h>
using namespace std;
struct edge{
	int from,to,nxt;
}e[200006];
int Head[100005],cnt,v[100005][2],num;
void add(int x,int y){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
int degree[10005];
void dfs(int now,int pre){
	if(pre)v[now][0]=v[pre][1];
	v[now][1]=++num;
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(to==pre)continue;
		dfs(to,now);
	}
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<n;++i){
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
		++degree[x];
		++degree[y];
	}
	if(n==2){
		cout<<"1 2\n2 1\n";
		return 0;
	}
	for(int i=1;i<=n;++i){
		if(degree[i]==1){
			v[i][0]=1;
			num=1;
			dfs(i,0);
			for(int j=1;j<=n;++j)cout<<v[j][0]<<" "<<v[j][1]<<"\n";
			return 0;
		}
	}
	
	return 0;
}
