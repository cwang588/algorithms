#include<bits/stdc++.h>
using namespace std;
struct edge{
	int from,to,nxt,value;
}e[5000005];
int cnt=1,Head[2000005];
void add(int x,int y){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
int value[2000005];
int num,n;
void dfs(int now,int pre){
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(to==pre)continue;
		++num;
		if(value[now]>=n){
			e[i].value=e[i^1].value=num+n;
			value[to]=num;
		}
		else{
			e[i].value=e[i^1].value=num;
			value[to]=num+n;
		}
		dfs(to,now);
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cnt=1;
		num=0;
		int p;
		cin>>p;
		n=(1<<p);
		for(int i=1;i<=n;++i)Head[i]=0;
		for(int i=1;i<n;++i){
			int x,y;
			cin>>x>>y;
			add(x,y);
			add(y,x);
		}
		value[1]=n;
		dfs(1,0);
		cout<<"1\n";
		for(int i=1;i<=n;++i)cout<<value[i]<<" ";
		cout<<"\n";
		for(int i=1;i<n;++i)cout<<e[i*2].value<<" ";
		cout<<"\n";
	}
	return 0;
}