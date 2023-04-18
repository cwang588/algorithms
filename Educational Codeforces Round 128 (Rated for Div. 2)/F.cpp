#include<bits/stdc++.h>
using namespace std;
struct edge{
	int from,to,nxt;
}e[2000005];
int Head[1000005],cnt;
void add(int x,int y){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
bool ky,tag;
int col[1000005];
void dfs(int now)
int main(){
	int t;
	cin>>t;
	while(t--){
		cnt=0;
		ky=true,tag=false;
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;++i)Head[i]=col[i]=0;
		for(int i=1;i<=m;++i){
			int x,y;
			cin>>x>>y;
			add(x,y);
			add(y,x);
		}
		col[1]=1;
		dfs(1,);
	}
	
	return 0;
}