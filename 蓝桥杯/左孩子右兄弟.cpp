#include<bits/stdc++.h>
using namespace std;
struct edge{
	int from,to,nxt;
}e[200005];
int cnt,Head[100005];
void add(int x,int y){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
int dep[100005];
void dfs(int now){
	int Max=0;
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		dfs(to);
		Max=max(Max,dep[to]);
		++dep[now];
	}
	dep[now]+=Max;
}
int main(){
	int n;
	cin>>n;
	for(int i=2;i<=n;++i){
		int tmp;
		cin>>tmp;
		add(tmp,i);
	}
	dfs(1);
	cout<<dep[1];
	return 0;
}