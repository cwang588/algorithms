#include<bits/stdc++.h>
using namespace std;
struct edge{
	int from,to,nxt;
}e[250005];
int Head[500005],cnt,rd[500005],n,m,k,tmprd[500005];
bool usd[500005];
int getid(int x,int y){
	return (x-1)*n+y;
}
void add(int x,int y){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
int now[500005],ans[500005];
int main(){
	cin>>n>>k>>m;
	for(int i=1;i<=m;++i){
		int x,y;
		cin>>x>>y;
		add(x,y);
		++rd[y];
	}
//	for(int i=1;i<=n;++i){
//		for(int j=1;j<=k;++j)tmprd[getid(j,i)]=rd[i];
//		if(!rd[i]){
//			for(int j=1;j<=k;++j)usd[getid(j,i)]=true;
//		}
//	}
	for(int i=1;i<=n*k;++i){
		int x;	
		cin>>x;
		++now[x];
		ans[i]=now[x];
	}
	for(int i=1;i<=n*k;++i)cout<<ans[i]<<" ";
	return 0;
}
