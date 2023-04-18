#include<bits/stdc++.h>
using namespace std;
struct edge{
	int from,to,nxt;
}e[600005];
int cnt,Head[300005],value[300005];
void add(int x,int y){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
int Max[300005],sum[300005],son[300005];
void dfs(int now,int pre){
	
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)cin>>value;
	for(int i=1;i<n;++i){
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	dfs(1,0);
	return 0;
}