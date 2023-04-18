#include<bits/stdc++.h>
using namespace std;
struct edge{
	int from,to,val,nxt;
}e[400005];
int cnt,Head[200005];
void add(int x,int y,int z){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].val=z;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
int tmp;
long long dis;
void dfs(int now,int pre,long long sum){
	if(sum>dis){
		dis=sum;
		tmp=now;
	}
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(to==pre)continue;
		dfs(to,now,sum+e[i].val);
	}
}
int main(){
	int n,m;
	cin>>n>>m;
	long long tot=0;
	for(int i=1;i<n;++i){
		int x,y,z;
		cin>>x>>y>>z;
		add(x,y,z);
		add(y,x,z);
		tot+=z;
	}
	if(m>1){
		cout<<tot<<"\n";
	}else{
		dfs(1,0,0);
		dfs(tmp,0,0);
		cout<<dis<<"\n";
	}
	return 0;
}